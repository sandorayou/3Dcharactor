param(
    [string]$UnityEditor = 'C:\Users\81904\Documents\Xfer\2022.3.62f3\Editor\Unity.exe',
    [switch]$FreshSnapshot
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
$portTimer = [Diagnostics.Stopwatch]::StartNew()
$portCacheRecord = Join-Path $portRoot 'Builds\ios-export-cache.json'
$portCheckout = $null
if (-not $FreshSnapshot) {
    if (Test-Path -LiteralPath $portCacheRecord) {
        $portCheckout = (Get-Content -LiteralPath $portCacheRecord -Raw | ConvertFrom-Json).path
    } elseif (Test-Path -LiteralPath (Join-Path $portRoot 'Builds\iOS-WindowsPort\source-manifest.json')) {
        $portPrevious = Get-Content -LiteralPath (Join-Path $portRoot 'Builds\iOS-WindowsPort\source-manifest.json') -Raw | ConvertFrom-Json
        $portCheckout = Split-Path $portPrevious.unityLog -Parent
    }
}
$portTempRoot = [IO.Path]::GetFullPath($env:TEMP).TrimEnd('\') + '\'
if ($portCheckout) {
    $portCheckout = [IO.Path]::GetFullPath($portCheckout)
    if ((Split-Path $portCheckout -Parent).TrimEnd('\') + '\' -ne $portTempRoot -or
        (Split-Path $portCheckout -Leaf) -notmatch '^MyProject5-ios-port-[a-f0-9]{32}$') {
        throw 'Unexpected managed export cache path.'
    }
    if (-not (Test-Path -LiteralPath $portCheckout)) { $portCheckout = $null }
}
$portCacheReused = [bool]$portCheckout
if (-not $portCheckout) {
    $portCheckout = Join-Path $env:TEMP ('MyProject5-ios-port-' + [Guid]::NewGuid().ToString('N'))
    New-Item -ItemType Directory -Path $portCheckout | Out-Null
}
if (-not $FreshSnapshot) {
    New-Item -ItemType Directory -Path (Split-Path $portCacheRecord -Parent) -Force | Out-Null
    @{path=$portCheckout} | ConvertTo-Json | Set-Content -LiteralPath $portCacheRecord -Encoding utf8
}
$portArchive = Join-Path $portCheckout 'source.zip'
& git archive --format=zip "--output=$portArchive" HEAD Assets Packages ProjectSettings
if ($LASTEXITCODE -ne 0) { throw 'Source snapshot failed.' }
$portSnapshot = Join-Path $portCheckout ('snapshot-' + [Guid]::NewGuid().ToString('N'))
Expand-Archive -LiteralPath $portArchive -DestinationPath $portSnapshot
# Sync only the committed input trees. Keep unchanged file timestamps and Library/Bee caches.
foreach ($portTree in @('Assets','Packages','ProjectSettings')) {
    $portInput = Join-Path $portSnapshot $portTree
    $portTarget = Join-Path $portCheckout $portTree
    $portInputPrefix = [IO.Path]::GetFullPath($portInput).TrimEnd('\') + '\'
    $portTargetPrefix = [IO.Path]::GetFullPath($portTarget).TrimEnd('\') + '\'
    foreach ($portFile in Get-ChildItem -LiteralPath $portInput -Recurse -File) {
        $portRelative = $portFile.FullName.Substring($portInputPrefix.Length)
        $portTargetFile = Join-Path $portTarget $portRelative
        if (-not (Test-Path -LiteralPath $portTargetFile) -or
            (Get-FileHash -LiteralPath $portFile.FullName).Hash -ne (Get-FileHash -LiteralPath $portTargetFile).Hash) {
            New-Item -ItemType Directory -Path (Split-Path $portTargetFile -Parent) -Force | Out-Null
            Copy-Item -LiteralPath $portFile.FullName -Destination $portTargetFile -Force
        }
    }
    foreach ($portFile in Get-ChildItem -LiteralPath $portTarget -Recurse -File) {
        if (-not $portFile.FullName.StartsWith($portTargetPrefix, [StringComparison]::OrdinalIgnoreCase)) {
            throw 'Cache input deletion escaped its managed tree.'
        }
        if (-not (Test-Path -LiteralPath (Join-Path $portInput $portFile.FullName.Substring($portTargetPrefix.Length)))) {
            Remove-Item -LiteralPath $portFile.FullName
        }
    }
    foreach ($portDirectory in Get-ChildItem -LiteralPath $portTarget -Recurse -Directory | Sort-Object { $_.FullName.Length } -Descending) {
        if (-not $portDirectory.FullName.StartsWith($portTargetPrefix, [StringComparison]::OrdinalIgnoreCase)) {
            throw 'Cache directory cleanup escaped its managed tree.'
        }
        if (-not (Get-ChildItem -LiteralPath $portDirectory.FullName -Force | Select-Object -First 1)) {
            Remove-Item -LiteralPath $portDirectory.FullName
        }
    }
}
if ([IO.Path]::GetFullPath($portSnapshot).StartsWith($portCheckout + '\', [StringComparison]::OrdinalIgnoreCase)) {
    Remove-Item -LiteralPath $portSnapshot -Recurse -Force
} else { throw 'Snapshot cleanup escaped its managed directory.' }
# Reuse import/IL2CPP caches, but create a clean Xcode output to prevent stale files.
$portSource = Join-Path $portCheckout 'Builds\iOS-WindowsPort'
if ([IO.Path]::GetFullPath($portSource) -ne $portCheckout + '\Builds\iOS-WindowsPort') {
    throw 'Unexpected managed Xcode output path.'
}
if (Test-Path -LiteralPath $portSource) { Remove-Item -LiteralPath $portSource -Recurse -Force }
$portSyncSeconds = $portTimer.Elapsed.TotalSeconds
$portLog = Join-Path $portCheckout 'ios-export.log'
Write-Output "Export source: $portCommit; project: $portCheckout"
Write-Output "Import cache reused: $portCacheReused; source sync: $([Math]::Round($portSyncSeconds,1)) seconds"
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
   exportedUTC=[DateTime]::UtcNow.ToString('o'); unityLog=$portLog;
   cacheReused=$portCacheReused; syncSeconds=$portSyncSeconds; totalSeconds=$portTimer.Elapsed.TotalSeconds } |
    ConvertTo-Json | Set-Content -LiteralPath (Join-Path $portDestination 'source-manifest.json') -Encoding utf8
Write-Output "SUCCESS: Xcode export at $portDestination ($portCommit)"
