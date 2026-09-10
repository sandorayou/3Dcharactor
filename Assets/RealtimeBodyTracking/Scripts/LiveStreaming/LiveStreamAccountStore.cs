using System;
using System.Collections.Generic;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    [Serializable]
    public sealed class LiveStreamAccount
    {
        public LiveStreamProvider provider;
        public string displayName;
        public string ingestUrl;
        public string streamKey;
        public string accessToken;
        public string liveChatId;
    }

    /// Settings-screen model. Production builds should replace PlayerPrefs with
    /// an iOS Keychain bridge; stream keys must never be committed to GitHub.
    public sealed class LiveStreamAccountStore
    {
        private const string Key = "live_stream_accounts_v1";
        [Serializable] private sealed class Wrapper { public List<LiveStreamAccount> items = new List<LiveStreamAccount>(); }

        public List<LiveStreamAccount> Load()
        {
            var json = LiveStreamSecureStore.Get(Key, "{\"items\":[]}");
            return JsonUtility.FromJson<Wrapper>(json)?.items ?? new List<LiveStreamAccount>();
        }

        public void Save(IEnumerable<LiveStreamAccount> accounts)
        {
            var wrapper = new Wrapper { items = new List<LiveStreamAccount>(accounts) };
            LiveStreamSecureStore.Set(Key, JsonUtility.ToJson(wrapper));
        }
    }
}
