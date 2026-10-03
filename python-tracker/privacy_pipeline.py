from __future__ import annotations

import time
import cv2
import numpy as np


class AdaptiveSkinMask:
    """Colour-only classification; luminance is separate from skin chroma."""

    def __init__(self, center=(116., 142.), spread=(4., 5.)):
        self.center = np.array(center, np.float32)
        self.seed = self.center.copy()
        self.spread = np.array(spread, np.float32)
        self.registered = False

    def classify(self, frame):
        height = max(1, round(160 * frame.shape[0] / frame.shape[1]))
        small = cv2.resize(frame, (160, height), interpolation=cv2.INTER_LINEAR)
        return self.classify_small(small)

    def classify_small(self, small):
        bgr = small.astype(np.float32)
        luminance = .299 * bgr[:, :, 2] + .587 * bgr[:, :, 1] + .114 * bgr[:, :, 0]
        normalizer = 140. / np.maximum(luminance, 20.)
        chroma = np.stack((128. + .564 * (bgr[:, :, 0] - luminance) * normalizer,
                           128. + .713 * (bgr[:, :, 2] - luminance) * normalizer), axis=-1)
        distance = np.sum(((chroma - self.center) / self.spread) ** 2, axis=2)
        plausible = (luminance > 20) & (luminance < 250) & (chroma[:, :, 1] > 132) & (chroma[:, :, 0] < 132) & (chroma[:, :, 1] < self.center[1] + 7)
        raw = (plausible & (distance < 2.25)).astype(np.uint8) * 255
        # Estimate local illumination from central high-confidence colour samples.
        h, w = raw.shape
        sample = (raw > 0) & (distance < .64)
        region = np.zeros_like(sample)
        region[max(0, h//10):max(1, h*3//5), w*35//100:w*65//100] = True
        sample &= region
        if not self.registered and np.count_nonzero(sample) < 40:
            candidates = region & (luminance > 40) & (luminance < 230)
            candidates &= (chroma[:, :, 0] > 90) & (chroma[:, :, 0] < 124)
            candidates &= (chroma[:, :, 1] > 135) & (chroma[:, :, 1] < 180)
            candidates &= np.all(np.abs(chroma - self.seed) < (14, 18), axis=2)
            if np.count_nonzero(candidates) >= 40:
                self.center = np.clip(np.mean(chroma[candidates], axis=0), self.seed - 6, self.seed + 6)
                self.registered = True
                return self.classify_small(small)
        if np.count_nonzero(sample) >= 40:
            illumination = float(np.mean(luminance[sample]))
            raw[luminance < illumination * .55] = 0
        # Close small gaps around eyebrows; fill enclosed non-skin eye/mouth holes.
        mask = cv2.morphologyEx(raw, cv2.MORPH_CLOSE, np.ones((9, 9), np.uint8), borderType=cv2.BORDER_REPLICATE)
        # A cropped eye can connect to the image edge: bridge short bounded row gaps too.
        gap = max(1, raw.shape[1] // 5)
        for row in mask:
            edges = np.diff(np.r_[1, (row > 0).astype(np.int8), 1])
            starts, ends = np.flatnonzero(edges == -1), np.flatnonzero(edges == 1)
            for start, end in zip(starts, ends):
                if start > 0 and end < row.size and end - start <= gap:
                    row[start:end] = 255
        padded = cv2.copyMakeBorder(mask, 1, 1, 1, 1, cv2.BORDER_CONSTANT, value=0)
        outside = padded.copy()
        cv2.floodFill(outside, None, (0, 0), 255)
        mask = cv2.bitwise_or(padded, cv2.bitwise_not(outside))[1:-1, 1:-1]
        mask = cv2.dilate(mask, np.ones((3, 3), np.uint8))
        if np.count_nonzero(sample) >= 40:
            target = np.mean(chroma[sample], axis=0)
            rate = .25 if not self.registered else .04
            self.center += np.clip(target - self.center, -4, 4) * rate
            self.center = np.clip(self.center, self.seed - 6, self.seed + 6)
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
