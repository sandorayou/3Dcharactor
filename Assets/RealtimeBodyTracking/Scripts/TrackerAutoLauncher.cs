using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using UnityEngine;
using Debug = UnityEngine.Debug;

namespace RealtimeBodyTracking
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(UdpPoseReceiver))]
    public sealed class TrackerAutoLauncher : MonoBehaviour
    {
        [SerializeField, Tooltip("Enable only when Unity should start the live camera tracker process.")]
        private bool autoLaunchLiveTracker = true;
        [SerializeField, Tooltip("Show the mirrored camera and tracking landmarks in a separate window.")]
        private bool showCameraPreviewWindow = true;
        [SerializeField, Tooltip("Live state")] private string launcherState = "waiting";
        [SerializeField, Tooltip("Live state")] private long observedFrame = -1;
        [SerializeField, Tooltip("Live state")] private string lastFailure;

        private UdpPoseReceiver receiver;
        private Process ownedTracker;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
            var receiver = FindObjectOfType<UdpPoseReceiver>();
            if (receiver != null && receiver.GetComponent<TrackerAutoLauncher>() == null)
            {
                receiver.gameObject.AddComponent<TrackerAutoLauncher>();
                Debug.Log("[TrackerAutoLauncher] Automatically installed onto UdpPoseReceiver GameObject.");
            }
        }

        private IEnumerator Start()
        {
            receiver = GetComponent<UdpPoseReceiver>();
            if (!autoLaunchLiveTracker)
            {
                launcherState = "replay_or_external_tracker";
                yield break;
            }
            observedFrame = receiver.LatestReceivedFrame;
            yield return null;
            yield return new WaitForSecondsRealtime(0.75f);
            RestartOwnedTracker("Unity play mode started");
        }

        private void RestartOwnedTracker(string reason)
        {
            StopOwnedTracker();
            var applicationRoot = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            var trackerDirectory = Path.Combine(applicationRoot, "python-tracker");
            var appPath = Path.Combine(trackerDirectory, "app.py");

            if (!File.Exists(appPath))
            {
                launcherState = "failed";
                lastFailure = $"Tracker script was not found: {appPath}";
                Debug.LogError($"[TrackerAutoLauncher] Auto-start failed: {lastFailure}", this);
                return;
            }

            var python = ResolvePythonExecutable(applicationRoot);
            try
            {
                var previewArgument = showCameraPreviewWindow ? string.Empty : " --no-preview";
                ownedTracker = Process.Start(new ProcessStartInfo
                {
                    FileName = python,
                    Arguments = $"\"{appPath}\" --source 0 --host 127.0.0.1 --port {receiver.Port}{previewArgument}",
                    WorkingDirectory = trackerDirectory,
                    UseShellExecute = false,
                    CreateNoWindow = true,
                    WindowStyle = ProcessWindowStyle.Hidden,
                });
                launcherState = "tracker_started_waiting_for_udp";
                lastFailure = string.Empty;
                Debug.Log($"[TrackerAutoLauncher] Process started ({reason}). python={python}", this);
            }
            catch (Exception exception)
            {
                ownedTracker = null;
                launcherState = "failed";
                lastFailure = exception.Message;
                Debug.LogError($"[TrackerAutoLauncher] Auto-start failed ({reason}): {exception.Message}", this);
            }
        }

        private static string ResolvePythonExecutable(string projectRoot)
        {
            var localPythonw = Path.Combine(projectRoot, "python-tracker", ".venv", "Scripts", "pythonw.exe");
            if (File.Exists(localPythonw)) return localPythonw;
            var localPython = Path.Combine(projectRoot, "python-tracker", ".venv", "Scripts", "python.exe");
            if (File.Exists(localPython)) return localPython;
            const string installedPythonw = @"C:\Python314\pythonw.exe";
            if (File.Exists(installedPythonw)) return installedPythonw;
            const string installedPython = @"C:\Python314\python.exe";
            return File.Exists(installedPython) ? installedPython : "python";
        }

        private void StopOwnedTracker()
        {
            if (ownedTracker == null) return;
            try
            {
                if (!ownedTracker.HasExited && ownedTracker.CloseMainWindow())
                    ownedTracker.WaitForExit(1500);
                if (!ownedTracker.HasExited) ownedTracker.Kill();
            }
            catch (Exception exception)
            {
                Debug.LogWarning($"[TrackerAutoLauncher] Stop warning: {exception.Message}", this);
            }
            finally
            {
                ownedTracker.Dispose();
                ownedTracker = null;
            }
        }

        private void OnDestroy()
        {
            StopOwnedTracker();
        }

        private void OnApplicationQuit()
        {
            StopOwnedTracker();
        }
    }
}
