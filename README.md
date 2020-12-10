## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg)

---------------------

Hashlink bindings for [Kinc](https://github.com/Kode/Kinc)

### Building

The build file expects the environment variable `HASHLINK` to point to wherever you installed hashlink

```bash
$ cd path/to/this/repo
$ node path/to/kinc/make.js --compile --dynlib --noshaders -g $GRAPHICS_API

$ copy Deployment\KincHL.dll %HASHLINK%\kinc.hdll # windows
$ cp Deployment/KincHL.so /usr/bin/kinc.hdll # or something like that on linux
$ cp Deployment/KincHL.dylib /usr/bin/kinc.hdll # or something like that on macos
```