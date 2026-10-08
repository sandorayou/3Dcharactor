#!/usr/bin/env python3
"""Apply current iOS viewport and head-mirror behavior to the saved IL2CPP export."""

from __future__ import annotations

import argparse
from pathlib import Path
import re


def replace_once(text: str, old: str, new: str, label: str) -> str:
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"Expected one {label} anchor, found {count}")
    return text.replace(old, new, 1)


def verify_patched(root: Path) -> None:
    source_dir = root / "Il2CppOutputProject" / "Source" / "il2cppOutput"
    driver = (source_dir / "Assembly-CSharp.cpp").read_text(encoding="utf-8")
    streaming = (source_dir / "Assembly-CSharp__1.cpp").read_text(encoding="utf-8")
    method_match = re.search(
        r"IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSLiveStreaming_Install_m[^\n]*\n\{.*?\n\}",
        streaming,
        re.DOTALL,
    )
    if method_match is None:
        raise SystemExit("Patched IOSLiveStreaming.Install method not found")
    method = method_match.group(0)
    if "GameObject_AddComponent_TisIOSLiveStreaming_" not in method:
        raise SystemExit("Streaming toolbar installation was lost")
    if "Camera_set_rect_" in method or "Camera_get_allCameras_" in method:
        raise SystemExit("Camera viewport resize remains in IOSLiveStreaming.Install")
    if "bool L_11 = false;" not in driver:
        raise SystemExit("Head rotation mirror remains enabled")
    if "___mirrorHeadRotation = (bool)0;" not in driver:
        raise SystemExit("Head rotation mirror default remains enabled")


def patch_export(root: Path, write: bool) -> None:
    source_dir = root / "Il2CppOutputProject" / "Source" / "il2cppOutput"
    driver = source_dir / "Assembly-CSharp.cpp"
    streaming = source_dir / "Assembly-CSharp__1.cpp"
    if not driver.is_file() or not streaming.is_file():
        raise SystemExit(f"IL2CPP source files not found under {source_dir}")

    driver_text = driver.read_text(encoding="utf-8")
    driver_text = replace_once(
        driver_text,
        "bool L_11 = __this->___mirrorHeadRotation;\n\t\tif (!L_11)",
        "bool L_11 = false;\n\t\tif (!L_11)",
        "head mirror condition",
    )
    driver_text = replace_once(
        driver_text,
        "__this->___mirrorHeadRotation = (bool)1;",
        "__this->___mirrorHeadRotation = (bool)0;",
        "head mirror default",
    )

    stream_text = streaming.read_text(encoding="utf-8")
    method_pattern = re.compile(
        r"IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSLiveStreaming_Install_m[^\n]*\n\{.*?\n\}",
        re.DOTALL,
    )
    match = method_pattern.search(stream_text)
    if match is None:
        raise SystemExit("IOSLiveStreaming.Install method not found in IL2CPP output")
    method = match.group(0)
    if method.count("Camera_get_allCameras_") != 1 or method.count("Camera_set_rect_") != 1:
        raise SystemExit("Expected one iOS camera viewport resize in Install")
    component_call = method.find("L_2 = GameObject_AddComponent_TisIOSLiveStreaming_")
    if component_call < 0:
        raise SystemExit("IOS streaming component installation not found")
    component_call_end = method.find("\n", component_call)
    if component_call_end < 0 or component_call_end >= method.find("Camera_get_allCameras_"):
        raise SystemExit("Could not isolate camera viewport loop after component installation")
    patched_method = method[:component_call_end] + "\n\treturn;\n}"
    stream_text = stream_text[: match.start()] + patched_method + stream_text[match.end() :]

    if write:
        driver.write_text(driver_text, encoding="utf-8", newline="\n")
        streaming.write_text(stream_text, encoding="utf-8", newline="\n")
        verify_patched(root)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("export", type=Path, help="Extracted Unity iOS Xcode export")
    parser.add_argument("--check", action="store_true", help="Validate anchors without writing")
    args = parser.parse_args()
    patch_export(args.export, write=not args.check)
    print("iOS viewport resize removed; head rotation mirror disabled")


if __name__ == "__main__":
    main()
