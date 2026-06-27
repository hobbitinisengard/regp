@echo off
powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0build_and_stage.ps1" %*
