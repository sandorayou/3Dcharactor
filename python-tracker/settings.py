from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


@dataclass(slots=True)
class TrackerSettings:
    source: str = "0"
    width: int = 640
    height: int = 480
    camera_fps: int = 30
    inference_size: int = 256
    inference_fps: float = 30.0
    model_path: Path = Path("models/pose_landmarker_lite.task")
    hand_model_path: Path = Path("models/hand_landmarker.task")
    face_model_path: Path = Path("models/face_landmarker.task")
    udp_host: str = "127.0.0.1"
    udp_port: int = 39541
    video_port: int = 39543
    preview: bool = True
    preview_mirror: bool = True
    tracking_mirror: bool = False
    debug: bool = False
    debug_log_path: Path = Path("debug/tracker-latest.jsonl")
    debug_video_path: Path = Path("debug/tracker-preview-latest.avi")
