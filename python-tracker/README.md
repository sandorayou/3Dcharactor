# Python tracker

Install dependencies with `python -m pip install -r requirements.txt`. The tracker uses MediaPipe **Pose Landmarker Lite** for the body and the dedicated **Hand Landmarker (21 points)** for each hand; place the official task files at `models/pose_landmarker_lite.task` and `models/hand_landmarker.task` when they are not already present.

Run a camera with `python app.py`, or a file with `python app.py --source path\\to\\video.mp4`. Use `--no-preview` for the lowest overhead. The capture thread overwrites its one-frame buffer, so inference never works through stale frames.

Every transmitted frame and its left/right assignment is written to `debug/tracker-latest.jsonl`. Unity separately records received UDP packets under `Application.persistentDataPath/RealtimeBodyTracker/received-latest.jsonl`.

Replay a captured interval with `python replay_debug.py debug/tracker-latest.jsonl --start-frame 260 --end-frame 350` while Unity is in Play mode.
