@echo off
@if %1 equ nobuild (
    @hl out.hl
) else (
    @haxe build.hxml -m %1
    @hl out.hl
)