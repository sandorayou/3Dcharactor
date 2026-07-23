# Python tracker

Install dependencies with `python -m pip install -r requirements.txt`, then download the official MediaPipe **Pose Landmarker Lite** model as `models/pose_landmarker_lite.task`.

Run a camera with `python app.py`, or a file with `python app.py --source path\\to\\video.mp4`. Use `--no-preview` for the lowest overhead. The capture thread overwrites its one-frame buffer, so inference never works through stale frames.
