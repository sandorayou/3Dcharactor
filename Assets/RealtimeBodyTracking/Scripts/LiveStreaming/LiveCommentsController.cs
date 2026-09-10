using System.Collections;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// Owns comment subscriptions. The panel calls StartReceiving only when it
    /// is visible, so closing the panel releases network activity immediately.
    public sealed class LiveCommentsController : MonoBehaviour
    {
        private Coroutine receiveRoutine;
        private Transform output;
        private LiveStreamProvider provider;

        public bool IsReceiving { get; private set; }

        public void StartReceiving(LiveStreamProvider selectedProvider, Transform outputRoot)
        {
            StopReceiving();
            provider = selectedProvider;
            output = outputRoot;
            IsReceiving = true;
            receiveRoutine = StartCoroutine(ReceiveLoop());
        }

        public void StopReceiving()
        {
            if (receiveRoutine != null) StopCoroutine(receiveRoutine);
            receiveRoutine = null;
            output = null;
            IsReceiving = false;
        }

        private IEnumerator ReceiveLoop()
        {
            while (IsReceiving)
            {
                // Provider adapters append messages to output only while the
                // panel is open. They are intentionally not polled in standby.
                yield return new WaitForSeconds(5f);
            }
        }

        private void OnDisable() => StopReceiving();
        private void OnDestroy() => StopReceiving();
    }
}
