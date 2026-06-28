param(
    [string]$StageDir = "reversed_game",
    [string]$BuildDir = "build",
    [switch]$Unicode,
    [switch]$SkipCompare
)

$ErrorActionPreference = "Stop"

$repoRoot = Resolve-Path (Join-Path $PSScriptRoot "..")
$stagePath = Join-Path $repoRoot $StageDir
if (!(Test-Path $stagePath)) {
    New-Item -ItemType Directory -Path $stagePath | Out-Null
}
$stagePath = Resolve-Path $stagePath
$buildPath = Join-Path $repoRoot $BuildDir
$cmake = Join-Path $repoRoot ".venv\Scripts\cmake.exe"
$reccmpProject = Join-Path $repoRoot ".venv\Scripts\reccmp-project.exe"
$reccmp = Join-Path $repoRoot ".venv\Scripts\reccmp-reccmp.exe"
$vcvars = Join-Path $repoRoot "3rdparty\MSVC600\VC98\Bin\VCVARS32.ps1"

if (!(Test-Path $cmake)) {
    throw "CMake was not found in .venv. Run the README setup first."
}

Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass -Force
. $vcvars

$configureArgs = @(
    ".", "-B", $buildPath,
    "-G", "NMake Makefiles",
    "-DCMAKE_BUILD_TYPE=RelWithDebInfo"
)

if ($Unicode) {
    $configureArgs += "-DSTUNTGP_UNICODE=ON"
}

Push-Location $repoRoot
try {
    & $cmake @configureArgs
    & $cmake --build $buildPath

    Copy-Item -LiteralPath (Join-Path $buildPath "StuntGP.exe") -Destination $stagePath -Force
    Copy-Item -LiteralPath (Join-Path $buildPath "StuntGP_D3D.exe") -Destination $stagePath -Force
    Copy-Item -LiteralPath (Join-Path $buildPath "StuntGP.pdb") -Destination $stagePath -Force
    Copy-Item -LiteralPath (Join-Path $buildPath "StuntGP_D3D.pdb") -Destination $stagePath -Force

    & $reccmpProject detect --what recompiled --search-path $buildPath
    if (!$SkipCompare) {
        & $reccmp --target STUNTGP_D3D
    }
}
finally {
    Pop-Location
}

Write-Host "Staged rebuilt binaries to $stagePath"
