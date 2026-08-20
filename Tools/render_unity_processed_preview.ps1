param(
    [string]$UnityPath = "C:\Users\81904\Documents\Xfer\2022.3.62f3\Editor\Unity.exe"
)

$ErrorActionPreference = "Stop"
$workspace = Split-Path -Parent $PSScriptRoot
$previewProject = Join-Path $workspace "Output\UnityProcessedPreviewProject"
$output = Join-Path $workspace "Output\unity-processed-preview.png"
$log = Join-Path $workspace "Output\unity-processed-preview.log"

New-Item -ItemType Directory -Force -Path $previewProject | Out-Null
foreach ($directory in @("Assets", "Packages", "ProjectSettings")) {
    $source = Join-Path $workspace $directory
    $destination = Join-Path $previewProject $directory
    New-Item -ItemType Directory -Force -Path $destination | Out-Null
    Copy-Item -Path (Join-Path $source "*") -Destination $destination -Recurse -Force
}

$env:UNITY_PREVIEW_OUTPUT = $output
$arguments = @(
    "-batchmode",
    "-projectPath", "`"$previewProject`"",
    "-executeMethod", "RealtimeBodyTracking.Editor.RenderProcessedAvatarPreview.Render",
    "-logFile", "`"$log`""
)
$process = Start-Process -FilePath $UnityPath -ArgumentList $arguments -Wait -PassThru -WindowStyle Hidden
if ($process.ExitCode -ne 0) {
    throw "Unity preview render failed with exit code $($process.ExitCode). See $log"
}
if (-not (Test-Path -LiteralPath $output)) {
    throw "Unity completed without creating $output. See $log"
}

Write-Output $output
