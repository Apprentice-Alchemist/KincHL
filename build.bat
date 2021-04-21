@echo off
@call node Kinc/make --dynlib %*
@cd build
@MSBuild KincHL.vcxproj /nologo /m "/p:Configuration=Debug,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc"
@cd ..