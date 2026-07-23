from __future__ import annotations

import time
from pathlib import Path
from types import SimpleNamespace

import cv2
import mediapipe as mp
import numpy as np

from protocol import LANDMARKS, MEDIAPIPE_INDEX, PosePacket, PosePoint
from settings import TrackerSettings


class PoseEstimator:
    """MediaPipe VIDEO mode preserves tracker state without accumulating frames."""

    def __init__(self, settings: TrackerSettings) -> None:
        if not settings.model_path.is_file():
            raise FileNotFoundError(
                f"Pose model not found: {settings.model_path}. Download pose_landmarker_lite.task into models/."
            )
        if not settings.hand_model_path.is_file():
            raise FileNotFoundError(f"Hand model not found: {settings.hand_model_path}")
        options = mp.tasks.vision.PoseLandmarkerOptions(
            base_options=mp.tasks.BaseOptions(model_asset_path=str(settings.model_path)),
            running_mode=mp.tasks.vision.RunningMode.VIDEO,
            num_poses=1,
            output_segmentation_masks=False,
        )
        self._landmarker = mp.tasks.vision.PoseLandmarker.create_from_options(options)
        hand_options = mp.tasks.vision.HandLandmarkerOptions(
            base_options=mp.tasks.BaseOptions(model_asset_path=str(settings.hand_model_path)),
            running_mode=mp.tasks.vision.RunningMode.VIDEO,
            num_hands=2,
            min_hand_detection_confidence=.35,
            min_hand_presence_confidence=.35,
            min_tracking_confidence=.35,
        )
        self._hand_landmarker = mp.tasks.vision.HandLandmarker.create_from_options(hand_options)
        self._size = settings.inference_size
        self.inference_ms = 0.0
        self.inference_fps = 0.0
        self._fps_started = time.perf_counter()
        self._fps_count = 0
        self.last_normalized_landmarks = None
        self.last_hand_landmarks: list[list[SimpleNamespace]] = []

    def close(self) -> None:
        self._landmarker.close()
        self._hand_landmarker.close()

    def estimate(self, frame: np.ndarray, timestamp_ms: int, frame_number: int) -> PosePacket:
        resized, scale, pad_left, pad_top = self._letterbox(frame)
        rgb = cv2.cvtColor(resized, cv2.COLOR_BGR2RGB)
        started = time.perf_counter()
        media_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb)
        result = self._landmarker.detect_for_video(media_image, timestamp_ms)
        hand_result = self._hand_landmarker.detect_for_video(media_image, timestamp_ms)
        self.inference_ms = (time.perf_counter() - started) * 1000.0
        self._fps_count += 1
        elapsed = time.perf_counter() - self._fps_started
        if elapsed >= 1.0:
            self.inference_fps, self._fps_count, self._fps_started = self._fps_count / elapsed, 0, time.perf_counter()
        self.last_normalized_landmarks = [
            SimpleNamespace(
                x=(landmark.x * self._size - pad_left) / (scale * frame.shape[1]),
                y=(landmark.y * self._size - pad_top) / (scale * frame.shape[0]),
            )
            for landmark in result.pose_landmarks[0]
        ] if result.pose_landmarks else None
        self.last_hand_landmarks = [
            [SimpleNamespace(
                x=(landmark.x * self._size - pad_left) / (scale * frame.shape[1]),
                y=(landmark.y * self._size - pad_top) / (scale * frame.shape[0]),
            ) for landmark in hand]
            for hand in hand_result.hand_landmarks
        ]
        points: list[PosePoint] = []
        if result.pose_world_landmarks:
            world = result.pose_world_landmarks[0]
            image = result.pose_landmarks[0]
            for name in LANDMARKS:
                index = MEDIAPIPE_INDEX[name]
                point, normalized = world[index], image[index]
                # Keep MediaPipe world coordinates on the wire. Unity owns the source-to-avatar axis conversion.
                image_x = (normalized.x * self._size - pad_left) / (scale * frame.shape[1])
                image_y = (normalized.y * self._size - pad_top) / (scale * frame.shape[0])
                points.append(PosePoint(
                    name, point.x, point.y, point.z, normalized.visibility,
                    image_x, image_y, normalized.z,
                ))
            handed_hands = []
            for hand_index, handedness in enumerate(hand_result.handedness):
                if not handedness:
                    continue
                category = handedness[0]
                label = (category.category_name or category.display_name or "").lower()
                if label in ("left", "right"):
                    handed_hands.append((float(category.score), label, hand_index))
            assigned = set()
            for score, side, hand_index in sorted(handed_hands, reverse=True):
                if side in assigned:
                    continue
                assigned.add(side)
                hand = hand_result.hand_landmarks[hand_index]
                hand_world = hand_result.hand_world_landmarks[hand_index]
                hand_names = (
                    "wrist", "thumb_cmc", "thumb_mcp", "thumb_ip", "thumb",
                    "index_mcp", "index_pip", "index_dip", "index",
                    "middle_mcp", "middle_pip", "middle_dip", "middle",
                    "ring_mcp", "ring_pip", "ring_dip", "ring",
                    "pinky_mcp", "pinky_pip", "pinky_dip", "pinky",
                )
                for index, suffix in enumerate(hand_names):
                    image_point = self.last_hand_landmarks[hand_index][index]
                    world_point = hand_world[index]
                    points.append(PosePoint(
                        f"{side}_hand_{suffix}", world_point.x, world_point.y, world_point.z, score,
                        image_point.x, image_point.y, hand[index].z,
                    ))
                palm_indices = (5, 9, 17)
                palm_image_x = sum(self.last_hand_landmarks[hand_index][index].x for index in palm_indices) / len(palm_indices)
                palm_image_y = sum(self.last_hand_landmarks[hand_index][index].y for index in palm_indices) / len(palm_indices)
                palm_world_x = sum(hand_world[index].x for index in palm_indices) / len(palm_indices)
                palm_world_y = sum(hand_world[index].y for index in palm_indices) / len(palm_indices)
                palm_world_z = sum(hand_world[index].z for index in palm_indices) / len(palm_indices)
                palm_image_z = sum(hand[index].z for index in palm_indices) / len(palm_indices)
                points.append(PosePoint(
                    f"{side}_hand_palm", palm_world_x, palm_world_y, palm_world_z, score,
                    palm_image_x, palm_image_y, palm_image_z,
                ))
        return PosePacket(
            version=2, frame=frame_number, timestamp_ms=timestamp_ms,
            source_width=frame.shape[1], source_height=frame.shape[0],
            tracking=bool(points), points=points,
        )

    def _letterbox(self, frame: np.ndarray) -> tuple[np.ndarray, float, int, int]:
        height, width = frame.shape[:2]
        scale = min(self._size / width, self._size / height)
        scaled = cv2.resize(frame, (round(width * scale), round(height * scale)), interpolation=cv2.INTER_AREA)
        top = (self._size - scaled.shape[0]) // 2
        bottom = self._size - scaled.shape[0] - top
        left = (self._size - scaled.shape[1]) // 2
        right = self._size - scaled.shape[1] - left
        padded = cv2.copyMakeBorder(scaled, top, bottom, left, right, cv2.BORDER_CONSTANT)
        return padded, scale, left, top
