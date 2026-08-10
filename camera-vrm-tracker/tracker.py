from __future__ import annotations

import argparse
import json
import socket
import time
from pathlib import Path

import cv2
import mediapipe as mp


POSE_NAMES = {
    0: "nose", 7: "left_ear", 8: "right_ear",
    11: "left_shoulder", 12: "right_shoulder",
    13: "left_elbow", 14: "right_elbow",
    15: "left_wrist", 16: "right_wrist",
    23: "left_hip", 24: "right_hip",
}
HAND_NAMES = (
    "wrist", "thumb_cmc", "thumb_mcp", "thumb_ip", "thumb_tip",
    "index_mcp", "index_pip", "index_dip", "index_tip",
    "middle_mcp", "middle_pip", "middle_dip", "middle_tip",
    "ring_mcp", "ring_pip", "ring_dip", "ring_tip",
    "little_mcp", "little_pip", "little_dip", "little_tip",
)


def point(name: str, world, image, confidence: float) -> dict:
    return {
        "name": name, "x": world.x, "y": world.y, "z": world.z,
        "u": image.x, "v": image.y, "d": image.z, "confidence": confidence,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--camera", type=int, default=0)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=39540)
    parser.add_argument("--pose-model", type=Path, default=Path("models/pose_landmarker_lite.task"))
    parser.add_argument("--hand-model", type=Path, default=Path("models/hand_landmarker.task"))
    parser.add_argument("--no-preview", action="store_true")
    args = parser.parse_args()

    pose_options = mp.tasks.vision.PoseLandmarkerOptions(
        base_options=mp.tasks.BaseOptions(model_asset_path=str(args.pose_model)),
        running_mode=mp.tasks.vision.RunningMode.VIDEO,
        num_poses=1,
        min_pose_detection_confidence=.5,
        min_tracking_confidence=.5,
    )
    hand_options = mp.tasks.vision.HandLandmarkerOptions(
        base_options=mp.tasks.BaseOptions(model_asset_path=str(args.hand_model)),
        running_mode=mp.tasks.vision.RunningMode.VIDEO,
        num_hands=2,
        min_hand_detection_confidence=.45,
        min_hand_presence_confidence=.45,
        min_tracking_confidence=.45,
    )
    capture = cv2.VideoCapture(args.camera)
    capture.set(cv2.CAP_PROP_BUFFERSIZE, 1)
    sender = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    frame_id = 0
    started = time.monotonic()
    with mp.tasks.vision.PoseLandmarker.create_from_options(pose_options) as pose_tracker, \
            mp.tasks.vision.HandLandmarker.create_from_options(hand_options) as hand_tracker:
        while capture.isOpened():
            ok, frame = capture.read()
            if not ok:
                break
            timestamp_ms = int((time.monotonic() - started) * 1000)
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb)
            pose = pose_tracker.detect_for_video(image, timestamp_ms)
            hands = hand_tracker.detect_for_video(image, timestamp_ms)
            points = []
            if pose.pose_landmarks and pose.pose_world_landmarks:
                for index, name in POSE_NAMES.items():
                    image_point = pose.pose_landmarks[0][index]
                    points.append(point(name, pose.pose_world_landmarks[0][index], image_point, image_point.visibility))
            for index, handedness in enumerate(hands.handedness):
                if not handedness:
                    continue
                category = handedness[0]
                side = category.category_name.lower()
                if side not in ("left", "right"):
                    continue
                for joint, name in enumerate(HAND_NAMES):
                    points.append(point(f"{side}_hand_{name}", hands.hand_world_landmarks[index][joint],
                                        hands.hand_landmarks[index][joint], category.score))
            packet = {"frame": frame_id, "timestampMs": timestamp_ms, "points": points}
            sender.sendto(json.dumps(packet, separators=(",", ":")).encode(), (args.host, args.port))
            frame_id += 1
            if not args.no_preview:
                cv2.imshow("Camera VRM Tracker", cv2.flip(frame, 1))
                if cv2.waitKey(1) & 0xFF == 27:
                    break
    capture.release()
    sender.close()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
