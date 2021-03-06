# theVaultC
An updated and upgraded version of theVault, now in C. Available for Windows, Linux, and Intel Macs.
### The (new!) greatest jumble of cross-platform C shenanigans around.
And yes, cross platform. All projects contained in theVaultC are guarenteed to work on 32-bit Windows, 64-bit Windows and Linux. Mostly compatible with macOS, however it is only available on Intel Macs, and possibly through Rosetta 2 on ARM Macs however that has not been tested.
## Compiling and Running
Unlike the old Vault, theVaultC does get relases, however they can often be out of date and you'll want to compile it yourself. A makefile has been provided for your convience.
It's important to note that there is a master Makefile that will compile all Vault programs and there are also Makefiles for the individual programs. You can use either, but just make sure you're using the one that will compile the program that you want to run.
## Before Starting, you'll need the proper compiler for your target system
Our makefile uses gcc for Linux, and mingw for Windows.
You can get both on a system with apt by typing:
`sudo apt install gcc mingw`
gcc is used for Linux, and mingw is used for Windows. You do not need to have both to compile.
### Compiling for all target platforms
To compile for Linux, Win32, and Win64, just use `make` or `make all`. All files will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for Linux only
To compile for Linux only, use `make linux`. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for Windows only
To compile for Windows only, either use `make win32` or `make win64` to compile a 32 or 64 bit version of the program, respectively. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for MacOS only
To compile for MacOS only, either use `make macX86` or `make macARM` depending on what procceser you have. MacOS is currently only able to compile on macOS, but you need the same compiler that is used on Linux; gcc. You can install it with homebrew by typing: `brew install gcc`.
### Removing build files
If you want to remove the bin folder and all of the builds, use `make clean`.
