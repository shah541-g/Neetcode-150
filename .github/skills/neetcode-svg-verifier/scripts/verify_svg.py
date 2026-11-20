#!/usr/bin/env python3
"""
Static verifier for NeetCode animated SVG diagrams.

Usage:
  python verify_svg.py <svg-or-folder> [--kind dry-run|overview|complexity] [--json]
Exit code: 0 = no errors, 1 = at least one ERROR (warnings do not fail).
"""
import sys, re, json, argparse
from pathlib import Path
import xml.etree.ElementTree as ET

PALETTE = {
    "#0f172a", "#1e293b", "#475569", "#e2e8f0", "#94a3b8",
    "#38bdf8", "#f59e0b", "#22c55e", "#ef4444", "#a78bfa",
    "#ffffff", "#000000", "none", "transparent", "currentcolor", "inherit",
}
NAMED_OK = {"white", "black", "none", "transparent", "currentcolor", "inherit"}
SVG_NS = "{http://www.w3.org/2000/svg}"


def strip(tag):
    return tag.split("}", 1)[-1]


def to_seconds(v):
    v = v.strip()
    if v.endswith("ms"):
        return float(v[:-2]) / 1000
    if v.endswith("s"):
        return float(v[:-1])
    return None


def norm_hex(c):
    c = c.lower()
    if re.fullmatch(r"#[0-9a-f]{3}", c):
        c = "#" + "".join(ch * 2 for ch in c[1:])
    return c


def parse_keyframes(css):
    """Return {name: [(percent_float, declaration_string), ...]}"""
    out = {}
    for m in re.finditer(r"@keyframes\s+([\w-]+)\s*\{", css):
        name, i, depth = m.group(1), m.end(), 1
        start = i
        while i < len(css) and depth:
            depth += {"{": 1, "}": -1}.get(css[i], 0)
            i += 1
        body = css[start:i - 1]
        frames = []
        for fm in re.finditer(r"([\d.%,\s]+|from|to)\s*\{([^}]*)\}", body):
            decl = re.sub(r"\s+", "", fm.group(2)).rstrip(";")
            for sel in fm.group(1).split(","):
                sel = sel.strip()
                if not sel:
                    continue
                p = {"from": 0.0, "to": 100.0}.get(sel)
                if p is None:
                    try:
                        p = float(sel.rstrip("%"))
                    except ValueError:
                        continue
                frames.append((p, decl))
        out[name] = sorted(frames)
    return out


