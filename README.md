## KincHL

![Build](https://github.com/Apprentice-Alchemist/KincHL/workflows/Build/badge.svg?branch=master)

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
$ cd path/to/this/repo
$ node path/to/kinc/make.js --compile --dynlib --noshaders -g $GRAPHICS_API

$ copy Deployment\KincHL.dll %HASHLINK%\kinc.hdll # windows
$ cp Deployment/KincHL.so /usr/bin/kinc.hdll # or something like that on linux
$ cp Deployment/KincHL.dylib /usr/bin/kinc.hdll # or something like that on macos
```
