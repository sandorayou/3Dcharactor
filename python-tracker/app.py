from __future__ import annotations

import argparse
import time
from pathlib import Path

import cv2

from camera import CameraCapture
from frame_buffer import LatestFrameBuffer
from pose_estimator import PoseEstimator
from settings import TrackerSettings
from udp_sender import UdpPoseSender


def parse_args() -> TrackerSettings:
    parser = argparse.ArgumentParser(description="Low-latency MediaPipe pose to Unity UDP tracker")
    parser.add_argument("--source", default="0", help="Camera index or video path")
    parser.add_argument("--model", default="models/pose_landmarker_lite.task")
    parser.add_argument("--hand-model", default="models/hand_landmarker.task")
    parser.add_argument("--width", type=int, default=640)
    parser.add_argument("--height", type=int, default=480)
    parser.add_argument("--inference-size", type=int, choices=(256, 320), default=256)
    parser.add_argument("--inference-fps", type=float, default=20.0)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=39541)
    parser.add_argument("--no-preview", action="store_true")
    parser.add_argument("--tracking-mirror", action="store_true")
    args = parser.parse_args()
    return TrackerSettings(source=args.source, model_path=Path(args.model), hand_model_path=Path(args.hand_model), width=args.width, height=args.height,
        inference_size=args.inference_size, inference_fps=args.inference_fps, udp_host=args.host, udp_port=args.port,
        preview=not args.no_preview, tracking_mirror=args.tracking_mirror)


def draw_preview(frame, estimator: PoseEstimator, text: str, mirror: bool) -> None:
    preview = frame.copy()
    if estimator.last_normalized_landmarks:
        for landmark in estimator.last_normalized_landmarks:
            x, y = int(landmark.x * preview.shape[1]), int(landmark.y * preview.shape[0])
            cv2.circle(preview, (x, y), 3, (0, 220, 0), -1)
    for hand in estimator.last_hand_landmarks:
        for landmark in hand:
            x, y = int(landmark.x * preview.shape[1]), int(landmark.y * preview.shape[0])
            cv2.circle(preview, (x, y), 2, (255, 180, 0), -1)
    cv2.putText(preview, text, (12, 28), cv2.FONT_HERSHEY_SIMPLEX, .55, (0, 255, 255), 2)
    if mirror:
        preview = cv2.flip(preview, 1)
    cv2.imshow("Realtime Body Tracker (Q to stop)", preview)


def main() -> None:
    settings = parse_args()
    frames = LatestFrameBuffer()
    camera = CameraCapture(settings, frames)
    estimator = PoseEstimator(settings)
    sender = UdpPoseSender(settings.udp_host, settings.udp_port)
    camera.start()
    frame_number, last_inference = 0, 0.0
    try:
        while camera.error is None and not camera.finished:
            now = time.monotonic()
            item = frames.take() if now - last_inference >= 1.0 / settings.inference_fps else None
            if item is not None:
                frame, timestamp_ms = item
                if settings.tracking_mirror:
                    frame = cv2.flip(frame, 1)
                frame_number += 1
                packet = estimator.estimate(frame, timestamp_ms, frame_number)
                sender.send(packet)
                last_inference = now
            if settings.preview and camera.last_frame is not None:
                latency = time.monotonic_ns() // 1_000_000 - (item[1] if item else 0)
                draw_preview(camera.last_frame, estimator,
                    f"cam {camera.camera_fps:.1f} | pose {estimator.inference_fps:.1f} fps | {estimator.inference_ms:.0f} ms | sent {sender.sent_packets} | drop {frames.dropped_frames} | latency {latency if item else '-'} ms",
                    settings.preview_mirror)
                if cv2.waitKey(1) & 0xFF in (ord("q"), 27):
                    break
            else:
                time.sleep(.001)
    finally:
        camera.stop()
        estimator.close()
        sender.close()
        cv2.destroyAllWindows()
    if camera.error:
        raise RuntimeError(camera.error)


if __name__ == "__main__":
    main()
