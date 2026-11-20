---
name: neetcode-pdf-notes
description: Write, extend, or update the "NeetCode 150 - DSA Prep (Roman Urdu)" PDF study notes in the exact same structure, Roman Urdu writing style, typography, and dark-navy/indigo color scheme as the reference NeetCode150.pdf. Use when asked to add problems, fix or rewrite notes, update recap tables, the master pattern map, or the STL cheat sheet, or to regenerate the PDF.
---

# NeetCode PDF Notes

The reference file is `NeetCode150.pdf` (A4, 33 pages, 23 problems, C++ solutions). Every new or updated page must look and read as if it came from the same document. Always open the reference PDF first and match it. When this skill and the PDF disagree, the PDF wins.

## Golden rules

1. **Code is the source of truth.** Use the author's own solution code from the problem folder, verbatim. Never replace it with a "cleaner" version. Only add short Roman Urdu comments on key lines, like the reference does (`// Duplicate mila!`).
2. **Do not invent facts.** Complexity, patterns, and mistakes must be derivable from the code.
3. **Do not touch existing content** unless the user asks. When adding a problem, also update every place it must appear (see "Update checklist").
4. **Same voice.** Roman Urdu + English mix. Technical terms (hash map, pointer, stack, window, O(n)) stay in English. Short, direct sentences. Use "—" (em dash) as the reference does.
5. **Same look.** Use only the tokens below. No new colors, fonts, or box styles.

## Document structure (in order)

