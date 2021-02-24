# theVaultC
An updated and upgraded version of theVault, now in C. Available for Windows and Linux.
### The (new!) greatest jumble of cross-platform C shenanigans around.
And yes, cross platform. All projects contained in theVaultC are guarenteed to work on 32-bit Windows, 64-bit Windows and Linux. Somewhat compatible with macOS, but it is not guarenteed.
## Compiling and Running
Unlike the old Vault, theVaultC does get relases, however they can often be out of date and you'll want to compile it yourself. A makefile has been provided for your convience.
# Before Starting, you'll need the proper compiler for your target system
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
To compile for MacOS only, either use `make macX86` or `make macARM` depending on what procceser you have. MacOS is currently only able to compile on macOS, but you need the same compiler that is used on Linux; gcc. You can install it with brew by typing: `brew install gcc`.
### Removing build files
If you want to remove the bin folder and all of the builds, use `make clean`.
