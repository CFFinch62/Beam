#!/usr/bin/env python3
"""
BEAM IDE - A modern IDE for the BEAM programming language
Based on the FORGE IDE architecture
"""

import sys
import os

from PyQt6.QtWidgets import QApplication
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QFont, QIcon

from beam_ide.app.main_window import BeamIDEMainWindow
from beam_ide.app.settings import SettingsManager


def main():
    """Main entry point for the BEAM IDE"""
    app = QApplication(sys.argv)
    app.setApplicationName("BEAM IDE")
    app.setApplicationVersion("1.0.0")
    app.setOrganizationName("BEAM Language")

    # Load settings
    settings = SettingsManager()

    # Apply theme
    from beam_ide.app.themes import ThemeManager
    theme_manager = ThemeManager(settings)
    app.setStyleSheet(theme_manager.get_current_stylesheet())

    # Create and show main window
    window = BeamIDEMainWindow(settings, theme_manager)
    window.show()

    sys.exit(app.exec())


if __name__ == "__main__":
    main()
