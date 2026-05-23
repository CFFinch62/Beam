// ============================================================
// BEAM Instruments — NMEA 0183 Marine Instrument Display
// Run: ./beam examples/beam-instruments.bas
//
// Displays GPS position, SOG, COG, heading, depth, water
// temperature, and wind from NMEA 0183 data.  Includes an
// AIS target list, NMEA sentence log, satellite summary,
// and voyage data panel.
//
// Supports both a built-in simulator (SIM mode) and live
// data from a serial port (LIVE mode).
// ============================================================

win = beam_open(1200, 800, "BEAM Instruments")
beam_set_style("dark")

// ── display state ──────────────────────────────────────────
g_lat$      = "---"
g_lon$      = "---"
g_sog$      = "---"
g_cog$      = "---"
g_hdg$      = "---"
g_depth$    = "---"
g_temp$     = "---"
g_wind_ang$ = "---"
g_wind_spd$ = "---"
g_pos_src$  = "---"
g_fix_type$ = "---"
g_sat_cnt   = 0
g_sat_used  = 0
g_hdop$     = "---"
g_pdop$     = "---"
g_utc_time$ = "--:--:--"
g_utc_date$ = "--/--/----"
g_stw$      = "---"
g_xte_mag$  = "---"
g_xte_dir$  = "-"
g_nav_dest$ = "---"
g_nav_brg$  = "---"
g_nav_dist$ = "---"
g_nav_vmg$  = "---"
g_nav_arr$  = "V"

// ── AIS target ring buffer (10 slots) ──────────────────────
// Format: "MMSI|SOG|LAT|LON|COG"  empty = unused
dim g_ais$(10)
g_ais_next  = 0
g_ais_scroll = 0

// ── NMEA log (ring buffer of 200 lines) ───────────────────
dim g_log$(200)
g_log_head  = 0
g_log_count = 0
g_log_scroll = 0

// ── operational state ──────────────────────────────────────
g_mode$     = "LIVE"    // "SIM" or "LIVE"
g_port$     = "/dev/ttyUSB0"
port_input$ = "/dev/ttyUSB0"
g_baud      = 4800
g_handle    = -1        // serial port handle
g_paused    = 0
g_tab       = 0         // 0=NMEA LOG  1=SATELLITES  2=VOYAGE DATA

// ── simulator state ────────────────────────────────────────
sim_running = 0
sim_tick    = 0
sim_lat     = 47.6352
sim_lon     = -122.357
sim_sog     = 6.8
sim_cog     = 247.0
sim_hdg     = 243.0
sim_depth   = 18.4
sim_wind_spd = 12.3
sim_wind_ang = 45.0
sim_water_tmp = 18.5
sim_xte  = 0.0    // cross-track error (nm, + = L, - = R)
sim_dist = 12.5   // distance to waypoint (nm)
sim_brg  = 252.0  // bearing to waypoint (deg)

// ── GSV / per-satellite data ───────────────────────────────
gsv_buf$    = ""
gsv_count   = 0
sat_count   = 0
dim sat_prn(16)
dim sat_snr(16)

// ── position source priority ───────────────────────────────
pos_level   = 0      // 3=RMC 2=GGA 1=GLL 0=none
rmc_miss    = 0
gga_miss    = 0

// ============================================================
// Helpers — NOTE: user-defined string subs (name$) cannot be
// called from inside other subs in yabasic.  Use built-in
// str$()/int()/val() inline instead.  These stubs remain for
// use only at the top level if needed.
// ============================================================

sub f1$(v)
  f1$ = str$(int(v * 10) / 10)
end sub

sub f2$(v)
  f2$ = str$(int(v * 100) / 100)
end sub

sub pad2$(n)
  if n < 10 then
    pad2$ = "0" + str$(n)
  else
    pad2$ = str$(n)
  end if
end sub

// ── Logging ────────────────────────────────────────────────
sub log_add(msg$)
  idx = mod(g_log_head, 200)
  g_log$(idx) = msg$
  g_log_head = g_log_head + 1
  if g_log_count < 200 then
    g_log_count = g_log_count + 1
  end if
end sub

// ── AIS upsert (ring buffer) ───────────────────────────────
sub ais_upsert(tgt$)
  p = instr(tgt$, "|")
  if p = 0 then
    return
  end if
  new_mmsi$ = left$(tgt$, p - 1)
  for i = 0 to 9
    slot$ = g_ais$(i)
    if len(slot$) > 2 then
      q = instr(slot$, "|")
      if q > 0 then
        if left$(slot$, q - 1) = new_mmsi$ then
          g_ais$(i) = tgt$
          return
        end if
      end if
    end if
  next i
  g_ais$(g_ais_next) = tgt$
  g_ais_next = mod(g_ais_next + 1, 10)
