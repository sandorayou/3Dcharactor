from __future__ import annotations

import itertools
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
        self.last_hand_assignments: list[dict] = []
        self._hand_positions: dict[str, tuple[float, float]] = {}
        self._hand_velocities: dict[str, tuple[float, float]] = {}
        self._hand_last_seen_frame: dict[str, int] = {}
        self._tracking_mirror = settings.tracking_mirror

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
            for hand_index, hand in enumerate(hand_result.hand_landmarks):
                handedness = hand_result.handedness[hand_index] if hand_index < len(hand_result.handedness) else []
                category = handedness[0] if handedness else None
                label = ((category.category_name or category.display_name or "").lower()
                         if category is not None else "")
                score = float(category.score) if category is not None else .5
                handed_hands.append((score, label if label in ("left", "right") else "", hand_index, hand[0].x, hand[0].y))
            self.last_hand_assignments = []
            pose_wrists = {}
            if result.pose_landmarks:
                for side, landmark_index in (("left", 15), ("right", 16)):
                    landmark = result.pose_landmarks[0][landmark_index]
                    if landmark.visibility >= .2:
                        pose_wrists[side] = (landmark.x, landmark.y)
            assignments = self._assign_hand_sides(handed_hands, pose_wrists, frame_number)
            for score, label, hand_index, wrist_x, wrist_y, side, reason in assignments:
                self.last_hand_assignments.append({
                    "detector_index": hand_index, "raw_label": label, "side": side,
                    "reason": reason, "score": score, "wrist_x": wrist_x, "wrist_y": wrist_y,
                })
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

    def _assign_hand_sides(
        self,
        hands: list[tuple[float, str, int, float, float]],
        pose_wrists: dict[str, tuple[float, float]],
        frame_number: int,
    ) -> list[tuple[float, str, int, float, float, str, str]]:
        if not hands:
            return []

        ordered = sorted(hands, reverse=True)[:2]
        best_cost = float("inf")
        best_sides: tuple[str, ...] = ()
        for sides in itertools.permutations(("left", "right"), len(ordered)):
            cost = 0.0
            for hand, side in zip(ordered, sides):
                score, label, _, wrist_x, wrist_y = hand
                age = frame_number - self._hand_last_seen_frame.get(side, frame_number)
                if side in self._hand_positions and age <= 10:
                    old_x, old_y = self._hand_positions[side]
                    velocity_x, velocity_y = self._hand_velocities.get(side, (0.0, 0.0))
                    prediction_frames = min(max(age, 1), 3)
                    predicted_x = old_x + velocity_x * prediction_frames
                    predicted_y = old_y + velocity_y * prediction_frames
                    cost += 5.0 * ((wrist_x - predicted_x) ** 2 + (wrist_y - predicted_y) ** 2)
                else:
                    cost += .12

                # Handedness is useful evidence, not an identity switch. Both hands are
                # frequently labelled the same way while they overlap at the body center.
                if score >= .7 and label in ("left", "right") and label != side:
                    cost += .10 * score
                if side in pose_wrists:
                    pose_x, pose_y = pose_wrists[side]
                    cost += .35 * ((wrist_x - pose_x) ** 2 + (wrist_y - pose_y) ** 2)

                image_left_side = "right" if self._tracking_mirror else "left"
                screen_side = image_left_side if wrist_x > .5 else (
                    "left" if image_left_side == "right" else "right"
                )
                if screen_side != side:
                    cost += .015
            if cost < best_cost:
                best_cost = cost
                best_sides = sides

        result = []
        for hand, side in zip(ordered, best_sides):
            score, label, hand_index, wrist_x, wrist_y = hand
            age = max(frame_number - self._hand_last_seen_frame.get(side, frame_number), 1)
            previous = self._hand_positions.get(side)
            if previous is not None and age <= 10:
                measured_velocity = (
                    (wrist_x - previous[0]) / age,
                    (wrist_y - previous[1]) / age,
                )
                old_velocity = self._hand_velocities.get(side, (0.0, 0.0))
                self._hand_velocities[side] = (
                    old_velocity[0] * .45 + measured_velocity[0] * .55,
                    old_velocity[1] * .45 + measured_velocity[1] * .55,
                )
                reason = "motion_track"
            else:
                self._hand_velocities[side] = (0.0, 0.0)
                reason = "reacquired"
            self._hand_positions[side] = (wrist_x, wrist_y)
            self._hand_last_seen_frame[side] = frame_number
            result.append((*hand, side, reason))
        return result

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
