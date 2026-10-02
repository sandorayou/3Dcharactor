Skin privacy uses Google MediaPipe SelfieMulticlass (256x256), independently of pose detection.
Only classes 2 (body-skin) and 3 (face-skin) are mosaicked. Colour-only thresholds and whole-person masks are not used.
Masks are always displayed with the exact source frame that produced them. Avatar inference does not wait for skin inference.

Official guide: https://developers.google.com/edge/mediapipe/solutions/vision/image_segmenter
Model: https://storage.googleapis.com/mediapipe-models/image_segmenter/selfie_multiclass_256x256/float32/latest/selfie_multiclass_256x256.tflite
Downloaded SHA256: c6748b1253a99067ef71f7e26ca71096cd449baefa8f101900ea23016507e0e0

Limitations: segmentation can misclassify or miss skin, especially close-up crops without a visible person, unusual lighting or rapid motion. It is not a guarantee of anonymization.
Representative checks: the official portrait has skin mosaicked while background, clothing, hair and accessories remain byte-identical; a flat tan background is not classified as skin. The user's narrow skin crop is classified as background, so its standalone masking is not verified.
