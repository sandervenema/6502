# 6502

A 6502 emulator written in C.

## Build instructions

This project uses [Meson](https://mesonbuild.com/). To build, go to the project's root directory and type:

```bash
$ meson setup builddir
$ cd builddir
$ ninja
```

in your shell, which will put the executable in the `builddir/src/` directory.

## License

This project is licensed under the MIT license. See [LICENSE](https://github.com/sandervenema/6502/blob/main/LICENSE)
for more info.
