from __future__ import annotations

import socket

from protocol import PosePacket


class UdpPoseSender:
    def __init__(self, host: str, port: int) -> None:
        self._target = (host, port)
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sent_packets = 0

    def send(self, packet: PosePacket) -> None:
        try:
            self._socket.sendto(packet.to_bytes(), self._target)
            self.sent_packets += 1
        except OSError:
            pass  # UDP is deliberately fire-and-forget.

    def close(self) -> None:
        self._socket.close()
