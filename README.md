# theVaultC
An updated and upgraded version of theVault, now in C. Available for Windows, Linux, and macOS.
### The (new!) greatest jumble of cross-platform C shenanigans around.
And yes, cross platform. All projects contained in theVaultC are guaranteed to work on macOS (10.12+) and Linux. Somewhat compatible with 64-bit Windows, however a lot of the code used does not work under Windows so the level of support varies by project.
### Quick Download Links Thanks to [nightly.link](nightly.link)
__Linux:__ Bin: [theVaultC-linux](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-linux.zip)
Checksum: [theVaultC-linux-Checksums](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-linux-Checksums.zip)

__macOS:__ Bin: [theVaultC-macOS](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-macOS.zip)
Checksum: [theVaultC-macOS-Checksums](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-macOS-Checksums.zip)

__Windows:__ Bin: [theVaultC-windows](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-windows.zip)
Checksum: [theVaultC-windows-Checksums](https://nightly.link/NCX-Programming/theVaultC/workflows/main/main/theVaultC-windows-Checksums.zip)
## Compiling and Running
Unlike the old Vault, theVaultC does get releases, however they can often be out of date and you'll want to compile it yourself, or download the latest build from Actions (see above section). As of October 8th, Windows, Linux and Universal macOS binaries are compiled automatically.
It's important to note that there is a master Makefile that will compile all VaultC programs, and then there are Makefiles for each individual project. Take note of which you are using because that will determine where the `bin/` folder with your executables will be located.
## Compiler
Our makefiles use GCC for Linux and macOS, and cl for Windows.
GCC comes preinstalled on many Linux systems, and on macOS you can install it by using `xcode-select --install` to install the Xcode Command Line Tools. You can get cl on Windows by installing Visual Studio and launching a developer command prompt. You will also need a version of `make` for Windows. We recommend `mingw32-make` since that's what GitHub Actions uses, therefore we know it will work.
### Dependencies
While most programs in theVaultC only use built-in packages, a few require dependencies. You can see a list of what project require them and how to install them [on the wiki.](https://github.com/NCX-Programming/theVaultC/wiki) Note that programs that need dependencies are not available on Windows.
### Compiling for Linux
To compile for Linux only, use `make linux`. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for Windows
To compile for Windows only, use `make win` to compile a 64 bit version of the program. The program will be outputted to a bin folder that will be created inside of your current directory.
### Compiling for macOS
To compile for macOS only, use `make mac`. If you have macOS 10.12 through 10.15, you need to use `make macX86`. You can only compile macOS binaries on macOS, and you can also only compile ARM and Universal Binaries on macOS 11.0+.
### Debug Builds
An empty macro, named `DEBUG`, is provided so that you can add your own flags for debugging purposes when you compile.
### Removing build files
If you want to remove the bin folder and all of the builds, use `make clean`.
