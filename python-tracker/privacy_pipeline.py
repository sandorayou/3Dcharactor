from __future__ import annotations

import queue
import threading
import time
from pathlib import Path

import cv2
import mediapipe as mp
import numpy as np


class PrivacyFramePipeline:
    """Bounded camera FIFO, parallel skin inference and ordered delayed playback."""

    def __init__(self, mosaic, publish, workers=4, delay=.2, capacity=60, segmenter_factory=None):
        self._mosaic, self._publish = mosaic, publish
        self._delay = delay
        self._factory = segmenter_factory or self._create_segmenter
        self._stop = threading.Event()
        self._slots = threading.BoundedSemaphore(capacity)
        self._input = queue.Queue()
        self._ready = {}
        self._condition = threading.Condition()
        self._sequence = 0
        self.error = None
        self.displayed_frames = 0
        self.latency_ms = 0.0
        self._workers = [threading.Thread(target=self._work, name=f"skin-fifo-{i}", daemon=True)
                         for i in range(workers)]
        self._player = threading.Thread(target=self._play, name="skin-playback", daemon=True)
        for worker in self._workers:
            worker.start()
        self._player.start()

    @staticmethod
    def _create_segmenter():
        root = Path(__file__).resolve().parent
        model = root / "models/selfie_multiclass.tflite"
        if not model.is_file():
            model = root.parent / "Assets/StreamingAssets/selfie_multiclass.tflite"
        return mp.tasks.vision.ImageSegmenter.create_from_options(
            mp.tasks.vision.ImageSegmenterOptions(
                base_options=mp.tasks.BaseOptions(model_asset_path=str(model)),
                running_mode=mp.tasks.vision.RunningMode.IMAGE,
                output_category_mask=True, output_confidence_masks=False))

    def submit(self, frame, captured_at_ms):
        # Backpressure rather than replacing queued frames with the latest image.
        while not self._stop.is_set():
            if self._slots.acquire(timeout=.05):
                if self._stop.is_set():
                    self._slots.release()
                    return
                sequence = self._sequence
                self._sequence += 1
                self._input.put((sequence, frame.copy(), captured_at_ms))
                return
        if self.error:
            raise RuntimeError(self.error)

    def _fail(self, error):
        self.error = str(error)
        self._stop.set()
        with self._condition:
            self._condition.notify_all()

    def _work(self):
        segmenter = None
        try:
            segmenter = self._factory()
            while not self._stop.is_set():
                try:
                    sequence, frame, captured_at_ms = self._input.get(timeout=.05)
                except queue.Empty:
                    continue
                image = mp.Image(image_format=mp.ImageFormat.SRGB,
                                 data=cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
                result = segmenter.segment(image)
                if result.category_mask is None:
                    raise RuntimeError("Skin segmentation returned no category mask")
                labels = result.category_mask.numpy_view().squeeze()
                mask = ((labels == 2) | (labels == 3)).astype(np.uint8) * 255
                processed = self._mosaic(frame, mask) if np.any(mask) else frame
                with self._condition:
                    self._ready[sequence] = (processed, captured_at_ms)
                    self._condition.notify_all()
        except Exception as error:
            self._fail(error)
        finally:
            if segmenter is not None:
                segmenter.close()

    def _play(self):
        sequence, offset = 0, None
        try:
            while not self._stop.is_set():
                with self._condition:
                    self._condition.wait_for(lambda: self._stop.is_set() or sequence in self._ready)
                    if self._stop.is_set():
                        return
                    frame, captured_at_ms = self._ready.pop(sequence)
                captured = captured_at_ms / 1000.0
                now = time.monotonic()
                if offset is None:
                    offset = now + self._delay - captured
                due = captured + offset
                if now - due > .05:
                    offset += now - due  # Add latency on underflow; do not skip images.
                    due = now
                if self._stop.wait(max(0.0, due - time.monotonic())):
                    return
                self._publish(frame)
                self.latency_ms = (time.monotonic() - captured) * 1000.0
                self.displayed_frames += 1
                sequence += 1
                self._slots.release()
        except Exception as error:
            self._fail(error)

    def close(self):
        self._stop.set()
        with self._condition:
            self._condition.notify_all()
        for worker in self._workers:
            worker.join()
        self._player.join()
