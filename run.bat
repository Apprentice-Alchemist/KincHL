@echo off
@if %1 equ shader (
    @haxe -cp haxe -cp samples -m Shader --resource "Deployment/shader.vert@shader.vert" --resource "Deployment/shader.frag@shader.frag" -hl out.hl
    @hl out.hl
) else if %1 equ texture (
    @haxe -cp haxe -cp samples -m Texture --resource "Deployment/texture.vert@texture.vert" --resource "Deployment/texture.frag@texture.frag" -hl out.hl
    @hl out.hl
)