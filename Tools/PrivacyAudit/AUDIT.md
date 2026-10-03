# Windows / iOS privacy audit

## Corrections

| Item | Before | Current |
|---|---|---|
| iPhone skin seed | PC sample 116/142, inappropriate for screenshot skin about 107/157 | iPhone sample 107/157, spreads 6/7; Windows seed 116/142 retained |
| Colour input | iOS pixel-buffer output colour space unspecified | sRGB explicitly specified on classifier readback, mosaic readback and displayed output |
| Chroma math | Windows quantized OpenCV YCbCr, iOS floating point | Same floating-point coefficients and luminance normalization |
| Calibration bootstrap | Strict skin detection required before registration | Central plausible skin candidates can initialize before strict detection succeeds |
| Mask gaps / borders | OpenCV horizontal closing versus native bounded-row fill; different edge padding | Same bounded-row fill and replicated edges |
| Mask enlargement | iOS interpolation implicit | Explicit nearest sampling, same policy as Windows |
| Mosaic | Windows 16, iOS 48; different filter | Both 16 source pixels with area average and nearest expansion |
| Export | No independent verification of native classifier implementation | Exported header hash checked, then source/export compared in CI |

## Evidence

The supplied iPhone screenshot is already composited/mosaicked, so it is not a raw-camera ground truth. With the corrected iPhone preset, a selected eye rectangle (x145,y900,w90,h35) was fully masked in the Python counterpart; selected unmasked wall (x120,y170,w300,h160) and curtain (x390,y880,w150,h220) rectangles had zero mask pixels. The selected larger face rectangle had about 93% coverage, including non-skin hair/eye pixels. The eight-frame check confirms processing on this available image, not physical camera operation.

Six frozen, synthetic BGRA fixtures cover two camera presets, portrait/landscape, boundary regions, eye holes, cold-start registration and a no-person wall. `verify_python.py` checks the current Python implementation against frozen golds. `audit.cpp` calls the actual iOS classifier and area-average implementation; mask equality must be exact, pixel average rounding may differ by at most one colour level. `audit_core_image.mm` tests actual Core Image/CVPixelBuffer sRGB and row-order round trips on macOS. GitHub Actions makes these checks prerequisites for IPA creation. The native checks are pending until that run completes; compiler errors or failed checks prevent success.

## Remaining differences and limitations

Physical cameras, exposure, white balance and skin presets intentionally differ. Camera resizing uses OpenCV linear interpolation on Windows and Core Image linear interpolation on iOS; edge sample phase may differ. Native arithmetic and compositor execution on an iPhone, Metal readback timing and live FPS are not verified by macOS CPU tests. No physical iPhone is available in this workspace. Rotation/reflection is applied to the combined camera-and-mask image, preventing separate mask transforms; source orientation remains platform-specific. Avatar rendering, pose/gaze behaviour and app signing are outside this privacy audit.

Colour-only detection still cannot distinguish identical skin/background colours. First-run colour registration assumes visible central skin. Runtime camera validation after installing the IPA remains necessary.

Apple API references: [explicit destination colour space](https://developer.apple.com/documentation/coreimage/cicontext/render(_:to:bounds:colorspace:)-2k8l2), [nearest sampling](https://developer.apple.com/documentation/coreimage/ciimage/samplingnearest()).