end sub

// ============================================================
// NMEA Parser
// ============================================================

sub nmea_parse(raw$)
  if g_paused then
    return
  end if
  log_add(raw$)

  sentence$ = raw$
  if left$(sentence$, 1) = "$" then
    sentence$ = right$(sentence$, len(sentence$) - 1)
  end if

  stype$ = beam_nmea_field(sentence$, 0)
  if len(stype$) = 5 then
    stype$ = right$(stype$, 3)
  end if

  if stype$ = "GGA" then
    handle_gga()
  elseif stype$ = "RMC" then
    handle_rmc()
  elseif stype$ = "GLL" then
    handle_gll()
  elseif stype$ = "DPT" then
    handle_dpt()
  elseif stype$ = "DBT" then
    handle_dbt()
  elseif stype$ = "MWV" then
    handle_mwv()
  elseif stype$ = "VHW" then
    handle_vhw()
  elseif stype$ = "HDT" then
    handle_hdt()
  elseif stype$ = "MTW" then
    handle_mtw()
  elseif stype$ = "VTG" then
    handle_vtg()
  elseif stype$ = "GSV" then
    handle_gsv()
  elseif stype$ = "GSA" then
    handle_gsa()
  elseif stype$ = "ZDA" then
    handle_zda()
  elseif stype$ = "XTE" then
    handle_xte()
  elseif stype$ = "RMB" then
    handle_rmb()
  end if
end sub

// ── Sentence handlers ──────────────────────────────────────

sub handle_gga()
  lat$ = beam_nmea_field(sentence$, 2)
  latd$ = beam_nmea_field(sentence$, 3)
  lon$ = beam_nmea_field(sentence$, 4)
  lond$ = beam_nmea_field(sentence$, 5)
  if len(lat$) > 0 then
    if pos_level < 3 then
      g_lat$ = lat$ + " " + latd$
      g_lon$ = lon$ + " " + lond$
      pos_level = 2
      g_pos_src$ = "GGA"
    else
      rmc_miss = rmc_miss + 1
      if rmc_miss > 5 then
        g_lat$ = lat$ + " " + latd$
        g_lon$ = lon$ + " " + lond$
        pos_level = 2
        g_pos_src$ = "GGA"
        rmc_miss = 0
      end if
    end if
  end if
end sub

sub handle_rmc()
  stat$ = beam_nmea_field(sentence$, 2)
  lat$ = beam_nmea_field(sentence$, 3)
  latd$ = beam_nmea_field(sentence$, 4)
  lon$ = beam_nmea_field(sentence$, 5)
  lond$ = beam_nmea_field(sentence$, 6)
  sog_raw$ = beam_nmea_field(sentence$, 7)
  cog_raw$ = beam_nmea_field(sentence$, 8)
  if len(lat$) > 0 and stat$ = "A" then
    g_lat$ = lat$ + " " + latd$
    g_lon$ = lon$ + " " + lond$
    pos_level = 3
    rmc_miss = 0
    gga_miss = 0
    g_pos_src$ = "RMC"
  end if
  if len(sog_raw$) > 0 then
    g_sog$ = str$(int(val(sog_raw$) * 10) / 10)
  end if
  if len(cog_raw$) > 0 then
    g_cog$ = str$(int(val(cog_raw$) * 10) / 10)
  end if
end sub

sub handle_gll()
  stat$ = beam_nmea_field(sentence$, 6)
  if stat$ <> "A" then
    return
  end if
  lat$ = beam_nmea_field(sentence$, 1)
  latd$ = beam_nmea_field(sentence$, 2)
  lon$ = beam_nmea_field(sentence$, 3)
  lond$ = beam_nmea_field(sentence$, 4)
  if len(lat$) > 0 then
    if pos_level >= 2 then
      gga_miss = gga_miss + 1
      if gga_miss > 5 then
        g_lat$ = lat$ + " " + latd$
        g_lon$ = lon$ + " " + lond$
        pos_level = 1
        g_pos_src$ = "GLL"
        gga_miss = 0
      end if
    else
      g_lat$ = lat$ + " " + latd$
      g_lon$ = lon$ + " " + lond$
      pos_level = 1
      g_pos_src$ = "GLL"
    end if
  end if
end sub

