#if !UNITY_IOS || UNITY_EDITOR
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
        [SerializeField, Tooltip("Live state")] private string launcherState = "waiting";
        [SerializeField, Tooltip("Live state")] private long observedFrame = -1;
        [SerializeField, Tooltip("Live state")] private string lastFailure;

        private UdpPoseReceiver receiver;
        private Process ownedTracker;
        [SerializeField, Tooltip("Selected camera index")] private int cameraSource;

        [Serializable] private sealed class CameraSettings { public int source; }

        public int CameraSource => cameraSource;
        public string Failure => ownedTracker != null && !ownedTracker.HasExited ? null : lastFailure;

        public void SelectCamera(int index)
        {
            if (index < 0) return;
            cameraSource = index;
            var root = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            var settingsDirectory = Path.Combine(root, "UserSettings");
            Directory.CreateDirectory(settingsDirectory);
            File.WriteAllText(Path.Combine(settingsDirectory, "MirrorInput.json"),
                JsonUtility.ToJson(new CameraSettings { source = index }));
            if (isActiveAndEnabled) RestartOwnedTracker("Camera selection changed");
        }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        private static void Install()
        {
#if UNITY_IOS && !UNITY_EDITOR
            return;
#else
            var receiver = FindObjectOfType<UdpPoseReceiver>();
            if (receiver != null && receiver.GetComponent<TrackerAutoLauncher>() == null)
            {
                receiver.gameObject.AddComponent<TrackerAutoLauncher>();
                Debug.Log("[TrackerAutoLauncher] Automatically installed onto UdpPoseReceiver GameObject.");
            }
#endif
        }

        private IEnumerator Start()
        {
#if UNITY_IOS && !UNITY_EDITOR
            yield break;
#else
            receiver = GetComponent<UdpPoseReceiver>();
            var configPath = Path.Combine(Path.GetFullPath(Path.Combine(Application.dataPath, "..")), "UserSettings", "MirrorInput.json");
            if (File.Exists(configPath))
            {
                try
                {
                    var settings = JsonUtility.FromJson<CameraSettings>(File.ReadAllText(configPath));
                    if (settings != null && settings.source >= 0) cameraSource = settings.source;
                }
                catch (Exception exception) { Debug.LogWarning($"[TrackerAutoLauncher] Camera settings could not be read: {exception.Message}", this); }
            }
            if (!autoLaunchLiveTracker)
            {
                launcherState = "replay_or_external_tracker";
                yield break;
            }
            observedFrame = receiver.LatestReceivedFrame;
            yield return null;
            yield return new WaitForSecondsRealtime(0.75f);
            RestartOwnedTracker("Unity play mode started");
#endif
        }

        private void RestartOwnedTracker(string reason)
        {
            StopOwnedTracker();
            receiver.TryTakeLatest(out _);
            foreach (var driver in FindObjectsOfType<HumanoidPoseDriver>()) driver.ResetForCameraSource();
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
                ownedTracker = Process.Start(new ProcessStartInfo
                {
                    FileName = python,
                    Arguments = $"\"{appPath}\" --source {cameraSource} --host 127.0.0.1 --port {receiver.Port} --no-preview",
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

        public static string ResolvePythonExecutable(string projectRoot)
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
                if (!ownedTracker.HasExited)
                {
                    ownedTracker.Kill();
                    ownedTracker.WaitForExit(3000);
                }
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

#else
namespace RealtimeBodyTracking
{
    public sealed class TrackerAutoLauncher : UnityEngine.MonoBehaviour
    {
    }
}
#endif
