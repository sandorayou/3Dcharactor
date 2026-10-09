using System;
using System.Collections;
using System.IO;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using UniGLTF;
using UnityEngine;

namespace RealtimeBodyTracking
{
    public sealed class WebVrmRuntimeLoader : MonoBehaviour
    {
        private const int MaximumVrmBytes = 256 * 1024 * 1024;
        private const int ChunkBytes = 128 * 1024;

#if UNITY_WEBGL && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern void WebVrmPicker_Open(string gameObjectName);
        [DllImport("__Internal")] private static extern int WebVrmPicker_GetSelectedSize();
        [DllImport("__Internal")] private static extern string WebVrmPicker_ReadChunk(int offset, int length);
        [DllImport("__Internal")] private static extern void WebVrmPicker_ClearSelected();
        [DllImport("__Internal")] private static extern void WebPwaSettings_SetAvatarStatus(string value);
#endif

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
        private struct OpenFileName
        {
            public int structSize;
            public IntPtr owner;
            public IntPtr instance;
            public string filter;
            public string customFilter;
            public int maxCustomFilter;
            public int filterIndex;
            public StringBuilder file;
            public int maxFile;
            public StringBuilder fileTitle;
            public int maxFileTitle;
            public string initialDirectory;
            public string title;
            public int flags;
            public short fileOffset;
            public short fileExtension;
            public string defaultExtension;
            public IntPtr customData;
            public IntPtr hook;
            public string templateName;
            public IntPtr reserved;
            public int reservedBytes;
            public int flagsEx;
        }

