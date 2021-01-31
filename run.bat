@echo off
@if -%1- equ -- (
    @hl out.hl
) else (
    @haxe build.hxml
    REM @echo Start
    @hl out.hl
    REM @echo End
)