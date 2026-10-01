from __future__ import annotations

from dataclasses import asdict
from datetime import datetime, timezone
import json
from pathlib import Path

import cv2

from protocol import PosePacket


def prepare_session_path(path: Path) -> Path:
    if not path.exists() or path.stat().st_size == 0:
        return path
    timestamp = datetime.fromtimestamp(path.stat().st_mtime).strftime("%Y%m%d-%H%M%S")
    archive = path.with_name(f"{path.stem}-{timestamp}{path.suffix}")
    sequence = 1
    while archive.exists():
        archive = path.with_name(f"{path.stem}-{timestamp}-{sequence}{path.suffix}")
        sequence += 1
    try:
        path.replace(archive)
        return path
    except OSError:
        return archive


class DebugRecorder:
    def __init__(self, path: Path) -> None:
        path.parent.mkdir(parents=True, exist_ok=True)
        path = prepare_session_path(path)
        self._stream = path.open("w", encoding="utf-8", buffering=1)

    def write(self, packet: PosePacket, hand_assignments: list[dict]) -> None:
        captured_at = datetime.now().astimezone()
        self._stream.write(json.dumps({
            "captured_at": captured_at.isoformat(timespec="milliseconds"),
            "captured_utc": captured_at.astimezone(timezone.utc).isoformat(
                timespec="milliseconds"
            ).replace("+00:00", "Z"),
            "packet": asdict(packet),
            "hand_assignments": hand_assignments,
        }, separators=(",", ":")) + "\n")

    def close(self) -> None:
        self._stream.close()


class DebugVideoRecorder:
    def __init__(self, path: Path, fps: float) -> None:
        path.parent.mkdir(parents=True, exist_ok=True)
        self._path = prepare_session_path(path)
        self._fps = fps
        self._writer = None

    def write(self, frame) -> None:
        if self._writer is None:
            height, width = frame.shape[:2]
            self._writer = cv2.VideoWriter(
                str(self._path), cv2.VideoWriter_fourcc(*"MJPG"), self._fps, (width, height)
            )
            if not self._writer.isOpened():
                raise RuntimeError(f"Could not open debug preview video: {self._path}")
        self._writer.write(frame)

    def close(self) -> None:
        if self._writer is not None:
            self._writer.release()
