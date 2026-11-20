---
name: neetcode-svg-verifier
description: Verify the animated SVG diagrams (overview, dry-run, complexity) created for LeetCode/NeetCode problem notes. Checks that each SVG is valid, self-contained, accessible, follows the style rules, renders without clipping, and, most importantly, that its animation matches what the user's actual solution code does. Use when asked to verify, review, validate, audit, or fix SVG diagrams in the problem folders.
---

# NeetCode SVG Verifier

Verify every `diagrams/*.svg` that belongs to a problem folder (created with the `leetcode-visual-notes` skill). A diagram passes only if it is technically valid AND shows the same execution as the user's solution code. A pretty diagram that shows the wrong algorithm is a failure.

Expected layout per problem:

```
<N>- <Problem Name>/
  solution.<ext>
  notes.md
  diagrams/
    01-overview.svg
    02-dry-run.svg
    03-complexity.svg   (optional)
```

## Verification has 4 layers. Run all of them, in order.

### Layer 1: Automated static checks (script)

Run the bundled script (needs only Python 3, no packages):

```bash
python scripts/verify_svg.py "<problem folder>/diagrams"          # one problem
python scripts/verify_svg.py "Source Code"                          # all problems (recurses)
python scripts/verify_svg.py "<file>.svg" --kind dry-run --json   # machine-readable
```

The script infers the kind from the file name (`dry`, `overview`, `complexity`). Exit code is 1 if any ERROR exists.

**ERRORS (must fix):**
- Invalid XML (unclosed tags, unescaped `&` or `<`)
- Missing `viewBox`
- `<script>`, `<foreignObject>`, `on*=` event attributes
- External references (`http(s)://` in `href`/`src`, `@import`, `url(http...)`, non-data `<image>`)
- Animated file without a `@media (prefers-reduced-motion: reduce)` block
- Dry-run diagram that has no animation at all

**WARNINGS (fix unless there is a reason):**
- Fixed `width`/`height` on `<svg>`, missing `role="img"` or `<title>`
- First and last keyframe differ (loop will jump), missing 0%/100%
- Dry-run loop outside 8-14s; overview animating longer than 6s
- Transforms animated without `transform-box: fill-box` (wrong pivot)
- Animating layout-like properties (`width`, `cx`, `x`, ...) instead of `transform`/`opacity`/`stroke-dashoffset`
- Colors outside the palette, fonts under 14px
- Rects or text extending past the viewBox (estimated)
- No "Step N / M" counter when there are more than 4 steps, no visible final answer

Palette (only these are allowed): `#0f172a #1e293b #475569 #e2e8f0 #94a3b8 #38bdf8 #f59e0b #22c55e #ef4444 #a78bfa` (+ white/black/none).

### Layer 2: Visual render check

Static checks cannot see clipped text or overlapping shapes, so render frames and look at them. If Playwright/Chromium is available:

```python
# render_frames.py  ->  python render_frames.py diagrams/02-dry-run.svg
import sys, pathlib
from playwright.sync_api import sync_playwright

svg = pathlib.Path(sys.argv[1]).resolve()
out = svg.with_suffix("")
with sync_playwright() as p:
    b = p.chromium.launch()
    pg = b.new_page(viewport={"width": 1000, "height": 520})
    pg.goto(f"file://{svg}")
    pg.wait_for_timeout(300)
    total = pg.evaluate("Math.max(0, ...document.getAnimations().map(a => a.effect.getComputedTiming().duration))")
    for i, frac in enumerate([0, .15, .3, .45, .6, .75, .9]):
        pg.evaluate("t => document.getAnimations().forEach(a => { a.pause(); a.currentTime = t; })", total * frac)
        pg.screenshot(path=f"{out}_frame{i}.png")
    b.close()
```

Then open the PNG frames and check:
- No text is cut off, overlapping other text, or outside its box
- Pointers/arrows sit on the correct cells in each frame
- The active cell highlight and the caption change together
- Nothing important is invisible for the whole loop (opacity never reaches 1)
- Frame 0 and the last frame look the same (seamless loop)
- It stays readable at small size (view at about 400px wide, as on a phone)
- It is readable on both a white and a dark page background (the diagram draws its own dark background rect)

If a browser is not available, say so in the report and do a careful manual read of coordinates instead. Do not claim a visual check you did not do.

### Layer 3: Semantic check against the solution code (most important)

For each `02-dry-run.svg`:

1. **Read the solution code** in the folder (never the notes alone).
2. **Identify the example input** used in the SVG (from its text) and confirm it is the same example as in `notes.md` section 5.
3. **Execute the code by hand (or really run it)** on that input and write a trace table, one row per loop iteration:

