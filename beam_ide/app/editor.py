"""
Code Editor Widget for BEAM IDE
Provides a code editor with line numbers and syntax highlighting
"""

import re

from PyQt6.QtWidgets import QPlainTextEdit, QWidget, QTextEdit
from PyQt6.QtCore import Qt, QRect, QSize, pyqtSignal
from PyQt6.QtGui import QPainter, QColor, QTextFormat, QFont, QTextCursor

from beam_ide.app.syntax import BeamHighlighter
from beam_ide.app.themes import UITheme, SyntaxColors
from beam_ide.app.settings import SettingsManager


class LineNumberArea(QWidget):
    """Widget for displaying line numbers in the editor gutter"""

    def __init__(self, editor):
        super().__init__(editor)
        self.editor = editor

    def sizeHint(self) -> QSize:
        return QSize(self.editor.line_number_area_width(), 0)

    def paintEvent(self, event):
        self.editor.line_number_area_paint_event(event)


class CodeEditor(QPlainTextEdit):
    """Code editor with line numbers and syntax highlighting"""

    file_modified = pyqtSignal(bool)

    def __init__(self, parent=None, ui_theme: UITheme = None,
                 syntax_theme: SyntaxColors = None,
                 settings: SettingsManager = None):
        super().__init__(parent)
        self.ui_theme = ui_theme
        self.syntax_theme = syntax_theme
        self.settings = settings
        self.file_path = None
        self._modified = False

        self.line_number_area = LineNumberArea(self)
        self.highlighter = BeamHighlighter(self.document(), syntax_theme)

        self.blockCountChanged.connect(self.update_line_number_area_width)
        self.updateRequest.connect(self.update_line_number_area)
        self.cursorPositionChanged.connect(self.highlight_current_line)
        self.textChanged.connect(self._on_text_changed)

        self.update_line_number_area_width(0)
        self.highlight_current_line()
        self.apply_settings()

    def apply_settings(self):
        """Apply editor settings"""
        if self.settings:
            s = self.settings.settings.editor
            font = QFont(s.font_family, s.font_size)
            font.setStyleHint(QFont.StyleHint.Monospace)
            self.setFont(font)
            self.line_number_area.setFont(font)
            self.setTabStopDistance(
                s.tab_width * self.fontMetrics().horizontalAdvance(' '))
            self.setLineWrapMode(
                QPlainTextEdit.LineWrapMode.WidgetWidth if s.word_wrap
                else QPlainTextEdit.LineWrapMode.NoWrap)
            self.line_number_area.setVisible(s.show_line_numbers)
            self.update_line_number_area_width(0)
            self.highlight_current_line()
            if self.ui_theme:
                self.apply_ui_theme(self.ui_theme)
            self.update()
            self.viewport().update()
            self.line_number_area.update()

    def apply_ui_theme(self, ui_theme: UITheme):
        """Apply UI theme to editor"""
        self.ui_theme = ui_theme
        font_family = "monospace"
        font_size = 12
        if self.settings and self.settings.settings.editor:
            font_family = self.settings.settings.editor.font_family
            font_size = self.settings.settings.editor.font_size
        self.setStyleSheet(f"""
            QPlainTextEdit {{
                background-color: {ui_theme.editor_background};
                color: {ui_theme.editor_foreground};
                selection-background-color: {ui_theme.editor_selection};
                border: none;
                font-family: "{font_family}";
                font-size: {font_size}pt;
            }}
        """)
        if self.settings and self.settings.settings.editor:
            self.setTabStopDistance(
                self.settings.settings.editor.tab_width *
                self.fontMetrics().horizontalAdvance(' '))
        self.highlight_current_line()
        self.viewport().update()
        self.line_number_area.update()

    def apply_syntax_theme(self, syntax_theme: SyntaxColors):
        """Apply syntax theme to editor"""
        self.syntax_theme = syntax_theme
        self.highlighter.set_syntax_theme(syntax_theme)

    def line_number_area_width(self) -> int:
        digits = len(str(max(1, self.blockCount())))
        return 8 + self.fontMetrics().horizontalAdvance('9') * digits

    def update_line_number_area_width(self, _):
        self.setViewportMargins(self.line_number_area_width(), 0, 0, 0)

    def update_line_number_area(self, rect, dy):
        if dy:
            self.line_number_area.scroll(0, dy)
        else:
            self.line_number_area.update(
                0, rect.y(), self.line_number_area.width(), rect.height())
        if rect.contains(self.viewport().rect()):
            self.update_line_number_area_width(0)

    def keyPressEvent(self, event):
        """Handle key press events for BEAM auto-indentation"""
        if event.key() in (Qt.Key.Key_Return, Qt.Key.Key_Enter):
            super().keyPressEvent(event)
            cursor = self.textCursor()
            prev_block = cursor.block().previous()
            if prev_block.isValid():
                prev_text = prev_block.text().rstrip()
                prev_stripped = prev_text.lstrip()
                indent = len(prev_text) - len(prev_text.lstrip())
                should_indent = False
                # Increase indent after block-starting statements
                lower = prev_stripped.lower()
                if re.match(r'^(sub\s+\w|while\b|for\b|else\b|elseif\b|'
                            r'do\b|switch\b|case\b|default\b)', lower):
                    should_indent = True
                elif re.match(r'^if\b.*\bthen\s*$', lower):
                    should_indent = True
                if should_indent:
                    indent += 4
                if indent > 0:
                    cursor.insertText(" " * indent)
        else:
            super().keyPressEvent(event)

    def resizeEvent(self, event):
        super().resizeEvent(event)
        cr = self.contentsRect()
        self.line_number_area.setGeometry(
            QRect(cr.left(), cr.top(),
                  self.line_number_area_width(), cr.height()))

    def line_number_area_paint_event(self, event):
        painter = QPainter(self.line_number_area)
        if self.ui_theme:
            painter.fillRect(event.rect(), QColor(self.ui_theme.editor_gutter_bg))
            text_color = QColor(self.ui_theme.editor_gutter_fg)
        else:
            painter.fillRect(event.rect(), QColor("#1e1e2e"))
            text_color = QColor("#6c7086")
        painter.setPen(text_color)
        block = self.firstVisibleBlock()
        block_number = block.blockNumber()
        top = round(self.blockBoundingGeometry(block)
                    .translated(self.contentOffset()).top())
        bottom = top + round(self.blockBoundingRect(block).height())
        while block.isValid() and top <= event.rect().bottom():
            if block.isVisible() and bottom >= event.rect().top():
                painter.drawText(
                    0, top, self.line_number_area.width() - 4,
                    self.fontMetrics().height(),
                    Qt.AlignmentFlag.AlignRight, str(block_number + 1))
            block = block.next()
            top = bottom
            bottom = top + round(self.blockBoundingRect(block).height())
            block_number += 1

    def _get_bracket_matches(self):
        """Find and highlight matching brackets"""
        extra_selections = []
        if not self.ui_theme:
            return extra_selections
        cursor = self.textCursor()
        text = self.toPlainText()
        pos = cursor.position()
        bracket_pairs = {'(': ')', ')': '(', '[': ']', ']': '[', '{': '}', '}': '{'}
        char_before = text[pos - 1] if pos > 0 else ''
        char_at = text[pos] if pos < len(text) else ''
        bracket_char = bracket_pos = None
        is_opening = False
        if char_before in bracket_pairs:
            bracket_char, bracket_pos = char_before, pos - 1
            is_opening = char_before in '([{'
        elif char_at in bracket_pairs:
            bracket_char, bracket_pos = char_at, pos
            is_opening = char_at in '([{'
        if bracket_char and bracket_pos is not None:
            match_pos = self._find_matching_bracket(
                text, bracket_pos, bracket_char, is_opening)
            if match_pos is not None:
                for bp in (bracket_pos, match_pos):
                    sel = QTextEdit.ExtraSelection()
                    sel.format.setBackground(QColor("#555555"))
                    sel.format.setForeground(QColor("#FFD700"))
                    c = QTextCursor(self.document())
                    c.setPosition(bp)
                    c.movePosition(QTextCursor.MoveOperation.Right,
                                   QTextCursor.MoveMode.KeepAnchor)
                    sel.cursor = c
                    extra_selections.append(sel)
        return extra_selections

    def _find_matching_bracket(self, text, pos, bracket, is_opening):
        pairs = {'(': ')', ')': '(', '[': ']', ']': '[', '{': '}', '}': '{'}
        target = pairs[bracket]
        direction = 1 if is_opening else -1
        depth = 0
        i = pos
        while 0 <= i < len(text):
            if text[i] == bracket:
                depth += 1
            elif text[i] == target:
                depth -= 1
                if depth == 0:
                    return i
            i += direction
        return None

    def highlight_current_line(self):
        extra_selections = []
        should_highlight = True
        if self.settings and self.settings.settings.editor:
            should_highlight = self.settings.settings.editor.highlight_current_line
        if not self.isReadOnly() and self.ui_theme and should_highlight:
            sel = QTextEdit.ExtraSelection()
            sel.format.setBackground(QColor(self.ui_theme.editor_line_highlight))
            sel.format.setProperty(QTextFormat.Property.FullWidthSelection, True)
            sel.cursor = self.textCursor()
            sel.cursor.clearSelection()
            extra_selections.append(sel)
        if self.settings and self.settings.settings.editor.bracket_matching:
            extra_selections.extend(self._get_bracket_matches())
        self.setExtraSelections(extra_selections)

    def _on_text_changed(self):
        if not self._modified:
            self._modified = True
            self.file_modified.emit(True)

    def set_modified(self, modified: bool):
        self._modified = modified
        self.file_modified.emit(modified)

    def is_modified(self) -> bool:
        return self._modified

    def indent_selection(self):
        """Indent the selected lines by one level (4 spaces)"""
        cursor = self.textCursor()
        if not cursor.hasSelection():
            cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
            cursor.insertText("    ")
            return
        start = cursor.selectionStart()
        end = cursor.selectionEnd()
        cursor.setPosition(start)
        cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
        start_block = cursor.blockNumber()
        cursor.setPosition(end)
        if cursor.positionInBlock() == 0 and start_block != cursor.blockNumber():
            cursor.movePosition(QTextCursor.MoveOperation.PreviousBlock)
        end_block = cursor.blockNumber()
        cursor.beginEditBlock()
        for bn in range(start_block, end_block + 1):
            cursor.setPosition(self.document().findBlockByNumber(bn).position())
            cursor.insertText("    ")
        cursor.endEditBlock()

    def dedent_selection(self):
        """Dedent the selected lines by one level (up to 4 spaces)"""
        cursor = self.textCursor()
        if not cursor.hasSelection():
            cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
            text = cursor.block().text()
            spaces = min(4, len(text) - len(text.lstrip(' ')))
            if spaces:
                cursor.movePosition(QTextCursor.MoveOperation.Right,
                                    QTextCursor.MoveMode.KeepAnchor, spaces)
                cursor.removeSelectedText()
            return
        start = cursor.selectionStart()
        end = cursor.selectionEnd()
        cursor.setPosition(start)
        cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
        start_block = cursor.blockNumber()
        cursor.setPosition(end)
        if cursor.positionInBlock() == 0 and start_block != cursor.blockNumber():
            cursor.movePosition(QTextCursor.MoveOperation.PreviousBlock)
        end_block = cursor.blockNumber()
        cursor.beginEditBlock()
        for bn in range(start_block, end_block + 1):
            block = self.document().findBlockByNumber(bn)
            cursor.setPosition(block.position())
            text = block.text()
            spaces = min(4, len(text) - len(text.lstrip(' ')))
            if spaces:
                cursor.movePosition(QTextCursor.MoveOperation.Right,
                                    QTextCursor.MoveMode.KeepAnchor, spaces)
                cursor.removeSelectedText()
        cursor.endEditBlock()

    def comment_selection(self):
        """Toggle single-quote comment on selected lines (BEAM uses ' for comments)"""
        cursor = self.textCursor()
        if not cursor.hasSelection():
            cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
            block = cursor.block()
            text = block.text()
            stripped = text.lstrip()
            indent = len(text) - len(stripped)
            if stripped.startswith("' "):
                new_text = " " * indent + stripped[2:]
            elif stripped.startswith("'"):
                new_text = " " * indent + stripped[1:]
            else:
                new_text = " " * indent + "' " + stripped
            cursor.setPosition(block.position())
            cursor.setPosition(block.position() + len(block.text()),
                               QTextCursor.MoveMode.KeepAnchor)
            cursor.insertText(new_text)
            return
        start = cursor.selectionStart()
        end = cursor.selectionEnd()
        cursor.setPosition(start)
        cursor.movePosition(QTextCursor.MoveOperation.StartOfLine)
        start_block = cursor.blockNumber()
        start_pos = cursor.position()
        cursor.setPosition(end)
        if cursor.positionInBlock() == 0 and start_block != cursor.blockNumber():
            cursor.movePosition(QTextCursor.MoveOperation.PreviousBlock)
        end_block = cursor.blockNumber()
        cursor.beginEditBlock()
        for bn in range(start_block, end_block + 1):
            block = self.document().findBlockByNumber(bn)
            cursor.setPosition(block.position())
            text = block.text()
            stripped = text.lstrip()
            indent = len(text) - len(stripped)
            if stripped.startswith("' "):
                new_text = " " * indent + stripped[2:]
            elif stripped.startswith("'"):
                new_text = " " * indent + stripped[1:]
            else:
                new_text = " " * indent + "' " + stripped
            cursor.setPosition(block.position())
            cursor.setPosition(block.position() + len(block.text()),
                               QTextCursor.MoveMode.KeepAnchor)
            cursor.insertText(new_text)
        cursor.endEditBlock()
