using System;
using System.Net;
using System.Net.Sockets;
using System.IO;
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
        [SerializeField] private int port = 39542;
        [SerializeField] private bool logMalformedPackets;
        [SerializeField] private bool recordIncomingPackets = true;
        [SerializeField, Min(1)] private int maximumRecordingMegabytes = 16;
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
        private long receivedPacketCount;
        private int latestPacketBytes;
        private long latestReceivedUtcTicks;
        private StreamWriter packetRecorder;
        public string RecordingPath { get; private set; }
        public int DroppedPackets { get; private set; }
        public int MalformedPackets => malformedPackets;
        public int Port => port;
        public long LatestReceivedFrame => latestReceivedFrame;
        public bool LatestTracking => latestTracking;
        public long ReceivedPacketCount => Interlocked.Read(ref receivedPacketCount);
        public int LatestPacketBytes => Volatile.Read(ref latestPacketBytes);
        public DateTime LatestReceivedUtc
        {
            get
            {
                var ticks = Interlocked.Read(ref latestReceivedUtcTicks);
                return ticks > 0 ? new DateTime(ticks, DateTimeKind.Utc) : DateTime.MinValue;
            }
        }

        private void OnEnable()
        {
#if UNITY_EDITOR
            AssemblyReloadEvents.beforeAssemblyReload -= StopReceiver;
            AssemblyReloadEvents.beforeAssemblyReload += StopReceiver;
#endif
            StopReceiver();
            try
            {
                if (recordIncomingPackets)
                {
                    var directory = Path.Combine(Application.persistentDataPath, "RealtimeBodyTracker");
                    Directory.CreateDirectory(directory);
                    RecordingPath = Path.Combine(directory, "received-latest.jsonl");
                    if (File.Exists(RecordingPath) && new FileInfo(RecordingPath).Length > maximumRecordingMegabytes * 1024L * 1024L)
                        File.Delete(RecordingPath);
                    packetRecorder = new StreamWriter(RecordingPath, true, Encoding.UTF8) { AutoFlush = true };
                    Debug.Log($"Recording incoming tracking packets to {RecordingPath}", this);
                }
                client = new UdpClient(AddressFamily.InterNetwork);
                client.Client.ExclusiveAddressUse = true;
                client.Client.Bind(new IPEndPoint(IPAddress.Any, port));
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
            packetRecorder?.Dispose();
            packetRecorder = null;
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
                    var json = Encoding.UTF8.GetString(bytes);
                    var receivedUtc = DateTime.UtcNow;
                    var receivedLocal = receivedUtc.ToLocalTime();
                    packetRecorder?.WriteLine(
                        $"{{\"received_at\":\"{receivedLocal:yyyy-MM-dd'T'HH:mm:ss.fffK}\"," +
                        $"\"received_utc\":\"{receivedUtc:yyyy-MM-dd'T'HH:mm:ss.fff'Z'}\",\"packet\":{json}}}");
                    var packet = JsonUtility.FromJson<PosePacket>(json);
                    if (packet == null || packet.version < 1 || packet.version > 4 || packet.frame < 0) throw new FormatException();
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
                    Interlocked.Increment(ref receivedPacketCount);
                    Volatile.Write(ref latestPacketBytes, bytes.Length);
                    Interlocked.Exchange(ref latestReceivedUtcTicks, receivedUtc.Ticks);
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