def verify(path: Path, kind: str):
    errors, warns, info = [], [], []
    E, W, I = errors.append, warns.append, info.append

    raw = path.read_text(encoding="utf-8", errors="replace")
    size_kb = len(raw.encode()) / 1024
    I(f"size: {size_kb:.1f} KB")
    if size_kb > 150:
        W(f"file is large ({size_kb:.0f} KB); simplify or reuse shapes with <use>")

    # 1. well-formed XML
    try:
        root = ET.fromstring(raw)
    except ET.ParseError as e:
        return [f"invalid XML: {e} (check unclosed tags, unescaped & or <)"], warns, info
    if strip(root.tag) != "svg":
        E("root element is not <svg>")
        return errors, warns, info

    # 2. viewBox
    vb = root.get("viewBox")
    vbw = vbh = None
    if not vb:
        E("missing viewBox on <svg>")
    else:
        try:
            _, _, vbw, vbh = [float(x) for x in vb.replace(",", " ").split()]
            I(f"viewBox: {vb}")
        except ValueError:
            E(f"bad viewBox value: {vb}")
    if root.get("width") or root.get("height"):
        W("fixed width/height on <svg>; prefer viewBox only so it scales")

    # 3. accessibility
    if root.get("role") != "img":
        W('missing role="img" on <svg>')
    if not any(strip(e.tag) == "title" for e in root):
        W("missing <title> as a direct child of <svg>")

    # 4. forbidden content
    for el in root.iter():
        t = strip(el.tag)
        if t in ("script", "foreignObject"):
            E(f"<{t}> is not allowed (does not run/render in markdown <img>)")
        for a, v in el.attrib.items():
            a_l = strip(a).lower()
            if a_l.startswith("on"):
                E(f"event handler attribute '{a_l}' on <{t}>")
            if a_l in ("href", "src") and re.match(r"\s*(https?:)?//", v):
                E(f"external reference in <{t} {a_l}>: {v[:60]}")
    if re.search(r"@import|url\(\s*['\"]?https?:", raw):
        E("external @import / url(http...) found (must be self-contained)")
    if re.search(r"<image[^>]+href=['\"](?!data:|#)", raw):
        E("<image> with non-data URI (no external assets allowed)")

    # 5. css
    css = "\n".join((el.text or "") for el in root.iter() if strip(el.tag) == "style")
    smil = [e for e in root.iter() if strip(e.tag) in ("animate", "animateTransform", "animateMotion", "set")]
    keyframes = parse_keyframes(css)
    animated = bool(keyframes or smil)
    if kind == "dry-run" and not animated:
        E("dry-run diagram has no animation (@keyframes or SMIL)")

    if animated and not re.search(r"prefers-reduced-motion", css):
        E("missing @media (prefers-reduced-motion: reduce) block")

    # animation names referenced must exist
    for nm in re.findall(r"animation(?:-name)?\s*:\s*([\w-]+)", css):
        if nm not in keyframes and nm not in ("none", "infinite", "linear", "ease", "initial", "inherit"):
            # might be shorthand beginning with a duration; skip numeric starts
            if not re.match(r"^\d", nm):
                W(f"animation references '{nm}' but no @keyframes of that name found")

    # keyframe loop seamlessness
    for name, frames in keyframes.items():
        if not frames:
            continue
        if frames[0][0] != 0.0 or frames[-1][0] != 100.0:
            W(f"@keyframes {name}: should define 0% and 100%")
        elif frames[0][1] != frames[-1][1]:
            W(f"@keyframes {name}: first and last frame differ, loop may jump")

    # durations
    durs = []
    for m in re.finditer(r"animation(?:-duration)?\s*:[^;{}]*", css):
        for tok in re.findall(r"(?<![\w.-])(\d*\.?\d+m?s)\b", m.group(0)):
            s = to_seconds(tok)
            if s is not None:
                durs.append(s)
    for m in re.finditer(r"--(?:total|duration|loop)\s*:\s*([\d.]+m?s)", css):
        s = to_seconds(m.group(1))
        if s:
            durs.append(s)
    for e in smil:
        d = e.get("dur")
        if d and d != "indefinite":
            s = to_seconds(d)
            if s:
                durs.append(s)
    if durs:
        longest = max(durs)
        I(f"longest animation duration: {longest:.1f}s")
        if kind == "dry-run" and not (8 <= longest <= 14):
            W(f"dry-run loop is {longest:.1f}s; target 8-14s")
        if kind == "overview" and longest > 6:
            W(f"overview should be near-static; found {longest:.1f}s animation")

    if animated and not re.search(r"infinite|repeatCount=['\"]indefinite", css + raw) and kind == "dry-run":
        W("dry-run does not loop (no infinite iteration)")

    # transform origin
    if re.search(r"transform", "".join(f[1] for fs in keyframes.values() for f in fs)) \
            and "transform-box" not in css:
        W("transforms are animated but 'transform-box: fill-box' not set (pivot bug)")

    # animating layout-like properties
    bad_props = re.findall(r"\b(width|height|cx|cy|x|y|r)\s*:", "".join(f[1] for fs in keyframes.values() for f in fs))
    if bad_props:
        W(f"keyframes animate {sorted(set(bad_props))}; prefer transform/opacity/stroke-dashoffset")

    # 6. palette
    colors = set()
    for m in re.finditer(r"#[0-9a-fA-F]{3,8}\b", raw):
        colors.add(norm_hex(m.group(0)))
    for el in root.iter():
        for a in ("fill", "stroke", "stop-color"):
            v = el.get(a)
            if v and not v.startswith(("url(", "#")) and v.lower() not in NAMED_OK:
                colors.add(v.lower())
    off = sorted(c for c in colors if c not in PALETTE and not re.fullmatch(r"#[0-9a-f]{8}", c))
    if off:
        W(f"colors outside the palette: {', '.join(off[:8])}")

    # 7. font sizes
    sizes = []
    for m in re.finditer(r"font-size\s*[:=]\s*['\"]?([\d.]+)(px|pt)?", raw):
        v = float(m.group(1))
        if m.group(2) == "pt":
            v *= 1.333
        sizes.append(v)
    if sizes:
        I(f"font sizes: min {min(sizes):g}, max {max(sizes):g}")
        if min(sizes) < 14:
            W(f"font-size {min(sizes):g}px is below the 14px minimum")
    else:
        W("no explicit font-size found; text may be tiny/huge")

    # 8. geometry / text overflow (heuristic, static x/y only)
    if vbw and vbh:
        def num(v):
            try:
                return float(re.sub(r"[a-z%]+$", "", v))
            except Exception:
                return None
        for el in root.iter():
            t = strip(el.tag)
            if t == "rect":
                x, y, w, h = (num(el.get(k, "0")) or 0 for k in ("x", "y", "width", "height"))
                if x < -1 or y < -1 or x + w > vbw + 1 or y + h > vbh + 1:
                    if el.get("transform") is None:
                        W(f"<rect> extends outside viewBox (x={x:g}, y={y:g}, w={w:g}, h={h:g})")
            if t == "text":
                txt = "".join(el.itertext()).strip()
                x, y = num(el.get("x", "0")), num(el.get("y", "0"))
                fs = num(el.get("font-size", "16")) or 16
                if x is None or y is None or not txt:
                    continue
                est = len(txt) * fs * 0.6
                anchor = el.get("text-anchor", "start")
                left = x if anchor == "start" else x - est / 2 if anchor == "middle" else x - est
                if left < -1 or left + est > vbw + 1:
                    if el.get("transform") is None:
                        W(f"text may overflow viewBox: '{txt[:40]}' (~{est:.0f}px wide)")
                if y > vbh + 1 or y < -1:
                    if el.get("transform") is None:
                        W(f"text outside viewBox vertically: '{txt[:40]}'")

    # 9. dry-run content hints
    if kind == "dry-run":
        texts = " ".join("".join(e.itertext()) for e in root.iter() if strip(e.tag) == "text")
        if not re.search(r"step\s*\d", texts, re.I) and len(keyframes) > 4:
            W('no "Step N / M" counter found (recommended when more than 4 steps)')
        if not re.search(r"(answer|return|result|true|false|\[\s*\d)", texts, re.I):
            W("no visible final answer/return value text found")
        if not re.search(r"(//|->|=>|==|<=|>=|<|>)", texts) and len(texts) < 40:
            W("very little caption text; each step should show what the code is doing")

    return errors, warns, info


