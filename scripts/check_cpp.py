import os
import subprocess
import sys
from collections import defaultdict
from pathlib import Path
from tempfile import TemporaryDirectory


def exercise_for(src):
    parts = src.parts
    if parts[0] == "project" and len(parts) >= 3:
        return Path(*parts[:2])           # project/week13_mudgame/
    if parts[0] in {"practice", "challenge"}:
        if len(parts) >= 4:
            return Path(*parts[:3])       # practice/week13/actions_test/
        return src                        # practice/week13/animal_virtual.cpp
    return src.parent                     # 그 밖의 위치는 같은 폴더끼리 검사


os.chdir(Path(__file__).resolve().parents[1])
tracked = subprocess.check_output(["git", "ls-files", "-z"]).split(b"\0")
exercises = defaultdict(list)
for name in tracked:
    if name.lower().endswith(b".cpp"):
        src = Path(os.fsdecode(name))
        exercises[exercise_for(src)].append(src)
if not exercises:
    sys.exit("No tracked .cpp files found.")

failures = []
compiled = 0
linked = 0
with TemporaryDirectory() as tmp:
    for exercise, sources in exercises.items():
        base = exercise.parent if exercise.is_file() else exercise
        mains, helpers = [], []

        for src in sources:
            obj = (Path(tmp) / src).with_suffix(".o")
            obj.parent.mkdir(parents=True, exist_ok=True)
            print(f"[compile] {src}", flush=True)
            cmd = [
                "g++", "-std=c++17", "-Wall", "-Wextra", "-x", "c++",
                "-I", base, "-I", base / "include", "-c", src.resolve(), "-o", obj,
            ]
            if subprocess.run(cmd).returncode:
                failures.append(f"COMPILE FAILED: {src}")
                continue
            compiled += 1
            symbols = subprocess.check_output(["nm", "-g", "--defined-only", "-j", obj])
            if b"main" in symbols.splitlines():
                mains.append((src, obj))
            else:
                helpers.append(obj)

        if len(mains) + len(helpers) != len(sources):
            print(f"[skip link] {exercise} (compile error)", flush=True)
            continue
        if not mains:
            failures.append(f"NO MAIN: {exercise}")

        for src, obj in mains:
            print(f"[link] {src}", flush=True)
            cmd = ["g++", obj, *helpers, "-o", obj.with_suffix(".exe")]
            if subprocess.run(cmd).returncode:
                failures.append(f"LINK FAILED: {src}")
            else:
                linked += 1

total = sum(len(sources) for sources in exercises.values())
print(f"Compiled {compiled}/{total} .cpp files. Linked {linked} executable(s).")
for failure in failures:
    print(failure)
sys.exit(1 if failures else 0)