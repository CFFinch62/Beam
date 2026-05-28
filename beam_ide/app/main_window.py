"""
Main Window for BEAM IDE
The primary application window containing all IDE components
"""

from pathlib import Path
from PyQt6.QtWidgets import (
    QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, QSplitter,
    QTabWidget, QMenuBar, QMenu, QToolBar, QStatusBar, QFileDialog,
    QMessageBox, QLabel, QStyle
)
from PyQt6.QtCore import Qt, QSize
from PyQt6.QtGui import QAction, QKeySequence, QIcon

import sys
import os

from beam_ide.app.settings import SettingsManager
from beam_ide.app.themes import ThemeManager
from beam_ide.app.editor import CodeEditor
from beam_ide.app.file_browser import FileBrowserWidget
from beam_ide.app.terminal import TerminalWidget
from beam_ide.app.find_replace import FindReplaceWidget
from beam_ide.app.settings_dialog import SettingsDialog
from beam_ide.app.help_viewer import HelpViewer
from beam_ide.app.utils import get_resource_path


class BeamIDEMainWindow(QMainWindow):
    """Main window for the BEAM IDE"""

    def __init__(self, settings: SettingsManager, theme_manager: ThemeManager):
        super().__init__()
        self.settings = settings
        self.theme_manager = theme_manager
        self.editors = {}  # path -> CodeEditor
        self.current_project_path = None

        self._setup_ui()
        self._setup_menus()
        self._setup_toolbar()
        self._setup_statusbar()
        self._apply_settings()
        self._apply_theme()
        self._restore_session()

    def _setup_ui(self):
        self.setWindowTitle("BEAM IDE")

        icon_path = get_resource_path("images/beam_icon_256.png")
        if icon_path and Path(icon_path).exists():
            self.setWindowIcon(QIcon(icon_path))

        central = QWidget()
        self.setCentralWidget(central)
        main_layout = QVBoxLayout(central)
        main_layout.setContentsMargins(0, 0, 0, 0)
        main_layout.setSpacing(0)

        self.main_splitter = QSplitter(Qt.Orientation.Horizontal)

        self.file_browser = FileBrowserWidget(
            theme=self._get_compat_theme(),
            settings=self.settings
        )
        self.file_browser.file_double_clicked.connect(self.open_file)
        self.file_browser.bookmark_navigated.connect(self._on_bookmark_navigated)
        self.main_splitter.addWidget(self.file_browser)

        self.middle_splitter = QSplitter(Qt.Orientation.Vertical)

        editor_container = QWidget()
        editor_layout = QVBoxLayout(editor_container)
        editor_layout.setContentsMargins(0, 0, 0, 0)
        editor_layout.setSpacing(0)

        self.tab_widget = QTabWidget()
        self.tab_widget.setTabsClosable(True)
        self.tab_widget.setMovable(True)
        self.tab_widget.tabCloseRequested.connect(self.close_tab)
        self.tab_widget.currentChanged.connect(self._on_tab_changed)
        editor_layout.addWidget(self.tab_widget)

        self.find_replace = FindReplaceWidget(theme=self._get_compat_theme())
        editor_layout.addWidget(self.find_replace)

        self.middle_splitter.addWidget(editor_container)

        self.terminal = TerminalWidget(
            theme=self._get_compat_theme(),
            settings=self.settings
        )
        self.middle_splitter.addWidget(self.terminal)
        self.middle_splitter.setSizes([600, 200])

        self.main_splitter.addWidget(self.middle_splitter)
        self.main_splitter.setSizes([250, 750])

        main_layout.addWidget(self.main_splitter)

    def _setup_menus(self):
        menubar = self.menuBar()

        # File menu
        file_menu = menubar.addMenu("&File")

        new_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_FileIcon), "New", self)
        new_action.setShortcut(QKeySequence.StandardKey.New)
        new_action.triggered.connect(self.new_file)
        file_menu.addAction(new_action)

        open_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_DirOpenIcon), "Open File...", self)
        open_action.setShortcut(QKeySequence.StandardKey.Open)
        open_action.triggered.connect(self.open_file_dialog)
        file_menu.addAction(open_action)

        open_folder_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_DirIcon), "Open Folder...", self)
        open_folder_action.setShortcut("Ctrl+Shift+O")
        open_folder_action.triggered.connect(self.open_folder_dialog)
        file_menu.addAction(open_folder_action)

        file_menu.addSeparator()

        save_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_DialogSaveButton), "Save", self)
        save_action.setShortcut(QKeySequence.StandardKey.Save)
        save_action.triggered.connect(self.save_file)
        file_menu.addAction(save_action)

        save_as_action = QAction("Save As...", self)
        save_as_action.setShortcut("Ctrl+Shift+S")
        save_as_action.triggered.connect(self.save_file_as)
        file_menu.addAction(save_as_action)

        file_menu.addSeparator()

        exit_action = QAction("Exit", self)
        exit_action.setShortcut("Ctrl+Q")
        exit_action.triggered.connect(self.close)
        file_menu.addAction(exit_action)

        # Edit menu
        edit_menu = menubar.addMenu("&Edit")

        undo_action = QAction("Undo", self)
        undo_action.setShortcut(QKeySequence.StandardKey.Undo)
        undo_action.triggered.connect(self._undo)
        edit_menu.addAction(undo_action)

        redo_action = QAction("Redo", self)
        redo_action.setShortcut(QKeySequence.StandardKey.Redo)
        redo_action.triggered.connect(self._redo)
        edit_menu.addAction(redo_action)

        edit_menu.addSeparator()

        cut_action = QAction("Cut", self)
        cut_action.setShortcut(QKeySequence.StandardKey.Cut)
        cut_action.triggered.connect(self._cut)
        edit_menu.addAction(cut_action)

        copy_action = QAction("Copy", self)
        copy_action.setShortcut(QKeySequence.StandardKey.Copy)
        copy_action.triggered.connect(self._copy)
        edit_menu.addAction(copy_action)

        paste_action = QAction("Paste", self)
        paste_action.setShortcut(QKeySequence.StandardKey.Paste)
        paste_action.triggered.connect(self._paste)
        edit_menu.addAction(paste_action)

        edit_menu.addSeparator()

        find_action = QAction("Find...", self)
        find_action.setShortcut("Ctrl+F")
        find_action.triggered.connect(self._show_find)
        edit_menu.addAction(find_action)

        replace_action = QAction("Replace...", self)
        replace_action.setShortcut("Ctrl+H")
        replace_action.triggered.connect(self._show_replace)
        edit_menu.addAction(replace_action)

        edit_menu.addSeparator()

        indent_action = QAction("Indent Selection", self)
        indent_action.setShortcuts(["Tab", "Ctrl+]"])
        indent_action.triggered.connect(self._indent_selection)
        edit_menu.addAction(indent_action)

        dedent_action = QAction("Dedent Selection", self)
        dedent_action.setShortcuts(["Shift+Tab", "Ctrl+["])
        dedent_action.triggered.connect(self._dedent_selection)
        edit_menu.addAction(dedent_action)

        comment_action = QAction("Comment Selection", self)
        comment_action.setShortcut("Ctrl+/")
        comment_action.triggered.connect(self._comment_selection)
        edit_menu.addAction(comment_action)

        edit_menu.addSeparator()

        prefs_action = QAction("Preferences...", self)
        prefs_action.setShortcut("Ctrl+,")
        prefs_action.triggered.connect(self._show_preferences)
        edit_menu.addAction(prefs_action)

        # View menu
        view_menu = menubar.addMenu("&View")

        toggle_browser = QAction(self._std_icon(QStyle.StandardPixmap.SP_DirIcon), "Toggle File Browser", self)
        toggle_browser.setShortcut("Ctrl+B")
        toggle_browser.triggered.connect(self._toggle_file_browser)
        view_menu.addAction(toggle_browser)

        toggle_terminal = QAction(self._std_icon(QStyle.StandardPixmap.SP_ComputerIcon), "Toggle Terminal", self)
        toggle_terminal.setShortcut("Ctrl+`")
        toggle_terminal.triggered.connect(self._toggle_terminal)
        view_menu.addAction(toggle_terminal)

        view_menu.addSeparator()

        theme_menu = view_menu.addMenu("Theme")

        ui_theme_menu = theme_menu.addMenu("UI Theme")
        for theme_name in self.theme_manager.get_available_ui_themes():
            theme_action = QAction(theme_name.replace('_', ' ').title(), self)
            theme_action.triggered.connect(lambda checked, n=theme_name: self._set_ui_theme(n))
            ui_theme_menu.addAction(theme_action)

        self.syntax_theme_menu = theme_menu.addMenu("Syntax Theme")
        self._update_syntax_theme_menu()

        view_menu.addSeparator()

        terminal_pos_menu = view_menu.addMenu("Terminal Position")
        terminal_bottom_action = QAction("Bottom", self)
        terminal_bottom_action.triggered.connect(lambda: self._set_terminal_position("bottom"))
        terminal_pos_menu.addAction(terminal_bottom_action)
        terminal_right_action = QAction("Right", self)
        terminal_right_action.triggered.connect(lambda: self._set_terminal_position("right"))
        terminal_pos_menu.addAction(terminal_right_action)

        # Run menu
        run_menu = menubar.addMenu("&Run")

        run_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_MediaPlay), "Run", self)
        run_action.setShortcut("F5")
        run_action.triggered.connect(self.run_current_file)
        run_menu.addAction(run_action)

        run_ext_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_ComputerIcon), "Run in External Terminal", self)
        run_ext_action.setShortcut("Ctrl+F5")
        run_ext_action.triggered.connect(self.run_current_file_external)
        run_menu.addAction(run_ext_action)

        stop_action = QAction(self._std_icon(QStyle.StandardPixmap.SP_MediaStop), "Stop", self)
        stop_action.setShortcut("Shift+F5")
        stop_action.triggered.connect(self.terminal.stop_execution)
        run_menu.addAction(stop_action)

        run_menu.addSeparator()

        set_interpreter_action = QAction("Set Interpreter...", self)
        set_interpreter_action.triggered.connect(self._show_interpreter_settings)
        run_menu.addAction(set_interpreter_action)

        # Help menu
        help_menu = menubar.addMenu("&Help")

        quick_ref_action = QAction("BEAM Language Reference", self)
        quick_ref_action.setShortcut("F1")
        quick_ref_action.triggered.connect(self._show_quick_reference)
        help_menu.addAction(quick_ref_action)

        help_menu.addSeparator()

        about_action = QAction("About BEAM IDE", self)
        about_action.triggered.connect(self._show_about)
        help_menu.addAction(about_action)

    def _std_icon(self, standard_pixmap):
        return self.style().standardIcon(standard_pixmap)

    def _setup_toolbar(self):
        toolbar = QToolBar("Main Toolbar")
        toolbar.setMovable(False)
        toolbar.setIconSize(QSize(24, 24))
        self.addToolBar(toolbar)

        new_btn = QAction(self._std_icon(QStyle.StandardPixmap.SP_FileIcon), "New", self)
        new_btn.setToolTip("New File (Ctrl+N)")
        new_btn.triggered.connect(self.new_file)
        toolbar.addAction(new_btn)

        open_btn = QAction(self._std_icon(QStyle.StandardPixmap.SP_DirOpenIcon), "Open", self)
        open_btn.setToolTip("Open File (Ctrl+O)")
        open_btn.triggered.connect(self.open_file_dialog)
        toolbar.addAction(open_btn)

        save_btn = QAction(self._std_icon(QStyle.StandardPixmap.SP_DialogSaveButton), "Save", self)
        save_btn.setToolTip("Save (Ctrl+S)")
        save_btn.triggered.connect(self.save_file)
        toolbar.addAction(save_btn)

        toolbar.addSeparator()

        run_btn = QAction(self._std_icon(QStyle.StandardPixmap.SP_MediaPlay), "Run", self)
        run_btn.setToolTip("Run (F5)")
        run_btn.triggered.connect(self.run_current_file)
        toolbar.addAction(run_btn)

        stop_btn = QAction(self._std_icon(QStyle.StandardPixmap.SP_MediaStop), "Stop", self)
        stop_btn.setToolTip("Stop (Shift+F5)")
        stop_btn.triggered.connect(self.terminal.stop_execution)
        toolbar.addAction(stop_btn)

    def _setup_statusbar(self):
        self.statusbar = QStatusBar()
        self.setStatusBar(self.statusbar)
        self.file_label = QLabel("No file open")
        self.statusbar.addWidget(self.file_label, 1)
        self.cursor_label = QLabel("Ln 1, Col 1")
        self.statusbar.addPermanentWidget(self.cursor_label)

    def _apply_settings(self):
        ws = self.settings.settings.window
        self.resize(ws.width, ws.height)
        if ws.maximized:
            self.showMaximized()
        home = str(Path.home())
        self.file_browser.set_root_path(home)
        terminal_position = self.settings.settings.terminal.position
        if terminal_position == "right":
            self._set_terminal_position("right")

    def _get_compat_theme(self):
        from beam_ide.app.themes import Theme
        ui_theme = self.theme_manager.get_current_ui_theme()
        syntax_theme = self.theme_manager.get_current_syntax_theme()
        return Theme(
            name=ui_theme.name,
            is_dark=ui_theme.is_dark,
            background=ui_theme.background,
            foreground=ui_theme.foreground,
            accent=ui_theme.accent,
            accent_hover=ui_theme.accent_hover,
            panel_background=ui_theme.panel_background,
            panel_border=ui_theme.panel_border,
            editor_background=ui_theme.editor_background,
            editor_foreground=ui_theme.editor_foreground,
            editor_line_highlight=ui_theme.editor_line_highlight,
            editor_selection=ui_theme.editor_selection,
            editor_gutter_bg=ui_theme.editor_gutter_bg,
            editor_gutter_fg=ui_theme.editor_gutter_fg,
            tab_background=ui_theme.tab_background,
            tab_active_background=ui_theme.tab_active_background,
            tab_hover_background=ui_theme.tab_hover_background,
            tab_border=ui_theme.tab_border,
            browser_background=ui_theme.browser_background,
            browser_item_hover=ui_theme.browser_item_hover,
            browser_item_selected=ui_theme.browser_item_selected,
            terminal_background=ui_theme.terminal_background,
            terminal_foreground=ui_theme.terminal_foreground,
            scrollbar_background=ui_theme.scrollbar_background,
            scrollbar_handle=ui_theme.scrollbar_handle,
            scrollbar_handle_hover=ui_theme.scrollbar_handle_hover,
            button_background=ui_theme.button_background,
            button_foreground=ui_theme.button_foreground,
            button_hover=ui_theme.button_hover,
            button_pressed=ui_theme.button_pressed,
            input_background=ui_theme.input_background,
            input_border=ui_theme.input_border,
            input_focus_border=ui_theme.input_focus_border,
            success=ui_theme.success,
            warning=ui_theme.warning,
            error=ui_theme.error,
            info=ui_theme.info,
            syntax=syntax_theme,
        )

    def _apply_theme(self):
        theme = self._get_compat_theme()
        self.file_browser.apply_theme(theme)
        self.terminal.apply_theme(theme)
        self.find_replace.apply_theme(theme)
        ui_theme = self.theme_manager.get_current_ui_theme()
        syntax_theme = self.theme_manager.get_current_syntax_theme()
        for editor in self.editors.values():
            editor.apply_ui_theme(ui_theme)
            editor.apply_syntax_theme(syntax_theme)

    def _restore_session(self):
        session = self.settings.settings.session
        if session.project_path and Path(session.project_path).exists():
            self.file_browser.set_root_path(session.project_path)
            self.current_project_path = session.project_path
        for file_path in session.open_files:
            if Path(file_path).exists():
                self.open_file(file_path)
        if session.active_file and session.active_file in self.editors:
            idx = self.tab_widget.indexOf(self.editors[session.active_file])
            if idx >= 0:
                self.tab_widget.setCurrentIndex(idx)

    def _set_ui_theme(self, name: str):
        self.theme_manager.set_ui_theme(name)
        from PyQt6.QtWidgets import QApplication
        QApplication.instance().setStyleSheet(self.theme_manager.get_current_stylesheet())
        ui_theme = self.theme_manager.get_current_ui_theme()
        compatible_names = self.theme_manager.get_compatible_syntax_themes(ui_theme.is_dark)
        current_syntax_name = getattr(self.settings.settings.theme, 'syntax_theme', 'default')
        if current_syntax_name not in compatible_names and compatible_names:
            self._set_syntax_theme(compatible_names[0])
        self._update_syntax_theme_menu()
        self._apply_theme()

    def _set_syntax_theme(self, name: str):
        self.theme_manager.set_syntax_theme(name)
        self._update_syntax_theme_menu()
        syntax_theme = self.theme_manager.get_current_syntax_theme()
        for editor in self.editors.values():
            editor.apply_syntax_theme(syntax_theme)

    def _update_syntax_theme_menu(self):
        if not hasattr(self, 'syntax_theme_menu'):
            return
        self.syntax_theme_menu.clear()
        ui_theme = self.theme_manager.get_current_ui_theme()
        compatible_themes = self.theme_manager.get_compatible_syntax_themes(ui_theme.is_dark)
        for theme_name in compatible_themes:
            display_name = theme_name.replace('_', ' ').title()
            current_syntax = getattr(self.settings.settings.theme, 'syntax_theme', 'default')
            if theme_name == current_syntax:
                display_name = f"✓ {display_name}"
            theme_action = QAction(display_name, self)
            theme_action.triggered.connect(lambda checked, n=theme_name: self._set_syntax_theme(n))
            self.syntax_theme_menu.addAction(theme_action)
        self.syntax_theme_menu.addSeparator()
        show_all_action = QAction("Show All Themes", self)
        show_all_action.triggered.connect(self._show_all_syntax_themes)
        self.syntax_theme_menu.addAction(show_all_action)

    def _show_all_syntax_themes(self):
        self.syntax_theme_menu.clear()
        for theme_name in self.theme_manager.get_available_syntax_themes():
            display_name = theme_name.replace('_', ' ').title()
            current_syntax = getattr(self.settings.settings.theme, 'syntax_theme', 'default')
            if theme_name == current_syntax:
                display_name = f"✓ {display_name}"
            theme_action = QAction(display_name, self)
            theme_action.triggered.connect(lambda checked, n=theme_name: self._set_syntax_theme(n))
            self.syntax_theme_menu.addAction(theme_action)

    # File operations
    def new_file(self):
        editor = CodeEditor(
            ui_theme=self.theme_manager.get_current_ui_theme(),
            syntax_theme=self.theme_manager.get_current_syntax_theme(),
            settings=self.settings
        )
        editor.cursorPositionChanged.connect(self._update_cursor_position)
        self.tab_widget.addTab(editor, "Untitled")
        self.tab_widget.setCurrentWidget(editor)

    def open_file_dialog(self):
        start_dir = self.current_project_path if self.current_project_path else str(Path.home())
        file_path, _ = QFileDialog.getOpenFileName(
            self, "Open File", start_dir,
            "BEAM Files (*.bas *.yab);;All Files (*)"
        )
        if file_path:
            self.open_file(file_path)

    def open_folder_dialog(self):
        start_dir = self.current_project_path if self.current_project_path else str(Path.home())
        folder = QFileDialog.getExistingDirectory(self, "Open Folder", start_dir)
        if folder:
            self.file_browser.set_root_path(folder)
            self.current_project_path = folder

    def open_file(self, file_path: str):
        path = Path(file_path)
        if file_path in self.editors:
            idx = self.tab_widget.indexOf(self.editors[file_path])
            self.tab_widget.setCurrentIndex(idx)
            return
        if not path.exists():
            QMessageBox.warning(self, "Error", f"File not found: {file_path}")
            return
        try:
            content = path.read_text(encoding='utf-8')
        except Exception as e:
            QMessageBox.warning(self, "Error", f"Could not read file: {e}")
            return
        editor = CodeEditor(
            ui_theme=self.theme_manager.get_current_ui_theme(),
            syntax_theme=self.theme_manager.get_current_syntax_theme(),
            settings=self.settings
        )
        editor.file_path = file_path
        editor.setPlainText(content)
        editor.set_modified(False)
        editor.cursorPositionChanged.connect(self._update_cursor_position)
        editor.file_modified.connect(lambda m, p=file_path: self._on_file_modified(p, m))
        self.editors[file_path] = editor
        idx = self.tab_widget.addTab(editor, path.name)
        self.tab_widget.setCurrentIndex(idx)
        self.settings.add_recent_file(file_path)
        self.file_label.setText(file_path)

    def save_file(self):
        editor = self.tab_widget.currentWidget()
        if not isinstance(editor, CodeEditor):
            return
        if editor.file_path:
            self._save_editor(editor, editor.file_path)
        else:
            self.save_file_as()

    def save_file_as(self):
        current_editor = self.tab_widget.currentWidget()
        if not isinstance(current_editor, CodeEditor):
            return
        initial_path = getattr(current_editor, 'suggested_save_path', None) or current_editor.file_path
        if not initial_path:
            initial_path = self.current_project_path if self.current_project_path else str(Path.home())
        file_path, _ = QFileDialog.getSaveFileName(
            self, "Save File", initial_path,
            "BEAM Files (*.bas *.yab);;All Files (*)"
        )
        if file_path:
            new_editor = CodeEditor(
                ui_theme=self.theme_manager.get_current_ui_theme(),
                syntax_theme=self.theme_manager.get_current_syntax_theme(),
                settings=self.settings
            )
            new_editor.setPlainText(current_editor.toPlainText())
            new_editor.cursorPositionChanged.connect(self._update_cursor_position)
            new_editor.file_modified.connect(lambda m, p=file_path: self._on_file_modified(p, m))
            self._save_editor(new_editor, file_path)
            self.editors[file_path] = new_editor
            idx = self.tab_widget.addTab(new_editor, Path(file_path).name)
            self.tab_widget.setCurrentIndex(idx)

    def _save_editor(self, editor: CodeEditor, file_path: str):
        try:
            Path(file_path).write_text(editor.toPlainText(), encoding='utf-8')
            editor.file_path = file_path
            editor.set_modified(False)
            idx = self.tab_widget.indexOf(editor)
            self.tab_widget.setTabText(idx, Path(file_path).name)
            if file_path not in self.editors:
                self.editors[file_path] = editor
            self.file_label.setText(file_path)
            self.statusbar.showMessage("File saved", 3000)
        except Exception as e:
            QMessageBox.warning(self, "Error", f"Could not save file: {e}")

    def close_tab(self, index: int):
        editor = self.tab_widget.widget(index)
        if not isinstance(editor, CodeEditor):
            return
        if editor.is_modified():
            reply = QMessageBox.question(
                self, "Save Changes?",
                "This file has unsaved changes. Save before closing?",
                QMessageBox.StandardButton.Save |
                QMessageBox.StandardButton.Discard |
                QMessageBox.StandardButton.Cancel
            )
            if reply == QMessageBox.StandardButton.Cancel:
                return
            elif reply == QMessageBox.StandardButton.Save:
                self.tab_widget.setCurrentIndex(index)
                self.save_file()
        if editor.file_path and editor.file_path in self.editors:
            del self.editors[editor.file_path]
        self.tab_widget.removeTab(index)

    def _on_tab_changed(self, index: int):
        editor = self.tab_widget.widget(index)
        if isinstance(editor, CodeEditor) and editor.file_path:
            self.file_label.setText(editor.file_path)
        else:
            self.file_label.setText("No file open")
        self._update_cursor_position()
        if isinstance(editor, CodeEditor) and self.find_replace.isVisible():
            self.find_replace.set_editor(editor)

    def _on_file_modified(self, path: str, modified: bool):
        if path in self.editors:
            editor = self.editors[path]
            idx = self.tab_widget.indexOf(editor)
            name = Path(path).name
            self.tab_widget.setTabText(idx, f"● {name}" if modified else name)

    def _update_cursor_position(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            cursor = editor.textCursor()
            line = cursor.blockNumber() + 1
            col = cursor.columnNumber() + 1
            self.cursor_label.setText(f"Ln {line}, Col {col}")

    # Edit operations
    def _undo(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.undo()

    def _redo(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.redo()

    def _cut(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.cut()

    def _copy(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.copy()

    def _paste(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.paste()

    # View operations
    def _toggle_file_browser(self):
        self.file_browser.setVisible(not self.file_browser.isVisible())

    def _toggle_terminal(self):
        self.terminal.setVisible(not self.terminal.isVisible())

    def _set_terminal_position(self, position: str):
        if position not in ["bottom", "right"]:
            return
        terminal_in_middle = any(
            self.middle_splitter.widget(i) is self.terminal
            for i in range(self.middle_splitter.count())
        )
        if position == "bottom" and terminal_in_middle:
            return
        if position == "right" and not terminal_in_middle:
            return
        self.settings.settings.terminal.position = position
        self.settings.save()
        was_visible = self.terminal.isVisible()
        self.terminal.hide()
        if position == "bottom":
            self.middle_splitter.addWidget(self.terminal)
            self.middle_splitter.setSizes([600, 200])
        else:
            self.main_splitter.addWidget(self.terminal)
            self.main_splitter.setSizes([250, 600, 400])
        self.terminal.setVisible(was_visible)

    def _on_bookmark_navigated(self, path: str):
        self.current_project_path = path

    # Find/Replace operations
    def _show_find(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            self.find_replace.set_editor(editor)
            self.find_replace.show_find()

    def _show_replace(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            self.find_replace.set_editor(editor)
            self.find_replace.show_find_replace()

    def _indent_selection(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.indent_selection()

    def _dedent_selection(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.dedent_selection()

    def _comment_selection(self):
        editor = self.tab_widget.currentWidget()
        if isinstance(editor, CodeEditor):
            editor.comment_selection()

    def _show_preferences(self):
        dialog = SettingsDialog(self.settings, self.theme_manager, parent=self)
        dialog.settings_applied.connect(self._apply_preferences_changes)
        dialog.exec()

    def _apply_preferences_changes(self):
        for editor in self.editors.values():
            editor.apply_settings()
        self.terminal.apply_settings()
        ui_theme_name = getattr(self.settings.settings.theme, 'ui_theme', 'dark')
        syntax_theme_name = getattr(self.settings.settings.theme, 'syntax_theme', 'default')
        self._set_ui_theme(ui_theme_name)
        if syntax_theme_name not in self.theme_manager.get_available_syntax_themes():
            self._set_syntax_theme('default')
        else:
            self._set_syntax_theme(syntax_theme_name)

    # Run operations
    def run_current_file(self):
        editor = self.tab_widget.currentWidget()
        if not isinstance(editor, CodeEditor):
            QMessageBox.warning(self, "No File", "No file is open to run.")
            return
        if editor.is_modified():
            if editor.file_path:
                self._save_editor(editor, editor.file_path)
            else:
                reply = QMessageBox.question(
                    self, "Save File?",
                    "File must be saved before running. Save now?",
                    QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
                )
                if reply == QMessageBox.StandardButton.Yes:
                    self.save_file_as()
                else:
                    return
        if not editor.file_path:
            QMessageBox.warning(self, "No File", "Please save the file first.")
            return
        self.terminal.setVisible(True)
        self.terminal.run_beam_file(editor.file_path)

    def run_current_file_external(self):
        editor = self.tab_widget.currentWidget()
        if not isinstance(editor, CodeEditor):
            QMessageBox.warning(self, "No File", "No file is open to run.")
            return
        if editor.is_modified():
            if editor.file_path:
                self._save_editor(editor, editor.file_path)
                if editor.is_modified():
                    return
            else:
                reply = QMessageBox.question(
                    self, "Save File?",
                    "File must be saved before running. Save now?",
                    QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
                )
                if reply == QMessageBox.StandardButton.Yes:
                    self.save_file_as()
                    if not editor.file_path:
                        return
                else:
                    return
        if not editor.file_path:
            QMessageBox.warning(self, "No File", "Please save the file first.")
            return
        self.terminal.run_external_file(editor.file_path)

    def _show_interpreter_settings(self):
        dialog = SettingsDialog(self.settings, self.theme_manager, parent=self)
        dialog.settings_applied.connect(self._apply_preferences_changes)
        dialog.tabs.setCurrentIndex(4)
        dialog.exec()

    def _show_quick_reference(self):
        viewer = HelpViewer(parent=self, theme=self._get_compat_theme())
        viewer.apply_theme(self._get_compat_theme())
        viewer.exec()

    def _show_about(self):
        QMessageBox.about(
            self, "About BEAM IDE",
            "<h2>BEAM IDE</h2>"
            "<p>Version 1.0.0</p>"
            "<p>A modern IDE for the BEAM programming language.</p>"
            "<p>(c) 2026 Chuck Finch - Fragillidae Software</p>"
        )

    def closeEvent(self, event):
        for editor in self.editors.values():
            if editor.is_modified():
                reply = QMessageBox.question(
                    self, "Unsaved Changes",
                    "You have unsaved changes. Are you sure you want to quit?",
                    QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
                )
                if reply == QMessageBox.StandardButton.No:
                    event.ignore()
                    return
                break
        ws = self.settings.settings.window
        ws.width = self.width()
        ws.height = self.height()
        ws.maximized = self.isMaximized()
        session = self.settings.settings.session
        session.open_files = [
            path for path, editor in self.editors.items()
            if path and Path(path).exists()
        ]
        current_editor = self.tab_widget.currentWidget()
        if isinstance(current_editor, CodeEditor) and current_editor.file_path:
            session.active_file = current_editor.file_path
        else:
            session.active_file = ""
        session.project_path = self.current_project_path or ""
        self.settings.save()
        event.accept()