def guess_kind(p: Path):
    n = p.name.lower()
    if "dry" in n:
        return "dry-run"
    if "overview" in n:
        return "overview"
    if "complex" in n:
        return "complexity"
    return "dry-run"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("--kind", choices=["dry-run", "overview", "complexity"])
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    t = Path(a.target)
    files = sorted(t.rglob("*.svg")) if t.is_dir() else [t]
    if not files:
        print("no .svg files found")
        sys.exit(1)

    results, failed = [], False
    for f in files:
        kind = a.kind or guess_kind(f)
        e, w, i = verify(f, kind)
        failed |= bool(e)
        results.append({"file": str(f), "kind": kind, "errors": e, "warnings": w, "info": i})

    if a.json:
        print(json.dumps(results, indent=2))
    else:
        for r in results:
            status = "FAIL" if r["errors"] else ("WARN" if r["warnings"] else "PASS")
            print(f"[{status}] {r['file']} ({r['kind']})")
            for x in r["info"]:
                print(f"    info  {x}")
            for x in r["errors"]:
                print(f"    ERROR {x}")
            for x in r["warnings"]:
                print(f"    warn  {x}")
        n_f = sum(1 for r in results if r["errors"])
        print(f"\n{len(results)} file(s): {n_f} failed, "
              f"{sum(1 for r in results if not r['errors'] and r['warnings'])} with warnings")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()