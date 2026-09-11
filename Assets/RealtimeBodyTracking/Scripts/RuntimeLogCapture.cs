using System;
using System.IO;
using System.Text;
using UnityEngine;
namespace RealtimeBodyTracking
{
    public sealed class RuntimeLogCapture : MonoBehaviour
    {
        private const int MaxLines = 400; private static readonly object Gate = new object(); private static readonly StringBuilder Buffer = new StringBuilder(); private static string path; private Application.LogCallback callback;
        public static string GetText() { lock (Gate) return Buffer.ToString(); }
        private void Awake() { path = Path.Combine(Application.persistentDataPath, "runtime.log"); callback = Handle; Application.logMessageReceivedThreaded += callback; DontDestroyOnLoad(gameObject); Debug.Log("[RuntimeLog] file: " + path); }
        private void OnDestroy() { if (callback != null) Application.logMessageReceivedThreaded -= callback; }
        private static void Handle(string condition, string stack, LogType type) { var line = $"[{DateTime.Now:yyyy-MM-dd HH:mm:ss.fff}] [{type}] {condition}"; if (type == LogType.Error || type == LogType.Exception) line += "\n" + stack; lock (Gate) { Buffer.AppendLine(line); var lines = Buffer.ToString().Split(new[] {'\n'}, StringSplitOptions.RemoveEmptyEntries); if (lines.Length > MaxLines) { Buffer.Clear(); for (var i = lines.Length - MaxLines; i < lines.Length; i++) Buffer.AppendLine(lines[i]); } try { File.AppendAllText(path, line + Environment.NewLine, Encoding.UTF8); } catch { } } }
    }
}
