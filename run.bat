@echo off
@if -%1- equ -- (
    @hl out.hl
) else (
    @haxe build.hxml -m %*
    REM @echo Start
    @hl out.hl
    REM @echo End
)