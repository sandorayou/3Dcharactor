import Foundation
import AVFoundation

#if canImport(RTMPHaishinKit)
import RTMPHaishinKit
#endif

/// Native iOS publisher used by the Unity C# facade.
/// Add https://github.com/shogo4405/HaishinKit.swift to the generated Xcode project
/// and select the RTMPHaishinKit product to enable publishing.
final class UnityLivePublisher {
    static let shared = UnityLivePublisher()
    private var front = true
#if canImport(RTMPHaishinKit)
    private var connection: RTMPConnection?
    private var stream: RTMPStream?
    private var mixer: MediaMixer?
#endif

    func start(url: String, key: String, width: Int, height: Int, fps: Int, videoKbps: Int, audioKbps: Int) -> Int {
#if canImport(RTMPHaishinKit)
        let connection = RTMPConnection()
        let stream = RTMPStream(connection: connection)
        let mixer = MediaMixer()
        self.connection = connection; self.stream = stream; self.mixer = mixer
        Task { @MainActor in
            do {
                let audio = AVCaptureDevice.default(for: .audio)
                let camera = AVCaptureDevice.default(.builtInWideAngleCamera, for: .video,
                    position: self.front ? .front : .back)
                try await mixer.attachAudio(audio)
                try await mixer.attachVideo(camera)
                mixer.addOutput(stream)
                var video = VideoCodecSettings()
                video.width = width
                video.height = height
                video.bitrate = videoKbps * 1000
                video.maxKeyFrameIntervalDuration = 2
                await stream.setVideoSettings(video)
                var audioSettings = AudioCodecSettings()
                audioSettings.bitrate = audioKbps * 1000
                await stream.setAudioSettings(audioSettings)
                connection.connect(url)
                stream.publish(key)
            } catch { self.stop() }
        }
        return 0
#else
        return -1
#endif
    }

    func stop() {
#if canImport(RTMPHaishinKit)
        stream?.close(); connection?.close(); stream = nil; connection = nil; mixer = nil
#endif
    }

    func setCamera(front: Bool) {
        self.front = front
#if canImport(RTMPHaishinKit)
        guard let mixer else { return }
        Task { @MainActor in
            let camera = AVCaptureDevice.default(.builtInWideAngleCamera, for: .video,
                position: front ? .front : .back)
            try? await mixer.attachVideo(camera)
        }
#endif
    }

    func setMuted(_ muted: Bool) {
#if canImport(RTMPHaishinKit)
        stream?.audioMixerSettings.isMuted = muted
#endif
    }
}

@_cdecl("NativeStart")
public func nativeStart(_ url: UnsafePointer<CChar>, _ key: UnsafePointer<CChar>, _ width: Int32,
                        _ height: Int32, _ fps: Int32, _ videoKbps: Int32, _ audioKbps: Int32) -> Int32 {
    UnityLivePublisher.shared.start(url: String(cString: url), key: String(cString: key),
        width: Int(width), height: Int(height), fps: Int(fps), videoKbps: Int(videoKbps), audioKbps: Int(audioKbps))
}

@_cdecl("NativeStop") public func nativeStop() { UnityLivePublisher.shared.stop() }
@_cdecl("NativeSetCamera") public func nativeSetCamera(_ front: Int32) {
    UnityLivePublisher.shared.setCamera(front: front != 0)
}
@_cdecl("NativeSetMuted") public func nativeSetMuted(_ muted: Int32) {
    UnityLivePublisher.shared.setMuted(muted != 0)
}