sub handle_dpt()
  d$ = beam_nmea_field(sentence$, 1)
  if len(d$) > 0 then
    g_depth$ = str$(int(val(d$) * 10) / 10)
  end if
end sub

sub handle_dbt()
  d$ = beam_nmea_field(sentence$, 3)
  if len(d$) > 0 and g_depth$ = "---" then
    g_depth$ = str$(int(val(d$) * 10) / 10)
  end if
end sub

sub handle_mwv()
  ang$ = beam_nmea_field(sentence$, 1)
  spd$ = beam_nmea_field(sentence$, 3)
  if len(ang$) > 0 then
    g_wind_ang$ = str$(int(val(ang$) * 10) / 10)
  end if
  if len(spd$) > 0 then
    g_wind_spd$ = str$(int(val(spd$) * 10) / 10)
  end if
end sub

sub handle_vhw()
  stw$ = beam_nmea_field(sentence$, 5)
  if len(stw$) > 0 then
    g_stw$ = str$(int(val(stw$) * 10) / 10)
  end if
end sub

sub handle_hdt()
  h$ = beam_nmea_field(sentence$, 1)
  if len(h$) > 0 then
    g_hdg$ = str$(int(val(h$) * 10) / 10)
  end if
end sub

sub handle_mtw()
  t$ = beam_nmea_field(sentence$, 1)
  if len(t$) > 0 then
    g_temp$ = str$(int(val(t$) * 10) / 10)
  end if
end sub

sub handle_vtg()
  s$ = beam_nmea_field(sentence$, 5)
  if len(s$) > 0 then
    g_sog$ = str$(int(val(s$) * 10) / 10)
  end if
end sub

sub handle_gsv()
  msg_n = val(beam_nmea_field(sentence$, 2))
  if msg_n = 1 then
    gsv_count = val(beam_nmea_field(sentence$, 3))
    sat_count = 0
  end if
  // Each message carries up to 4 satellites in fields 4-7, 8-11, 12-15, 16-19
  for si = 0 to 3
    prn$ = beam_nmea_field(sentence$, 4 + si * 4)
    snr$ = beam_nmea_field(sentence$, 7 + si * 4)
    if len(prn$) > 0 and sat_count < 16 then
      sat_prn(sat_count) = val(prn$)
      sat_snr(sat_count) = val(snr$)
      sat_count = sat_count + 1
    end if
  next si
  g_sat_cnt = gsv_count
end sub

sub handle_gsa()
  fix_n$ = beam_nmea_field(sentence$, 2)
  g_pdop$ = beam_nmea_field(sentence$, 15)
  g_hdop$ = beam_nmea_field(sentence$, 16)
  if val(fix_n$) = 1 then
    g_fix_type$ = "No Fix"
  elseif val(fix_n$) = 2 then
    g_fix_type$ = "2D"
  elseif val(fix_n$) = 3 then
    g_fix_type$ = "3D"
  else
    g_fix_type$ = "---"
  end if
  g_sat_used = 0
  for fld = 3 to 14
    prn$ = beam_nmea_field(sentence$, fld)
    if len(prn$) > 0 then
      g_sat_used = g_sat_used + 1
    end if
  next fld
end sub

sub handle_zda()
  ts$ = beam_nmea_field(sentence$, 1)
  day$ = beam_nmea_field(sentence$, 2)
  mon$ = beam_nmea_field(sentence$, 3)
  yr$ = beam_nmea_field(sentence$, 4)
  if len(ts$) >= 6 then
    g_utc_time$ = left$(ts$, 2) + ":" + mid$(ts$, 3, 2) + ":" + mid$(ts$, 5, 2)
    g_utc_date$ = day$ + "/" + mon$ + "/" + yr$
  end if
end sub

sub handle_xte()
  warn$ = beam_nmea_field(sentence$, 1)
  if warn$ <> "A" then
    return
  end if
  g_xte_mag$ = str$(int(val(beam_nmea_field(sentence$, 3)) * 100) / 100)
  g_xte_dir$ = beam_nmea_field(sentence$, 4)
end sub

sub handle_rmb()
  stat$ = beam_nmea_field(sentence$, 1)
  if stat$ <> "A" then
    return
  end if
  g_nav_dest$ = beam_nmea_field(sentence$, 5)
  g_nav_dist$ = str$(int(val(beam_nmea_field(sentence$, 10)) * 100) / 100)
  g_nav_brg$  = str$(int(val(beam_nmea_field(sentence$, 11)) * 10) / 10)
  g_nav_vmg$  = str$(int(val(beam_nmea_field(sentence$, 12)) * 10) / 10)
  g_nav_arr$  = beam_nmea_field(sentence$, 13)