        [DllImport("comdlg32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        private static extern bool GetOpenFileNameW(ref OpenFileName openFileName);
#endif

        private HumanoidPoseDriver poseDriver;
        private RuntimeGltfInstance currentAvatar;
        private string currentAvatarName;
        private string status;
        private bool loading;

        public string CurrentAvatarName => currentAvatarName;
        public string Status => status;

        private void SetStatus(string value)
        {
            status = value;
#if UNITY_WEBGL && !UNITY_EDITOR
            WebPwaSettings_SetAvatarStatus(value ?? string.Empty);
#endif
        }

        public void OpenFilePicker()
        {
            if (loading) return;
#if UNITY_WEBGL && !UNITY_EDITOR
            SetStatus("VRMファイルを選択してください。");
            WebVrmPicker_Open(gameObject.name);
#elif UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
            var dialog = new OpenFileName
            {
                structSize = Marshal.SizeOf<OpenFileName>(),
                filter = "VRMファイル (*.vrm)\0*.vrm\0\0",
                filterIndex = 1,
                file = new StringBuilder(1024),
                maxFile = 1024,
                fileTitle = new StringBuilder(256),
                maxFileTitle = 256,
                title = "VRMファイルを選択",
                flags = 0x00001000 | 0x00080000 | 0x00000008
            };
            if (!GetOpenFileNameW(ref dialog)) return;
            try
            {
                var path = dialog.file.ToString();
                var bytes = File.ReadAllBytes(path);
                if (bytes.Length > MaximumVrmBytes) throw new InvalidOperationException("VRMのサイズが上限（256 MB）を超えています。");
                SetStatus("VRMを読み込んでいます…");
                StartCoroutine(WatchOperation(LoadAndReplaceAsync(Path.GetFileName(path), bytes)));
            }
            catch (Exception exception) { SetStatus("VRM読み込み失敗: " + exception.Message); }
#else
            SetStatus("VRMファイル選択はWeb版とWindows版で利用できます。");
#endif
        }

#if UNITY_WEBGL && !UNITY_EDITOR
        public void OnVrmFilePicked(string fileName)
        {
            if (loading) return;
            if (string.IsNullOrEmpty(fileName) || !fileName.EndsWith(".vrm", StringComparison.OrdinalIgnoreCase))
            {
                SetStatus("VRMファイルを選択してください。");
                return;
            }
            var size = WebVrmPicker_GetSelectedSize();
            if (size <= 0 || size > MaximumVrmBytes)
            {
                SetStatus("VRMのサイズが上限（256 MB）を超えています。");
                WebVrmPicker_ClearSelected();
                return;
            }
            SetStatus("VRMデータを読み取っています…");
            StartCoroutine(WatchOperation(ReadAndLoadWebVrmAsync(fileName, size)));
        }

        private async Task ReadAndLoadWebVrmAsync(string fileName, int size)
        {
            try
            {
                var bytes = new byte[size];
                for (var offset = 0; offset < size; offset += ChunkBytes)
                {
                    var requested = Math.Min(ChunkBytes, size - offset);
                    var encoded = WebVrmPicker_ReadChunk(offset, requested);
                    var chunk = Convert.FromBase64String(encoded ?? string.Empty);
                    if (chunk.Length != requested) throw new InvalidOperationException("VRMデータを完全に読み取れませんでした。");
                    Buffer.BlockCopy(chunk, 0, bytes, offset, chunk.Length);
                    await Task.Yield();
                }
                SetStatus("VRMモデルを解析しています…");
                await LoadAndReplaceAsync(fileName, bytes);
            }
            finally { WebVrmPicker_ClearSelected(); }
        }
#endif

        private IEnumerator WatchOperation(Task operation)
        {
            loading = true;
            while (!operation.IsCompleted) yield return null;
            if (operation.IsFaulted)
            {
                SetStatus("VRM読み込み失敗: " + operation.Exception.GetBaseException().Message);
                Debug.LogException(operation.Exception.GetBaseException(), this);
            }
            else if (operation.IsCanceled) SetStatus("VRMの読み込みがキャンセルされました。");
            loading = false;
        }

        private async Task LoadAndReplaceAsync(string fileName, byte[] bytes)
        {
            SetStatus("VRMをUnityへ読み込んでいます…");
            var nextAvatar = await LoadVrmBytesAsync(fileName, bytes);
            SetStatus("VRMを追跡対象へ設定しています…");
            var nextAnimator = nextAvatar != null && nextAvatar.Root != null
                ? nextAvatar.Root.GetComponentInChildren<Animator>(true)
                : null;
            poseDriver = FindObjectOfType<HumanoidPoseDriver>();
            if (poseDriver == null || nextAnimator == null || !nextAnimator.isHuman)
            {
                if (nextAvatar != null) Destroy(nextAvatar.gameObject);
                throw new InvalidOperationException("Humanoid形式のVRMを読み込めませんでした。");
            }

            var oldAnimator = poseDriver.TargetAnimator;
            var oldRenderers = oldAnimator != null
                ? oldAnimator.GetComponentsInChildren<Renderer>(true)
                : new Renderer[0];
            var previousAvatar = currentAvatar;
            nextAvatar.transform.SetParent(poseDriver.transform, false);
            nextAvatar.transform.localPosition = Vector3.zero;
            nextAvatar.transform.localRotation = Quaternion.identity;
            nextAvatar.transform.localScale = Vector3.one;
            if (!poseDriver.SetTargetAnimator(nextAnimator))
            {
                Destroy(nextAvatar.gameObject);
                throw new InvalidOperationException("新しいVRMを追跡対象に設定できませんでした。");
            }

            if (oldAnimator != null) oldAnimator.enabled = false;
            foreach (var renderer in oldRenderers)
                if (renderer != null) renderer.enabled = false;
            if (previousAvatar != null) Destroy(previousAvatar.gameObject);
            currentAvatar = nextAvatar;
            currentAvatarName = fileName;
            SetStatus("VRMを切り替えました。");
        }

        private static async Task<RuntimeGltfInstance> LoadVrmBytesAsync(string fileName, byte[] bytes)
        {
            var utilityType = Assembly.Load("VRM").GetType("VRM.VrmUtility", true);
            var awaitAssembly = Assembly.Load("UniGLTF.Utils");
#if UNITY_WEBGL && !UNITY_EDITOR
            // WebGL is single-threaded by default; RuntimeOnlyAwaitCaller uses Task.Run,
            // which can leave the importer waiting forever in this player.
            var awaitCallerType = awaitAssembly.GetType("UniGLTF.ImmediateCaller", true);
#else
            var awaitCallerType = awaitAssembly.GetType("UniGLTF.RuntimeOnlyAwaitCaller", true);
#endif
            var method = utilityType.GetMethod("LoadBytesAsync", BindingFlags.Public | BindingFlags.Static);
            if (method == null) throw new MissingMethodException("VRM.VrmUtility.LoadBytesAsync was not found.");

            var parameters = method.GetParameters();
            var arguments = new object[parameters.Length];
            arguments[0] = fileName;
            arguments[1] = bytes;
#if UNITY_WEBGL && !UNITY_EDITOR
            arguments[2] = Activator.CreateInstance(awaitCallerType);
#else
            arguments[2] = Activator.CreateInstance(awaitCallerType, new object[] { 1f / 1000f });
#endif
            for (var index = 3; index < parameters.Length; index++)
                arguments[index] = parameters[index].HasDefaultValue ? parameters[index].DefaultValue : null;

            var task = method.Invoke(null, arguments) as Task;
            if (task == null) throw new InvalidOperationException("VRM loader returned no asynchronous task.");
            await task;
            return task.GetType().GetProperty("Result").GetValue(task) as RuntimeGltfInstance;
        }
    }
}
