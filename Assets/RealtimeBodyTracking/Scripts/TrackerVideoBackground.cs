#if !UNITY_IOS || UNITY_EDITOR
using System.Collections;
using System;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;
using UnityEngine;
using UnityEngine.Networking;
using Debug = UnityEngine.Debug;

namespace RealtimeBodyTracking
{
    /// Displays the exact source selected by python-tracker behind the avatar.
    /// The tracker publishes the latest captured frame, so this also works with
    /// video files and network-capable OpenCV sources, not only a local webcam.
    public sealed class TrackerVideoBackground : MonoBehaviour
    {
        [SerializeField] private string frameUrl = "http://127.0.0.1:39543/frame.jpg";
        [SerializeField, Range(5, 60)] private int refreshRate = 30;
        [SerializeField] private bool mirror;
        [SerializeField, Min(1f)] private float backgroundDistance = 100f;
        [SerializeField] private Color blueBackground = new Color(.55f, .85f, 1f, 1f);
        private Camera targetCamera;
        private Transform background;
        private MeshRenderer backgroundRenderer;
        private Texture2D texture;
        private int cameraGeneration;
        [SerializeField] private bool realBackground;
        private string cameraError;
        private WebCamDevice[] cameras = new WebCamDevice[0];
        private WebCamTexture selectedCamera;
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        [Serializable] private sealed class TrackerCamera { public int index; public string name; }
        [Serializable] private sealed class TrackerCameraList { public TrackerCamera[] devices; }
        private TrackerCamera[] trackerCameras = new TrackerCamera[0];
        private Task<string> cameraScan;
        private TrackerAutoLauncher trackerLauncher;
#endif
        private bool showControls = true;
        private float lastPanelTapTime = -1f;
        private const float HeaderDoubleTapSeconds = .35f;
        private Rect controlsRect;
        private Rect controlsPanelRect;
        [SerializeField, Min(1f)] private float mobileUiScale = 1.7f;
        private float currentUiScale = 1f;

        private void Awake()
        {
#if UNITY_IOS && !UNITY_EDITOR
            // Native synchronized mosaic sits behind the transparent Unity view.
            enabled = false;
            return;
#else
            targetCamera = GetComponent<Camera>() ?? Camera.main;
            var quad = GameObject.CreatePrimitive(PrimitiveType.Quad);
            quad.name = "Tracker Video Background";
            quad.layer = 31;
            background = quad.transform;
            background.SetParent(targetCamera.transform, false);
            background.localPosition = Vector3.forward * backgroundDistance;
            background.localRotation = Quaternion.identity;
            Destroy(quad.GetComponent<Collider>());
            backgroundRenderer = quad.GetComponent<MeshRenderer>();
            var shader = Shader.Find("Unlit/Texture");
            backgroundRenderer.material = new Material(shader);
            backgroundRenderer.enabled = false;
            SetBackgroundMode(false);
            StartCoroutine(PollFrames());
#endif
        }

        private void Start()
        {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            trackerLauncher = FindObjectOfType<TrackerAutoLauncher>();
            RefreshTrackerCameras();
#endif
        }

        private IEnumerator PollFrames()
        {
            var wait = new WaitForSecondsRealtime(1f / refreshRate);
            while (true)
            {
                if (!realBackground) { yield return wait; continue; }
#if !UNITY_STANDALONE_WIN && !UNITY_EDITOR_WIN
                if (selectedCamera != null)
                {
                    if (selectedCamera.didUpdateThisFrame && selectedCamera.width > 16 && selectedCamera.height > 16)
                    {
                        backgroundRenderer.material.mainTexture = selectedCamera;
                        FitToSource(selectedCamera.width, selectedCamera.height);
                        backgroundRenderer.enabled = true;
                    }
                    yield return wait;
                    continue;
                }
#endif
                using (var request = UnityWebRequestTexture.GetTexture(frameUrl + "?t=" + Time.realtimeSinceStartup))
                {
                    var generation = cameraGeneration;
                    yield return request.SendWebRequest();
                    if (realBackground && generation == cameraGeneration && request.result == UnityWebRequest.Result.Success)
                    {
                        var next = DownloadHandlerTexture.GetContent(request);
                        if (next != null)
                        {
                            if (texture != null) Destroy(texture);
                            texture = next;
                            texture.wrapMode = TextureWrapMode.Clamp;
                            backgroundRenderer.material.mainTexture = texture;
                            backgroundRenderer.material.mainTextureScale =
                                mirror ? new Vector2(-1f, 1f) : Vector2.one;
                            backgroundRenderer.material.mainTextureOffset =
                                mirror ? new Vector2(1f, 0f) : Vector2.zero;
                            FitToSource(texture.width, texture.height);
                            backgroundRenderer.enabled = true;
                        }
                    }
                }
                yield return wait;
            }
        }