1. **Cover page**: dark gradient. Eyebrow `SYED ABDUL ALI SHAH · DSA PREP`, title `NeetCode 150`, short description (Roman Urdu), row of pill tags (topics + `C++ Solutions`). Description mentions the problem count ("23 core problems") so update it when problems are added.
2. **Part divider page** (full-bleed dark): eyebrow `P A R T 1`, big title (`Arrays, Hashing & Heap`), one line `Problems 1-6: <first> se <last> tak.` plus a 1-2 line Roman Urdu teaser.
3. **Problem pages**: problems flow continuously one after another (no forced page break between problems; only avoid splitting a box across pages).
4. **Part recap** after the last problem of each part: eyebrow `P A R T 1 · R E C A P`, title `Part 1 Ka Pattern Summary`, one intro paragraph, table (Problem | Pattern | Time | Space), then a dark "DEKHO KAISE YE CHAIN BANTI HAI" card.
5. After all parts: **Master Pattern Map** divider, then per-pattern sections (pattern name, "Idea:" line, table of problems with how each uses it), a "Cross-Pattern Connections" bullet list, the "Complete Problem-to-Pattern Table" (# | Problem | Primary Pattern | Time | Space), and the "FINAL INTERVIEW MINDSET" dark card.
6. **STL Cheat Sheet**: divider, then one block per data structure (category eyebrow like `H A S H C O N T A I N E R`, title like `unordered_set<T> — Hash Set`, 2-line description, operations table with Operation | Complexity | Note, "IN GUIDE KAHAN KAHAN USE HUA" list referencing problem numbers), ending with the "Quick Decision Guide" table (Zaroorat | Data Structure).

## Per-problem template (exact order)

```
PROBLEM 7 · ARRAYS AND HASHING            <- eyebrow, spaced caps: "P R O B L E M  7 · ..."
36 - Valid Sudoku                         <- LeetCode number - Name (title)
Problem Samajhte Hain                     <- purple section heading
<1-3 line Roman Urdu description>
[PROBLEM STATEMENT box]                   <- blue box: Input / Output / Example (+ Constraint/Target/Rules if needed)
Core Intuition — <Technique Name>         <- purple section heading
<Roman Urdu paragraph: the trick and why it works, quoting the key question in "...">
[CODE block]                              <- label: "C++ — <Approach> (OPTIMAL)"
                                             last line: // Time: O(..) | Space: O(..)
(optional) bold-lead explanation paragraph: "Kyun O(n) hai, O(n²) nahi?" / "Deque mein INDICES kyun?"
(optional) small table (box-index table, approach comparison, etc.)
[INTERVIEW INSIGHT box]  and/or  [COMMON MISTAKE box]    <- green / red; at least one of them
[YAAD RAKHNE WALI CHEEZEIN box]           <- purple box, 3-4 bullets
```

Content rules:
- **Problem Samajhte Hain**: explain the problem as if to a friend, 1-3 sentences, Roman Urdu.
- **PROBLEM STATEMENT box**: `Input:`, `Output:`, `Example:` lines with bold labels. Examples use `->`. Add `Constraint:` / `Target:` only if the problem has one.
- **Core Intuition**: heading is `Core Intuition — <Pattern/Trick>`. First put the guiding question in quotes (`"Ye element pehle dekha hai kya?"`), then explain the approach in 2-4 sentences matching the actual code.
- **Code label**: `C++ — <what it is> (OPTIMAL)`. If the folder has a brute force and an optimal solution, show only the optimal one in the code block and mention brute force in text or a comparison table (see Trapping Rain Water).
- **INTERVIEW INSIGHT**: why this choice beats alternatives (e.g. `unordered_set > set`, `count() > at()`), or how it connects to another problem.
- **COMMON MISTAKE**: one concrete bug people make with this problem (wrong condition, `if` vs `while`, pop order, missing separator). Must be specific.
- **YAAD RAKHNE WALI CHEEZEIN**: always starts with `Pattern: <name>`, then complexity/trick bullets, and at least one cross-reference to another problem as `(#128)`.
- Problem numbers in cross-references use `#<leetcode number>` (e.g. `#217`, `#1`).

## Design tokens

Page: A4, white background, side margins about 22pt, content width fills the page.

| Token | Value | Used for |
|---|---|---|
| ink | `#1b2033` | body text, code block background |
| ink-deep | `#171c30` | top bar, table header, dark cards |
| muted | `#6a6d7a` | secondary text |
| purple (heading) | `#4c3fc4` | section headings, box labels (purple box) |
| purple-accent | `#6d4fd6` | purple box left border, bullets |
| purple-soft | `#9d8cf1` | eyebrows, code block label, top bar title |
| lavender-text | `#a99bf5` | label inside dark cards |
| blue | `#5b8def` | problem statement border + label |
| green | `#43a06a` | insight border + label, complexity comment line |
| red | `#e5636a` | mistake border + label |
| bg-blue | `#eaf1fd` | problem statement box |
| bg-green | `#eaf6ee` | insight box |
| bg-red | `#fdecec` | mistake box |
| bg-purple | `#f1eefc` | remember box |
| bg-row-alt | `#f8f7fd` | alternate table rows |
| border-soft | `#e5e3f2` | table borders |
| cover gradient | `#171c30` (top-left) to `#1b2240` (middle) to `#201b3a` (bottom-right), about 160deg | cover + part dividers |

These were sampled from the reference PDF's rendered pages. The code-syntax text colors inside the dark code block are light grey-blue for code and the green token for the `// Time:` line; match them visually against the PDF.

Fonts:
- **Poppins** (Regular 400, Medium 500, SemiBold/Bold 600-700) for all text.
- **DejaVu Sans Mono** for code (Bold for the code label only if needed).
- Sizes (pt, approximate): body 8.5-9, problem title 15-16 bold, section heading 9.5 bold in purple, eyebrow 6.5 uppercase with wide letter-spacing (0.25em), box label 6.5 uppercase letter-spacing 0.12em bold, code 6.8-7, table 7.5, cover title 34 bold, part-divider title 24-26 bold.
- Eyebrows are written with letter-spacing, not by typing spaces between letters (the PDF text extracts as `P R O B L E M  1` because of spacing).

Components (CSS to reuse):

```css
@page { size: A4; margin: 14mm 8mm 12mm 8mm; }
* { box-sizing: border-box; }
body { font-family: 'Poppins', sans-serif; font-size: 8.8pt; line-height: 1.55; color: #1b2033; margin: 0; }
.eyebrow { font-size: 6.5pt; letter-spacing: .25em; text-transform: uppercase; color: #8f78df; font-weight: 500; margin: 18pt 0 2pt; }
h1.problem { font-size: 15.5pt; font-weight: 700; margin: 0 0 8pt; }
h2 { font-size: 9.5pt; font-weight: 700; color: #4c3fc4; margin: 10pt 0 3pt; }
p { margin: 0 0 6pt; }
.box { border-left: 2.2pt solid; border-radius: 4pt; padding: 7pt 9pt; margin: 7pt 0; break-inside: avoid; }
.box .label { font-size: 6.3pt; letter-spacing: .12em; text-transform: uppercase; font-weight: 700; margin-bottom: 3pt; }
.statement { background: #eaf1fd; border-color: #5b8def; } .statement .label { color: #5b8def; }
.insight   { background: #eaf6ee; border-color: #43a06a; } .insight .label   { color: #43a06a; }
.mistake   { background: #fdecec; border-color: #e5636a; } .mistake .label   { color: #e5636a; }
.remember  { background: #f1eefc; border-color: #6d4fd6; } .remember .label  { color: #4c3fc4; }
.remember ul { margin: 0; padding-left: 12pt; } .remember li::marker { color: #6d4fd6; }
.code { background: #1b2033; color: #dfe6f5; border-radius: 6pt; padding: 8pt 10pt; margin: 7pt 0; break-inside: avoid; }
.code .label { color: #9d8cf1; font: 700 6.3pt 'DejaVu Sans Mono', monospace; letter-spacing: .12em; text-transform: uppercase; margin-bottom: 5pt; }
.code pre { margin: 0; font: 6.9pt/1.45 'DejaVu Sans Mono', monospace; white-space: pre; }
.code .c { color: #8a93ad; } .code .t { color: #43a06a; }   /* .t = the final "// Time: ..." line */
table.t { width: 100%; border-collapse: collapse; font-size: 7.5pt; margin: 7pt 0; }
table.t th { background: #171c30; color: #fff; text-align: left; padding: 5pt 7pt; font-weight: 500; }
table.t td { padding: 4.5pt 7pt; border-bottom: 1pt solid #e5e3f2; }
table.t tr:nth-child(even) td { background: #f8f7fd; }
.chain { background: #1b2033; color: #dfe6f5; border-radius: 6pt; padding: 9pt 11pt; margin: 9pt 0; break-inside: avoid; }
.chain .label { color: #a99bf5; font-size: 6.3pt; letter-spacing: .12em; text-transform: uppercase; font-weight: 700; margin-bottom: 3pt; }
.cover, .divider { background: linear-gradient(160deg, #171c30 0%, #1b2240 55%, #201b3a 100%); color: #fff; }
.pill { display: inline-block; border: 1pt solid #3a3f5c; background: #23263d; color: #d9dcf2; border-radius: 12pt; padding: 3pt 9pt; font-size: 7pt; margin-right: 5pt; }
```

Top bar on every content page (not on cover or dividers): full-width `#171c30` band, left `NeetCode 150` in `#9d8cf1` (medium), right `DSA Prep · Roman Urdu` in light grey (medium), font about 6.5pt.

Code block syntax: do not do heavy syntax highlighting. Plain light text on dark; comments in the muted grey-blue; the final `// Time: ... | Space: ...` line in green.

## How to produce the PDF

Preferred pipeline: write HTML + the CSS above, render with headless Chromium (Playwright), merge parts with pypdf.

1. Put fonts in `fonts/` (Poppins 400/500/600/700, DejaVu Sans Mono) and load them with `@font-face` so the PDF embeds them. Do not rely on the system having them.
2. Render the cover and each part divider as **full-bleed pages with no header/footer** (`@page { margin: 0 }` for those files).
3. Render content (problems, recaps, tables) with the top bar through Playwright's `header_template` (`display_header_footer=True`, `print_background=True`, enough top margin for the bar) and `prefer_css_page_size=True`.
4. Merge in document order with pypdf (cover, divider, content, recap, divider, ...).
5. Use `break-inside: avoid` on `.box`, `.code`, `.chain`, tables rows so no box splits across pages. If a code block is longer than a page, allow a split only inside the code.
6. Check: open the output, rasterize at least the cover, one problem page, a recap page, and the last page, and compare side by side with the reference PDF.

Minimal render sketch:

```python
from playwright.sync_api import sync_playwright
from pypdf import PdfWriter

HEADER = '''<div style="width:100%;background:#171c30;-webkit-print-color-adjust:exact;
 font:500 6.5pt Poppins,sans-serif;padding:5pt 24pt;display:flex;justify-content:space-between">
 <span style="color:#9d8cf1">NeetCode 150</span><span style="color:#c9cce3">DSA Prep · Roman Urdu</span></div>'''

def render(html, out, header):
    with sync_playwright() as p:
        b = p.chromium.launch(); pg = b.new_page()
        pg.goto(f"file://{html}"); pg.wait_for_load_state("networkidle")
        pg.pdf(path=out, format="A4", print_background=True, prefer_css_page_size=not header,
               display_header_footer=header, header_template=HEADER if header else "<span></span>",
               footer_template="<span></span>",
               margin=dict(top="12mm" if header else "0", bottom="10mm" if header else "0", left="0", right="0"))
        b.close()

parts = [("cover.html", False), ("part1_divider.html", False), ("part1_content.html", True)]  # extend in order
w = PdfWriter()
for i, (h, hdr) in enumerate(parts):
    out = f"build/{i:02d}.pdf"; render(f"/abs/path/{h}", out, hdr); w.append(out)
w.write("NeetCode150.pdf")
```

If Playwright is not available, WeasyPrint is acceptable. Keep the same CSS tokens either way.

## Update checklist

When adding or changing a problem, update ALL of these:

- [ ] The problem section itself (all template parts, in order)
- [ ] The part's **recap table** and the "Dekho kaise ye chain banti hai" card if a new connection appears
- [ ] The part divider line (`Problems 7-19: ...`) and cover description (problem count, topic pills)
- [ ] The **Master Pattern Map**: the pattern's problem table, cross-pattern connections if relevant
- [ ] The **Complete Problem-to-Pattern Table** (keep the same order as the guide)
- [ ] The **STL Cheat Sheet**: add the problem to "IN GUIDE KAHAN KAHAN USE HUA" of every container it uses, and to the Quick Decision Guide if a new container appears
- [ ] Cross-references `(#N)` in other problems' "Yaad rakhne wali cheezein" where the new problem reuses a pattern
- [ ] Problem sequence numbers in eyebrows (`PROBLEM 24`) stay consecutive

## Writing quality checklist (per problem)

- [ ] Roman Urdu is natural and simple; technical words in English
- [ ] Intuition explains WHY, not just what the code does
- [ ] Complexity in the code's final comment matches the recap and master table
- [ ] The COMMON MISTAKE is specific to this code, not generic advice
- [ ] No box or table is cut across a page break
- [ ] Visual check against the reference PDF done

## Workflow

1. Read the reference PDF pages that are closest to what you are writing (a similar pattern problem, plus the recap and master map pages).
2. Read the problem's solution code from its folder.
3. Draft the problem section from the template, then update every item in the Update checklist.
4. Build the PDF and compare against the reference visually.
5. For the first run, do only 2-3 problems and ask the user to confirm the look before continuing.