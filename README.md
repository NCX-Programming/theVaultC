# theVaultC
An updated and upgraded version of theVault, now in C. Available for Windows, Linux, and Intel Macs.
### The (new!) greatest jumble of cross-platform C shenanigans around.
And yes, cross platform. All projects contained in theVaultC are guaranteed to work on macOS (10.12+) and Linux. Somewhat compatible with 32/64-bit Windows, however a lot of the code used does not work under Windows so the level of support varies by project.
## Compiling and Running
Unlike the old Vault, theVaultC does get releases, however they can often be out of date and you'll want to compile it yourself, or download the latest build from Actions. Note that only Linux and X86 Mac builds are compiled automatically.
It's important to note that there is a master Makefile that will compile all VaultC programs, and then there are Makefiles for each individual project. Take note of which you are using because that will determine where the `bin/` folder with your executables will be located.
## Compiler
Our makefiles use GCC for Linux and macOS, and MinGW for Windows.
GCC comes preinstalled on many Linux systems, and on macOS you can install it with brew by  using the command `brew install gcc` (you have to get it through brew because we rely on GCC 11, rather than the old version that the Xcode command line tools will give you). You can get MinGW from the `mingw-w64` package on most package managers if you would like to cross-compile on Linux. For Windows you can get it [here](https://sourceforge.net/projects/mingw-w64/), however our makefiles have not been tested on Windows, as they were designed for cross-compiling on Linux.
### Dependencies
While most programs in theVaultC only use built-in packages, a few require dependencies. You can see a list of what project require them and how to install them [on the wiki.](https://github.com/NCX-Programming/theVaultC/wiki) Note that programs that need dependencies are not available on Windows.
### Compiling for Linux
To compile for Linux only, use `make linux`. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for Windows
To compile for Windows only, either use `make win32` or `make win64` to compile a 32 or 64 bit version of the program, respectively. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for macOS
To compile for MacOS only, either use `make mac` or `make macARM` depending on what procceser you have (`mac` on its own is for X86 Macs). You can only compile macOS binaries on macOS, and you can also only compile x86 builds on x86 Macs and ARM builds on ARM Macs.
### Debug Builds
An empty macro, named `DEBUG`, is provided so that you can add your own flags for debugging purposes when you compile.
### Removing build files
If you want to remove the bin folder and all of the builds, use `make clean`.
