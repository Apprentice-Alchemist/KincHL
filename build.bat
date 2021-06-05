@echo off
@call node Kinc/make --dynlib %*
@cd build
IF DEFINED DEBUG (
@MSBuild KincHL.vcxproj /nologo /m "/p:Configuration=Debug,Platform=x64,OutDir=bin/debug/,TargetExt=.hdll,TargetName=kinc"
) ELSE (
@MSBuild KincHL.vcxproj /nologo /m "/p:Configuration=Release,Platform=x64,OutDir=bin/release/,TargetExt=.hdll,TargetName=kinc"
)
@cd ..