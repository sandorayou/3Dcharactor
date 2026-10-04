import UIKit
import ReplayKit
import AVFoundation
import CoreImage
import ImageIO
import Security
import VideoToolbox
import HaishinKit
import Logboard

@_silgen_name("MyProjectLiveStreamingNotify")
private func notifyUnity(_ receiver: UnsafePointer<CChar>, _ json: UnsafePointer<CChar>)

private enum StreamSecrets {
    static func query(_ service: String) -> [String: Any] {
        [kSecClass as String: kSecClassGenericPassword,
         kSecAttrService as String: "com.sandorayou.myproject5.live",
         kSecAttrAccount as String: service]
    }
    static func read(_ service: String) -> String {
        var q = query(service)
        q[kSecReturnData as String] = true
        q[kSecMatchLimit as String] = kSecMatchLimitOne
        var result: CFTypeRef?
        guard SecItemCopyMatching(q as CFDictionary, &result) == errSecSuccess,
              let data = result as? Data else { return "" }
        return String(data: data, encoding: .utf8) ?? ""
    }
    static func save(_ key: String, service: String) -> Bool {
        let q = query(service)
        if key.isEmpty {
            let status = SecItemDelete(q as CFDictionary)
            return status == errSecSuccess || status == errSecItemNotFound
        }
        let attributes: [String: Any] = [kSecValueData as String: Data(key.utf8),
            kSecAttrAccessible as String: kSecAttrAccessibleWhenUnlockedThisDeviceOnly]
        let status = SecItemUpdate(q as CFDictionary, attributes as CFDictionary)
        if status == errSecSuccess { return true }
        guard status == errSecItemNotFound else { return false }
        return SecItemAdd(q.merging(attributes) { _, new in new } as CFDictionary, nil) == errSecSuccess
    }
}

private struct Destination {
    let name: String
    let server: String
    let key: String
}

// Each destination owns its connection, encoder and retry timer. One failure
// does not stop the other destinations. All control/append calls run on main.
private final class StreamOutput: NSObject {
    let destination: Destination
    private var connection: RTMPConnection?
    private var stream: RTMPStream?
    private var retry: DispatchWorkItem?
    private var watchdog: DispatchWorkItem?
    private var stopped = false
    private var videoSize = CGSize.zero
    private(set) var publishing = false
    var stateChanged: ((String) -> Void)?

    init(_ destination: Destination) { self.destination = destination }

