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
$ cd path/to/this/repo
$ ./build.bat
$ copy build/bin/ %HASHLINK%

# linux or macos
$ node Kinc/make --dynlib --noshaders --compile
$ cp Deployment/KincHL.so /usr/bin/kinc.hdll # Linux
$ cp Deployment/KincHL.dylib /usr/bin/kinc.hdll # Macos
# And hope it all works out fine
```
