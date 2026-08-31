from __future__ import annotations

import argparse
import sys
import time
from pathlib import Path

import cv2

from camera import CameraCapture
from debug_recorder import DebugRecorder, DebugVideoRecorder
from frame_buffer import LatestFrameBuffer
from pose_estimator import PoseEstimator
from settings import TrackerSettings
from udp_sender import UdpPoseSender

PREVIEW_WINDOW = "Realtime Body Tracker (Q to stop)"


def parse_args() -> TrackerSettings:
    parser = argparse.ArgumentParser(description="Low-latency MediaPipe pose to Unity UDP tracker")
    parser.add_argument("--source", default="0", help="Camera index or video path")
    parser.add_argument("--model", default="models/pose_landmarker_lite.task")
    parser.add_argument("--hand-model", default="models/hand_landmarker.task")
    parser.add_argument("--face-model", default="models/face_landmarker.task")
    parser.add_argument("--width", type=int, default=640)
    parser.add_argument("--height", type=int, default=480)
    parser.add_argument("--inference-size", type=int, choices=(256, 320), default=256)
    parser.add_argument("--inference-fps", type=float, default=20.0)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=39540)
    parser.add_argument("--no-preview", action="store_true")
    parser.add_argument("--tracking-mirror", action="store_true")
    parser.add_argument("--debug-log", type=Path, default=Path("debug/tracker-latest.jsonl"))
    parser.add_argument("--debug-video", type=Path, default=Path("debug/tracker-preview-latest.avi"))
    args = parser.parse_args()
    return TrackerSettings(
        source=args.source,
        model_path=Path(args.model),
        hand_model_path=Path(args.hand_model),
        face_model_path=Path(args.face_model),
        width=args.width,
        height=args.height,
        inference_size=args.inference_size,
        inference_fps=args.inference_fps,
        udp_host=args.host,
        udp_port=args.port,
        preview=not args.no_preview,
        tracking_mirror=args.tracking_mirror,
        debug_log_path=args.debug_log,
        debug_video_path=args.debug_video,
    )


def draw_preview(frame, estimator: PoseEstimator, text: str, mirror: bool):
    preview = frame.copy()
    h, w = preview.shape[:2]

    # Draw body pose landmarks (Green circles)
    if estimator.last_normalized_landmarks:
        for landmark in estimator.last_normalized_landmarks:
            x, y = int(landmark.x * w), int(landmark.y * h)
            cv2.circle(preview, (x, y), 3, (0, 220, 0), -1)

    # Draw hand 21 landmarks with Cyan (Left) / Magenta (Right)
    for hand_landmarks, assignment in zip(estimator.last_hand_landmarks, estimator.last_hand_assignments):
        is_left = (assignment.get("side") == "left")
        color = (255, 255, 0) if is_left else (255, 0, 255) # Cyan for Left, Magenta for Right

        for landmark in hand_landmarks:
            x, y = int(landmark.x * w), int(landmark.y * h)
            cv2.circle(preview, (x, y), 3, color, -1)

        wrist_x = 1.0 - assignment["wrist_x"] if mirror else assignment["wrist_x"]
        position = (int(wrist_x * w), int(assignment["wrist_y"] * h))
        cv2.putText(preview, assignment["side"].upper(), position, cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)

    if mirror:
        preview = cv2.flip(preview, 1)

    cv2.putText(preview, text, (12, 28), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 255, 255), 2)
    return preview


def main() -> None:
    settings = parse_args()
    frames = LatestFrameBuffer()
    camera = CameraCapture(settings, frames)
    estimator = PoseEstimator(settings)
    sender = UdpPoseSender(settings.udp_host, settings.udp_port)
    recorder = DebugRecorder(settings.debug_log_path)
    video_recorder = DebugVideoRecorder(settings.debug_video_path, settings.camera_fps)
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
                recorder.write(packet, estimator.last_hand_assignments)
                # Publish the same captured frame that produced this packet,
                # with tracker points overlaid for Unity's background.
                frame_server.update(draw_preview(
                    frame, estimator, f"frame {frame_number}", settings.preview_mirror))
                last_inference = now
            if settings.preview and camera.last_frame is not None:
                latency = time.monotonic_ns() // 1_000_000 - (item[1] if item else 0)
                preview = draw_preview(
                    camera.last_frame,
                    estimator,
                    f"cam {camera.camera_fps:.1f} | pose {estimator.inference_fps:.1f} fps | {estimator.inference_ms:.0f} ms | sent {sender.sent_packets} | drop {frames.dropped_frames} | latency {latency if item else '-'} ms",
                    settings.preview_mirror,
                )
                video_recorder.write(preview)
                cv2.imshow(PREVIEW_WINDOW, preview)
                key = cv2.waitKey(1) & 0xFF
                if key in (ord("q"), 27):
                    break
                if cv2.getWindowProperty(PREVIEW_WINDOW, cv2.WND_PROP_VISIBLE) < 1:
                    break
            else:
                time.sleep(0.001)
    finally:
        camera.stop()
        estimator.close()
        sender.close()
        recorder.close()
        video_recorder.close()
        cv2.destroyAllWindows()
    if camera.error:
        raise RuntimeError(camera.error)


if __name__ == "__main__":
    main()
