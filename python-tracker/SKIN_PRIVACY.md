# Face-only live camera mosaic

Windows and iOS reuse the existing FaceLandmarker landmarks. No additional skin classification model or inference is run. Hands, arms and body are outside the face mask.

Camera frames are displayed immediately. A 160-pixel motion image tracks the face mask between detector results. Late results are aligned to their captured frame before presentation. Masks expire after 400 ms without a detected face; orientation changes reset the mask and motion history. Detection is independent of body/avatar presence. iOS mosaic block width remains 48 pixels.

Before initial detection and after tracking expires, camera frames are unmasked. Fast movements or missed detections can expose part of a face; this is not a guaranteed anonymization system.
