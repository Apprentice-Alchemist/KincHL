## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg)

---------------------

Hashlink bindings for [Kinc](https://github.com/Kode/Kinc)

## Building

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

```bash
$ cd path/to/kinchl
$ haxe --run Build

$ copy build/bin/kinc.hdll /path/to/hashlink/ # Windows
$ sudo cp build/bin/kinc.hdll /usr/local/lib/ # Linux/Mac
```

### iOS
The kfile expects the `HASHLINK_BIN` environment variable to point to a directory containing `libhl.dylib`.

### Android

TODO