        public void SetBackgroundMode(bool useRealCamera)
        {
            realBackground = useRealCamera;
            if (targetCamera == null) return;
            targetCamera.clearFlags = CameraClearFlags.SolidColor;
            targetCamera.backgroundColor = blueBackground;
            if (backgroundRenderer != null) backgroundRenderer.enabled = useRealCamera && (texture != null || selectedCamera != null);
        }

        private void Update()
        {
            if (Input.GetKeyDown(KeyCode.D) && (Input.GetKey(KeyCode.LeftAlt) || Input.GetKey(KeyCode.RightAlt))) showControls = !showControls;
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            if (cameraScan != null && cameraScan.IsCompleted)
            {
                if (cameraScan.IsFaulted) cameraError = cameraScan.Exception.GetBaseException().Message;
                else
                {
                    try { trackerCameras = JsonUtility.FromJson<TrackerCameraList>(cameraScan.Result).devices ?? new TrackerCamera[0]; }
                    catch (Exception exception) { cameraError = exception.Message; }
                }
                cameraScan = null;
            }
#endif
            if (Input.touchCount != 1) return;
            var touch = Input.GetTouch(0);
            if (touch.phase != TouchPhase.Ended) return;
            if (!controlsRect.Contains(touch.position)) return;
            var now = Time.unscaledTime;
            if (lastPanelTapTime >= 0f && now - lastPanelTapTime <= HeaderDoubleTapSeconds)
            {
                showControls = !showControls;
                lastPanelTapTime = -1f;
            }
            else lastPanelTapTime = now;
        }

        private void OnGUI()
        {
            if (!showControls) return;
            currentUiScale = Application.isMobilePlatform ? mobileUiScale : 1f;
            var panelWidth = Mathf.Min(290f * currentUiScale, Screen.width - 32f);
            var panelHeight = Mathf.Min(270f * currentUiScale, Screen.height - 32f);
            controlsPanelRect = new Rect(16f, Screen.height - panelHeight - 16f, panelWidth, panelHeight);
            controlsRect = new Rect(controlsPanelRect.x, Screen.height - 16f - 290f * currentUiScale, panelWidth, Mathf.Min(290f * currentUiScale, Screen.height - 32f));
            var oldMatrix = GUI.matrix;
            GUI.matrix = Matrix4x4.TRS(new Vector3(controlsPanelRect.x, controlsPanelRect.y, 0f), Quaternion.identity, new Vector3(currentUiScale, currentUiScale, 1f));
            GUILayout.BeginArea(new Rect(0f, 0f, 290f, 270f), GUI.skin.box);
            GUILayout.Label("背景とカメラ");
            GUILayout.BeginHorizontal();
            if (GUILayout.Toggle(!realBackground, "青背景", GUI.skin.button) != !realBackground) SetBackgroundMode(false);
            if (GUILayout.Toggle(realBackground, "実写", GUI.skin.button) != realBackground) SetBackgroundMode(true);
            GUILayout.EndHorizontal();
            if (GUILayout.Button("カメラ一覧を更新"))
            {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
                RefreshTrackerCameras();
#else
                try { cameras = WebCamTexture.devices; cameraError = null; }
                catch (Exception exception) { cameraError = exception.Message; }
#endif
            }
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            foreach (var device in trackerCameras)
                if (GUILayout.Button(device.name + (trackerLauncher != null && trackerLauncher.CameraSource == device.index ? "（選択中）" : string.Empty)))
                    SelectTrackerCamera(device);
            if (trackerCameras.Length == 0 && cameraScan == null) GUILayout.Label("カメラ一覧を更新してください。");
            if (trackerLauncher == null) GUILayout.Label("追跡トラッカーが見つかりません。");
            else if (!string.IsNullOrEmpty(trackerLauncher.Failure)) GUILayout.Label(trackerLauncher.Failure);
#else
            if (selectedCamera != null && GUILayout.Button("カメラを停止")) StopCamera();
            foreach (var device in cameras)
                if (GUILayout.Button(device.name)) StartCamera(device);
            if (cameras.Length == 0) GUILayout.Label("ブラウザーのカメラ許可後に一覧を更新してください。");
#endif
            if (!string.IsNullOrEmpty(cameraError)) GUILayout.Label(cameraError);
            GUILayout.EndArea();
            GUI.matrix = oldMatrix;
        }

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        private void RefreshTrackerCameras()
        {
            if (cameraScan != null) return;
            cameraError = null;
            var root = System.IO.Path.GetFullPath(System.IO.Path.Combine(Application.dataPath, ".."));
            var python = TrackerAutoLauncher.ResolvePythonExecutable(root);
            var script = System.IO.Path.Combine(root, "python-tracker", "list_cameras.py");
            cameraScan = Task.Run(() =>
            {
                using (var process = new Process())
                {
                    process.StartInfo = new ProcessStartInfo
                    {
                        FileName = python,
                        Arguments = "\"" + script + "\"",
                        WorkingDirectory = System.IO.Path.Combine(root, "python-tracker"),
                        UseShellExecute = false,
                        CreateNoWindow = true,
                        WindowStyle = ProcessWindowStyle.Hidden,
                        RedirectStandardOutput = true,
                        RedirectStandardError = true
                    };
                    process.Start();
                    var output = process.StandardOutput.ReadToEndAsync();
                    var diagnostics = process.StandardError.ReadToEndAsync();
                    if (!process.WaitForExit(20000)) { process.Kill(); throw new IOException("カメラ一覧の取得がタイムアウトしました。"); }
                    if (process.ExitCode != 0) throw new IOException(diagnostics.GetAwaiter().GetResult());
                    return output.GetAwaiter().GetResult();
                }
            });
        }

