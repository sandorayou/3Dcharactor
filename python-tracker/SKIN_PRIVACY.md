Skin privacy uses Google MediaPipe SelfieMulticlass (256x256), independently of pose detection.
Only classes 2 (body-skin) and 3 (face-skin) are mosaicked. Colour-only thresholds and whole-person masks are not used.
Masks are always displayed with the exact source frame that produced them. Windows camera frames enter a bounded FIFO (60 frames), processed by four independent CPU segmenters. Results are played in capture order with an initial 200ms buffer, even when workers finish out of order. Capture timestamps determine frame spacing; underflow adds delay instead of skipping images.
iOS uses a serial video-mode FIFO, GPU preferred (CPU fallback), and display-link playback after three completed frames plus 100ms. Live-stream frame dropping is disabled for skin inference. Orientation changes cancel queued frames from the old orientation.
Neither implementation deliberately lowers the requested camera FPS. If sustained processing throughput is below capture throughput, the bounded queue eventually applies backpressure; a finite buffer cannot guarantee 30fps or constant latency in that case.
Avatar inference is separate from skin inference, although capture backpressure can limit both under sustained overload.

Official guide: https://developers.google.com/edge/mediapipe/solutions/vision/image_segmenter
Model: https://storage.googleapis.com/mediapipe-models/image_segmenter/selfie_multiclass_256x256/float32/latest/selfie_multiclass_256x256.tflite
Downloaded SHA256: c6748b1253a99067ef71f7e26ca71096cd449baefa8f101900ea23016507e0e0

Limitations: segmentation can misclassify or miss skin, especially close-up crops without a visible person, unusual lighting or rapid motion. It is not a guarantee of anonymization.
Representative checks: the official portrait has skin mosaicked while background, clothing, hair and accessories remain byte-identical; a flat tan background is not classified as skin. The user's narrow skin crop is classified as background, so its standalone masking is not verified.
