from __future__ import annotations

import threading
import time

import cv2
import numpy as np


class PrivacyFramePipeline:
    """Live camera presentation with existing face detection and mask motion tracking."""

    def __init__(self, mosaic, publish, face_provider):
        self._mosaic, self._publish = mosaic, publish
        self._face_provider = face_provider
        self._last_seen = -1
        self._epoch = -1
        self._stop = threading.Event()
        self._applied_sequence = -1
        self._frame_shape = None
        self._previous_gray = None
        self._mask = None
        self._history = []
        self._size = (160, 120)
        x, y = np.meshgrid(np.arange(160), np.arange(120))
        self._grid = np.stack((x, y), axis=-1).astype(np.float32)
        self.error = None
        self.displayed_frames = 0
        self.latency_ms = 0.0

    def _warp(self, mask, backward_flow):
        coords = self._grid + backward_flow
        return cv2.remap(mask, coords[:, :, 0], coords[:, :, 1], cv2.INTER_NEAREST,
                         borderMode=cv2.BORDER_CONSTANT, borderValue=0)

    def submit(self, frame, captured_at_ms):
        if self._stop.is_set():
            if self.error:
                raise RuntimeError(self.error)
            return
        sequence = captured_at_ms
        if self._frame_shape != frame.shape[:2]:
            self._frame_shape = frame.shape[:2]
            self._previous_gray = None
            self._history = []
            self._mask = None
            self._applied_sequence = sequence - 1
            self._epoch = sequence
        gray = cv2.cvtColor(cv2.resize(frame, self._size), cv2.COLOR_BGR2GRAY)
        if self._previous_gray is not None and gray.shape == self._previous_gray.shape:
            # Backward flow samples the preceding mask at each current pixel.
            flow = cv2.calcOpticalFlowFarneback(gray, self._previous_gray, None,
                                               .5, 3, 15, 2, 5, 1.2, 0)
            self._history.append((sequence, flow))
            self._history = self._history[-30:]
            if self._mask is not None:
                self._mask = self._warp(self._mask, flow)
        self._previous_gray = gray
        result = self._face_provider()
        if result is not None:
            anchor, points, shape = result
            if anchor > self._applied_sequence and anchor >= self._epoch and shape == self._frame_shape:
                if len(points) >= 3 and captured_at_ms - anchor <= 400:
                    vertices = np.asarray(points, dtype=np.float32)
                    center = vertices.mean(axis=0)
                    vertices = center + (vertices - center) * (1.12, 1.15)
                    vertices = np.rint(vertices * self._size).astype(np.int32)
                    corrected = np.zeros((120, 160), np.uint8)
                    cv2.fillConvexPoly(corrected, cv2.convexHull(vertices), 255)
                    for stamp, flow in self._history:
                        if stamp > anchor:
                            corrected = self._warp(corrected, flow)
                    self._mask = corrected
                    self._last_seen = anchor
                self._applied_sequence = anchor
        if captured_at_ms - self._last_seen > 400:
            self._mask = None
        output = self._mosaic(frame, self._mask) if self._mask is not None and np.any(self._mask) else frame
        self._publish(output)
        self.displayed_frames += 1
        self.latency_ms = (time.monotonic() - captured_at_ms / 1000.0) * 1000.0

    def close(self):
        self._stop.set()
