# -*- mode: python ; coding: utf-8 -*-
# PyInstaller spec file for BEAM IDE
#
# Run from the Beam/ directory:
#   pyinstaller beam_ide.spec
#
# Output: dist/BeamIDE/
#   BeamIDE             ← main executable
#   _internal/          ← PyInstaller support files
#     beam              ← bundled BEAM interpreter
#     images/           ← application icons
#     themes/syntax/    ← bundled syntax themes (copied to ~/.config/beam_ide on first run)
#     docs/             ← BEAM language reference
#     beam_ide/         ← Python package

block_cipher = None

a = Analysis(
    ['beam_ide/main.py'],
    pathex=['.'],
    binaries=[
        # Bundle the BEAM interpreter alongside the IDE.
        # In PyInstaller 6.x onedir mode this lands in _internal/ (sys._MEIPASS).
        ('beam', '.'),
    ],
    datas=[
        # Application icons — resolved by get_resource_path("images/...")
        # Place your icon files (beam_icon.ico, beam_icon_256.png, etc.) in
        # beam_ide/images/ before building.
        ('beam_ide/images', 'images'),
        # Bundled syntax themes — copied to ~/.config/beam_ide/themes/syntax/ on first run.
        # Resolved by ThemeManager._get_bundled_themes_dir() via sys._MEIPASS.
        ('beam_ide/themes/syntax', 'themes/syntax'),
        # Language reference — resolved by get_resource_path("docs/...")
        ('docs', 'docs'),
    ],
    hiddenimports=[
        # Ensure all beam_ide sub-modules are included (they may not be auto-detected
        # because main.py imports some of them lazily inside functions).
        'beam_ide',
        'beam_ide.app',
        'beam_ide.app.main_window',
        'beam_ide.app.editor',
        'beam_ide.app.syntax',
        'beam_ide.app.terminal',
        'beam_ide.app.settings',
        'beam_ide.app.settings_dialog',
        'beam_ide.app.themes',
        'beam_ide.app.utils',
        'beam_ide.app.file_browser',
        'beam_ide.app.find_replace',
        'beam_ide.app.help_viewer',
        # PyQt6
        'PyQt6',
        'PyQt6.QtWidgets',
        'PyQt6.QtCore',
        'PyQt6.QtGui',
        'PyQt6.QtPrintSupport',
        # stdlib used at runtime
        'configparser',
        'json',
        'shutil',
        'subprocess',
    ],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[
        'tkinter',
        'matplotlib',
        'numpy',
        'scipy',
        'pandas',
        'PIL',
    ],
    win_no_prefer_redirects=False,
    win_private_assemblies=False,
    cipher=block_cipher,
    noarchive=False,
)

pyz = PYZ(a.pure, a.zipped_data, cipher=block_cipher)

exe = EXE(
    pyz,
    a.scripts,
    [],
    exclude_binaries=True,   # onedir mode — separate COLLECT step below
    name='BeamIDE',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    console=False,           # GUI application — no console window
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
    # Icon used for the executable (Windows .ico / macOS .icns; ignored on Linux).
    icon='beam_ide/images/beam_icon.ico',
)

coll = COLLECT(
    exe,
    a.binaries,
    a.zipfiles,
    a.datas,
    strip=False,
    upx=True,
    upx_exclude=[],
    name='BeamIDE',
)