end sub

// ============================================================
// Simulator
// ============================================================

sub sim_drift()
  t = sim_tick
  sim_sog       = 7.0  + 2.0  * sin(t * 6.2832 / 1200.0)
  sim_cog       = 247.0 + 15.0 * sin(t * 6.2832 / 1800.0)
  sim_hdg       = sim_cog + 4.0 * sin(t * 6.2832 / 1350.0) - 2.0
  sim_depth     = 18.5 + 6.5  * sin(t * 6.2832 / 2700.0)
  sim_wind_spd  = 13.0 + 5.0  * sin(t * 6.2832 / 1350.0)
  sim_wind_ang  = 45.0 + 40.0 * sin(t * 6.2832 / 3600.0)
  sim_water_tmp = 18.5 + 0.5  * sin(t * 6.2832 / 5400.0)
  sim_xte       = 0.3  * sin(t * 6.2832 / 2400.0)
  sim_dist      = 12.5 + 2.0  * sin(t * 6.2832 / 7200.0)
  sim_brg       = 252.0 + 8.0 * sin(t * 6.2832 / 5400.0)
end sub

// ── Format helpers (inline str$/int to avoid user-sub-in-sub) ──
// These are used only inside sim_tick_step below.

sub sim_tick_step()
  if sim_running = 0 then
    return
  end if
  sim_tick = sim_tick + 1
  sim_drift()

  // On first tick: emit a full set so all tabs show data immediately.
  if sim_tick = 1 then
    nmea_parse("$GPGGA,123519,4738.11,N,12221.43,W,1,09,1.2,54.0,M,0.0,M,,*00")
    nmea_parse("$GPRMC,123519,A,4738.11,N,12221.43,W,7.0,247.0,040426,,,*00")
    nmea_parse("$SDDPT,18.5,0.5*00")
    nmea_parse("$IIMWV,45.0,R,13.0,N,A*00")
    nmea_parse("$HCHDT,243.0,T*00")
    nmea_parse("$YXMTW,18.5,C*00")
    nmea_parse("$GPZDA,123519.00,04,04,2026,00,00*00")
    nmea_parse("$GPGSA,A,3,01,03,05,07,09,11,13,15,,,,,1.8,1.2,1.4*00")
    nmea_parse("$GPGSV,3,1,09,01,72,120,45,03,55,310,42,05,38,064,39,07,29,188,41*00")
    nmea_parse("$GPGSV,3,2,09,09,55,220,38,11,42,105,35,13,28,045,32,15,18,310,29*00")
    nmea_parse("$GPGSV,3,3,09,17,08,190,22*00")
    nmea_parse("$GPXTE,A,A,0.0,L,N*00")
    nmea_parse("$GPRMB,A,0.3,L,ORIG,WAYP1,4738.11,N,12221.43,W,12.5,252.0,7.0,V*00")
  end if

  if mod(sim_tick, 5) <> 0 then
    return
  end if

  seq = mod(sim_tick / 5, 11)

  // Build value strings inline — user-defined string subs cannot be
  // called from inside another sub in yabasic.
  sog_s$  = str$(int(sim_sog      * 10) / 10)
  cog_s$  = str$(int(sim_cog      * 10) / 10)
  dpt_s$  = str$(int(sim_depth    * 10) / 10)
  wsp_s$  = str$(int(sim_wind_spd * 10) / 10)
  wan_s$  = str$(int(sim_wind_ang * 10) / 10)
  hdg_s$  = str$(int(sim_hdg      * 10) / 10)
  tmp_s$  = str$(int(sim_water_tmp* 10) / 10)
  dist_s$ = str$(int(sim_dist     * 10) / 10)
  brg_s$  = str$(int(sim_brg      * 10) / 10)
  vmg_s$  = str$(int(sim_sog      * 10) / 10)

  if seq = 0 then
    nmea_parse("$GPGGA,123519,4738.11,N,12221.43,W,1,09,1.2,54.0,M,0.0,M,,*00")
  elseif seq = 1 then
    nmea_parse("$GPRMC,123519,A,4738.11,N,12221.43,W," + sog_s$ + "," + cog_s$ + ",040426,,,*00")
  elseif seq = 2 then
    nmea_parse("$SDDPT," + dpt_s$ + ",0.5*00")
  elseif seq = 3 then
    nmea_parse("$IIMWV," + wan_s$ + ",R," + wsp_s$ + ",N,A*00")
  elseif seq = 4 then
    nmea_parse("$HCHDT," + hdg_s$ + ",T*00")
  elseif seq = 5 then
    nmea_parse("$YXMTW," + tmp_s$ + ",C*00")
  elseif seq = 6 then
    nmea_parse("$GPZDA,123519.00,04,04,2026,00,00*00")
  elseif seq = 7 then
    // GSA: 3D fix, 8 sats used (PRNs 01-08), PDOP/HDOP vary slightly
    nmea_parse("$GPGSA,A,3,01,03,05,07,09,11,13,15,,,,,1.8,1.2,1.4*00")
  elseif seq = 8 then
    // GSV: 9 sats, 3 messages (4+4+1).  msg 1 resets accumulator.
    nmea_parse("$GPGSV,3,1,09,01,72,120,45,03,55,310,42,05,38,064,39,07,29,188,41*00")
    nmea_parse("$GPGSV,3,2,09,09,55,220,38,11,42,105,35,13,28,045,32,15,18,310,29*00")
    nmea_parse("$GPGSV,3,3,09,17,08,190,22*00")
  elseif seq = 9 then
    // XTE: oscillating cross-track error, direction depends on sign
    if sim_xte >= 0 then
      xte_s$ = str$(int(sim_xte * 100) / 100)
      nmea_parse("$GPXTE,A,A," + xte_s$ + ",L,N*00")
    else
      xte_s$ = str$(int(-sim_xte * 100) / 100)
      nmea_parse("$GPXTE,A,A," + xte_s$ + ",R,N*00")
    end if
  elseif seq = 10 then
    // RMB: navigate to waypoint WAYP1
    nmea_parse("$GPRMB,A,0.3,L,ORIG,WAYP1,4738.11,N,12221.43,W," + dist_s$ + "," + brg_s$ + "," + vmg_s$ + ",V*00")
  end if

  // Simulated AIS targets every ~10 s (300 frames)
  if mod(sim_tick, 300) = 10 then
    lat1 = 47.6230 + 0.002 * sin(sim_tick * 6.2832 / 9000.0)
    lon1 = -122.3380 + 0.003 * sin(sim_tick * 6.2832 / 7200.0)
    la1$ = str$(int(lat1 * 100) / 100)
    lo1$ = str$(int(lon1 * 100) / 100)
    ais_upsert("338234567|7.2|" + la1$ + "|" + lo1$ + "|180.0")
  end if
  if mod(sim_tick, 300) = 110 then
    lat2 = 47.7100 + 0.004 * sin(sim_tick * 6.2832 / 12000.0)
    lon2 = -122.4200 - 0.002 * sin(sim_tick * 6.2832 / 9000.0)
    la2$ = str$(int(lat2 * 100) / 100)
    lo2$ = str$(int(lon2 * 100) / 100)
    ais_upsert("366998750|14.5|" + la2$ + "|" + lo2$ + "|315.0")
  end if
  if mod(sim_tick, 300) = 220 then
    ais_upsert("235456780|0.1|47.5820|-122.2970|0.0")
  end if
  if mod(sim_tick, 300) = 60 then
    lat4 = 47.6416 + 0.001 * sin(sim_tick * 6.2832 / 4000.0)
    lon4 = -122.3456 - 0.001 * sin(sim_tick * 6.2832 / 3500.0)
    la4$ = str$(int(lat4 * 100) / 100)
    lo4$ = str$(int(lon4 * 100) / 100)
    ais_upsert("366112233|5.1|" + la4$ + "|" + lo4$ + "|225.0")
  end if
