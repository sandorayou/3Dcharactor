# Colour-only live privacy mosaic

Windows and iOS use luminance-normalized Cb/Cr colour classification, morphological closing, bounded row-gap filling, enclosed-hole filling and a one-pixel margin. There is no privacy face/eye detector, semantic segmentation, optical flow, camera queue or FPS cap. Avatar tracking is independent.

Windows and native calculations use the same floating-point coefficients; border replication and bounded row gaps are now identical. The iOS implementation lives in `Assets/Plugins/iOS/PrivacyMosaicCore.h`, which is compiled directly in the parity audit. Windows and iOS both use 16-source-pixel blocks, area averages and nearest expansion. iOS exports and processes explicit sRGB bytes, with nearest sampling of the binary mask.

Camera-specific initial colour settings are intentionally distinct: Windows Cb/Cr 116/142 with spreads 4/5, based on the supplied PC skin patch; iOS 107/157 with spreads 6/7, based on the supplied iPhone screenshot. Adaptive centres are bounded to six units from their seeds. When strict initial samples are absent, plausible central skin colours can initialize the model before strict classification succeeds. This fallback remains colour-only and excludes low-chroma walls; similarly coloured wood can still initialize incorrectly.

The classifier is evaluated at 160 pixels wide. Rows 10%-60% and central 30% of width supply colour calibration. For a reliable initial registration, visible skin should be in that region. Shadows below 55% of sampled brightness are rejected. Eye/mouth holes surrounded by skin are filled. Strong lighting, glasses, isolated eyes without adjacent skin or backgrounds matching skin can still leak or be mosaicked. This is not guaranteed anonymization.

Run `python Tools/PrivacyAudit/verify_python.py` locally. GitHub Actions additionally compiles the exact native header and checks six frozen synthetic fixtures against Windows masks and mosaic output, plus an actual Core Image sRGB/pixel-row round trip. See `Tools/PrivacyAudit/AUDIT.md` for scope and remaining limits.
