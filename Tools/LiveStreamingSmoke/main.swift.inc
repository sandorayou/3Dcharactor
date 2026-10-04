// Appended to the actual StreamOutput source in a temporary Swift package.
// This executes the production RTMP connection, publish, append and stop code.
import Foundation
import CoreVideo
import AudioToolbox
import Darwin

func require(_ condition: Bool, _ message: String) {
    if !condition { fputs("ERROR: \(message)\n", stderr); exit(1) }
}
func pump(_ seconds: Double) {
    let end = Date().addingTimeInterval(seconds)
    while Date() < end { RunLoop.main.run(until: Date().addingTimeInterval(0.01)) }
}
func frame(_ index: Int) -> CMSampleBuffer {
    var pixels: CVPixelBuffer?
    require(CVPixelBufferCreate(kCFAllocatorDefault, 128, 128, kCVPixelFormatType_32BGRA,
        [kCVPixelBufferIOSurfacePropertiesKey: [:]] as CFDictionary, &pixels) == kCVReturnSuccess, "pixel buffer")
    let buffer = pixels!
    CVPixelBufferLockBaseAddress(buffer, [])
    let bytes = CVPixelBufferGetBaseAddress(buffer)!.assumingMemoryBound(to: UInt8.self)
    let stride = CVPixelBufferGetBytesPerRow(buffer)
    for y in 0..<128 { for x in 0..<128 {
        let offset = y * stride + x * 4
        bytes[offset] = UInt8((x + index * 3) % 255)
        bytes[offset + 1] = UInt8((y + index * 2) % 255)
        bytes[offset + 2] = 100
        bytes[offset + 3] = 255
    }}
    CVPixelBufferUnlockBaseAddress(buffer, [])
    var format: CMVideoFormatDescription?
    require(CMVideoFormatDescriptionCreateForImageBuffer(allocator: kCFAllocatorDefault,
        imageBuffer: buffer, formatDescriptionOut: &format) == noErr, "video format")
    var timing = CMSampleTimingInfo(duration: CMTime(value: 1, timescale: 30),
        presentationTimeStamp: CMTime(value: Int64(index), timescale: 30), decodeTimeStamp: .invalid)
    var sample: CMSampleBuffer?
    require(CMSampleBufferCreateReadyWithImageBuffer(allocator: kCFAllocatorDefault,
        imageBuffer: buffer, formatDescription: format!, sampleTiming: &timing, sampleBufferOut: &sample) == noErr,
        "video sample")
    return sample!
}
func sound(_ index: Int) -> CMSampleBuffer {
    let count = 1470 // One 30fps frame at 44.1kHz.
    var pcm = [Int16](repeating: 0, count: count)
    for n in 0..<count { pcm[n] = Int16(sin(Double(index * count + n) * 2 * .pi * 440 / 44100) * 8000) }
    var asbd = AudioStreamBasicDescription(mSampleRate: 44100, mFormatID: kAudioFormatLinearPCM,
        mFormatFlags: kAudioFormatFlagIsSignedInteger | kAudioFormatFlagIsPacked,
        mBytesPerPacket: 2, mFramesPerPacket: 1, mBytesPerFrame: 2, mChannelsPerFrame: 1,
        mBitsPerChannel: 16, mReserved: 0)
    var format: CMAudioFormatDescription?
    require(CMAudioFormatDescriptionCreate(allocator: kCFAllocatorDefault, asbd: &asbd,
        layoutSize: 0, layout: nil, magicCookieSize: 0, magicCookie: nil, extensions: nil,
        formatDescriptionOut: &format) == noErr, "audio format")
    var block: CMBlockBuffer?
    require(CMBlockBufferCreateWithMemoryBlock(allocator: kCFAllocatorDefault, memoryBlock: nil,
        blockLength: count * 2, blockAllocator: kCFAllocatorDefault, customBlockSource: nil,
        offsetToData: 0, dataLength: count * 2, flags: 0, blockBufferOut: &block) == kCMBlockBufferNoErr, "audio block")
    pcm.withUnsafeBytes { bytes in
        require(CMBlockBufferReplaceDataBytes(with: bytes.baseAddress!, blockBuffer: block!,
            offsetIntoDestination: 0, dataLength: count * 2) == kCMBlockBufferNoErr, "audio bytes")
    }
    var timing = CMSampleTimingInfo(duration: CMTime(value: 1, timescale: 44100),
        presentationTimeStamp: CMTime(value: Int64(index * count), timescale: 44100), decodeTimeStamp: .invalid)
    var size = 2
    var sample: CMSampleBuffer?
    require(CMSampleBufferCreateReady(allocator: kCFAllocatorDefault, dataBuffer: block,
        formatDescription: format, sampleCount: count, sampleTimingEntryCount: 1,
        sampleTimingArray: &timing, sampleSizeEntryCount: 1, sampleSizeArray: &size,
        sampleBufferOut: &sample) == noErr, "audio sample")
    return sample!
}

LBLogger.with(HaishinKitIdentifier).appender = NullAppender.shared
private let outputs = ["youtube", "twitch", "twitcast"].map { name -> StreamOutput in
    let output = StreamOutput(Destination(name: name, server: "rtmp://127.0.0.1:1935/live", key: name))
    output.stateChanged = { print("\(name): \($0)") }
    return output
}
for output in outputs { output.connect() }
let connectionDeadline = Date().addingTimeInterval(25)
while !outputs.allSatisfy({ $0.publishing }) && Date() < connectionDeadline { pump(0.05) }
require(outputs.allSatisfy({ $0.publishing }), "All three production outputs must publish")

// A separate failure must leave the three good destinations publishing.
private let bad = StreamOutput(Destination(name: "unreachable", server: "rtmp://127.0.0.1:1936/live", key: "invalid"))
bad.connect()
for index in 0..<240 {
    let video = frame(index)
    let audio = sound(index)
    for output in outputs { output.append(video, type: .video); output.append(audio, type: .audioMic) }
    pump(1.0 / 30.0)
}
require(outputs.allSatisfy({ $0.publishing }), "A failed destination must not stop other outputs")
require(!bad.publishing, "Unreachable destination must not report publishing")
bad.stop()
for output in outputs { output.stop() }
pump(0.3)
require(outputs.allSatisfy({ !$0.publishing }), "Stop must clear all publishing states")
print("PASS: three destinations, H.264/AAC samples, isolated failure and stop")