end sub

// ============================================================
// Serial reader tick
// ============================================================

sub serial_tick()
  if g_handle < 0 then
    return
  end if
  line$ = beam_nmea_read(g_handle)
  if len(line$) > 1 then
    nmea_parse(line$)
  end if
end sub

// ============================================================
// Clear all received data
// ============================================================

sub clear_all()
  g_lat$      = "---"
  g_lon$      = "---"
  g_sog$      = "---"
  g_cog$      = "---"
  g_hdg$      = "---"
  g_depth$    = "---"
  g_temp$     = "---"
  g_wind_ang$ = "---"
  g_wind_spd$ = "---"
  g_pos_src$  = "---"
  g_fix_type$ = "---"
  g_sat_cnt   = 0
  g_sat_used  = 0
  g_hdop$     = "---"
  g_pdop$     = "---"
  g_utc_time$ = "--:--:--"
  g_utc_date$ = "--/--/----"
  g_stw$      = "---"
  g_xte_mag$  = "---"
  g_xte_dir$  = "-"
  g_nav_dest$ = "---"
  g_nav_brg$  = "---"
  g_nav_dist$ = "---"
  g_nav_vmg$  = "---"
  g_nav_arr$  = "V"
  for i = 0 to 9 : g_ais$(i) = "" : next i
  g_ais_next = 0
  g_ais_scroll = 0
  g_log_head = 0
  g_log_count = 0
  g_log_scroll = 0
  pos_level = 0
  rmc_miss = 0
  gga_miss = 0
  gsv_buf$ = ""
  gsv_count = 0
  sat_count = 0
