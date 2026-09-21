using System;
using System.IO;
using System.Text;

namespace RealtimeBodyTracking
{
    // One bounded file, replaced only by an explicit new recording. No camera images.
    public sealed class TrackingJsonlRecorder : IDisposable
    {
        private const int MaxFrames = 6000;
        private const long MaxBytes = 8 * 1024 * 1024;
        private StreamWriter writer;
        private long bytes;
        public bool IsRecording { get { return writer != null; } }
        public string FilePath { get; private set; }
        public string Status { get; private set; } = "記録OFF";
        public int Frames { get; private set; }

        public void Start(string directory)
        {
            Stop();
            try
            {
                Directory.CreateDirectory(directory);
                FilePath = Path.Combine(directory, "tracking-latest.jsonl");
                writer = new StreamWriter(FilePath, false, new UTF8Encoding(false));
                writer.NewLine = "\n";
                writer.AutoFlush = true;
                Frames = 0;
                bytes = 0;
                Status = "記録中";
            }
            catch (Exception error) { Fail(error); }
        }

        public void Append(string packetJson)
        {
            if (!IsRecording) return;
            // A caller must pass a serialized PosePacket, never raw camera payloads.
            if (string.IsNullOrEmpty(packetJson) || packetJson.IndexOfAny(new[] { '\r', '\n' }) >= 0)
                return;
            var size = Encoding.UTF8.GetByteCount(packetJson) + 1;
            if (Frames >= MaxFrames || bytes + size > MaxBytes)
            {
                Stop();
                Status = "上限で停止 (6000フレーム / 8 MiB)";
                return;
            }
            try
            {
                writer.WriteLine(packetJson);
                bytes += size;
                Frames++;
                if (Frames >= MaxFrames || bytes >= MaxBytes)
                {
                    Stop();
                    Status = "上限で停止 (6000フレーム / 8 MiB)";
                }
            }
            catch (Exception error) { Fail(error); }
        }

        public void Stop()
        {
            if (writer == null) return;
            var closing = writer;
            writer = null;
            try { closing.Dispose(); Status = "記録停止"; }
            catch (Exception error) { Status = "記録エラー: " + error.Message; }
        }

        private void Fail(Exception error)
        {
            Stop();
            Status = "記録エラー: " + error.Message;
        }

        public void Dispose() { Stop(); }
    }
}
