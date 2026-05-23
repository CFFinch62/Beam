/*
 * beam_nmea.c - BEAM NMEA 0183 serial port support
 *
 * Non-blocking serial I/O for reading NMEA 0183 data.  Each open port has a
 * line-accumulation buffer; beam_nmea_read() returns complete lines (up to
 * '\n') without blocking the GUI render loop.
 *
 * Platform: POSIX (Linux/macOS).  On Windows this would use Win32 COMM APIs;
 * for now the stubs fall through gracefully if termios is unavailable.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
  /* Windows stubs — serial support not yet implemented */
  static int win32_open(const char *p, int b) { (void)p; (void)b; return -1; }
  static void win32_close(int h)               { (void)h; }
  static int  win32_read_byte(int h)           { (void)h; return -1; }
  #define PLATFORM_OPEN(p,b)  win32_open(p,b)
  #define PLATFORM_CLOSE(h)   win32_close(h)
  #define PLATFORM_READBYTE(h) win32_read_byte(h)
#else
  #include <fcntl.h>
  #include <termios.h>
  #include <unistd.h>

static speed_t baud_to_speed(int baud) {
    switch (baud) {
        case 4800:   return B4800;
        case 9600:   return B9600;
        case 19200:  return B19200;
        case 38400:  return B38400;
        case 57600:  return B57600;
        case 115200: return B115200;
        default:     return B4800;
    }
}

static int posix_open(const char *path, int baud) {
    int fd = open(path, O_RDONLY | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) return -1;

    struct termios tio;
    memset(&tio, 0, sizeof(tio));
    cfsetispeed(&tio, baud_to_speed(baud));
    cfsetospeed(&tio, baud_to_speed(baud));
    tio.c_cflag  = CS8 | CREAD | CLOCAL;
    tio.c_iflag  = IGNPAR;
    tio.c_oflag  = 0;
    tio.c_lflag  = 0;
    tio.c_cc[VMIN]  = 0;
    tio.c_cc[VTIME] = 0;
    if (tcsetattr(fd, TCSANOW, &tio) != 0) {
        close(fd);
        return -1;
    }
    tcflush(fd, TCIFLUSH);
    return fd;
}

static void posix_close(int fd) {
    if (fd >= 0) close(fd);
}

static int posix_read_byte(int fd) {
    unsigned char c;
    int n = (int)read(fd, &c, 1);
    return (n == 1) ? (int)c : -1;
}

  #define PLATFORM_OPEN(p,b)   posix_open(p,b)
  #define PLATFORM_CLOSE(h)    posix_close(h)
  #define PLATFORM_READBYTE(h) posix_read_byte(h)
#endif  /* !_WIN32 */

#include "beam_nmea.h"

/* ------------------------------------------------------------------ */
/* Port state                                                           */
/* ------------------------------------------------------------------ */

#define LINE_BUF_SIZE 512

typedef struct {
    int  fd;
    int  is_open;
    char line_buf[LINE_BUF_SIZE];
    int  line_len;
} NmeaPort;

static NmeaPort ports[BEAM_NMEA_MAX_PORTS];
static int      ports_initialised = 0;

static void ensure_init(void) {
    if (ports_initialised) return;
    memset(ports, 0, sizeof(ports));
    for (int i = 0; i < BEAM_NMEA_MAX_PORTS; i++) ports[i].fd = -1;
    ports_initialised = 1;
}

/* ------------------------------------------------------------------ */
/* Static return buffers                                                */
/* ------------------------------------------------------------------ */

static char read_result[LINE_BUF_SIZE];
static char field_result[LINE_BUF_SIZE];

/* ------------------------------------------------------------------ */
/* Public API                                                           */
/* ------------------------------------------------------------------ */

int beam_nmea_open(const char *port_path, int baud) {
    ensure_init();
    for (int i = 0; i < BEAM_NMEA_MAX_PORTS; i++) {
        if (!ports[i].is_open) {
            int fd = PLATFORM_OPEN(port_path, baud);
            if (fd < 0) return -1;
            ports[i].fd       = fd;
            ports[i].is_open  = 1;
            ports[i].line_len = 0;
            memset(ports[i].line_buf, 0, LINE_BUF_SIZE);
            return i;
        }
    }
    return -1;   /* no free slot */
}

void beam_nmea_close(int handle) {
    ensure_init();
    if (handle < 0 || handle >= BEAM_NMEA_MAX_PORTS) return;
    if (!ports[handle].is_open) return;
    PLATFORM_CLOSE(ports[handle].fd);
    ports[handle].fd      = -1;
    ports[handle].is_open = 0;
    ports[handle].line_len = 0;
}

const char *beam_nmea_read(int handle) {
    ensure_init();
    read_result[0] = '\0';
    if (handle < 0 || handle >= BEAM_NMEA_MAX_PORTS) return read_result;
    NmeaPort *p = &ports[handle];
    if (!p->is_open) return read_result;

    /* Read up to 256 bytes per call so bursts don't starve the GUI */
    for (int n = 0; n < 256; n++) {
        int b = PLATFORM_READBYTE(p->fd);
        if (b < 0) break;

        if (b == '\n') {
            /* Trim trailing whitespace/CR */
            while (p->line_len > 0 &&
                   (p->line_buf[p->line_len - 1] == '\r' ||
                    p->line_buf[p->line_len - 1] == ' ')) {
                p->line_len--;
            }
            if (p->line_len > 1) {
                p->line_buf[p->line_len] = '\0';
                strncpy(read_result, p->line_buf, LINE_BUF_SIZE - 1);
                read_result[LINE_BUF_SIZE - 1] = '\0';
            }
            p->line_len = 0;
            if (read_result[0] != '\0') return read_result;
        } else if (b == '\r') {
            /* skip — handled above */
        } else {
            if (p->line_len < LINE_BUF_SIZE - 1) {
                p->line_buf[p->line_len++] = (char)b;
            }
        }
    }
    return read_result;  /* "" if no complete line yet */
}

const char *beam_nmea_field(const char *sentence, int n) {
    field_result[0] = '\0';
    if (!sentence || n < 0) return field_result;

    /* Skip leading '$' or '!' if present */
    const char *s = sentence;
    if (*s == '$' || *s == '!') s++;

    int field = 0;
    const char *start = s;

    while (*s) {
        if (*s == ',' || *s == '*') {
            if (field == n) {
                int len = (int)(s - start);
                if (len >= LINE_BUF_SIZE) len = LINE_BUF_SIZE - 1;
                strncpy(field_result, start, len);
                field_result[len] = '\0';
                return field_result;
            }
            if (*s == '*') break;  /* checksum — stop here */
            field++;
            start = s + 1;
        }
        s++;
    }
    /* Handle last field (no trailing comma, may end at '*' or '\0') */
    if (field == n) {
        const char *end = s;
        /* Strip checksum if we ended at null without hitting '*' */
        const char *cs = start;
        while (cs < end && *cs != '*') cs++;
        int len = (int)(cs - start);
        if (len >= LINE_BUF_SIZE) len = LINE_BUF_SIZE - 1;
        strncpy(field_result, start, len);
        field_result[len] = '\0';
    }
    return field_result;
}