end sub

// ============================================================
// Draw helpers
// ============================================================

sub instr_panel(label$, value$)
  beam_group_begin(label$)
    beam_row(28, 1)
      beam_label(value$)
    beam_row_end()
  beam_group_end()
end sub

// ============================================================
// Draw AIS target row
// ============================================================

sub draw_ais_slot(slot$)
  if len(slot$) < 3 then
    beam_row(14, 5)
      beam_label("---")
      beam_label("--")
      beam_label("----")
      beam_label("-----")
      beam_label("---")
    beam_row_end()
    return
  end if
  p0 = instr(slot$, "|")
  if p0 = 0 then
    beam_label(slot$)
    return
  end if
  mmsi$ = left$(slot$, p0 - 1)
  rest1$ = right$(slot$, len(slot$) - p0)
  p1 = instr(rest1$, "|")
  if p1 = 0 then
    sog_s$ = rest1$ : lat_s$ = "--" : lon_s$ = "--" : cog_s$ = "--"
  else
    sog_s$ = left$(rest1$, p1 - 1)
    rest2$ = right$(rest1$, len(rest1$) - p1)
    p2 = instr(rest2$, "|")
    if p2 = 0 then
      lat_s$ = rest2$ : lon_s$ = "--" : cog_s$ = "--"
    else
      lat_s$ = left$(rest2$, p2 - 1)
      rest3$ = right$(rest2$, len(rest2$) - p2)
      p3 = instr(rest3$, "|")
      if p3 = 0 then
        lon_s$ = rest3$ : cog_s$ = "--"
      else
        lon_s$ = left$(rest3$, p3 - 1)
        cog_s$ = right$(rest3$, len(rest3$) - p3)
      end if
    end if
  end if
  beam_row(14, 5)
    beam_label(mmsi$)
    beam_label(sog_s$ + " kt")
    beam_label(lat_s$)
    beam_label(lon_s$)
    beam_label(cog_s$ + deg$)
  beam_row_end()
end sub

// ============================================================
// Draw NMEA log tab
// ============================================================

sub draw_log_tab()
  beam_group_begin("NMEA Log")
    visible = 18
    start_idx = g_log_count - visible - g_log_scroll
    if start_idx < 0 then
      start_idx = 0
    end if
    shown = 0
    for li = start_idx to g_log_count - 1
      if shown >= visible then
        break
      end if
      ridx = mod(li, 200)
      beam_row(14, 1)
        beam_label(g_log$(ridx))
      beam_row_end()
      shown = shown + 1
    next li
    beam_row(24, 3)
      if beam_button("^ Up", 80, 20) then
        if g_log_scroll < g_log_count - visible then
          g_log_scroll = g_log_scroll + 3
        end if
      end if
      beam_label(" ")
      if beam_button("v Dn", 80, 20) then
        if g_log_scroll > 0 then
          g_log_scroll = g_log_scroll - 3
        end if
      end if
    beam_row_end()
  beam_group_end()
end sub

// ============================================================
// Draw satellite summary tab
// ============================================================

sub draw_sat_tab()
  beam_group_begin("Satellite Status")
    beam_row(20, 4)
      beam_label("FIX: " + g_fix_type$)
      beam_label("IN VIEW: " + str$(g_sat_cnt))
      beam_label("USED: " + str$(g_sat_used))
      beam_label("HDOP: " + g_hdop$)
    beam_row_end()
    beam_row(20, 2)
      beam_label("PDOP: " + g_pdop$)
      beam_label("POS SRC: " + g_pos_src$)
    beam_row_end()
    beam_separator()
    if sat_count > 0 then
      // SNR bar chart — one vertical bar per satellite
      beam_row(80, sat_count)
        for si = 0 to sat_count - 1
          beam_vbar(sat_snr(si), 60, 0, 80)
        next si
      beam_row_end()
      // PRN labels under bars
      beam_row(14, sat_count)
        for si = 0 to sat_count - 1
          beam_label(str$(sat_prn(si)))
        next si
      beam_row_end()
      // SNR values under PRN labels
      beam_row(14, sat_count)
        for si = 0 to sat_count - 1
          beam_label(str$(sat_snr(si)) + "dB")
        next si
      beam_row_end()
    else
      beam_row(20, 1)
        beam_label("Waiting for satellite data...")
      beam_row_end()
    end if
  beam_group_end()
