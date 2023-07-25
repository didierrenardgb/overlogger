@echo off
cmake project -Bbuild
if "%1" == "open" (
    start build/overlogger.sln
)
