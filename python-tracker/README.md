# Python tracker

Install dependencies with `python -m pip install -r requirements.txt`. The tracker uses MediaPipe **Pose Landmarker Lite** for the body, **Hand Landmarker (21 points)** for each hand, and **Face Landmarker** for absolute head rotation. The required task files are stored under `models/`.

Run a camera with `python app.py`, or a file with `python app.py --source path\\to\\video.mp4`. Use `--no-preview` for the lowest overhead. The capture thread overwrites its one-frame buffer, so inference never works through stale frames.

Every transmitted frame and its left/right assignment is written to `debug/tracker-latest.jsonl`. Unity separately records received UDP packets under `Application.persistentDataPath/RealtimeBodyTracker/received-latest.jsonl`.