    func connect() {
        guard !stopped else { return }
        retry = nil
        let connection = RTMPConnection()
        let stream = RTMPStream(connection: connection)
        connection.timeout = 15
        connection.addEventListener(.rtmpStatus, selector: #selector(status(_:)), observer: self)
        connection.addEventListener(.ioError, selector: #selector(ioError(_:)), observer: self)
        stream.addEventListener(.rtmpStatus, selector: #selector(status(_:)), observer: self)
        stream.videoSettings = VideoCodecSettings(videoSize: CGSize(width: 720, height: 1280),
            bitRate: 2_000_000, profileLevel: kVTProfileLevel_H264_Baseline_AutoLevel as String)
        stream.videoSettings.maxKeyFrameIntervalDuration = 2
        stream.videoSettings.scalingMode = .letterbox
        stream.videoSettings.frameInterval = VideoCodecSettings.frameInterval30
        stream.audioSettings = AudioCodecSettings(bitRate: 96_000)
        self.connection = connection
        self.stream = stream
        videoSize = .zero
        stateChanged?("接続中")
        let timeout = DispatchWorkItem { [weak self] in self?.reconnect() }
        watchdog = timeout
        DispatchQueue.main.asyncAfter(deadline: .now() + 20, execute: timeout)
        connection.connect(destination.server)
    }

    @objc private func status(_ notification: Notification) {
        guard let data = Event.from(notification).data as? ASObject,
              let code = data["code"] as? String else { return }
        // Events may arrive on the library's socket queue. Discard old events.
        let source = notification.object as AnyObject?
        DispatchQueue.main.async { [weak self] in
            guard let self = self, !self.stopped,
                  source === self.connection || source === self.stream else { return }
            switch code {
            case "NetConnection.Connect.Success": self.stream?.publish(self.destination.key)
            case "NetStream.Publish.Start":
                self.watchdog?.cancel()
                self.publishing = true
                self.stateChanged?("配信中")
            case "NetConnection.Connect.Rejected", "NetStream.Publish.BadName":
                self.disconnect()
                self.stateChanged?("設定を確認してください")
            case "NetConnection.Connect.Failed", "NetConnection.Connect.Closed",
                 "NetConnection.Connect.AppShutdown", "NetStream.Publish.Idle",
                 "NetStream.Unpublish.Success": self.reconnect()
            default: break
            }
        }
    }

    @objc private func ioError(_ notification: Notification) {
        let source = notification.object as AnyObject?
        DispatchQueue.main.async { [weak self] in
            guard let self = self, source === self.connection else { return }
            self.reconnect()
        }
    }

    private func disconnect() {
        watchdog?.cancel()
        watchdog = nil
        publishing = false
        let connection = self.connection
        let stream = self.stream
        self.connection = nil
        self.stream = nil
        connection?.removeEventListener(.rtmpStatus, selector: #selector(status(_:)), observer: self)
        connection?.removeEventListener(.ioError, selector: #selector(ioError(_:)), observer: self)
        stream?.removeEventListener(.rtmpStatus, selector: #selector(status(_:)), observer: self)
        stream?.close()
        connection?.close()
    }

    private func reconnect() {
        guard !stopped, retry == nil else { return }
        disconnect()
        stateChanged?("再接続中")
        let work = DispatchWorkItem { [weak self] in self?.connect() }
        retry = work
        DispatchQueue.main.asyncAfter(deadline: .now() + 5, execute: work)
    }

    func append(_ sample: CMSampleBuffer, type: RPSampleBufferType) {
        guard publishing, let stream = stream, CMSampleBufferDataIsReady(sample) else { return }
        if type == .video {
            guard let image = CMSampleBufferGetImageBuffer(sample) else { return }
            let size = CGSize(width: CVPixelBufferGetWidth(image), height: CVPixelBufferGetHeight(image))
            if videoSize != size {
                videoSize = size
                let scale = min(1, 1280 / max(size.width, size.height))
                stream.videoSettings.videoSize = CGSize(width: max(2, floor(size.width * scale / 2) * 2),
                    height: max(2, floor(size.height * scale / 2) * 2))
            }
            stream.append(sample)
        } else if type == .audioMic { stream.append(sample, track: 0) }
    }

    func stop() {
        stopped = true
        retry?.cancel()
        retry = nil
        disconnect()
    }
}

@objc(MyProjectLiveStreaming)
final class MyProjectLiveStreaming: NSObject, RPScreenRecorderDelegate {
    private static let shared = MyProjectLiveStreaming()
    private var receiver = ""
    private var active = false
    private var generation = 0
    private var captureStarted = false
    private var capturePending = false
    private var stoppingCapture = false
    private var lastVideoTime = CMTime.invalid
    private var previousIdleTimerDisabled = false
    private var outputs: [StreamOutput] = []
    private var states: [String: String] = [:]
    private let pendingSamples = DispatchSemaphore(value: 2)
    private let imageContext = CIContext(options: [.cacheIntermediates: false])
    private var settings: StreamSettingsController?

    override init() {
        super.init()
        // Never log RTMP messages, URLs or stream keys through this library.
        LBLogger.with(HaishinKitIdentifier).appender = NullAppender.shared
        NotificationCenter.default.addObserver(self, selector: #selector(background),
            name: UIApplication.didEnterBackgroundNotification, object: nil)
    }

    @objc(show:) static func show(_ receiver: String) { shared.showSettings(receiver) }
    @objc static func stop() { shared.finish("配信終了") }
    @objc static func isActive() -> Bool { shared.active || shared.capturePending || shared.stoppingCapture }
    @objc private func background() { if active { finish("バックグラウンドに移ったため配信終了") } }

    private func emit(_ summary: String? = nil) {
        let text = summary ?? outputs.map { $0.destination.name + ": " + (states[$0.destination.name] ?? "接続中") }.joined(separator: "\n")
        guard let data = try? JSONSerialization.data(withJSONObject: ["active": active, "summary": text]),
              let json = String(data: data, encoding: .utf8) else { return }
        receiver.withCString { r in json.withCString { notifyUnity(r, $0) } }
    }

    private func showSettings(_ receiver: String) {
        guard !Self.isActive(), settings == nil else { return }
        self.receiver = receiver
        guard !RPScreenRecorder.shared().isRecording else { emit("録画を終了してから配信を開始してください"); return }
        guard let root = UIApplication.shared.windows.first(where: { $0.isKeyWindow })?.rootViewController else { return }
        let controller = StreamSettingsController()
        controller.onCancel = { [weak self] in self?.settings = nil }
        controller.onStart = { [weak self, weak controller] destinations in
            controller?.dismiss(animated: true) { self?.settings = nil; self?.begin(destinations) }
        }
        settings = controller
        let navigation = UINavigationController(rootViewController: controller)
        navigation.modalPresentationStyle = .fullScreen
        root.present(navigation, animated: true)
    }

    private func begin(_ destinations: [Destination]) {
        guard !active, !destinations.isEmpty else { return }
        let recorder = RPScreenRecorder.shared()
        guard recorder.isAvailable, !recorder.isRecording else { emit("画面取得を開始できません。録画状態を確認してください"); return }
        active = true
        previousIdleTimerDisabled = UIApplication.shared.isIdleTimerDisabled
        UIApplication.shared.isIdleTimerDisabled = true
        lastVideoTime = .invalid
        generation += 1
        let token = generation
        emit("マイクの許可を確認中")
        AVAudioSession.sharedInstance().requestRecordPermission { [weak self] allowed in
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.25) {
                guard let self = self, self.active, self.generation == token else { return }
                guard allowed else { self.finish("設定アプリでマイクを許可してください"); return }
                guard UIApplication.shared.applicationState == .active else { self.finish("アプリを開いてから開始してください"); return }
                do {
                    let audio = AVAudioSession.sharedInstance()
                    try audio.setCategory(.playAndRecord, mode: .videoChat, options: [.defaultToSpeaker, .allowBluetooth])
                    try audio.setActive(true)
                } catch { self.finish("マイクの初期化に失敗しました"); return }
                self.outputs = destinations.map { destination in
                    let output = StreamOutput(destination)
                    output.stateChanged = { [weak self] state in
                        guard let self = self, self.active, self.generation == token else { return }
                        self.states[destination.name] = state
                        self.emit()
                    }
                    return output
                }
                recorder.delegate = self
                recorder.isMicrophoneEnabled = true
                self.capturePending = true
                self.emit("画面共有の開始を待っています")
                recorder.startCapture(handler: { [weak self] sample, type, error in
                    guard let self = self else { return }
                    if error != nil {
                        DispatchQueue.main.async { if self.generation == token { self.finish("画面取得が中断されました") } }
                        return
                    }
                    guard type == .video || type == .audioMic,
                          self.pendingSamples.wait(timeout: .now()) == .success else { return }
                    DispatchQueue.main.async {
                        defer { self.pendingSamples.signal() }
                        guard self.active, self.generation == token else { return }
                        if type == .video {
                            let time = CMSampleBufferGetPresentationTimeStamp(sample)
                            if self.lastVideoTime.isValid && CMTimeGetSeconds(time - self.lastVideoTime) < 1.0 / 30.0 { return }
                            self.lastVideoTime = time
                        }
                        guard let normalized = type == .video ? self.orient(sample) : sample else { return }
                        for output in self.outputs { output.append(normalized, type: type) }
                    }
                }, completionHandler: { [weak self] error in
                    DispatchQueue.main.async {
                        guard let self = self else { return }
                        self.capturePending = false
                        guard self.active, self.generation == token else {
                            if error == nil { self.stopCapture() }
                            return
                        }
                        guard error == nil else { self.finish("画面共有を開始できませんでした"); return }
                        self.captureStarted = true
                        for output in self.outputs { output.connect() }
                    }
                })
            }
        }
    }

    // ReplayKit buffers carry orientation separately. Bake it into the pixels
    // so all three services receive upright video, including on iOS 15.
    private func orient(_ sample: CMSampleBuffer) -> CMSampleBuffer? {
        guard let value = CMGetAttachment(sample, key: RPVideoSampleOrientationKey as CFString,
                attachmentModeOut: nil) as? NSNumber,
              let orientation = CGImagePropertyOrientation(rawValue: value.uint32Value),
              orientation != .up, let input = CMSampleBufferGetImageBuffer(sample) else { return sample }
        let image = CIImage(cvPixelBuffer: input).oriented(orientation)
        let extent = image.extent
        var pixels: CVPixelBuffer?
        guard CVPixelBufferCreate(kCFAllocatorDefault, Int(extent.width), Int(extent.height),
            kCVPixelFormatType_32BGRA, [kCVPixelBufferIOSurfacePropertiesKey: [:]] as CFDictionary, &pixels) == kCVReturnSuccess,
            let pixels = pixels else { return nil }
        imageContext.render(image.transformed(by: CGAffineTransform(translationX: -extent.minX, y: -extent.minY)), to: pixels)
        var format: CMVideoFormatDescription?
        guard CMVideoFormatDescriptionCreateForImageBuffer(allocator: kCFAllocatorDefault, imageBuffer: pixels,
            formatDescriptionOut: &format) == noErr, let format = format else { return nil }
        var timing = CMSampleTimingInfo(duration: CMSampleBufferGetDuration(sample),
            presentationTimeStamp: CMSampleBufferGetPresentationTimeStamp(sample), decodeTimeStamp: .invalid)
        var result: CMSampleBuffer?
        guard CMSampleBufferCreateReadyWithImageBuffer(allocator: kCFAllocatorDefault, imageBuffer: pixels,
            formatDescription: format, sampleTiming: &timing, sampleBufferOut: &result) == noErr else { return nil }
        return result
    }

    private func finish(_ message: String) {
        guard active else { return }
        active = false
        UIApplication.shared.isIdleTimerDisabled = previousIdleTimerDisabled
        generation += 1
        for output in outputs { output.stop() }
        outputs = []
        states = [:]
        let recorder = RPScreenRecorder.shared()
        if captureStarted {
            captureStarted = false
            stopCapture()
        }
        recorder.isMicrophoneEnabled = false
        emit(message)
    }

    private func stopCapture() {
        stoppingCapture = true
        RPScreenRecorder.shared().stopCapture { [weak self] _ in
            DispatchQueue.main.async { self?.stoppingCapture = false }
        }
    }

    func screenRecorder(_ screenRecorder: RPScreenRecorder, didStopRecordingWith error: Error,
                        previewViewController: RPPreviewViewController?) {
        DispatchQueue.main.async { self.finish("画面共有が終了しました") }
    }
}

private final class StreamSettingsController: UIViewController {
    private let names = ["YouTube", "Twitch", "ツイキャス"]
    private var toggles: [UISwitch] = []
    private var servers: [UITextField] = []
    private var keys: [UITextField] = []
    var onStart: (([Destination]) -> Void)?
    var onCancel: (() -> Void)?

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "配信先を選択"
        view.backgroundColor = .systemBackground
        navigationItem.leftBarButtonItem = UIBarButtonItem(title: "閉じる", style: .plain, target: self, action: #selector(cancel))
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: "配信開始", style: .done, target: self, action: #selector(start))
        let scroll = UIScrollView()
        scroll.keyboardDismissMode = .interactive
        scroll.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(scroll)
        let stack = UIStackView()
        stack.axis = .vertical
        stack.spacing = 14
        stack.translatesAutoresizingMaskIntoConstraints = false
        scroll.addSubview(stack)
        NSLayoutConstraint.activate([
            scroll.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scroll.bottomAnchor.constraint(equalTo: view.keyboardLayoutGuide.topAnchor),
            scroll.leadingAnchor.constraint(equalTo: view.leadingAnchor), scroll.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            stack.topAnchor.constraint(equalTo: scroll.contentLayoutGuide.topAnchor, constant: 20),
            stack.bottomAnchor.constraint(equalTo: scroll.contentLayoutGuide.bottomAnchor, constant: -20),
            stack.leadingAnchor.constraint(equalTo: scroll.contentLayoutGuide.leadingAnchor, constant: 20),
            stack.trailingAnchor.constraint(equalTo: scroll.contentLayoutGuide.trailingAnchor, constant: -20),
            stack.widthAnchor.constraint(equalTo: scroll.frameLayoutGuide.widthAnchor, constant: -40)])
        let description = UILabel()
        description.numberOfLines = 0
        description.text = "1つでも複数でも選べます。各サービスの配信設定にあるサーバーURLとストリームキーを入力してください。\n画面の映像とマイク音声を送信します。キーはこのiPhoneのKeychainに保存します。"
        stack.addArrangedSubview(description)
        for name in names {
            let row = UIStackView()
            row.axis = .horizontal
            let label = UILabel(); label.text = name
            let toggle = UISwitch()
            toggle.isOn = UserDefaults.standard.bool(forKey: "live.enabled." + name)
            row.addArrangedSubview(label); row.addArrangedSubview(toggle)
            stack.addArrangedSubview(row); toggles.append(toggle)
            let server = field("サーバーURL（rtmp:// または rtmps://）", secure: false)
            server.text = StreamSecrets.read(name + ".server")
            let key = field("ストリームキー", secure: true)
            key.text = StreamSecrets.read(name)
            stack.addArrangedSubview(server); stack.addArrangedSubview(key)
            servers.append(server); keys.append(key)
        }
        let note = UILabel(); note.numberOfLines = 0; note.font = .preferredFont(forTextStyle: .footnote)
        note.text = "同時配信は送信先の数だけ通信量が増えます。配信中はこのアプリを開いたままにしてください。録画との同時使用はできません。"
        stack.addArrangedSubview(note)
    }

    private func field(_ placeholder: String, secure: Bool) -> UITextField {
        let field = UITextField()
        field.borderStyle = .roundedRect
        field.placeholder = placeholder
        field.isSecureTextEntry = secure
        field.autocapitalizationType = .none
        field.autocorrectionType = .no
        field.spellCheckingType = .no
        field.keyboardType = .asciiCapable
        field.heightAnchor.constraint(equalToConstant: 48).isActive = true
        return field
    }

    @objc private func cancel() { dismiss(animated: true) { self.onCancel?() } }

    @objc private func start() {
        var destinations: [Destination] = []
        for index in names.indices where toggles[index].isOn {
            let server = (servers[index].text ?? "").trimmingCharacters(in: .whitespacesAndNewlines)
            let key = (keys[index].text ?? "").trimmingCharacters(in: .whitespacesAndNewlines)
            guard let url = URLComponents(string: server),
                  ["rtmp", "rtmps"].contains(url.scheme?.lowercased() ?? ""),
                  let host = url.host, !host.isEmpty, url.user == nil, url.password == nil,
                  !url.path.isEmpty, !key.isEmpty,
                  !server.contains(where: { $0.isWhitespace }), !key.contains(where: { $0.isWhitespace }) else {
                error(names[index] + "のサーバーURLとストリームキーを確認してください"); return
            }
            destinations.append(Destination(name: names[index], server: server, key: key))
        }
        guard !destinations.isEmpty else { error("配信先を1つ以上選んでください"); return }
        for index in names.indices {
            guard StreamSecrets.save(keys[index].text ?? "", service: names[index]),
                  StreamSecrets.save(servers[index].text ?? "", service: names[index] + ".server") else {
                error("ストリームキーを保存できませんでした"); return
            }
            UserDefaults.standard.set(toggles[index].isOn, forKey: "live.enabled." + names[index])
        }
        view.endEditing(true)
        onStart?(destinations)
    }

    private func error(_ message: String) {
        let alert = UIAlertController(title: "配信設定", message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default))
        present(alert, animated: true)
    }
}
