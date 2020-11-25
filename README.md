## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg)

---------------------

Hashlink bindings for [Kinc](https://github.com/Kode/Kinc)

### Building

The build file expects the environment variable `HASHLINK` to point to wherever you installed hashlink

```bash
$ cd path/to/this/repo
$ node path/to/kinc/make.js --compile --dynlib --noshaders -g $GRAPHICS_API
$ copy Deployment\KincHL.dll $HASHLINK\kinc.hdll # windows
or
$ cp Deplyment/KincHL.so $HASHLINK/kinc.hdll # linux
or
$ cp Deployment/KincHL.dylib $HASHLINK/kinc.hdll # macos
```