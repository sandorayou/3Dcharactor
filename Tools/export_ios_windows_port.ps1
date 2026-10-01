param(
    [string]$UnityEditor = 'C:\Users\81904\Documents\Xfer\2022.3.62f3\Editor\Unity.exe'
)
$ErrorActionPreference = 'Stop'
$portRoot = Split-Path $PSScriptRoot -Parent
Set-Location -LiteralPath $portRoot
if (-not (Test-Path -LiteralPath $UnityEditor -PathType Leaf)) { throw "Unity editor missing: $UnityEditor" }
$existingPort = Get-CimInstance Win32_Process -Filter "Name = 'Unity.exe'" |
    Where-Object { $_.CommandLine -like '*MyProject5-ios-port-*' }
if ($existingPort) { throw 'An isolated iOS export is already running. Do not start a duplicate.' }

# A committed snapshot avoids modifying or closing the user's running editor.
$portCommit = (& git rev-parse HEAD).Trim()
if ($LASTEXITCODE -ne 0) { throw 'Cannot identify the committed source.' }
$portCheckout = Join-Path $env:TEMP ('MyProject5-ios-port-' + [Guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $portCheckout | Out-Null
$portArchive = Join-Path $portCheckout 'source.zip'
& git archive --format=zip "--output=$portArchive" HEAD Assets Packages ProjectSettings
if ($LASTEXITCODE -ne 0) { throw 'Source snapshot failed.' }
Expand-Archive -LiteralPath $portArchive -DestinationPath $portCheckout
$portLog = Join-Path $portCheckout 'ios-export.log'
Write-Output "Export source: $portCommit; project: $portCheckout"
$portArgs = @('-batchmode', '-nographics', '-quit', '-buildTarget', 'iOS',
    '-projectPath', ('"{0}"' -f $portCheckout),
    '-executeMethod', 'RealtimeBodyTracking.Editor.IOSBuildExporter.Export',
    '-logFile', ('"{0}"' -f $portLog))
$portProcess = Start-Process -FilePath $UnityEditor -ArgumentList $portArgs -WindowStyle Hidden -PassThru -Wait
if ($portProcess.ExitCode -ne 0) {
    Select-String -LiteralPath $portLog -Pattern 'error|failed|exception' -Context 2,5 |
        Select-Object -Last 12 | ForEach-Object { $_.ToString() }
    throw "Unity iOS export failed ($($portProcess.ExitCode)). Log: $portLog"
}
$portSource = Join-Path $portCheckout 'Builds\iOS-WindowsPort'
$portMarker = Join-Path $portSource 'windows-port-export.txt'
if (-not (Test-Path -LiteralPath $portMarker)) { throw "No current iOS export marker: $portLog" }
if ((Get-Content -LiteralPath $portMarker -Raw).Trim() -ne 'WindowsPort-PoseHandFace-Mosaic-v1') {
    throw 'Unexpected iOS export version.'
}
$portDestination = Join-Path $portRoot 'Builds\iOS-WindowsPort'
$portBuildRoot = [IO.Path]::GetFullPath((Join-Path $portRoot 'Builds')) + [IO.Path]::DirectorySeparatorChar
if (Test-Path -LiteralPath $portDestination) {
    $portBackup = Join-Path $portRoot ('Builds\iOS-WindowsPort-previous-' + [Guid]::NewGuid().ToString('N'))
    foreach ($portPath in @($portDestination, $portBackup)) {
        if (-not [IO.Path]::GetFullPath($portPath).StartsWith($portBuildRoot, [StringComparison]::OrdinalIgnoreCase)) {
            throw 'Export replacement path is outside the intended Builds directory.'
        }
    }
    Move-Item -LiteralPath $portDestination -Destination $portBackup
}
New-Item -ItemType Directory -Path $portDestination -Force | Out-Null
Get-ChildItem -LiteralPath $portSource | Copy-Item -Destination $portDestination -Recurse -Force
@{ commit=$portCommit; unity='2022.3.62f3'; sourceArchiveSHA256=(Get-FileHash -LiteralPath $portArchive).Hash;
   exportedUTC=[DateTime]::UtcNow.ToString('o'); unityLog=$portLog } |
    ConvertTo-Json | Set-Content -LiteralPath (Join-Path $portDestination 'source-manifest.json') -Encoding utf8
Write-Output "SUCCESS: Xcode export at $portDestination ($portCommit)"
