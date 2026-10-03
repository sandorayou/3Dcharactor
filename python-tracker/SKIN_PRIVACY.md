# Adaptive colour-only camera mosaic

Windows and iOS classify current camera pixels in YCbCr at 160 pixels wide. Mosaic masks do not use FaceLandmarker, eye detection, semantic segmentation or optical flow. The avatar still uses its existing pose/hand/face tracking independently.

A conservative Cb/Cr prior starts immediately, including when only the eyes and adjacent skin are visible. High-confidence candidates within the central 30% of image width, between 10% and 60% of image height, register the current skin colour automatically. Put skin in this area at startup. Chroma updates are slow and bounded to limit drift. The current central sample brightness adjusts the darkness threshold each frame. There is no FPS cap, inference waiting or retained camera queue.

A 9x9 closing operation and bounded horizontal gap filling join gaps, enclosed holes are filled to cover non-skin eyes/mouth, and a one-pixel margin expands the mask. Mosaic block sizes remain Windows 16 and iOS 48.

Colour alone cannot distinguish face skin from hands or a similarly coloured background: those regions can also be mosaicked. Strong shadows, saturated light, glasses, or isolated eyes without enough surrounding skin can still be missed. This implementation is a trial, not guaranteed anonymization. Tests use one local portrait, an eye-only crop, and simulated brightness changes; iPhone camera performance and real lighting require device testing.
