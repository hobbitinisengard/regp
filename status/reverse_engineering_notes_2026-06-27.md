# Reverse Engineering Notes (2026-06-27)

## Startup and Render Pipeline

- `WinMain` boot order in `STUNTGP_D3D/main.cpp`:
  - Parse config (`Script_ParseGameConfig`)
  - Create window + DirectDraw objects (`windowCreate`)
  - Build version string (`GetGameBuildVersion`)
  - Big setup (`FUN_442120`)
  - Timing init (`FUN_44e5d0`)
  - Main loop: message pump + keyboard + frame timing + present (`FUN_44e9d0`)

## DirectDraw Lifecycle

- `FUN_422f30` in `STUNTGP_D3D/windowInit.cpp` is the display mode and primary/backbuffer creation gate.
- If requested mode fails, fallback path uses `FUN_422c60` (640x480 with same depth).
- `FUN_4230b0` creates an 8-bit palette and binds it to primary surface.
- `restoreAndClearSurface` is restore + clear helper used by resume and per-frame checks.

## Resume / Lost Surface Path

- `FUN_44e4b0(1)`:
  - Guarded by `g_WindowMessage` latch.
  - Optional MODEX recreation through `FUN_422f30`.
  - Restores primary + secondary surfaces, then `FlipToGDISurface` when both restore.
- `FUN_44e9d0`:
  - Validates primary and backbuffer (`surfaceExists`).
  - Clears frame to game fog color and draws debug probe overlay.
  - Presents with `Blt` and validates all tracked resource surfaces (`FUN_4314c0`).
  - Falls back to `FUN_44e4b0(1)` if any stage fails.

## Setup-State Functions (Observed)

- `FUN_442120` appears to be global runtime init/reset entry.
- `FUN_442030` appears to be per-state refresh path with branch on `g_612be8`.
- `FUN_462090` zeroes/initializes runtime arrays and a few control globals.
- `FUN_45ec30` initializes a repeated record table at `g_62d580` with default `0xffff` field.

## Verified Call Graph Anchors

- `FUN_442120 -> FUN_442030` (direct call at end of setup).
- `FUN_442030` always calls: `FUN_45f9d0`, `FUN_460dd0`, `FUN_460c90`, `FUN_445fa0`, `FUN_42ea80`, `FUN_42e6e0`, `FUN_443d70`, `FUN_4457e0`, `FUN_442100`.
- `FUN_442030` in `g_612be8 == 1` path calls: `FUN_445f80`, `FUN_4469f0`, `FUN_40e050`, `FUN_40a2f0`, `FUN_401de0`, `FUN_413670`, `FUN_422420`, `FUN_4199a0`, `FUN_40d500`, then `FUN_43d1b0`.
- `FUN_442030` in `g_612be8 == 2` path calls: `FUN_424c30(1)` and either `FUN_43d0b0` (first entry, guarded by `g_60d61c`) or `FUN_43d1d0`.

## Confirmed Resource/Mode Behavior

- `FUN_422a80` is a thin `CreateSurface` wrapper with cleanup on failure.
- `FUN_422ac0` creates and clears an offscreen plain surface.
- `FUN_422c60` is a confirmed 640x480 display fallback branch.
- `FUN_422f30` caches active mode in `g_DD_DISPLAYRESWIDTH/HEIGHT/DEPTH` and only rebuilds surfaces when mode tuple changes.

## Fade/Intensity-Like Controller Cluster

- `FUN_446a90` and `FUN_446ac0` increment wrapping counters (`g_62e0f0`, `g_62e0a8`) then call `FUN_460bc0`.
- `FUN_460bc0` computes derived values (`g_62e0f8`, `g_489798`, `g_48979c`) from base factor `g_489790`.
- `FUN_460cb0` sets target/current relationship from a passed value.
- `FUN_460ce0` smooths current toward target in steps of 4.

## Gaps / Next Targets

1. Find write-sites for `g_612be8`, `g_489790`, `g_482718`, `g_482f38` (currently mostly local to main TU).
2. Replace stubs in the `FUN_442030` call chain (`FUN_443bd0`, `FUN_445620`, `FUN_445610`, `FUN_460330`, etc.).
3. Recover semantics for `g_SurfaceResources` population path (currently only validated, not populated in seen code).
4. Correlate `g_62d580` record layout with gameplay/runtime systems.

## Reccmp Priorities (Latest JSON Snapshot)

- Full compare snapshot saved at `status/reccmp_stuntgp_d3d_latest.json`.
- 0% functions (19 total) are now confirmed targets:
  - `FUN_460330`, `FUN_460dd0`, `FUN_443bd0`, `FUN_445620`, `FUN_445fa0`, `FUN_4469f0`, `FUN_424c30`, `FUN_43d0b0`, `FUN_42e6e0`, `FUN_42bf00`, `FUN_401de0`, `FUN_40a2f0`, `FUN_40d500`, `FUN_413670`, `FUN_4199a0`, `FUN_422420`, `FUN_4249b0`, `FUN_445d70`, `FUN_4320c0`.
- Lowest non-zero matches (<25%) worth immediate cleanup after stubs:
  - `FUN_44ea50` (3.28%)
  - `FUN_422a00` (7.41%)
  - `WndProc` (9.20%)
  - `FUN_422ac0` (14.88%)
  - `FUN_422f30` (14.94%)
  - `Script_ParseGameConfig` (16.60%)
  - `FUN_4230b0` (20.25%)

## Tooling Constraint (Important)

- Reccmp currently maps many symbols via `filename:line` from PDB + annotations.
- Adding/removing lines above mapped functions can cause `Debug data out of sync` and missing-function errors in compare output.
- Safe edit strategy for now:
  - Prefer in-place replacements that do not shift surrounding line numbers.
  - Avoid adding new helper globals/functions near the top of heavily-mapped files (`main.cpp`, `windowInit.cpp`).
  - Rebuild + rerun JSON compare after each candidate change and revert quickly if coverage drops below baseline (`Implemented 154/154`).
