"""
Shared BEAM (yabasic) block-structure rules.

This module is the single source of truth for "what counts as a nested
block" in BEAM, used by editor.py's nested scope-box renderer (paintEvent).

Unlike PLAIN/FORGE, BEAM is NOT indentation-significant -- it's yabasic,
where blocks close via explicit paired keywords and indentation is purely
cosmetic (see Beam/docs/BEAM_Language_Reference.md section 5 and
beam_ide/app/syntax.py's control_kw regex, which is the authoritative list
of real BEAM keywords). So this does keyword-pair matching (structurally
like bracket matching) instead of PLAIN/FORGE's indentation dedent-stack.

Recognized pairs:
  if ... then$ / end if  (single-line "if x then action" is NOT a block --
                           BEAM's own docs say the single-line form is only
                           safe at the top level and must not appear inside
                           a multi-line if/end-if block)
  for / next
  while / wend
  do / loop
  repeat / until
  switch / end switch
  sub / end sub

elseif/else (inside if) and case/default (inside switch) do not open their
own pair -- they split the enclosing block into sibling same-depth
segments, mirroring how PLAIN/FORGE's dedent-stack gives each elif/else
its own box. This keeps the visual result consistent with the other IDEs
even though the underlying detection algorithm is different.

This is a lightweight keyword tracker, not a real parser: it does not
validate syntax and will happily under- or over-match on malformed or
mid-edit code. That's intentional -- it needs to keep working while the
user is halfway through typing.
"""

import re
from typing import List, Optional, Tuple

# "end if"/"end switch"/"end sub" also accept the no-space form (endif,
# endswitch, endsub) as a defensive superset -- real BEAM code uses the
# two-word form, but this costs nothing to also accept.
IF_OPEN = re.compile(r'^if\b.*\bthen\s*$', re.IGNORECASE)
IF_CLOSE = re.compile(r'^end\s*if\b', re.IGNORECASE)
ELSEIF_MARKER = re.compile(r'^elseif\b.*\bthen\s*$', re.IGNORECASE)
ELSE_MARKER = re.compile(r'^else\s*$', re.IGNORECASE)

FOR_OPEN = re.compile(r'^for\b', re.IGNORECASE)
FOR_CLOSE = re.compile(r'^next\b', re.IGNORECASE)

WHILE_OPEN = re.compile(r'^while\b', re.IGNORECASE)
WHILE_CLOSE = re.compile(r'^wend\b', re.IGNORECASE)

DO_OPEN = re.compile(r'^do\b', re.IGNORECASE)
DO_CLOSE = re.compile(r'^loop\b', re.IGNORECASE)

REPEAT_OPEN = re.compile(r'^repeat\s*$', re.IGNORECASE)
REPEAT_CLOSE = re.compile(r'^until\b', re.IGNORECASE)

SWITCH_OPEN = re.compile(r'^switch\b', re.IGNORECASE)
SWITCH_CLOSE = re.compile(r'^end\s*switch\b', re.IGNORECASE)
CASE_MARKER = re.compile(r'^case\b', re.IGNORECASE)
DEFAULT_MARKER = re.compile(r'^default\s*$', re.IGNORECASE)

SUB_OPEN = re.compile(r'^sub\b', re.IGNORECASE)
SUB_CLOSE = re.compile(r'^end\s*sub\b', re.IGNORECASE)

# (kind, opener pattern, closer pattern, sibling-marker patterns)
BLOCK_KINDS = [
    ("if", IF_OPEN, IF_CLOSE, (ELSEIF_MARKER, ELSE_MARKER)),
    ("for", FOR_OPEN, FOR_CLOSE, ()),
    ("while", WHILE_OPEN, WHILE_CLOSE, ()),
    ("do", DO_OPEN, DO_CLOSE, ()),
    ("repeat", REPEAT_OPEN, REPEAT_CLOSE, ()),
    ("switch", SWITCH_OPEN, SWITCH_CLOSE, (CASE_MARKER, DEFAULT_MARKER)),
    ("sub", SUB_OPEN, SUB_CLOSE, ()),
]


class _Frame:
    __slots__ = ("kind", "closer", "markers", "depth", "segment_start")

    def __init__(self, kind, closer, markers, depth, segment_start):
        self.kind = kind
        self.closer = closer
        self.markers = markers
        self.depth = depth
        self.segment_start = segment_start


def compute_scopes(text: str) -> List[Tuple[int, int, int]]:
    """
    Walk the full document text and compute nested scope ranges using
    BEAM's paired block keywords (not indentation).

    Returns a list of (start_line, end_line, depth) tuples, 0-indexed and
    inclusive on both ends, matching QTextDocument block numbers.
    """
    lines = text.split("\n")
    scopes: List[Tuple[int, int, int]] = []
    stack: List[_Frame] = []

    def last_nonblank(before_index: int, floor: int) -> int:
        idx = before_index
        while idx > floor and not lines[idx].strip():
            idx -= 1
        return idx

    for i, raw_line in enumerate(lines):
        stripped = raw_line.strip()
        if not stripped:
            continue

        # 1. Does this line close the block currently on top of the stack?
        if stack and stack[-1].closer.match(stripped):
            frame = stack.pop()
            scopes.append((frame.segment_start, i, frame.depth))
            continue

        # 2. Does this line split the current block into a new sibling
        #    segment (elseif/else inside if, case/default inside switch)?
        if stack and any(m.match(stripped) for m in stack[-1].markers):
            frame = stack[-1]
            end_idx = last_nonblank(i - 1, frame.segment_start)
            scopes.append((frame.segment_start, end_idx, frame.depth))
            frame.segment_start = i
            continue

        # 3. Does this line open a new block?
        for kind, opener, closer, markers in BLOCK_KINDS:
            if opener.match(stripped):
                stack.append(_Frame(kind, closer, markers, len(stack), i))
                break

    # Close any blocks still open at end of document.
    last_idx = last_nonblank(len(lines) - 1, 0)
    while stack:
        frame = stack.pop()
        scopes.append((frame.segment_start, last_idx, frame.depth))

    return scopes
