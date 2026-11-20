---
name: leetcode-visual-notes
description: Add animated SVG diagrams and motion visuals to existing LeetCode notes.md files. Use when asked to visualize, animate, or add diagrams to a problem's notes or solution (pointer movement, hash map filling, stack push/pop, sliding window, binary search shrinking, etc.).
---

# LeetCode Visual Notes

Turn each problem's `notes.md` into a visual explanation by adding animated SVG diagrams that show how the solution runs. Diagrams must be based ONLY on the solution code in that folder. Never invent behavior the code does not have.

## Output layout

For every problem folder, e.g. `1- Contains Duplicate/`:

```
1- Contains Duplicate/
  solution.<ext>        (existing, do not touch)
  notes.md              (existing, edit to embed diagrams)
  diagrams/
    01-overview.svg     static or lightly animated "big picture"
    02-dry-run.svg      step-by-step animated walkthrough of the code
    03-complexity.svg   (optional) brute force vs optimal comparison
```

Embed in `notes.md` with normal image syntax so it renders in the VS Code preview and on GitHub:

```md
![Dry run](diagrams/02-dry-run.svg)
```

Do not rewrite the existing text of notes.md. Only insert images under the matching sections:

| Section in notes.md        | Diagram to add                                   |
|----------------------------|--------------------------------------------------|
| 3. Intuition               | 01-overview.svg (the key idea in one picture)    |
| 5. Optimal Approach        | 02-dry-run.svg (animated step-by-step run)       |
| 4/7. Brute Force / Complexity | 03-complexity.svg (optional comparison)       |

## Technical rules for every SVG

- Single self-contained file. No external fonts, images, scripts, or links. NO JavaScript (it does not run when SVG is used via `<img>` or in the markdown preview).
- Always set `viewBox` (use `0 0 800 360` by default). Do not set fixed width/height.
- Use CSS `@keyframes` inside a `<style>` block (default). Use SMIL (`<animate>`, `<animateTransform>`) only if CSS cannot do it.
- For any transform on an SVG element add: `transform-box: fill-box; transform-origin: center;`
- Animate only `transform`, `opacity`, `stroke-dashoffset`, and `fill`/`stroke`.
- The dry run is a looping timeline: total loop 8-14 seconds, `animation-iteration-count: infinite`, first and last keyframe identical so the loop is seamless. Add a 1-1.5s pause at the end before restarting.
- Add `role="img"` and a `<title>` describing the diagram.
- Support reduced motion: `@media (prefers-reduced-motion: reduce) { * { animation: none !important; } }`
- Readable in both light and dark themes: do not rely on a transparent background for contrast. Draw a rounded background `<rect>` (fill `#0f172a`) and use light text on it.
- Font: `font-family: ui-monospace, Menlo, Consolas, monospace;` for array values and code, sans-serif for captions. Minimum font size 14.

## Palette (use consistently across all problems)

```
background   #0f172a
card/cell    #1e293b
cell border  #475569
text         #e2e8f0
muted text   #94a3b8
primary      #38bdf8   (current element / left pointer)
secondary    #f59e0b   (right pointer / second pointer)
success      #22c55e   (match found / valid / answer)
danger       #ef4444   (mismatch / duplicate / pop / discard)
accent       #a78bfa   (stack / map / extra data structure)
```

## How to build the dry-run animation

1. Read the solution code and pick ONE small example input (5-8 elements max). Prefer the example already used in notes.md section 5.
2. Draw the input as a row of boxes (array/string cells) with index labels under them.
3. Draw every data structure the code uses next to the array: hash map/set as a table of key/value rows, stack as a vertical column, queue/deque as a horizontal row, result as a separate row.
4. Show each pointer or variable (`i`, `left`, `right`, `mid`, `window`) as a labeled arrow or bracket that MOVES between cells using `transform: translateX()`. Never redraw it in a new place; move it.
5. Split the timeline into one step per loop iteration of the code. For each step:
   - highlight the active cell (primary color, slight scale up 1 to 1.1)
   - show a one-line caption of what the code is doing at the bottom (swap caption text by fading `opacity` in and out per step)
   - animate data structure changes (new map row slides in, stack item drops in from the top, popped item fades out in danger color)
6. End on the final answer: flash the answer in success color and show the return value.
7. Add a small step counter at the top right ("Step 3 / 7") if there are more than 4 steps.

