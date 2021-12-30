## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg)

---------------------

Hashlink bindings for [Kinc](https://github.com/Kode/Kinc)

### Building

On windows the kincfile expects an environment variable called HASHLINK to point to your hashlink installation, which should have the following structure :
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
# windows
$ cd path/to/kinchl
$ haxe --run Build

$ copy build/bin/kinc.hdll /path/to/hashlink/ # Windows
$ sudo cp build/bin/kinc.hdll /usr/local/lib/ # Linux/Mac
```
