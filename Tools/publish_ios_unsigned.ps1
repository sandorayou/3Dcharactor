param(
    [string]$Branch = 'codex/ios-small-build-20261001',
    [switch]$SkipExport
)
$ErrorActionPreference = 'Stop'
$portRoot = Split-Path $PSScriptRoot -Parent
Set-Location -LiteralPath $portRoot
if (-not $SkipExport) { & (Join-Path $PSScriptRoot 'export_ios_windows_port.ps1') }
$portOutput = Join-Path $portRoot 'Builds\iOS-WindowsPort'
$portManifest = Get-Content -LiteralPath (Join-Path $portOutput 'source-manifest.json') -Raw | ConvertFrom-Json
$sourceChanges = & git diff --name-only $portManifest.commit HEAD -- Assets Packages ProjectSettings
if ($LASTEXITCODE -ne 0 -or $sourceChanges) { throw 'The export is older than the committed source. Export again before publishing.' }
$portCpp = Get-ChildItem -LiteralPath (Join-Path $portOutput 'Il2CppOutputProject\Source\il2cppOutput') -Filter 'Assembly-CSharp*.cpp' |
    ForEach-Object { Get-Content -LiteralPath $_.FullName -Raw }
foreach ($symbol in @('OnNativePoseJson','OnNativeCameraPermissionGranted','TryTakeLatestPose','WindowsPortStartRecording','OnIOSRecordingState')) {
    if (-not ($portCpp -match $symbol)) { throw "The exported player is missing $symbol" }
}
foreach ($model in @('pose_landmarker_lite.task','hand_landmarker.task','face_landmarker.task','selfie_multiclass.tflite')) {
    $sourceHash = (Get-FileHash -LiteralPath (Join-Path $portRoot "Assets\StreamingAssets\$model")).Hash
    $exportHash = (Get-FileHash -LiteralPath (Join-Path $portOutput "Data\Raw\$model")).Hash
    if ($sourceHash -ne $exportHash) { throw "Exported model mismatch: $model" }
}
$portSizes = @{}
foreach ($group in @('Data','Libraries','Il2CppOutputProject')) {
    $portSizes[$group] = (Get-ChildItem -LiteralPath (Join-Path $portOutput $group) -Recurse -File |
        Measure-Object -Property Length -Sum).Sum
}
$portSizes | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $portOutput 'size-report.json') -Encoding utf8
Add-Type -AssemblyName System.IO.Compression.FileSystem
$portZip = Join-Path $portRoot 'Builds\iOS-WindowsPort.zip'
if ([IO.Path]::GetFullPath($portZip) -ne [IO.Path]::GetFullPath((Join-Path $portRoot 'Builds\iOS-WindowsPort.zip'))) {
    throw 'Unexpected archive destination.'
}
if (Test-Path -LiteralPath $portZip) { Remove-Item -LiteralPath $portZip }
[IO.Compression.ZipFile]::CreateFromDirectory($portOutput, $portZip, [IO.Compression.CompressionLevel]::Optimal, $false)
Write-Output "iOS archive: $((Get-Item -LiteralPath $portZip).Length) bytes"
& git add -f -- Builds/iOS-WindowsPort.zip
if ($LASTEXITCODE -ne 0) { throw 'Could not stage iOS export.' }
& git commit --only -m 'Include compact iOS Xcode export for unsigned IPA workflow' -- Builds/iOS-WindowsPort.zip
if ($LASTEXITCODE -ne 0) { throw 'Could not commit iOS export.' }
& git push origin "HEAD:refs/heads/$Branch"
if ($LASTEXITCODE -ne 0) { throw 'GitHub push failed.' }
$portPublishedCommit = (& git rev-parse HEAD).Trim()
& gh workflow run build-ios.yml --repo sandorayou/3Dcharactor --ref $Branch
if ($LASTEXITCODE -ne 0) { throw 'GitHub workflow dispatch failed.' }
$portRun = $null
for ($attempt = 0; $attempt -lt 10; $attempt++) {
    $portRuns = & gh run list --repo sandorayou/3Dcharactor --workflow build-ios.yml --branch $Branch --event workflow_dispatch --limit 10 --json databaseId,url,headSha | ConvertFrom-Json
    if ($LASTEXITCODE -ne 0) { throw 'Could not identify workflow run.' }
    $portRun = $portRuns | Where-Object { $_.headSha -eq $portPublishedCommit } | Select-Object -First 1
    if ($portRun) { break }
    Start-Sleep -Seconds 2
}
if (-not $portRun) { throw 'Workflow dispatched, but its run is not visible yet.' }
$portRun | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $portOutput 'github-run.json') -Encoding utf8
Write-Output "Workflow: $($portRun.url)"
& gh run watch $portRun.databaseId --repo sandorayou/3Dcharactor --exit-status --interval 60
if ($LASTEXITCODE -ne 0) { throw "Unsigned IPA build failed: $($portRun.url)" }
$portArtifacts = Join-Path $portRoot ('Builds\iOS-IPA\' + $portRun.databaseId)
& gh run download $portRun.databaseId --repo sandorayou/3Dcharactor --name MyProject5-unsigned-ipa --dir $portArtifacts
if ($LASTEXITCODE -ne 0) { throw 'Build succeeded, but IPA artifact download failed.' }
Write-Output "SUCCESS: unsigned IPA saved to $portArtifacts"
