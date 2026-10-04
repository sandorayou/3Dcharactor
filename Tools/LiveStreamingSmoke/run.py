"""Run the production Swift transport against a local MediaMTX RTMP server.

macOS CI requires swift, mediamtx, ffmpeg and ffprobe. No service keys or
public broadcasts are used. Results include source hashes and decoded outputs.
"""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import time


def main():
    root = Path(__file__).resolve().parents[2]
    source = root / "Assets/Plugins/iOS/IOSLiveStreaming.swift"
    text = source.read_text(encoding="utf-8-sig")
    transport = text[text.index("private struct Destination"):text.index("@objc(MyProjectLiveStreaming)")]
    result_dir = root / "Output/live-streaming-smoke"
    result_dir.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="myproject5-stream-smoke-") as temp:
        temp = Path(temp)
        package = temp / "package"
        src = package / "Sources/LiveStreamingSmoke"
        src.mkdir(parents=True)
        shutil.copyfile(Path(__file__).with_name("Package.swift"), package / "Package.swift")
        imports = "import Foundation\nimport AVFoundation\nimport ReplayKit\nimport VideoToolbox\nimport HaishinKit\nimport Logboard\n"
        src.joinpath("main.swift").write_text(imports + transport + Path(__file__).with_name("main.swift.inc").read_text(), encoding="utf-8")
        subprocess.run(["swift", "build", "-c", "release", "--package-path", str(package)], check=True)
        config = temp / "mediamtx.yml"
        config.write_text("logLevel: warn\nrtmp: yes\nrtmpAddress: 127.0.0.1:1935\nrtsp: no\nhls: no\nwebrtc: no\nsrt: no\napi: no\nmetrics: no\nplayback: no\npaths:\n  all_others:\n", encoding="utf-8")
        receivers = []
        server_log = open(result_dir / "server.log", "w")
        server = subprocess.Popen(["mediamtx", str(config)], stdout=server_log, stderr=subprocess.STDOUT)
        try:
            time.sleep(1)
            if server.poll() is not None:
                raise RuntimeError("Local RTMP server failed to start")
            # FFmpeg connects as soon as each publisher appears. The sender pumps
            # eight seconds of frames, and each receiver records four seconds.
            script = "import subprocess,time,sys\n" + "\n".join([
                "end=time.monotonic()+30",
                "while time.monotonic()<end:",
                " p=subprocess.run(['ffmpeg','-v','error','-y','-rw_timeout','15000000','-i',sys.argv[1],'-t','4','-c','copy',sys.argv[2]],capture_output=True,timeout=20)",
                " if p.returncode==0: sys.exit(0)",
                " time.sleep(0.2)",
                "sys.exit('Receiver failed')",
            ])
            receiver_script = temp / "receive.py"
            receiver_script.write_text(script)
            for name in ("youtube", "twitch", "twitcast"):
                receivers.append((name, subprocess.Popen([sys.executable, str(receiver_script),
                    "rtmp://127.0.0.1:1935/live/" + name, str(result_dir / (name + ".flv"))])))
            with open(result_dir / "sender.log", "w") as log:
                subprocess.run([str(package / ".build/release/LiveStreamingSmoke")], check=True,
                    stdout=log, stderr=subprocess.STDOUT, timeout=70)
            results = {}
            for name, receiver in receivers:
                if receiver.wait(timeout=35) != 0:
                    raise RuntimeError("Receiver failed: " + name)
                output = result_dir / (name + ".flv")
                probe = json.loads(subprocess.check_output(["ffprobe", "-v", "error", "-show_streams", "-of", "json", str(output)]))
                codecs = {s["codec_type"]: s["codec_name"] for s in probe["streams"]}
                if codecs.get("video") != "h264" or codecs.get("audio") != "aac":
                    raise RuntimeError("Missing H.264/AAC: " + name)
                video = next(s for s in probe["streams"] if s["codec_type"] == "video")
                if video.get("width") != 128 or video.get("height") != 128:
                    raise RuntimeError("Unexpected frame dimensions: " + name)
                subprocess.run(["ffmpeg", "-v", "error", "-xerror", "-i", str(output), "-f", "null", "-"], check=True)
                results[name] = {"codecs": codecs, "bytes": output.stat().st_size,
                    "sha256": hashlib.sha256(output.read_bytes()).hexdigest(), "decode": "pass"}
            record = {"acceptance": "pass", "sourceSHA256": hashlib.sha256(source.read_bytes()).hexdigest(),
                "transportSHA256": hashlib.sha256(transport.encode()).hexdigest(), "outputs": results,
                "limitations": "Synthetic video/audio on macOS; iPhone ReplayKit/camera/mic and actual service accounts require device verification."}
            (result_dir / "result.json").write_text(json.dumps(record, indent=2))
            print(json.dumps(record, indent=2))
        finally:
            for _, receiver in receivers:
                if receiver.poll() is None:
                    receiver.terminate()
                    receiver.wait(timeout=10)
            server.terminate()
            server.wait(timeout=10)
            server_log.close()


if __name__ == "__main__":
    main()
