$ErrorActionPreference = 'Stop'
Add-Type -Path (Join-Path $PSScriptRoot '../Assets/RealtimeBodyTracking/Scripts/TrackingJsonlRecorder.cs')
$testDirectory = Join-Path ([IO.Path]::GetTempPath()) ('tracking-recorder-' + [Guid]::NewGuid().ToString('N'))
$recorder = [RealtimeBodyTracking.TrackingJsonlRecorder]::new()
function Assert-True($condition, $message) { if (!$condition) { throw $message } }
try {
    Assert-True (!$recorder.IsRecording) 'Recording must default OFF'
    $recorder.Append('{"frame":0}')
    Assert-True (!(Test-Path -LiteralPath $testDirectory)) 'OFF must not create files'
    $recorder.Start($testDirectory)
    $recorder.Append('{"frame":1}')
    $recorder.Stop()
    $recorder.Append('{"frame":2}')
    Assert-True ([IO.File]::ReadAllText($recorder.FilePath) -eq "{`"frame`":1}`n") 'Stop must flush and reject later frames'
    $recorder.Start($testDirectory)
    for ($frame = 0; $frame -lt 6001; $frame++) { $recorder.Append('{"frame":3}') }
    Assert-True (!$recorder.IsRecording -and $recorder.Frames -eq 6000) 'Frame limit must auto-stop'
    Assert-True ([IO.File]::ReadAllLines($recorder.FilePath).Length -eq 6000) 'New recording must replace previous file'
    $recorder.Start($testDirectory)
    $recorder.Append('x' * (8 * 1024 * 1024))
    Assert-True (!$recorder.IsRecording -and (Get-Item -LiteralPath $recorder.FilePath).Length -eq 0) 'Byte limit must reject overflow before write'
    $recorder.Start($testDirectory)
    $recorder.Append("{}`n{}")
    $recorder.Append('{"frame":4}')
    $recorder.Stop()
    Assert-True ([IO.File]::ReadAllLines($recorder.FilePath).Length -eq 1) 'Reject multiline packets; allow restarting after limit'
    $recorder.Start($recorder.FilePath)
    Assert-True (!$recorder.IsRecording -and $recorder.Status.StartsWith('記録エラー')) 'IO errors must not escape'
    Write-Output 'PASS: recorder compilation, default OFF, flush/stop, restart, frame/byte bounds, JSONL framing, IO failure'
}
finally {
    $recorder.Dispose()
    # Only remove the single known test file and its empty dedicated directory.
    $testFile = Join-Path $testDirectory 'tracking-latest.jsonl'
    if (Test-Path -LiteralPath $testFile) { Remove-Item -LiteralPath $testFile }
    if (Test-Path -LiteralPath $testDirectory) { Remove-Item -LiteralPath $testDirectory }
}
