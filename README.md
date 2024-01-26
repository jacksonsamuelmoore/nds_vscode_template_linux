# nds_vscode_template
[![License: CC0-1.0](https://img.shields.io/badge/License-CC0%201.0-lightgrey.svg)](http://creativecommons.org/publicdomain/zero/1.0/)

Develop Nintendo DS homebrew in a modern Visual Studio Code development environment.

  * ARM [devkitPro](https://devkitpro.org) toolchain
  * Emulation and debugging with [DeSmuME](https://desmume.org/)
  * Working IntelliSense in [VS Code](https://code.visualstudio.com/)

## Getting Started

Before this template will work, we need to do some homework and install the compiler toolchian, the emulator, and the necessary extensions for our development environment.

**NOTE**: Forked from [nds_vscode_template](https://github.com/cuibonobo/nds_vscode_template/) these instuctions are for linux

### devkitPro

**devkitPro** provides a set of compilers and tools so that we can create programs that are compatible with the ARM 7 and ARM 9 processors in the Nintendo DS.

Follow the instructions on the [Getting Started](https://devkitpro.org/wiki/Getting_Started) page to install devkitPro for you distribution. This will involve setting up pacman as shown [here](https://devkitpro.org/wiki/devkitPro_pacman)



### melonDS

**melonDS** has been recenlty update with a GDB stub built in (see [this PR](https://github.com/melonDS-emu/melonDS/pull/1583))

This is not included in the most recent release, so download the most recent nightly build from [github actions](https://github.com/melonDS-emu/melonDS/actions/workflows/build-ubuntu.yml?query=branch%3Amaster). Select the most recent successfull build and download the only artifact `melonDS-ubuntu-x86_64`

To install, unzip `melonDS-ubuntu-x86_64.zip` and move `melonDS` to the root of this template folder. Allow executing of this file by running `chmod +x melonDS`.

Run the emulator once, and open `Config > Emu Settings > Devtools` and check `Enable GDB stub`

### VS Code

Install a copy of [Visual Studio Code](https://code.visualstudio.com/) if you don't have it already, and also install the following extensions:

  * [ARM](https://marketplace.visualstudio.com/items?itemName=dan-c-underwood.arm)
  * [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  * [C++ Intellisense](https://marketplace.visualstudio.com/items?itemName=austin.code-gnu-global)
  * [Make](https://marketplace.visualstudio.com/items?itemName=technosophos.vscode-make)

## Using this template

The C++ source code for your Nintendo DS program will go into the `source` directory. The `main.cpp` file in this template is from the `nds/hello_world` example that comes with devkitPro. You can use this as a starting point for your own program.

The `include` directory has a `vscode_fix.h` file that is used to fix IntelliSense behavior in Visual Studio Code. At the moment IntelliSense isn't smart enough to detect the feature flags that would be set by the compiler, so we add any interfaces that IntelliSense doesn't understand to this file.

For example, the `main.cpp` example code uses the `iprintf` function to print text to the screen. The `iprintf` function is defined in `/opt/devkitpro/devkitARM/arm-none-eabi/include/stdio.h`, but it is protected by the `__MISC_VISIBLE` compiler feature. Since IntelliSense doesn't know what features our compiler has, we have to help it along by copying the interface from the `stdio.h` file and into `vscode_fix.h`.

The `vscode_fix.h` file is _only_ used by IntelliSense and will not compile with your code!

The `.vscode` directory holds the settings that VS Code should use for the project. The `c_cpp_properties.json` file determines what directories IntelliSense searches in to find code for your project. The `tasks.json` file defines useful tasks like `make` and `make clean` so you don't have to switch to your terminal application to run them. The `launch.json` file defines the `(gdb) Launch` task for running the debugger.

Running the `make` build task will create an `.nds` file at the root of the project. You can run this file in the emulator by running the `run` task.

---
To the extent possible under law, [cuibonobo](https://github.com/cuibonobo/) has [waived all copyright](https://creativecommons.org/publicdomain/zero/1.0/) and related or neighboring rights to this work.