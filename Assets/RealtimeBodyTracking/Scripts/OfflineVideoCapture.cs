using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using UnityEngine;
using Debug = UnityEngine.Debug;

namespace RealtimeBodyTracking
{
    [DisallowMultipleComponent]
    [RequireComponent(typeof(Camera))]
    public sealed class OfflineVideoCapture : MonoBehaviour
    {
        [SerializeField] private int width = 1280;
        [SerializeField] private int height = 720;
        [SerializeField] private int frameRate = 30;
        private Camera sourceCamera;
        private Camera maskedCamera;
        private Camera avatarCamera;
        private RenderTexture maskedTarget;
        private RenderTexture avatarTarget;
        private Texture2D readback;
        private Process maskedEncoder;
        private Process avatarEncoder;
        private bool recording;
        private float nextFrameTime;
        private string outputDirectory;
        private string ffmpegPath;
        private string maskedOutputPath;
        private string avatarOutputPath;

        private void Awake()
        {
            sourceCamera = GetComponent<Camera>();
        }

        private void OnGUI()
        {
            var old = GUI.backgroundColor;
            GUI.backgroundColor = recording ? new Color(1f, .35f, .35f) : new Color(.35f, 1f, .45f);
            if (GUI.Button(new Rect(16, 16, 180, 48), recording ? "録画終了" : "録画開始"))
            {
                if (recording) StopRecording(); else StartRecording();
            }
            GUI.backgroundColor = old;
            if (recording) GUI.Label(new Rect(210, 28, 300, 30), "REC  実写マスク + 透過アバター");
        }

        private void StartRecording()
        {
            ffmpegPath = ResolveFfmpeg();
            if (string.IsNullOrEmpty(ffmpegPath))
            {
                Debug.LogError("ffmpeg.exe が見つからないため録画を開始できません。", this);
                return;
            }
            var stamp = DateTime.Now.ToString("yyyyMMdd-HHmmss");
            outputDirectory = Path.Combine(Directory.GetParent(Application.dataPath).FullName, "Output", "Captures", stamp);
            Directory.CreateDirectory(outputDirectory);
            maskedOutputPath = Path.Combine(outputDirectory, "masked-real.mp4");
            avatarOutputPath = Path.Combine(outputDirectory, "avatar-alpha.mov");
            SetupCameras();
            maskedEncoder = StartEncoder(ffmpegPath, maskedOutputPath, false);
            avatarEncoder = StartEncoder(ffmpegPath, avatarOutputPath, true);
            recording = maskedEncoder != null && avatarEncoder != null;
            nextFrameTime = Time.unscaledTime;
            if (recording) StartCoroutine(CaptureLoop()); else StopRecording();
        }

        private IEnumerator CaptureLoop()
        {
            var wait = new WaitForEndOfFrame();
            while (recording)
            {
                yield return wait;
                if (Time.unscaledTime + .0001f < nextFrameTime) continue;
                nextFrameTime += 1f / Mathf.Max(frameRate, 1);
                WriteCamera(maskedCamera, maskedTarget, maskedEncoder);
                WriteCamera(avatarCamera, avatarTarget, avatarEncoder);
            }
        }

        private void SetupCameras()
        {
            maskedTarget = new RenderTexture(width, height, 24, RenderTextureFormat.ARGB32);
            avatarTarget = new RenderTexture(width, height, 24, RenderTextureFormat.ARGB32);
            readback = new Texture2D(width, height, TextureFormat.RGBA32, false);
            maskedCamera = CreateCaptureCamera("Masked Real Capture Camera", maskedTarget, 1 << 31, Color.black);
            avatarCamera = CreateCaptureCamera("Avatar Alpha Capture Camera", avatarTarget,
                sourceCamera.cullingMask & ~(1 << 31), new Color(0f, 0f, 0f, 0f));
        }

        private Camera CreateCaptureCamera(string objectName, RenderTexture target, int mask, Color clear)
        {
            var go = new GameObject(objectName);
            go.transform.SetPositionAndRotation(sourceCamera.transform.position, sourceCamera.transform.rotation);
            go.transform.SetParent(sourceCamera.transform, true);
            var camera = go.AddComponent<Camera>();
            camera.CopyFrom(sourceCamera);
            camera.enabled = false;
            camera.targetTexture = target;
            camera.cullingMask = mask;
            camera.clearFlags = CameraClearFlags.SolidColor;
            camera.backgroundColor = clear;
            return camera;
        }

