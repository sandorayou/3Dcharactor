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
        [SerializeField, Min(.5f)] private float startupGraceSeconds = 30f;
        [SerializeField, Min(.5f)] private float heartbeatSeconds = 1f;
        [SerializeField, Range(1, 10)] private int missedHeartbeatsBeforeRestart = 10;
        [SerializeField, Tooltip("Live state")] private string launcherState = "waiting";
        [SerializeField, Tooltip("Live state")] private long observedFrame = -1;
        [SerializeField, Tooltip("Live state")] private string lastFailure;

        private UdpPoseReceiver receiver;
        private Process ownedTracker;
        private int missedHeartbeats;
        private bool shuttingDown;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
            var receiver = FindObjectOfType<UdpPoseReceiver>();
            if (receiver != null && receiver.GetComponent<TrackerAutoLauncher>() == null)
                receiver.gameObject.AddComponent<TrackerAutoLauncher>();
        }

        private IEnumerator Start()
        {
            receiver = GetComponent<UdpPoseReceiver>();
            observedFrame = receiver.LatestReceivedFrame;
            launcherState = "probing_external_tracker";
            yield return new WaitForSecondsRealtime(1.5f);
            var startupFrame = receiver.LatestReceivedFrame;
            if (startupFrame <= observedFrame) RestartOwnedTracker("Unity play mode started without UDP");
            else
            {
                observedFrame = startupFrame;
                launcherState = "external_tracker_receiving";
            }
            launcherState = "startup_grace";
            yield return new WaitForSecondsRealtime(startupGraceSeconds);

            while (!shuttingDown)
            {
                var currentFrame = receiver.LatestReceivedFrame;
                if (currentFrame > observedFrame)
                {
                    observedFrame = currentFrame;
                    missedHeartbeats = 0;
                    launcherState = ownedTracker != null && !ownedTracker.HasExited ? "owned_tracker_receiving" : "external_tracker_receiving";
                }
                else
                {
                    missedHeartbeats++;
                    launcherState = $"no_udp_{missedHeartbeats}/{missedHeartbeatsBeforeRestart}";
                    if (missedHeartbeats >= missedHeartbeatsBeforeRestart)
                    {
                        RestartOwnedTracker("UDP frame did not advance");
                        missedHeartbeats = 0;
                    }
                }
                yield return new WaitForSecondsRealtime(heartbeatSeconds);
            }
        }

        private void RestartOwnedTracker(string reason)
        {
            StopOwnedTracker();
            var projectRoot = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            var trackerDirectory = Path.Combine(projectRoot, "python-tracker");
            var appPath = Path.Combine(trackerDirectory, "app.py");
            if (!File.Exists(appPath))
            {
                launcherState = "failed";
                lastFailure = $"Tracker script was not found: {appPath}";
                Debug.LogError($"Tracker auto-start failed: {lastFailure}", this);
                return;
            }

            var python = ResolvePythonExecutable(projectRoot);
            try
            {
                ownedTracker = Process.Start(new ProcessStartInfo
                {
                    FileName = python,
                    Arguments = $"\"{appPath}\" --source 0 --host 127.0.0.1 --port 39541",
                    WorkingDirectory = trackerDirectory,
                    UseShellExecute = false,
                    CreateNoWindow = false,
                    WindowStyle = ProcessWindowStyle.Normal,
                });
                launcherState = "tracker_started_waiting_for_udp";
                lastFailure = string.Empty;
                Debug.Log($"Tracker auto-start: process started because {reason}. python={python}", this);
            }
            catch (System.Exception exception)
            {
                ownedTracker = null;
                launcherState = "failed";
                lastFailure = exception.Message;
                Debug.LogError($"Tracker auto-start failed ({reason}): {exception.Message}", this);
            }
        }

        private static string ResolvePythonExecutable(string projectRoot)
        {
            var localPython = Path.Combine(projectRoot, "python-tracker", ".venv", "Scripts", "python.exe");
            if (File.Exists(localPython)) return localPython;
            const string installedPython = @"C:\Python314\python.exe";
            return File.Exists(installedPython) ? installedPython : "python";
        }

        private void StopOwnedTracker()
        {
            if (ownedTracker == null) return;
            try
            {
                if (!ownedTracker.HasExited) ownedTracker.Kill();
            }
            catch (System.Exception exception)
            {
                Debug.LogWarning($"Tracker auto-stop warning: {exception.Message}", this);
            }
            finally
            {
                ownedTracker.Dispose();
                ownedTracker = null;
            }
        }

        private void OnDestroy()
        {
            shuttingDown = true;
            StopOwnedTracker();
        }
    }
}
