from __future__ import annotations

import json
import sys

import cv2

def main() -> int:
    devices = []
    try:
        from cv2_enumerate_cameras import enumerate_cameras

        devices = [
            {"index": camera.index, "name": camera.name}
            for camera in enumerate_cameras(cv2.CAP_DSHOW)
        ]
    except ImportError:
        # Fallback for installations where the optional enumeration package
        # was not installed. Probe DirectShow indices using OpenCV itself.
        for index in range(10):
            capture = cv2.VideoCapture(index, cv2.CAP_DSHOW)
            try:
                if capture.isOpened():
                    devices.append({"index": index, "name": f"Camera {index}"})
            finally:
                capture.release()

    print(json.dumps({"devices": devices}, ensure_ascii=True))
    if not devices:
        print("カメラが見つかりません。カメラの接続とWindowsの許可を確認してください。", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
