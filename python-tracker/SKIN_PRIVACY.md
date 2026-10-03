# Adaptive colour-only camera mosaic

Windows and iOS classify current camera pixels in YCbCr at 160 pixels wide. Mosaic masks do not use FaceLandmarker, eye detection, semantic segmentation or optical flow. The avatar still uses its existing pose/hand/face tracking independently.

A conservative Cb/Cr prior starts immediately, including when only the eyes and adjacent skin are visible. High-confidence candidates within the central 30% of image width, between 10% and 60% of image height, register the current skin colour automatically. Put skin in this area at startup. Chroma updates are slow and bounded to limit drift. The current central sample brightness adjusts the darkness threshold each frame. There is no FPS cap, inference waiting or retained camera queue.

A 9x9 closing operation and bounded horizontal gap filling join gaps, enclosed holes are filled to cover non-skin eyes/mouth, and a one-pixel margin expands the mask. Mosaic block sizes remain Windows 16 and iOS 48.

Colour alone cannot distinguish face skin from hands or a similarly coloured background: those regions can also be mosaicked. Strong shadows, saturated light, glasses, or isolated eyes without enough surrounding skin can still be missed. This implementation is a trial, not guaranteed anonymization. Tests use one local portrait, an eye-only crop, and simulated brightness changes; iPhone camera performance and real lighting require device testing.

The supplied skin sample sets the starting Cb/Cr centre to 116/142. Chroma is normalized to reference luminance 140 before comparison: 128 + (chroma - 128) * 140 / max(Y,20). Spreads are Cb 4 and Cr 5, squared distance < 2.25, upper Cr offset 7. Adaptive centres are bounded to Cb 110-122 and Cr 136-148. The darkness cutoff is 55% of sampled brightness to retain shaded skin.

One representative check used the supplied skin patch and already-mosaicked screenshot: skin coverage about 97%, selected wood region about 49% (previously 9% and 79%). Synthetic brightness changes and synthetic eye holes passed. These are not unprocessed live camera images; similar wood can still match.
