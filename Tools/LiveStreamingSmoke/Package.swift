// swift-tools-version:5.9
import PackageDescription

let package = Package(name: "LiveStreamingSmoke", platforms: [.macOS(.v13)],
    dependencies: [
        .package(url: "https://github.com/HaishinKit/HaishinKit.swift.git", exact: "1.9.9"),
        .package(url: "https://github.com/shogo4405/Logboard.git", exact: "2.5.0")
    ], targets: [.executableTarget(name: "LiveStreamingSmoke", dependencies: [
        .product(name: "HaishinKit", package: "HaishinKit.swift"),
        .product(name: "Logboard", package: "Logboard")
    ])])
