from __future__ import annotations

import threading
import time
from pathlib import Path

import cv2

from frame_buffer import LatestFrameBuffer
from settings import TrackerSettings


class CameraCapture:
    def __init__(self, settings: TrackerSettings, frames: LatestFrameBuffer) -> None:
        self._settings = settings
        self._frames = frames
        self._stop = threading.Event()
        self._thread: threading.Thread | None = None
        self.last_frame = None
        self.camera_fps = 0.0
        self.error: str | None = None
        self.finished = False

    def start(self) -> None:
        self._thread = threading.Thread(target=self._run, name="camera-capture", daemon=True)
        self._thread.start()

    def stop(self) -> None:
        self._stop.set()
        if self._thread:
            self._thread.join(timeout=2)

    def _run(self) -> None:
        source = int(self._settings.source) if self._settings.source.isdigit() else str(Path(self._settings.source))
        backend = cv2.CAP_DSHOW if isinstance(source, int) else cv2.CAP_ANY
        capture = cv2.VideoCapture(source, backend)
        if not capture.isOpened() and backend != cv2.CAP_ANY:
            capture.open(source, cv2.CAP_MSMF)
        if not capture.isOpened():
            self.error = f"Could not open source: {self._settings.source}"
            return
        capture.set(cv2.CAP_PROP_FRAME_WIDTH, self._settings.width)
        capture.set(cv2.CAP_PROP_FRAME_HEIGHT, self._settings.height)
        capture.set(cv2.CAP_PROP_FPS, self._settings.camera_fps)
        capture.set(cv2.CAP_PROP_BUFFERSIZE, 1)
        count, window_start = 0, time.perf_counter()
        try:
            while not self._stop.is_set():
                ok, frame = capture.read()
                if not ok:
                    if isinstance(source, int):
                        self.error = "Camera read failed or was disconnected."
                    break
                captured_at_ms = time.monotonic_ns() // 1_000_000
                self.last_frame = frame
                self._frames.put(frame, captured_at_ms)
                count += 1
                elapsed = time.perf_counter() - window_start
                if elapsed >= 1:
                    self.camera_fps, count, window_start = count / elapsed, 0, time.perf_counter()
        finally:
            capture.release()
            self.finished = True
