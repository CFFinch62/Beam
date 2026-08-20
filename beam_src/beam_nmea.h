/*
 * beam_nmea.h - BEAM NMEA 0183 serial port support
 *
 * Provides non-blocking serial I/O for reading NMEA 0183 sentences from a
 * GPS/chartplotter data bus.  Up to BEAM_NMEA_MAX_PORTS ports may be open
 * simultaneously; each is identified by a small integer handle (0-based).
 *
 * Public API (called from beam_commands.c dispatch):
 *   beam_nmea_open(port$, baud)  -> handle (0-3) or -1 on error
 *   beam_nmea_close(handle)      -> void
 *   beam_nmea_read$(handle)      -> next complete sentence or "" (non-blocking)
 *   beam_nmea_field$(sent$, n)   -> comma-field n (1-based) from sentence
 *
 * On beam_nmea_open() failure, the reason (e.g. "open '/tmp/ttyV1' failed:
 * Device or resource busy") is printed to stderr and also available via
 * beam_nmea_last_error() for callers embedding beam_nmea.c directly.  This
 * is not yet exposed to BASIC scripts (would require a new bison/flex
 * token); check the terminal beam was launched from when Connect fails.
 */

#ifndef BEAM_NMEA_H
#define BEAM_NMEA_H

/* Maximum number of simultaneously-open NMEA ports */
#define BEAM_NMEA_MAX_PORTS 4

/* Open a serial port in non-blocking mode.
 * port_path: device path e.g. "/dev/ttyUSB0"
 * baud:      baud rate   e.g. 4800
 * Returns a handle (0-3) on success, -1 on failure.           */
int  beam_nmea_open(const char *port_path, int baud);

/* Close a previously-opened port.  No-op if handle is invalid. */
void beam_nmea_close(int handle);

/* Non-blocking read of one complete NMEA sentence.
 * Returns a pointer to a static buffer containing the trimmed sentence
 * (without leading '$' stripping — raw sentence as received), or an
 * empty string "" when no complete sentence is available yet.
 * The returned pointer is valid until the next call to beam_nmea_read.  */
const char *beam_nmea_read(int handle);

/* Extract comma-delimited field n (1-based) from an NMEA sentence string.
 * Field 0 is the talker+sentence-type prefix (e.g. "GPGGA").
 * Field 1 is the first data field.
 * Returns pointer to a static buffer; empty string if field is out of range.
 * The checksum suffix (*XX) is excluded from the last field automatically. */
const char *beam_nmea_field(const char *sentence, int n);

/* Reason the most recent beam_nmea_open() call failed, or "" if the last
 * call succeeded.  Valid until the next beam_nmea_open() call.            */
const char *beam_nmea_last_error(void);

#endif /* BEAM_NMEA_H */
