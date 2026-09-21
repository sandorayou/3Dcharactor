"""Compile and execute the iOS bridge's actual portable privacy pixel core.

Usage: python -B Tools/test_native_privacy.py --cc /path/to/tcc-or-clang
Apple framework integration still requires an iOS build/device.
"""
import argparse
from pathlib import Path
import shutil
import subprocess
import tempfile


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cc", default=shutil.which("clang") or shutil.which("gcc") or shutil.which("tcc"))
    args = parser.parse_args()
    if not args.cc:
        parser.error("A C compiler is required; pass --cc.")
    bridge = (Path(__file__).resolve().parents[1] / "Assets/Plugins/iOS/NativePoseBridge.mm").read_text()
    core = bridge.split("// BEGIN PORTABLE PRIVACY CORE", 1)[1].split("\n", 1)[1].split("// END PORTABLE PRIVACY CORE", 1)[0]
    harness = r'''
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <assert.h>
CORE
int main(void) {
    assert(PrivacySkinPixel(200,150,110));
    assert(PrivacySkinPixel(150,100,80));
    assert(!PrivacySkinPixel(255,255,255));
    assert(!PrivacySkinPixel(240,230,220));
    assert(!PrivacySkinPixel(100,100,100));
    assert(!PrivacySkinPixel(0,0,0));
    assert(!PrivacySkinPixel(60,40,30));
    assert(!PrivacySkinPixel(0,0,255));
    // Skin outside the expanded bones is untouched; bone-only white and
    // antialiased white edge pixels remain untouched even next to skin.
    unsigned char bone[] = {255, 0, 255, 255, 128, 64};
    unsigned char skin[] = {255, 255, 0, 255, 0, 255};
    const unsigned char expected[] = {255, 0, 0, 255, 0, 64};
    IntersectPrivacyMask(bone, skin, 6);
    for (int i = 0; i < 6; ++i) assert(bone[i] == expected[i]);
    // Exhaustive neutral ramp stays excluded at every bone coverage value.
    for (int gray = 0; gray < 256; ++gray) {
        assert(!PrivacySkinPixel(gray,gray,gray));
        for (int coverage = 0; coverage < 256; ++coverage) {
            unsigned char value = coverage, neutral = 0;
            IntersectPrivacyMask(&value, &neutral, 1);
            assert(value == 0);
        }
    }
    return 0;
}
'''.replace("CORE", core)
    with tempfile.TemporaryDirectory(prefix="native-privacy-test-") as directory:
        source = Path(directory) / "privacy.c"
        binary = Path(directory) / "privacy.exe"
        source.write_text(harness)
        result = subprocess.run([args.cc, str(source), "-o", str(binary)], capture_output=True, text=True, timeout=12)
        if result.returncode:
            raise RuntimeError((result.stdout + result.stderr)[-6000:])
        subprocess.run([str(binary)], check=True, timeout=5)
    # Check that production consumes the tested function after bone rasterization
    # and never scales/dilates/unions its output with an earlier-frame mask.
    pose = bridge.split("static CIImage *CurrentPosePrivacyMask", 1)[1].split("static CIImage *WindowsStyleMosaic", 1)[0]
    assert pose.index("CGContextFlush(context)") < pose.index("IntersectPrivacyMask(") < pose.index("CGBitmapContextCreateImage(context)")
    assert "CGAffineTransformMakeScale" not in pose
    assert "CIMorphology" not in bridge and "CIMaximumCompositing" not in bridge
    assert 'CurrentPosePrivacyMask(result, source.extent, captured[@"privacy"])' in bridge
    assert "mask[y * width + x] = PrivacySkinPixel" in bridge
    assert "CIColor colorWithRed:0 green:0 blue:0" in bridge
    print("PASS: compiled native skin/intersection core; neutral ramp, bone-only, skin-only, edge exclusion; frame/fail-closed wiring")


if __name__ == "__main__":
    main()
