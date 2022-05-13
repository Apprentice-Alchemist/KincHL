## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg)

---------------------

Hashlink bindings for [Kinc](https://github.com/Kode/Kinc)

## Building

First get Kinc and its tools
```bash
$ git submodule update --init
$ Kinc/get_dlc
```
Then build with
```bash
$ haxe --run Build
```
The resulting kinc.hdll file can be found in `build/bin`.

### Windows

The kfile expects an environment variable called HASHLINK to point to your hashlink installation, which should have the following structure :
```
%HASHLINK%
    - hl.exe
    - libhl.dll
    - libhl.lib
    - *.hdll
    - /include
        - hl.h
        - hlc.h
        - hlc_main.c
```

### iOS
The kfile expects the `HASHLINK_BIN` environment variable to point to a directory containing `libhl.dylib`.

### Android

TODO