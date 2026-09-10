using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    /// UI-facing controller for a settings screen that is rendered by Unity,
    /// while the native publisher captures only the camera and microphone.
    public sealed class LiveStreamSettingsController : MonoBehaviour
    {
        [SerializeField] private LiveStreamingController streaming;
        private readonly LiveStreamAccountStore store = new LiveStreamAccountStore();

        public void SelectAccount(LiveStreamProvider provider)
        {
            var account = store.Load().Find(x => x.provider == provider);
            if (account == null || streaming == null) return;
            streaming.Configure(account.provider, account.ingestUrl, account.streamKey);
        }

        public void SaveAccount(LiveStreamProvider provider, string displayName, string ingestUrl, string streamKey)
        {
            var accounts = store.Load();
            accounts.RemoveAll(x => x.provider == provider);
            accounts.Add(new LiveStreamAccount { provider = provider, displayName = displayName, ingestUrl = ingestUrl, streamKey = streamKey });
            store.Save(accounts);
        }

        public bool HasAccount(LiveStreamProvider provider) => store.Load().Exists(x => x.provider == provider);
    }
}