```
step | variables before            | decision taken                  | data structure after      | output so far
1    | i=0 num=1  set={}           | not in set -> insert            | set={1}                   | -
2    | i=1 num=2  set={1}          | not in set -> insert            | set={1,2}                 | -
...
```

   Where possible, actually run the solution on the input to confirm the final answer (add temporary prints in a scratch copy, do not edit the user's file).
4. **Compare the trace to the SVG step by step:**
   - Number of animated steps equals the number of meaningful loop iterations (or clearly grouped, with a caption saying so)
   - Pointer/variable positions in each step equal the trace values (`left`, `right`, `mid`, `i`, window bounds)
   - Data structure contents after each step equal the trace (map entries, stack contents and push/pop order, deque contents, set members, counters)
   - Each caption describes what THIS code does, using its real conditions (for example "sum > target -> right--", not a generic sentence)
   - Order of operations matches the code (for example Product Except Self: store `pre` BEFORE multiplying; RPN: first pop is the right operand)
   - The final returned value in the SVG equals the real output
   - Edge conditions in the code that fire on this example (duplicate skip, early break, guard checks) are shown, not skipped
5. **Check algorithm identity.** The SVG must show the user's approach (for example sliding window with a set that shrinks in a `while`), not a different textbook variant (for example the hash-map-with-last-index version).
6. For `01-overview.svg`: the single idea shown must be true for this code and match notes.md section 3. For `03-complexity.svg`: the Big-O labels must match the Time/Space in notes.md and in the code's closing comment; the brute force shown must be the brute force described in notes.md.

Pattern-specific things to verify:

| Pattern | Must be correct in the diagram |
|---|---|
| Hash map / set | lookup happens BEFORE insert if the code does that; hit/miss colors match |
| Two pointers | which pointer moves for each comparison result; stop condition `left<right` |
| Sliding window | when the window grows vs shrinks; `while` shrink repeats multiple times if code uses `while`; best-so-far updates only where the code updates it |
| Stack | push/pop order, empty-stack case, what is compared with the top |
| Monotonic stack/deque | stores indices or values as the code does; pops happen under the code's exact condition |
| Binary search | `mid` formula, which half is discarded, final index |
| Prefix/suffix | two separate passes, direction of each pass, update order |
| Backtracking | build, recurse, undo; the constraint that prunes branches |

### Layer 4: notes.md integration check

- Every `![...](diagrams/xxx.svg)` in `notes.md` points to a file that exists (relative path, correct case and spacing in folder names)
- Every SVG in `diagrams/` is referenced from `notes.md` (no orphan files)
- Images sit under the right section (overview under Intuition, dry-run under Optimal Approach, complexity under Complexity/Brute Force)
- Alt text is meaningful (not empty)
- The solution file was not modified (compare with git: `git diff --stat -- "<folder>/solution.*"` should be empty)

## Fixing

By default report only. If the user asked to fix, then:
1. Fix ERRORS first, then semantic mismatches, then warnings.
2. Edit the SVG minimally; keep the visual style, palette, and file names. Do not redraw from scratch unless the algorithm shown is wrong.
3. Re-run Layer 1 (and Layer 2 if available) after each fix, and re-check the semantic trace for the changed steps.
4. Never edit the solution code, and do not change numbers in notes.md to match a wrong diagram; if notes.md and the code disagree, tell the user.

## Report format

Give one block per problem, then a summary table. Be specific, with file and step references. Example:

```
### 1- Contains Duplicate
diagrams/02-dry-run.svg   FAIL
  [semantic] Step 3 shows set={1,2} but code has inserted 3 by then (set={1,2,3}).
  [semantic] Caption in step 4 says "found in map" but the code uses a set.
  [static]   warn: loop is 6.0s (target 8-14s)
  [visual]   not checked (no browser available)
diagrams/01-overview.svg  PASS
notes.md links            PASS
```

Summary table:

| # | Problem | Static | Visual | Semantic | Links | Result |
|---|---|---|---|---|---|---|
| 1 | Contains Duplicate | pass | pass | FAIL (2) | pass | FAIL |

Use these result labels only: PASS (no errors, no semantic mismatches, warnings acceptable), PASS WITH WARNINGS, FAIL. Mark any layer you did not run as "not checked", never as pass.

## Workflow

1. Verify problems 1, 2, 3 first and show the report.
2. Continue in batches of 5 problems, then give the final summary table with counts of passed, warned, and failed.
3. If a folder has no diagrams or no solution code, list it as skipped.
4. Do not assume a diagram is right because it looks right. The trace comparison is mandatory for every dry-run.