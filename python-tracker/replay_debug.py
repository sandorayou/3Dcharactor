from __future__ import annotations

import argparse
import json
from pathlib import Path
import socket
import time


def main() -> None:
    parser = argparse.ArgumentParser(description="Replay a recorded tracker JSONL into Unity")
    parser.add_argument("path", type=Path)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=39542)
    parser.add_argument("--fps", type=float, default=20.0)
    parser.add_argument("--start-frame", type=int, default=0)
    parser.add_argument("--end-frame", type=int, default=2**31 - 1)
    parser.add_argument(
        "--frame-offset",
        type=int,
        default=1_000_000_000,
        help="Makes replay frames newer than any preceding live-camera session.",
    )
    args = parser.parse_args()

    packets = []
    with args.path.open("r", encoding="utf-8-sig") as stream:
        for line in stream:
            row = json.loads(line)
            packet = row.get("packet", row)
            frame = int(packet["frame"])
            if args.start_frame <= frame <= args.end_frame:
                packets.append(packet)
    sender = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        for replay_frame, packet in enumerate(packets, args.frame_offset + 1):
            packet["frame"] = replay_frame
            packet["timestamp_ms"] = int(time.monotonic() * 1000)
            sender.sendto(json.dumps(packet, separators=(",", ":")).encode("utf-8"), (args.host, args.port))
            time.sleep(1.0 / args.fps)
    finally:
        sender.close()


if __name__ == "__main__":
    main()
