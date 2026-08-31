using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

namespace RealtimeBodyTracking
{
    /// Displays the exact source selected by python-tracker behind the avatar.
    /// The tracker publishes the latest captured frame, so this also works with
    /// video files and network-capable OpenCV sources, not only a local webcam.
    public sealed class TrackerVideoBackground : MonoBehaviour
    {
        [SerializeField] private string frameUrl = "http://127.0.0.1:39543/frame.jpg";
        [SerializeField, Range(5, 60)] private int refreshRate = 30;
        [SerializeField] private bool mirror = true;
        private RawImage image;
        private Texture2D texture;

        private void Awake()
        {
            var canvasObject = new GameObject("Tracker Video Background", typeof(Canvas));
            var canvas = canvasObject.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceCamera;
            canvas.worldCamera = GetComponent<Camera>() ?? Camera.main;
            canvas.sortingOrder = -100;
            var rect = new GameObject("Source Frame", typeof(RectTransform), typeof(RawImage));
            rect.transform.SetParent(canvasObject.transform, false);
            var transform = rect.GetComponent<RectTransform>();
            transform.anchorMin = Vector2.zero;
            transform.anchorMax = Vector2.one;
            transform.offsetMin = Vector2.zero;
            transform.offsetMax = Vector2.zero;
            image = rect.GetComponent<RawImage>();
            image.color = Color.white;
            image.uvRect = mirror ? new Rect(1f, 0f, -1f, 1f) : new Rect(0f, 0f, 1f, 1f);
            StartCoroutine(PollFrames());
        }

        private IEnumerator PollFrames()
        {
            var wait = new WaitForSecondsRealtime(1f / refreshRate);
            while (true)
            {
                using (var request = UnityWebRequestTexture.GetTexture(frameUrl + "?t=" + Time.realtimeSinceStartup))
                {
                    yield return request.SendWebRequest();
                    if (request.result == UnityWebRequest.Result.Success)
                    {
                        var next = DownloadHandlerTexture.GetContent(request);
                        if (next != null)
                        {
                            if (texture != null) Destroy(texture);
                            texture = next;
                            image.texture = texture;
                        }
                    }
                }
                yield return wait;
            }
        }

        private void OnDestroy()
        {
            if (texture != null) Destroy(texture);
        }
    }
}