end sub

// ============================================================
// Draw voyage data tab
// ============================================================

sub draw_voyage_tab()
  beam_group_begin("Voyage Data")
    beam_row(20, 3)
      beam_label("TIME: " + g_utc_time$)
      beam_label("DATE: " + g_utc_date$)
      beam_label("POS SRC: " + g_pos_src$)
    beam_row_end()
    beam_separator()
    beam_row(20, 2)
      beam_label("STW: " + g_stw$ + " kts")
      beam_label("SOG: " + g_sog$ + " kts")
    beam_row_end()
    beam_separator()
    beam_row(20, 3)
      beam_label("XTE: " + g_xte_mag$ + " nm")
      if g_xte_dir$ = "L" then
        beam_label("STEER RIGHT")
      elseif g_xte_dir$ = "R" then
        beam_label("STEER LEFT")
      else
        beam_label("")
      end if
      beam_label("")
    beam_row_end()
    beam_separator()
    beam_row(20, 4)
      beam_label("DEST: " + g_nav_dest$)
      beam_label("BRG: " + g_nav_brg$ + deg$)
      beam_label("DIST: " + g_nav_dist$ + " nm")
      beam_label("VMG: " + g_nav_vmg$ + " kts")
    beam_row_end()
    if g_nav_arr$ = "A" then
      beam_row(16, 1)
        beam_label("*** ARRIVED AT WAYPOINT ***")
      beam_row_end()
    end if
  beam_group_end()
end sub

// ============================================================
// Settings panel
// ============================================================

settings_open = 0

sub draw_settings()
  beam_group_begin("Settings")
    beam_row(20, 1)
      beam_label("Serial Port (press Enter to apply):")
    beam_row_end()
    beam_row(28, 1)
      if beam_input(port_input$, 64, 500) then
        g_port$ = beam_input$
        port_input$ = beam_input$
      end if
    beam_row_end()
    beam_row(24, 4)
      beam_label("Baud:")
      if beam_button("4800",  60, 20) then
        g_baud = 4800
      end if
      if beam_button("9600",  60, 20) then
        g_baud = 9600
      end if
      if beam_button("38400", 60, 20) then
        g_baud = 38400
      end if
    beam_row_end()
    beam_row(24, 3)
      if g_handle >= 0 then
        if beam_button("Disconnect", 100, 20) then
          beam_nmea_close(g_handle)
          g_handle = -1
          g_mode$ = "LIVE"
        end if
        beam_label("Connected: " + g_port$)
      elseif g_mode$ = "SIM" then
        beam_label("Stop SIM to enable serial")
        beam_label("")
      else
        if beam_button("Connect", 90, 20) then
          g_handle = beam_nmea_open(g_port$, g_baud)
          if g_handle >= 0 then
            sim_running = 0
            g_mode$ = "LIVE"
          end if
        end if
        if g_handle < 0 then
          beam_label("Not connected")
        end if
      end if
      beam_label("")
    beam_row_end()
  beam_group_end()
end sub

// ============================================================
// Degree symbol
// ============================================================
deg$ = chr$(176)

// ============================================================
// Main loop
// ============================================================