        private void WriteCamera(Camera camera, RenderTexture target, Process encoder)
        {
            if (camera == null || encoder == null || encoder.HasExited) return;
            camera.Render();
            var previous = RenderTexture.active;
            RenderTexture.active = target;
            readback.ReadPixels(new Rect(0, 0, width, height), 0, 0, false);
            readback.Apply(false, false);
            RenderTexture.active = previous;
            var bytes = readback.GetRawTextureData<byte>();
            var managed = bytes.ToArray();
            encoder.StandardInput.BaseStream.Write(managed, 0, managed.Length);
        }

        private Process StartEncoder(string ffmpeg, string output, bool alpha)
        {
            var codec = alpha ? "-c:v qtrle -pix_fmt argb" : "-c:v libx264 -preset veryfast -crf 18 -pix_fmt yuv420p";
            var arguments = $"-y -loglevel error -f rawvideo -pix_fmt rgba -s {width}x{height} -r {frameRate} -i - -vf vflip {codec} \"{output}\"";
            return Process.Start(new ProcessStartInfo
            {
                FileName = ffmpeg,
                Arguments = arguments,
                UseShellExecute = false,
                RedirectStandardInput = true,
                RedirectStandardError = false,
                CreateNoWindow = true,
                WindowStyle = ProcessWindowStyle.Hidden,
            });
        }

        private void StopRecording()
        {
            recording = false;
            CloseEncoder(maskedEncoder);
            CloseEncoder(avatarEncoder);
            maskedEncoder = null;
            avatarEncoder = null;
            CreateComposite();
            if (maskedCamera != null) Destroy(maskedCamera.gameObject);
            if (avatarCamera != null) Destroy(avatarCamera.gameObject);
            if (maskedTarget != null) Destroy(maskedTarget);
            if (avatarTarget != null) Destroy(avatarTarget);
            if (readback != null) Destroy(readback);
            if (!string.IsNullOrEmpty(outputDirectory))
                Debug.Log($"録画を保存しました: {outputDirectory}", this);
        }

        private void CreateComposite()
        {
            if (string.IsNullOrEmpty(ffmpegPath) || !File.Exists(maskedOutputPath) ||
                !File.Exists(avatarOutputPath)) return;
            var output = Path.Combine(outputDirectory, "composited.mp4");
            var arguments = $"-y -loglevel error -i \"{maskedOutputPath}\" -i \"{avatarOutputPath}\" " +
                $"-filter_complex \"[0:v][1:v]overlay=0:0:format=auto\" -c:v libx264 " +
                $"-preset veryfast -crf 18 -pix_fmt yuv420p -shortest \"{output}\"";
            using (var process = Process.Start(new ProcessStartInfo
            {
                FileName = ffmpegPath,
                Arguments = arguments,
                UseShellExecute = false,
                CreateNoWindow = true,
                WindowStyle = ProcessWindowStyle.Hidden,
            }))
            {
                process?.WaitForExit();
                if (process != null && process.ExitCode != 0)
                    Debug.LogError("合成動画の生成に失敗しました。", this);
            }
        }

        private static void CloseEncoder(Process process)
        {
            if (process == null) return;
            try
            {
                process.StandardInput.Close();
                if (!process.WaitForExit(10000)) process.Kill();
            }
            catch { }
            finally { process.Dispose(); }
        }

        private static string ResolveFfmpeg()
        {
            var pathValue = Environment.GetEnvironmentVariable("PATH") ?? string.Empty;
            foreach (var directory in pathValue.Split(Path.PathSeparator))
            {
                var candidate = Path.Combine(directory.Trim(), "ffmpeg.exe");
                if (File.Exists(candidate)) return candidate;
            }
            var packages = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
                "Microsoft", "WinGet", "Packages");
            if (!Directory.Exists(packages)) return null;
            foreach (var candidate in Directory.GetFiles(packages, "ffmpeg.exe", SearchOption.AllDirectories))
                return candidate;
            return null;
        }

        private void OnDisable()
        {
            if (recording) StopRecording();
        }
    }
}
