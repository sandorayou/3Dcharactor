using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif

namespace RealtimeBodyTracking
{
    public sealed class UdpPoseReceiver : MonoBehaviour
    {
        [SerializeField] private int port = 39541;
        [SerializeField] private bool logMalformedPackets;
        [SerializeField, Tooltip("Live diagnostics; updated by the receiver thread.")] private long latestReceivedFrame = -1;
        [SerializeField, Tooltip("Live diagnostics; updated by the receiver thread.")] private bool latestTracking;

        private readonly object sync = new object();
        private UdpClient client;
        private Thread receiveThread;
        private volatile bool running;
        private PosePacket latestPacket;
        private long latestFrame = -1;
        private long latestTimestampMs = -1;
        private int malformedPackets;
        public int DroppedPackets { get; private set; }
        public int MalformedPackets => malformedPackets;
        public long LatestReceivedFrame => latestReceivedFrame;
        public bool LatestTracking => latestTracking;

        private void OnEnable()
        {
#if UNITY_EDITOR
            AssemblyReloadEvents.beforeAssemblyReload -= StopReceiver;
            AssemblyReloadEvents.beforeAssemblyReload += StopReceiver;
#endif
            try
            {
                client = new UdpClient(port);
                running = true;
                receiveThread = new Thread(ReceiveLoop) { IsBackground = true, Name = "udp-pose-receiver" };
                receiveThread.Start();
            }
            catch (SocketException exception)
            {
                Debug.LogError($"Unable to receive pose UDP on {port}: {exception.Message}");
            }
        }

        private void OnDisable()
        {
#if UNITY_EDITOR
            AssemblyReloadEvents.beforeAssemblyReload -= StopReceiver;
#endif
            StopReceiver();
        }

        private void StopReceiver()
        {
            running = false;
            client?.Close();
            if (receiveThread != null && receiveThread.IsAlive) receiveThread.Join(250);
            client = null;
            receiveThread = null;
        }

        public bool TryTakeLatest(out PosePacket packet)
        {
            lock (sync)
            {
                packet = latestPacket;
                latestPacket = null;
                return packet != null;
            }
        }

        private void ReceiveLoop()
        {
            var endpoint = new IPEndPoint(IPAddress.Any, 0);
            while (running)
            {
                try
                {
                    var bytes = client.Receive(ref endpoint);
                    var packet = JsonUtility.FromJson<PosePacket>(Encoding.UTF8.GetString(bytes));
                    if (packet == null || packet.version < 1 || packet.version > 2 || packet.frame < 0) throw new FormatException();
                    lock (sync)
                    {
                        if (packet.frame <= latestFrame)
                        {
                            if (packet.timestamp_ms <= latestTimestampMs + 100) { DroppedPackets++; continue; }
                            latestFrame = -1; // The sender restarted and its frame counter began again.
                        }
                        latestFrame = packet.frame;
                        latestTimestampMs = packet.timestamp_ms;
                        latestReceivedFrame = packet.frame;
                        latestTracking = packet.tracking;
                        latestPacket = packet; // Intentionally overwrite stale unread poses.
                    }
                }
                catch (SocketException) when (!running) { return; }
                catch (Exception exception)
                {
                    malformedPackets++;
                    if (logMalformedPackets) Debug.LogWarning($"Ignored UDP pose packet: {exception.Message}");
                }
            }
        }
    }
}