while beam_running(win)
  beam_begin(win)

    // ── Title bar ───────────────────────────────────────────
    beam_row(40, 5)
      beam_label("BEAM INSTRUMENTS")
      if g_mode$ = "SIM" then
        if beam_button("SIM > LIVE", 100, 34) then
          sim_running = 0
          g_mode$ = "LIVE"
        end if
      elseif g_handle >= 0 then
        beam_label("LIVE (serial)")
      else
        if beam_button("LIVE > SIM", 100, 34) then
          sim_running = 1
          sim_tick = 0
          g_mode$ = "SIM"
        end if
      end if
      if g_paused then
        beam_label("** PAUSED **")
      else
        beam_label("")
      end if
      if beam_button("Clear", 70, 34) then
        clear_all()
      end if
      if g_paused then
        if beam_button("Resume", 70, 34) then
          g_paused = 0
        end if
      else
        if beam_button("Pause", 70, 34) then
          g_paused = 1
        end if
      end if
    beam_row_end()

    beam_separator()

    // ── Instrument panels ────────────────────────────────────
    beam_row(100, 4)

      beam_group_begin("POSITION")
        beam_row(22, 1)
          beam_label(g_lat$)
        beam_row_end()
        beam_row(22, 1)
          beam_label(g_lon$)
        beam_row_end()
        beam_row(16, 2)
          beam_label("SRC: " + g_pos_src$)
          beam_label("FIX: " + g_fix_type$)
        beam_row_end()
      beam_group_end()

      beam_group_begin("SPEED & COURSE")
        beam_row(22, 2)
          beam_label("SOG")
          beam_label(g_sog$ + " kts")
        beam_row_end()
        beam_row(22, 2)
          beam_label("COG")
          beam_label(g_cog$ + deg$)
        beam_row_end()
        beam_row(22, 2)
          beam_label("HDG")
          beam_label(g_hdg$ + deg$)
        beam_row_end()
      beam_group_end()

      beam_group_begin("DEPTH & TEMP")
        beam_row(22, 2)
          beam_label("DEPTH")
          beam_label(g_depth$ + " m")
        beam_row_end()
        beam_row(22, 2)
          beam_label("WATER")
          beam_label(g_temp$ + " C")
        beam_row_end()
      beam_group_end()

      beam_group_begin("WIND")
        beam_row(22, 2)
          beam_label("DIR")
          beam_label(g_wind_ang$ + deg$)
        beam_row_end()
        beam_row(22, 2)
          beam_label("SPD")
          beam_label(g_wind_spd$ + " kts")
        beam_row_end()
      beam_group_end()

    beam_row_end()

    beam_separator()

    // ── AIS targets ──────────────────────────────────────────
    beam_row(160, 1)
      beam_group_begin("AIS TARGETS")
        beam_row(14, 5)
          beam_label("MMSI")
          beam_label("SOG")
          beam_label("LAT")
          beam_label("LON")
          beam_label("COG")
        beam_row_end()
        beam_separator()
        for ai = 0 to 4
          sidx = mod(g_ais_scroll + ai, 10)
          draw_ais_slot(g_ais$(sidx))
        next ai
        beam_row(24, 4)
          if beam_button("^ Scroll", 90, 20) then
            if g_ais_scroll > 0 then
              g_ais_scroll = g_ais_scroll - 1
            end if
          end if
          if beam_button("v Scroll", 90, 20) then
            if g_ais_scroll < 5 then
              g_ais_scroll = g_ais_scroll + 1
            end if
          end if
          beam_label("")
          beam_label("")
        beam_row_end()
      beam_group_end()
    beam_row_end()

    beam_separator()

    // ── Tab selector ─────────────────────────────────────────
    beam_row(26, 5)
      if beam_button("NMEA LOG", 100, 22) then
        g_tab = 0
      end if
      if beam_button("SATELLITES", 100, 22) then
        g_tab = 1
      end if
      if beam_button("VOYAGE DATA", 120, 22) then
        g_tab = 2
      end if
      beam_label("")
      if settings_open then
        if beam_button("Hide Settings", 120, 22) then
          settings_open = 0
        end if
      else
        if beam_button("Settings", 80, 22) then
          settings_open = 1
        end if
      end if
    beam_row_end()

    // ── Tab content or Settings ───────────────────────────────
    if settings_open then
      draw_settings()
    elseif g_tab = 0 then
      draw_log_tab()
    elseif g_tab = 1 then
      draw_sat_tab()
    elseif g_tab = 2 then
      draw_voyage_tab()
    end if

    // ── Status bar ───────────────────────────────────────────
    beam_separator()
    beam_row(20, 1)
      if g_mode$ = "SIM" then
        beam_label("SIM MODE  |  Sats: " + str$(g_sat_used) + "/" + str$(g_sat_cnt) + "  |  FIX: " + g_fix_type$)
      elseif g_handle >= 0 then
        beam_label("LIVE  |  " + g_port$ + "  |  Sats: " + str$(g_sat_used) + "/" + str$(g_sat_cnt) + "  |  FIX: " + g_fix_type$)
      else
        beam_label("LIVE  |  No serial connection — press Settings to connect")
      end if
    beam_row_end()

  beam_end(win)

  sim_tick_step()
  serial_tick()

wend
