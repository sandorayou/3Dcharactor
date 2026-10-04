"""Bounded, non-public Twitch test using the existing OBS profile.

Never prints or stores the key. Only Twitch's bandwidthtest mode is supported.
Input is the running tracker's processed mosaic JPEG, with silent AAC audio.
"""
import configparser
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import threading
import time
from urllib.request import urlopen


def main():
    root = Path(__file__).resolve().parents[2]
    result_dir = root / "Output/WindowsStreamingTest"
    result_dir.mkdir(parents=True, exist_ok=True)
    profiles = Path(os.environ["APPDATA"]) / "obs-studio/basic/profiles"
    candidates = []
    for profile in profiles.iterdir():
        ini = configparser.ConfigParser(strict=False, interpolation=None)
        ini.read(profile / "basic.ini", encoding="utf-8-sig")
        if ini.get("Twitch", "Name", fallback="").lower() == "sandareyou":
            candidates.append(profile)
    if len(candidates) != 1:
        raise RuntimeError("Exactly one existing OBS profile for sandareyou is required")
    service = json.loads((candidates[0] / "service.json").read_text(encoding="utf-8-sig"))
    if service.get("settings", {}).get("service") != "Twitch":
        raise RuntimeError("Profile must be for Twitch")
    key = service["settings"].get("key", "").split("?", 1)[0]
    if not re.fullmatch(r"live_[A-Za-z0-9_]+", key):
        raise RuntimeError("Saved Twitch key is unavailable or invalid")
    with urlopen("https://ingest.twitch.tv/ingests", timeout=10) as response:
        ingests = json.load(response)["ingests"]
    tokyo = [x for x in ingests if "Tokyo" in x["name"]]
    if not tokyo:
        raise RuntimeError("Tokyo ingest endpoint unavailable")
    server = tokyo[0]["url_template"]
    if not re.fullmatch(r"rtmp://[a-z0-9.-]+/app/\{stream_key\}", server):
        raise RuntimeError("Unexpected ingest endpoint")
    target = server.replace("{stream_key}", key + "?bandwidthtest=true")
    ffmpeg = shutil.which("ffmpeg")
    if not ffmpeg:
        raise RuntimeError("FFmpeg unavailable")
    # Keep the local encoded output identical to the submitted stream.
    output = result_dir / "twitch-bandwidth-test.flv"
    tee = "[f=flv:onfail=abort]" + target + "|[f=flv]" + output.as_posix()
    command = [ffmpeg, "-hide_banner", "-loglevel", "error", "-y",
        "-f", "image2pipe", "-vcodec", "mjpeg", "-framerate", "15", "-i", "pipe:0",
        "-f", "lavfi", "-i", "anullsrc=r=44100:cl=stereo", "-map", "0:v", "-map", "1:a",
        "-c:v", "libx264", "-preset", "veryfast", "-pix_fmt", "yuv420p", "-b:v", "2000k",
        "-g", "30", "-keyint_min", "30", "-sc_threshold", "0", "-c:a", "aac", "-b:a", "96k",
        "-t", "30", "-flags", "+global_header", "-progress", "pipe:1", "-f", "tee", tee]
    process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, creationflags=subprocess.CREATE_NO_WINDOW)
    errors = []
    progress = []
    def drain(pipe, collection):
        for line in iter(pipe.readline, b""):
            collection.append(line.decode("utf-8", errors="replace").replace(key, "[REDACTED]"))
    threads = [threading.Thread(target=drain, args=(process.stdout, progress), daemon=True),
               threading.Thread(target=drain, args=(process.stderr, errors), daemon=True)]
    for thread in threads:
        thread.start()
    submitted = 0
    started = time.monotonic()
    try:
        # Fetch the exact processed frames used by TrackerVideoBackground.
        for index in range(451):
            if process.poll() is not None:
                break
            with urlopen("http://127.0.0.1:39543/frame.jpg", timeout=3) as response:
                frame = response.read()
            if not frame.startswith(b"\xff\xd8"):
                raise RuntimeError("Processed tracker frame unavailable")
            process.stdin.write(frame)
            process.stdin.flush()
            submitted += 1
            delay = started + (index + 1) / 15 - time.monotonic()
            if delay > 0:
                time.sleep(delay)
    except BrokenPipeError:
        pass
    finally:
        process.stdin.close()
        try:
            code = process.wait(timeout=20)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait()
            raise RuntimeError("Twitch test exceeded its bounded shutdown")
        for thread in threads:
            thread.join(timeout=3)
        (result_dir / "ffmpeg.redacted.log").write_text("".join(errors), encoding="utf-8")
    record = {"channel": "sandareyou", "public": False, "mode": "bandwidthtest=true",
        "ingest": tokyo[0]["name"], "exit": code, "submittedFrames": submitted,
        "elapsedSeconds": round(time.monotonic() - started, 2),
        "source": "live tracker mosaic frames", "audio": "synthetic silence; microphone not tested",
        "avatar": "Unity overlay is not included in this transport test",
        "localOutput": str(output), "progress": "".join(progress[-12:])}
    (result_dir / "result.json").write_text(json.dumps(record, indent=2), encoding="utf-8")
    print(json.dumps({k: v for k, v in record.items() if k != "progress"}, indent=2))
    if code != 0 or submitted < 400:
        raise RuntimeError("Twitch test failed; inspect only the redacted log")
    probe = shutil.which("ffprobe")
    info = json.loads(subprocess.check_output([probe, "-v", "error", "-show_streams", "-of", "json", str(output)]))
    codecs = {s["codec_type"]: s["codec_name"] for s in info["streams"]}
    if codecs != {"video": "h264", "audio": "aac"}:
        raise RuntimeError("Expected H.264/AAC output")
    subprocess.run([ffmpeg, "-v", "error", "-xerror", "-i", str(output), "-f", "null", "-"], check=True,
        creationflags=subprocess.CREATE_NO_WINDOW)
    print("PASS: Windows processed video submitted in Twitch bandwidth-test mode; H.264/AAC decoded")


if __name__ == "__main__":
    main()
