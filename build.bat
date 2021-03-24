@echo off
@call node Kinc/make --dynlib --noshaders %*
@cd build
@MSBuild KincHL.vcxproj /nologo /m "/p:Configuration=Release,Platform=x64,OutDir=bin/,TargetExt=.hdll,TargetName=kinc"
@cd ..