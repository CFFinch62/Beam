"""
BEAM Language Syntax Highlighter
Provides syntax highlighting for BEAM (yabasic-based) programs
"""

import re
from PyQt6.QtGui import QSyntaxHighlighter, QTextCharFormat, QColor, QFont

from beam_ide.app.themes import SyntaxColors


class BeamHighlighter(QSyntaxHighlighter):
    """Syntax highlighter for the BEAM/yabasic language"""

    def __init__(self, parent=None, syntax_theme: SyntaxColors = None):
        super().__init__(parent)
        self.syntax_theme = syntax_theme
        self._setup_rules()

    def set_syntax_theme(self, syntax_theme: SyntaxColors):
        """Update the syntax theme and refresh highlighting"""
        self.syntax_theme = syntax_theme
        self._setup_rules()
        self.rehighlight()

    def _create_format(self, color: str, bold: bool = False,
                       italic: bool = False) -> QTextCharFormat:
        """Create a text format with the given style"""
        fmt = QTextCharFormat()
        fmt.setForeground(QColor(color))
        if bold:
            fmt.setFontWeight(QFont.Weight.Bold)
        if italic:
            fmt.setFontItalic(True)
        return fmt

    def _setup_rules(self):
        """Set up highlighting rules based on current syntax theme"""
        self.rules = []
        if self.syntax_theme is None:
            return

        syntax = self.syntax_theme

        # --- BEAM GUI commands ---
        beam_cmds = (
            r'\b(beam_open|beam_close|beam_title|beam_size|beam_running|'
            r'beam_begin|beam_end|beam_button|beam_label|beam_text|beam_input|'
            r'beam_checkbox|beam_combo|beam_slider|beam_progress|beam_separator|'
            r'beam_spacing|beam_image|beam_row|beam_row_end|beam_group_begin|'
            r'beam_group_end|beam_panel_begin|beam_panel_end|beam_msgbox|'
            r'beam_confirm|beam_open_file|beam_save_file|beam_set_color|'
            r'beam_set_style|beam_time|beam_sleep)\b'
        )
        self.rules.append((re.compile(beam_cmds, re.IGNORECASE),
                           self._create_format(syntax.builtin, bold=True)))

        # --- Control flow keywords ---
        control_kw = (
            r'\b(if|then|else|elseif|end\s+if|while|wend|for|to|step|next|'
            r'goto|gosub|return|switch|case|default|end\s+switch|break|'
            r'loop|exit\s+while|exit\s+for|do|until|repeat)\b'
        )
        self.rules.append((re.compile(control_kw, re.IGNORECASE),
                           self._create_format(syntax.keyword, bold=True)))

        # --- Declaration keywords ---
        decl_kw = (
            r'\b(sub|end\s+sub|local|dim|import|export|label|'
            r'rem|end|print|input|open|close|read|write|'
            r'line\s+input|data|restore|on\s+error|error)\b'
        )
        self.rules.append((re.compile(decl_kw, re.IGNORECASE),
                           self._create_format(syntax.keyword, bold=True)))

        # --- Logical operators ---
        logical_kw = r'\b(and|or|not|mod|xor)\b'
        self.rules.append((re.compile(logical_kw, re.IGNORECASE),
                           self._create_format(syntax.operator, bold=True)))

        # --- Built-in string functions ---
        str_funcs = (
            r'\b(len|left\$|right\$|mid\$|upper\$|lower\$|ltrim\$|rtrim\$|'
            r'trim\$|instr|str\$|val|chr\$|asc|left|right|mid|upper|lower|'
            r'ltrim|rtrim|trim)\b'
        )
        self.rules.append((re.compile(str_funcs, re.IGNORECASE),
                           self._create_format(syntax.function)))

        # --- Built-in math functions ---
        math_funcs = (
            r'\b(abs|int|sqrt|sin|cos|tan|log|exp|max|min|ran|'
            r'peek|poke|atn|sgn|fix|frac|rnd|randomize)\b'
        )
        self.rules.append((re.compile(math_funcs, re.IGNORECASE),
                           self._create_format(syntax.function)))

        # --- Built-in I/O / system functions ---
        io_funcs = (
            r'\b(eof|isopen|filesize|system|execute|token\$|tokencount)\b'
        )
        self.rules.append((re.compile(io_funcs, re.IGNORECASE),
                           self._create_format(syntax.builtin)))

        # --- String variables (end with $) ---
        string_var = r'\b[a-zA-Z_][a-zA-Z0-9_]*\$'
        self.rules.append((re.compile(string_var),
                           self._create_format(syntax.variable)))

        # --- Subroutine / function call (identifier followed by '(') ---
        func_call = r'\b([a-zA-Z_][a-zA-Z0-9_]*)\s*(?=\()'
        self.rules.append((re.compile(func_call),
                           self._create_format(syntax.function)))

        # --- Numbers (integer, float, hex) ---
        numbers = (
            r'\b(0x[0-9a-fA-F]+|\d+\.?\d*([eE][+-]?\d+)?)\b'
        )
        self.rules.append((re.compile(numbers),
                           self._create_format(syntax.number)))

        # --- Strings (double-quoted) ---
        strings = r'"[^"\\]*(\\.[^"\\]*)*"'
        self.rules.append((re.compile(strings),
                           self._create_format(syntax.string)))

        # --- Operators ---
        operators = r'[+\-*\/\^=<>]'
        self.rules.append((re.compile(operators),
                           self._create_format(syntax.operator)))

        # --- REM comments (keyword form) — must come before single-quote ---
        rem_comment = r'\brem\b.*$'
        self.rules.append((re.compile(rem_comment, re.IGNORECASE),
                           self._create_format(syntax.comment, italic=True)))

        # --- Single-quote comments — applied last so they override everything ---
        sq_comment = r"'.*$"
        self.rules.append((re.compile(sq_comment),
                           self._create_format(syntax.comment, italic=True)))

    def highlightBlock(self, text: str):
        """Apply highlighting to a block of text"""
        if self.syntax_theme is None:
            return

        self.setCurrentBlockState(0)

        for pattern, fmt in self.rules:
            for match in pattern.finditer(text):
                self.setFormat(match.start(),
                               match.end() - match.start(), fmt)