Implement step timing with CSS variables so it is easy to edit:

```css
:root { --step: 1.4s; --total: 11s; }
.step3 { animation: show3 var(--total) infinite; }
@keyframes show3 { 0%,28%{opacity:0} 30%,50%{opacity:1} 52%,100%{opacity:0} }
```

Use `animation-delay: calc(var(--i) * 0.1s)` (with `style="--i:N"`) to stagger repeated elements such as map rows.

## Diagram recipes by pattern

**Hash Map / Hash Set** (Contains Duplicate, Two Sum, Valid Anagram, Group Anagrams, Top K Frequent)
Array on top. Map as a table on the right. Each step: pointer moves, the lookup is shown as a short line from the current cell to the map; a hit flashes success/danger, a miss inserts a new row sliding in from the left.

**Two Pointers** (Valid Palindrome, Two Sum II, 3Sum, Container With Most Water, Trapping Rain Water)
Left arrow (primary) and right arrow (secondary) moving toward each other. Show the current comparison or sum between them in a small label. Shade the range still being searched; dim the discarded range. For Container With Most Water, draw bars and animate the water rectangle between the pointers. For Trapping Rain Water, fill trapped water cells in a blue color rising from 0 height.

**Sliding Window** (Buy and Sell Stock, Longest Substring Without Repeating, Longest Repeating Character Replacement, Permutation in String, Minimum Window Substring, Sliding Window Maximum)
Draw the window as a translucent rounded rectangle that EXPANDS (right edge moves) and SHRINKS (left edge moves) over the cells. Show the current window contents/count map beside it. Color the window success when valid, danger when it must shrink. Show best-so-far value updating. For Sliding Window Maximum, also draw the deque and animate pops from the back and front.

**Stack** (Valid Parentheses, MinStack, Evaluate Reverse Polish Notation, Daily Temperatures, Car Fleet, Largest Rectangle in Histogram)
Vertical stack on the right: push = item drops in from above, pop = item lifts out and fades in danger color. Input tokens on the left with a pointer. For monotonic stacks, show the comparison that causes the pop. For MinStack, show two columns (values and running min).

**Binary Search**
Draw cells with `left`, `mid`, `right` markers. Each step the discarded half dims to 25% opacity and the markers slide. Show the comparison caption ("nums[mid] < target, move left"). End by flashing the found index.

**Prefix / Suffix** (Product Except Self)
Three rows: input, prefix pass (left to right fills with a sweeping highlight), suffix pass (right to left), and final result. Animate the sweep as a moving highlight bar.

**Sudoku / Grid problems**
Draw the grid, highlight the row, column, and 3x3 box being checked in turn, and flash danger on a conflict.

**Longest Consecutive Sequence**
Show numbers as unordered bubbles in a set, then animate a chain forming (line-draw with `stroke-dashoffset`) from the start of each sequence only.

## Overview diagram (01-overview.svg)

One picture that captures the intuition: the key trick, not the full run. Examples: "check seen set before inserting", "move the smaller side inward", "stack keeps only decreasing temperatures". Keep it nearly static: allow at most subtle motion (a pulse on the key element, a line-draw on arrows). Include a one-line title at the top.

## Complexity diagram (03-complexity.svg), optional

Two horizontal bars on the same scale, brute force vs optimal, with labels like `O(n^2)` and `O(n)`. Animate the bars growing from 0 with a springy ease (`cubic-bezier(.34,1.56,.64,1)`). Only add when it clarifies the improvement.

## Quality checklist before finishing each problem

- [ ] Diagram steps match the real execution order of MY code (not a textbook version)
- [ ] Example input is small and the same one used in the text
- [ ] Every pointer and data structure in the code appears in the diagram
- [ ] Loop is seamless and total duration is 8-14s
- [ ] Text is at least 14px and does not overflow its box (shorten captions instead of shrinking font)
- [ ] Colors follow the palette; no external resources; no JavaScript
- [ ] Image paths in notes.md are correct and relative (`diagrams/...`)
- [ ] SVG is valid XML (all tags closed, `&` escaped as `&amp;`, `<` in text as `&lt;`)

## Workflow

1. Do problems 1, 2, 3 first. Show the result and ask for confirmation of the visual style before continuing.
2. Then continue in batches of 5 problems.
3. If a folder has no code or no notes.md, skip it and list it at the end.
4. Never modify the solution code files.