echo "Compiling for Linux, Win32, and Win64!"
# Check if bin exists before trying to make it
DIR="bin/"
if [ ! -d "$DIR" ]; then
  mkdir bin
fi
# Build for Linux and Windows
gcc main.c -o bin/guessMyNumber
i686-w64-mingw32-gcc -o bin/guessMyNumber32.exe  main.c
x86_64-w64-mingw32-gcc -o bin/guessMyNumber64.exe main.c
