from __future__ import annotations

import time
import cv2
import numpy as np


class AdaptiveSkinMask:
    """Colour-only classification; luminance is separate from skin chroma."""

    def __init__(self):
        self.center = np.array([105., 151.], np.float32)  # Cb, Cr bootstrap prior
        self.spread = np.array([9., 8.], np.float32)
        self.registered = False

    def classify(self, frame):
        height = max(1, round(160 * frame.shape[0] / frame.shape[1]))
        small = cv2.resize(frame, (160, height), interpolation=cv2.INTER_LINEAR)
        ycc = cv2.cvtColor(small, cv2.COLOR_BGR2YCrCb).astype(np.float32)
        chroma = ycc[:, :, [2, 1]]
        distance = np.sum(((chroma - self.center) / self.spread) ** 2, axis=2)
        plausible = (ycc[:, :, 0] > 20) & (ycc[:, :, 0] < 250) & (chroma[:, :, 1] > 132) & (chroma[:, :, 0] < 132) & (chroma[:, :, 1] < self.center[1] + 7)
        raw = (plausible & (distance < 1.44)).astype(np.uint8) * 255
        # Estimate local illumination from central high-confidence colour samples.
        h, w = raw.shape
        sample = (raw > 0) & (distance < .64)
        region = np.zeros_like(sample)
        region[max(0, h//10):max(1, h*3//5), w*35//100:w*65//100] = True
        sample &= region
        if np.count_nonzero(sample) >= 40:
            illumination = float(np.mean(ycc[:, :, 0][sample]))
            raw[ycc[:, :, 0] < illumination * .8] = 0
        # Close small gaps around eyebrows; fill enclosed non-skin eye/mouth holes.
        mask = cv2.morphologyEx(raw, cv2.MORPH_CLOSE, np.ones((9, 9), np.uint8))
        # A cropped eye can connect to the image edge: bridge short bounded row gaps too.
        gap = max(3, raw.shape[1] // 5)
        extended = cv2.copyMakeBorder(mask, 0, 0, gap, gap, cv2.BORDER_CONSTANT, value=0)
        mask = cv2.morphologyEx(extended, cv2.MORPH_CLOSE, np.ones((1, gap + 1), np.uint8))[:, gap:-gap]
        padded = cv2.copyMakeBorder(mask, 1, 1, 1, 1, cv2.BORDER_CONSTANT, value=0)
        outside = padded.copy()
        cv2.floodFill(outside, None, (0, 0), 255)
        mask = cv2.bitwise_or(padded, cv2.bitwise_not(outside))[1:-1, 1:-1]
        mask = cv2.dilate(mask, np.ones((3, 3), np.uint8))
        if np.count_nonzero(sample) >= 40:
            target = np.mean(chroma[sample], axis=0)
            rate = .25 if not self.registered else .04
            self.center += np.clip(target - self.center, -4, 4) * rate
            self.center = np.clip(self.center, [95, 143], [115, 165])
            self.registered = True
        return mask


class PrivacyFramePipeline:
    """Classify the current frame with colours only; no detector waits or optical flow."""

    def __init__(self, mosaic, publish):
        self._mosaic, self._publish = mosaic, publish
        self._skin = AdaptiveSkinMask()
        self._closed = False
        self.error = None
        self.displayed_frames = 0
        self.latency_ms = 0.0

    def submit(self, frame, captured_at_ms):
        if self._closed:
            return
        mask = self._skin.classify(frame)
        self._publish(self._mosaic(frame, mask) if np.any(mask) else frame)
        self.displayed_frames += 1
        self.latency_ms = (time.monotonic() - captured_at_ms / 1000.0) * 1000.0

    def close(self):
        self._closed = True
