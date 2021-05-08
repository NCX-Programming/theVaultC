# theVaultC
An updated and upgraded version of theVault, now in C. Available for Windows, Linux, and Intel Macs.
### The (new!) greatest jumble of cross-platform C shenanigans around.
And yes, cross platform. All projects contained in theVaultC are guarenteed to work on 32-bit Windows, 64-bit Windows and Linux. Mostly compatible with macOS, however it is only available on Intel Macs, and possibly through Rosetta 2 on ARM Macs however that has not been tested.
## Compiling and Running
Unlike the old Vault, theVaultC does get relases, however they can often be out of date and you'll want to compile it yourself. GH Actions has been set up now, however it only compiles for x86 Macs and Linux.
It's important to note that there is a master Makefile that will compile all Vault programs and there are also Makefiles for the individual programs. You can use either, but just make sure you're using the one that will compile the program that you want to run.
## Before Starting, you'll need the proper compiler for your target system
Our makefiles use GCC for Linux/macOS, and MinGW for Windows.
GCC comes preinstalled on many Linux systems, and on macOS you can install it with brew using `brew install gcc` (you have to do this because we rely on GCC 10, rather than what Xcode command line tools gives you). You can get MinGW from the `mingw-w64` package on most package managers. For Windows you can get it ![here](https://sourceforge.net/projects/mingw-w64/), however our makefiles have not been tested on Windows, as they were designed for cross-compiling on Linux.
### Dependencies
While most programs in theVaultC only use built-in packages, a few require dependencies. You can see a list of what project require them and how to install them ![on the wiki.](https://github.com/NCX-Programming/theVaultC/wiki) Note that programs that need dependencies are not available on Windows.
### Full Build (Linux-only)
If you'd like to mass-build all projects, use `make all` or just `make`. This will compile the Linux, Win32, and Win64 versions of all programs (as long as they support those platforms).
### Compiling for Linux
To compile for Linux only, use `make linux`. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for Windows
To compile for Windows only, either use `make win32` or `make win64` to compile a 32 or 64 bit version of the program, respectively. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for macOS
To compile for MacOS only, either use `make mac` or `make macARM` depending on what procceser you have (`mac` on its own is for X86 Macs). You can only compile macOS binaries on macOS, and you can also only compile x86 builds on x86 Macs and ARM builds on ARM Macs.
### Removing build files
If you want to remove the bin folder and all of the builds, use `make clean`.
