from __future__ import annotations

from dataclasses import asdict, dataclass
import json

LANDMARKS = (
    "nose", "left_eye", "right_eye", "left_ear", "right_ear", "left_shoulder", "right_shoulder", "left_elbow", "right_elbow",
    "left_wrist", "right_wrist", "left_pinky", "right_pinky", "left_index", "right_index", "left_thumb", "right_thumb",
    "left_hip", "right_hip", "left_knee",
    "right_knee", "left_ankle", "right_ankle", "left_heel", "right_heel",
    "left_foot_index", "right_foot_index",
)

MEDIAPIPE_INDEX = {
    "nose": 0, "left_eye": 2, "right_eye": 5, "left_ear": 7, "right_ear": 8, "left_shoulder": 11, "right_shoulder": 12, "left_elbow": 13,
    "right_elbow": 14, "left_wrist": 15, "right_wrist": 16, "left_hip": 23,
    "left_pinky": 17, "right_pinky": 18, "left_index": 19, "right_index": 20, "left_thumb": 21, "right_thumb": 22,
    "right_hip": 24, "left_knee": 25, "right_knee": 26, "left_ankle": 27,
    "right_ankle": 28, "left_heel": 29, "right_heel": 30,
    "left_foot_index": 31, "right_foot_index": 32,
}


@dataclass(slots=True)
class PosePoint:
    name: str
    x: float
    y: float
    z: float
    confidence: float
    image_x: float
    image_y: float
    image_z: float


@dataclass(slots=True)
class PosePacket:
    version: int
    frame: int
    timestamp_ms: int
    source_width: int
    source_height: int
    tracking: bool
    points: list[PosePoint]

    def to_bytes(self) -> bytes:
        return json.dumps(asdict(self), separators=(",", ":")).encode("utf-8")
