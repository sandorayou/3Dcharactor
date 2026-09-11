import Foundation
import AVFoundation
import ReplayKit
import Photos

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
        guard url.hasPrefix("rtmp://") || url.hasPrefix("rtmps://"), !key.isEmpty else { return -1 }
        do {
            let audioSession = AVAudioSession.sharedInstance()
            try audioSession.setCategory(.playAndRecord, mode: .videoRecording, options: [.defaultToSpeaker, .allowBluetooth])
            try audioSession.setActive(true)
        } catch { return -1 }
        let connection = RTMPConnection()
        let stream = RTMPStream(connection: connection)
        let mixer = MediaMixer()
        self.connection = connection; self.stream = stream; self.mixer = mixer
        Task { @MainActor in
            do {
                guard await AVCaptureDevice.requestAccess(for: .video), await AVCaptureDevice.requestAccess(for: .audio) else { self.stop(); return }
                let audio = AVCaptureDevice.default(for: .audio)
                let camera = AVCaptureDevice.default(.builtInWideAngleCamera, for: .video,
                    position: self.front ? .front : .back)
                try await mixer.attachAudio(audio)
                try await mixer.attachVideo(camera)
                mixer.addOutput(stream)
                var video = VideoCodecSettings()
                video.width = width
                video.height = height
                video.bitRate = videoKbps * 1000
                video.videoSize = CGSize(width: width, height: height)
                video.maxKeyFrameIntervalDuration = 2
                try await stream.setVideoSettings(video)
                var audioSettings = AudioCodecSettings()
                audioSettings.bitRate = audioKbps * 1000
                try await stream.setAudioSettings(audioSettings)
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
        guard let mixer else { return }
        Task { @MainActor in
            var settings = mixer.audioMixerSettings
            settings.isMuted = muted
            await mixer.setAudioMixerSettings(settings)
        }
#endif
    }
}

final class UnityScreenRecorder {
    static let shared = UnityScreenRecorder()
    private let recorder = RPScreenRecorder.shared()
    func start() -> Int { guard recorder.isAvailable, !recorder.isRecording else { return -1 }; recorder.startRecording { error in if let error { NSLog("[Recorder] %@", error.localizedDescription) } }; return 0 }
    func stop() { guard recorder.isRecording else { return }; recorder.stopRecording { preview, error in if let error { NSLog("[Recorder] %@", error.localizedDescription); return }; guard let preview else { return }; preview.previewControllerDelegate = nil; preview.exportedVideoQuality = .high; preview.saveVideo(to: .photoLibrary) { saveError in if let saveError { NSLog("[Recorder] save failed %@", saveError.localizedDescription) } } } }
}

@_cdecl("NativeStart")
public func nativeStart(_ url: UnsafePointer<CChar>, _ key: UnsafePointer<CChar>, _ width: Int32,
                        _ height: Int32, _ fps: Int32, _ videoKbps: Int32, _ audioKbps: Int32) -> Int32 {
    return Int32(UnityLivePublisher.shared.start(url: String(cString: url), key: String(cString: key),
        width: Int(width), height: Int(height), fps: Int(fps), videoKbps: Int(videoKbps), audioKbps: Int(audioKbps))
    )
}

@_cdecl("NativeStop") public func nativeStop() { UnityLivePublisher.shared.stop() }
@_cdecl("NativeSetCamera") public func nativeSetCamera(_ front: Int32) {
    UnityLivePublisher.shared.setCamera(front: front != 0)
}
@_cdecl("NativeSetMuted") public func nativeSetMuted(_ muted: Int32) {
    UnityLivePublisher.shared.setMuted(muted != 0)
}
@_cdecl("NativeStartRecording") public func nativeStartRecording() -> Int32 { return Int32(UnityScreenRecorder.shared.start()) }
@_cdecl("NativeStopRecording") public func nativeStopRecording() { UnityScreenRecorder.shared.stop() }
