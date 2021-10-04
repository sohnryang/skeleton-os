# skeletonOS

OS with bare bones only. (That's why the name is skeletonOS)

## Why?

I cloned [torvalds/linux](https://github.com/torvalds/linux) a few weeks ago, and still don't know what I should do. So I decided to learn some OS concepts by building one.

## Project Goals

[Track progress here](https://github.com/sohnryang/skeleton-os/projects/2)

- Write most of the OS in C language for portability
  - Main target arch will be x86(-64) and ARM though
- Should run on actual hardware such as Raspberry Pi
- Feature basic OS elements such as file system and process scheduling.

## Building & Running the OS

This project uses [`meson`](https://mesonbuild.com/) as a build system. Therefore, `meson` and `ninja` is needed.

### x86

x86 builds require a compiler which targets `i686-elf`. OSDev Wiki has [an article](https://wiki.osdev.org/GCC_Cross-Compiler) about how to build such compiler yourself.

```
$ meson setup build --cross-file=cross-files/cross.ini --cross-file=cross-files/i686.ini
$ cd build
$ ninja
```

`os.bin` will be created after a successful build. This file can be run in QEMU using `-kernel` flag.

```
$ qemu-system-i386 -kernel os.bin
```

## Build Status

| libc unit tests                                              | OS integration test                                       |
| ------------------------------------------------------------ | --------------------------------------------------------- |
| [![Run libc unit tests](https://github.com/sohnryang/skeleton-os/actions/workflows/libc-unit-test.yml/badge.svg)](https://github.com/sohnryang/skeleton-os/actions/workflows/libc-unit-test.yml) | [WIP](https://github.com/sohnryang/skeleton-os/issues/14) |

