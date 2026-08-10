using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using UnityEngine;

namespace CameraVrmMocap
{
    public sealed class UdpTrackingReceiver : MonoBehaviour
    {
        [SerializeField] private int port = 39540;
        private readonly object gate = new();
        private UdpClient client;
        private Thread thread;
        private TrackingPacket latest;

        private void OnEnable()
        {
            client = new UdpClient(port);
            thread = new Thread(Receive) { IsBackground = true, Name = "VRM tracking UDP" };
            thread.Start();
        }

        private void OnDisable()
        {
            client?.Close();
            thread?.Join(100);
            client = null;
            thread = null;
        }

        public bool TryTakeLatest(out TrackingPacket packet)
        {
            lock (gate) { packet = latest; latest = null; }
            return packet != null;
        }

        private void Receive()
        {
            var endpoint = new IPEndPoint(IPAddress.Any, 0);
            while (client != null)
            {
                try
                {
                    var bytes = client.Receive(ref endpoint);
                    var packet = JsonUtility.FromJson<TrackingPacket>(Encoding.UTF8.GetString(bytes));
                    lock (gate) latest = packet;
                }
                catch (SocketException) { if (client != null) Debug.LogWarning("Tracking UDP reception stopped."); }
                catch (ObjectDisposedException) { }
                catch (Exception error) { Debug.LogException(error); }
            }
        }
    }
}
