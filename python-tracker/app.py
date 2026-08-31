from __future__ import annotations

import argparse
import sys
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

import cv2
import numpy as np

from camera import CameraCapture
from debug_recorder import DebugRecorder, DebugVideoRecorder
from frame_buffer import LatestFrameBuffer
from pose_estimator import PoseEstimator
from settings import TrackerSettings
from udp_sender import UdpPoseSender

PREVIEW_WINDOW = "Realtime Body Tracker (Q to stop)"


class FastPersonHider:
    """Cheap pose-guided clean plate; no segmentation network or full-size inpaint."""
    def __init__(self) -> None:
        self._plate = None
        self._size = (160, 120)

    def apply(self, frame, estimator: PoseEstimator):
        if not estimator.last_normalized_landmarks:
            return frame
        small = cv2.resize(frame, self._size, interpolation=cv2.INTER_AREA)
        mask = np.zeros((self._size[1], self._size[0]), dtype=np.uint8)
        points = estimator.last_normalized_landmarks

        def point(index):
            p = points[index]
            return int(p.x * self._size[0]), int(p.y * self._size[1])

        shoulder_width = max(abs(point(11)[0] - point(12)[0]), 10)
        body_thickness = max(shoulder_width // 2, 9)
        limb_thickness = max(shoulder_width // 3, 7)
        # Torso, head and limbs form a conservative silhouette around the real performer.
        torso = np.array([point(11), point(12), point(24), point(23)], dtype=np.int32)
        cv2.fillConvexPoly(mask, torso, 255)
        cv2.circle(mask, point(0), max(shoulder_width // 2, 9), 255, -1)
        for chain in ((11, 13, 15), (12, 14, 16), (23, 25, 27), (24, 26, 28)):
            for start, end in zip(chain, chain[1:]):
                cv2.line(mask, point(start), point(end), 255, limb_thickness)
            cv2.circle(mask, point(chain[-1]), limb_thickness, 255, -1)
        for hand in estimator.last_hand_landmarks:
            hand_points = np.array([
                (int(p.x * self._size[0]), int(p.y * self._size[1])) for p in hand
            ], dtype=np.int32)
            if len(hand_points) >= 3:
                cv2.fillConvexPoly(mask, cv2.convexHull(hand_points), 255)
        mask = cv2.dilate(mask, np.ones((7, 7), np.uint8), iterations=1)

        if self._plate is None or self._plate.shape != small.shape:
            # Inpaint only once, at 160x120. Later frames are simple masked copies.
            self._plate = cv2.inpaint(small, mask, 3, cv2.INPAINT_TELEA)
        else:
            self._plate[mask == 0] = small[mask == 0]
        # Preserve the original full-resolution camera image everywhere except
        # the concealed performer pixels. Only the replacement patch is upscaled.
        full_size = (frame.shape[1], frame.shape[0])
        full_mask = cv2.resize(mask, full_size, interpolation=cv2.INTER_NEAREST)
        full_plate = cv2.resize(self._plate, full_size, interpolation=cv2.INTER_LINEAR)
        hidden = frame.copy()
        hidden[full_mask != 0] = full_plate[full_mask != 0]
        return hidden


class TrackerFrameServer:
    def __init__(self, port: int) -> None:
        self._jpeg = b""
        owner = self

        class Handler(BaseHTTPRequestHandler):
            def do_GET(self) -> None:
                if self.path.split("?", 1)[0] != "/frame.jpg" or not owner._jpeg:
                    self.send_error(404)
                    return
                payload = owner._jpeg
                self.send_response(200)
                self.send_header("Content-Type", "image/jpeg")
                self.send_header("Cache-Control", "no-store, no-cache, must-revalidate")
                self.send_header("Content-Length", str(len(payload)))
                self.end_headers()
                self.wfile.write(payload)

            def log_message(self, *_args) -> None:
                pass

        self._server = ThreadingHTTPServer(("127.0.0.1", port), Handler)
        threading.Thread(target=self._server.serve_forever, name="tracker-frame-server", daemon=True).start()

    def update(self, frame) -> None:
        ok, encoded = cv2.imencode(".jpg", frame, [cv2.IMWRITE_JPEG_QUALITY, 88])
        if ok:
            self._jpeg = encoded.tobytes()

    def close(self) -> None:
        self._server.shutdown()
        self._server.server_close()


def parse_args() -> TrackerSettings:
    parser = argparse.ArgumentParser(description="Low-latency MediaPipe pose to Unity UDP tracker")
    parser.add_argument("--source", default="0", help="Camera index or video path")
    parser.add_argument("--model", default="models/pose_landmarker_lite.task")
    parser.add_argument("--hand-model", default="models/hand_landmarker.task")
    parser.add_argument("--face-model", default="models/face_landmarker.task")
    parser.add_argument("--width", type=int, default=640)
    parser.add_argument("--height", type=int, default=480)
    parser.add_argument("--inference-size", type=int, choices=(256, 320), default=256)
    parser.add_argument("--inference-fps", type=float, default=30.0)
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

    if text:
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
    frame_server = TrackerFrameServer(settings.video_port)
    person_hider = FastPersonHider()
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
                hidden_frame = person_hider.apply(frame, estimator)
                frame_server.update(draw_preview(
                    hidden_frame, estimator, "", settings.preview_mirror))
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
        frame_server.close()
        cv2.destroyAllWindows()
    if camera.error:
        raise RuntimeError(camera.error)


if __name__ == "__main__":
    main()