        private void SelectTrackerCamera(TrackerCamera device)
        {
            if (trackerLauncher == null) return;
            cameraError = null;
            cameraGeneration++;
            backgroundRenderer.enabled = false;
            if (texture != null) Destroy(texture);
            texture = null;
            backgroundRenderer.material.mainTexture = null;
            trackerLauncher.SelectCamera(device.index);
            SetBackgroundMode(true);
        }
#endif

        private void StartCamera(WebCamDevice device)
        {
            StopCamera();
            cameraError = null;
            selectedCamera = new WebCamTexture(device.name, 1280, 720, 30);
            selectedCamera.Play();
            SetBackgroundMode(true);
        }

        private void StopCamera()
        {
            if (selectedCamera == null) return;
            selectedCamera.Stop();
            Destroy(selectedCamera);
            selectedCamera = null;
            backgroundRenderer.enabled = realBackground && texture != null;
        }

        private void FitToSource(int width, int height)
        {
            float viewHeight = 2f * backgroundDistance *
                               Mathf.Tan(targetCamera.fieldOfView * Mathf.Deg2Rad * .5f);
            float viewWidth = viewHeight * targetCamera.aspect;
            float sourceAspect = (float)width / Mathf.Max(height, 1);
            // Cover the game view. Aspect differences are cropped symmetrically,
            // so no camera-clear bars remain at the sides or top/bottom.
            float fittedWidth;
            float fittedHeight;
            if (sourceAspect < targetCamera.aspect)
            {
                fittedWidth = viewWidth;
                fittedHeight = viewWidth / sourceAspect;
            }
            else
            {
                fittedHeight = viewHeight;
                fittedWidth = viewHeight * sourceAspect;
            }
            background.localScale = new Vector3(fittedWidth, fittedHeight, 1f);
        }

        private void OnDestroy()
        {
            StopCamera();
            if (texture != null) Destroy(texture);
            if (backgroundRenderer != null && backgroundRenderer.material != null)
                Destroy(backgroundRenderer.material);
        }
    }
}

#else
namespace RealtimeBodyTracking
{
    public sealed class TrackerVideoBackground : UnityEngine.MonoBehaviour
    {
        public void SetBackgroundMode(bool useRealCamera) { }
    }
}
#endif
