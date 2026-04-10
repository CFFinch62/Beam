#!/usr/bin/env bash
# ============================================================
# BEAM Language Plugin — MyCode installer
# ============================================================
# Copies the beam-language plugin to the MyCode user plugin
# directory so MyCode discovers it on next launch.
#
# Usage:  ./mycode_plugin/install.sh
# ============================================================

set -e

PLUGIN_SRC="$(cd "$(dirname "$0")/beam-language" && pwd)"
PLUGIN_NAME="beam-language"

# Electron stores user data at ~/.config/<productName> on Linux
# MyCode's productName is "MyCode" (from package.json build.productName)
USERDATA_DIR="$HOME/.config/MyCode"
PLUGIN_DEST="$USERDATA_DIR/plugins/$PLUGIN_NAME"

echo "BEAM Plugin Installer"
echo "====================="
echo "Source : $PLUGIN_SRC"
echo "Target : $PLUGIN_DEST"
echo ""

# Create plugin directory if needed
mkdir -p "$PLUGIN_DEST"

# Copy plugin files
cp "$PLUGIN_SRC/package.json" "$PLUGIN_DEST/package.json"
cp "$PLUGIN_SRC/renderer.js"  "$PLUGIN_DEST/renderer.js"

echo "Files copied."

# Optionally copy into the MyCode dev tree so it works when running from source
DEV_PLUGINS_DIR="$(cd "$(dirname "$0")/../../../EDITORS/MyCode/plugins" 2>/dev/null && pwd)" || true
if [ -d "$DEV_PLUGINS_DIR" ]; then
    DEV_DEST="$DEV_PLUGINS_DIR/$PLUGIN_NAME"
    mkdir -p "$DEV_DEST"
    cp "$PLUGIN_SRC/package.json" "$DEV_DEST/package.json"
    cp "$PLUGIN_SRC/renderer.js"  "$DEV_DEST/renderer.js"
    echo "Also installed to dev tree: $DEV_DEST"
fi

echo ""
echo "Done! Restart MyCode and the BEAM plugin will be available."
echo ""
echo "In MyCode:"
echo "  - .bas and .yab files get BEAM syntax highlighting automatically"
echo "  - Click  [▶ Run BEAM]  in the status bar to run the open file"
echo "  - Click  [■ Stop]      in the status bar to kill the process"
echo "  - Tools menu also has Run BEAM / Stop BEAM items"
