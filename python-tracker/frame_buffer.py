from __future__ import annotations

import threading
from typing import Any


class LatestFrameBuffer:
    """One-slot buffer. A producer never waits for a slow pose estimator."""

    def __init__(self) -> None:
        self._lock = threading.Lock()
        self._frame: Any | None = None
        self._captured_at_ms = 0
        self.dropped_frames = 0

    def put(self, frame: Any, captured_at_ms: int) -> None:
        with self._lock:
            if self._frame is not None:
                self.dropped_frames += 1
            self._frame = frame
            self._captured_at_ms = captured_at_ms

    def take(self) -> tuple[Any, int] | None:
        with self._lock:
            if self._frame is None:
                return None
            frame, timestamp = self._frame, self._captured_at_ms
            self._frame = None
            return frame, timestamp
