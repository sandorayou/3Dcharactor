using System.Runtime.InteropServices;
using UnityEngine;

namespace RealtimeBodyTracking.LiveStreaming
{
    internal static class LiveStreamSecureStore
    {
        public static string Get(string key, string fallback)
        {
#if UNITY_IOS && !UNITY_EDITOR
            var pointer = NativeGet(key);
            return pointer == System.IntPtr.Zero ? fallback : Marshal.PtrToStringAnsi(pointer) ?? fallback;
#else
            return PlayerPrefs.GetString(key, fallback);
#endif
        }

        public static void Set(string key, string value)
        {
#if UNITY_IOS && !UNITY_EDITOR
            NativeSet(key, value);
#else
            PlayerPrefs.SetString(key, value); PlayerPrefs.Save();
#endif
        }

#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")] private static extern void NativeSet(string key, string value);
        [DllImport("__Internal")] private static extern System.IntPtr NativeGet(string key);
#endif
    }
}
