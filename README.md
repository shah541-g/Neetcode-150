# NeetCode 150 — C++ Solutions and Study Notes

A personal DSA study repository with C++ solutions, problem-by-problem notes, animated diagrams, and a Roman Urdu revision guide.

> **Coverage:** `Source Code/` currently has 54 problem folders. The PDF contains 55 study entries; it is a growing guide, not a claim that all 150 NeetCode problems are complete.

## What’s inside

- [`Source Code/`](<Source Code/>) — one folder per coded problem. Each folder contains a C++ solution, an English `notes.md`, and two SVG diagrams:
  - `diagrams/01-overview.svg` — visual summary of the approach.
  - `diagrams/02-dry-run.svg` — animated walk-through of an example.
- [`Content/NeetCode150.pdf`](Content/NeetCode150.pdf) — Roman Urdu explanations, solution code, complexity analysis, part recaps, a pattern map, and an STL cheat sheet.

Folder numbers are this repository’s ordering, not LeetCode problem numbers. The PDF headings use LeetCode IDs; folder names and notes identify the repository problem.

## How to study a problem

1. Choose a folder under `Source Code/` and try the problem before reading the explanation.
2. Read its `.cpp` file first. It is the source of truth for the implementation.
3. Use `notes.md` to review the pattern, intuition, dry run, complexity, edge cases, and pitfalls.
4. Open the diagrams from the notes to see the approach and its example execution.
5. Use the PDF for Roman Urdu revision, pattern connections, and STL references.

For example: [Contains Duplicate](<Source Code/1- Contains Duplicate/>).

## Running a solution

Install a C++ compiler such as GCC/MinGW. Most solution files include a local `main()` and test cases, so compile **one problem file at a time**. From the repository root in PowerShell:

```powershell
g++ -std=c++17 ".\Source Code\1- Contains Duplicate\1- Contains Duplicate.cpp" -o ".\contains-duplicate.exe"
.\contains-duplicate.exe
```

For a LeetCode submission, use the class and method expected by that problem and omit the local `main()` harness. Use LeetCode’s provided list/tree types where applicable.

## Notes about coverage

- There is no separate source folder for **Generate Parentheses (#22)**, although it appears as a study entry in the PDF.
- The folder [`45- Subtree of Another Tree`](<Source Code/45- Subtree of Another Tree/>) is named for LeetCode #572, but its C++ method compares two complete trees (`Same Tree`, #100). The notes and PDF call out this mismatch; check the source before relying on the folder name.

