using System.Collections;
using UnityEngine;
using UnityEngine.Networking;

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
        private Camera targetCamera;
        private Transform background;
        private MeshRenderer backgroundRenderer;
        private Texture2D texture;

        private void Awake()
        {
            targetCamera = GetComponent<Camera>() ?? Camera.main;
            var quad = GameObject.CreatePrimitive(PrimitiveType.Quad);
            quad.name = "Tracker Video Background";
            background = quad.transform;
            background.SetParent(targetCamera.transform, false);
            background.localPosition = Vector3.forward * backgroundDistance;
            background.localRotation = Quaternion.identity;
            Destroy(quad.GetComponent<Collider>());
            backgroundRenderer = quad.GetComponent<MeshRenderer>();
            var shader = Shader.Find("Unlit/Texture");
            backgroundRenderer.material = new Material(shader);
            backgroundRenderer.enabled = false;
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

        private void FitToSource(int width, int height)
        {
            float viewHeight = 2f * backgroundDistance *
                               Mathf.Tan(targetCamera.fieldOfView * Mathf.Deg2Rad * .5f);
            float viewWidth = viewHeight * targetCamera.aspect;
            float sourceAspect = (float)width / Mathf.Max(height, 1);
            float fittedWidth;
            float fittedHeight;
            if (sourceAspect > targetCamera.aspect)
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
            if (texture != null) Destroy(texture);
            if (backgroundRenderer != null && backgroundRenderer.material != null)
                Destroy(backgroundRenderer.material);
        }
    }
}
