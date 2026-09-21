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
    assert(!PrivacyEligiblePixel(255,255,255));
    assert(!PrivacyEligiblePixel(220,220,220));
    assert(PrivacyEligiblePixel(40,40,40)); // eye/hair detail remains covered
    // Skin outside the expanded bones is untouched; bone-only white and
    // antialiased white edge pixels remain untouched even next to skin.
    unsigned char bone[] = {255, 0, 255, 255, 128, 64};
    unsigned char skin[] = {255, 255, 0, 255, 0, 255};
    const unsigned char expected[] = {255, 0, 0, 255, 0, 64};
    IntersectPrivacyMask(bone, skin, 6);
    for (int i = 0; i < 6; ++i) assert(bone[i] == expected[i]);
    // Same-frame skin seeds expand to nearby dark facial features, while a
    // light achromatic background stays excluded from the final mask.
    unsigned char faceBone[49], faceSkin[49] = {0}, faceEligible[49], faceHorizontal[49] = {0}, faceOutput[49] = {0};
    for (int i = 0; i < 49; ++i) { faceBone[i] = 255; faceEligible[i] = 255; }
    faceSkin[24] = 255;
    faceEligible[0] = 0; faceEligible[1] = 0; faceEligible[7] = 0; faceEligible[17] = 0;
    ExpandPrivacyMask(faceBone, faceSkin, faceEligible, 7, 7, 2, faceHorizontal, faceOutput);
    assert(faceOutput[24] == 255 && faceOutput[10] == 255); // skin and nearby eye/mouth
    assert(faceOutput[0] == 0 && faceOutput[1] == 0 && faceOutput[7] == 0 && faceOutput[17] == 0); // white background
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
    display = bridge.split("static void DisplaySynchronizedBackground", 1)[1].split("// Each detector", 1)[0]
    assert pose.index("CGContextFlush(context)") < pose.index("ExpandPrivacyMask(") < pose.index("CGBitmapContextCreateImage(context)")
    assert "CGAffineTransformMakeScale" not in pose
    assert "CIMorphology" not in bridge and "CIMaximumCompositing" not in bridge
    assert 'CurrentPosePrivacyMask(result, source.extent,' in bridge
    assert 'captured[@"privacy"], captured[@"eligible"]' in bridge
    assert "mask[y * width + x] = PrivacySkinPixel" in bridge
    # The native bridge must retain a last safe frame on tracking loss instead
    # of replacing the camera layer with a black image.
    assert "s_lastSafeBackgroundImage" in bridge
    assert "UIImage *image = s_lastSafeBackgroundImage" in bridge
    assert "point.visibility.floatValue >= .15f" in bridge
    assert "eligible.length != width * height" in bridge
    assert "ExpandPrivacyMask" in bridge
    assert "captured[@\"eligible\"]" in bridge
    assert "MAX(32.0, s_mosaicScale)" in bridge
    assert "{11,23}" in pose and "{24,26}" in pose
    assert "s_backgroundLayer.contents = (__bridge id)image.CGImage" in display
    assert "Publish from the pose callback itself" in display
    submit = bridge.split("static void SubmitResult", 1)[1].split("@interface NativePoseCaptureDelegate", 1)[0]
    assert "parts.count == 3" not in submit
    assert "handAge <= 150" in submit and "faceAge <= 150" in submit
    assert "CIColor colorWithRed:0 green:0 blue:0" not in bridge
    print("PASS: compiled native skin/intersection core; neutral ramp, bone-only, skin-only, edge exclusion; frame/fail-closed wiring")


if __name__ == "__main__":
    main()
