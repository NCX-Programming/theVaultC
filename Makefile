CC = gcc

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) GraphicStuffC/main.c -o bin/graphicStuff
	$(CC) GuessMyNumberC/main.c -o bin/guessMyNumber
	$(CC) PrintUnixTime/main.c -o bin/UnixTime
	$(CC) RainbowType/main.c -lncurses -o bin/RainbowType

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o bin/graphicStuff32.exe GraphicStuffC/main.c
	i686-w64-mingw32-gcc -o bin/guessMyNumber32.exe GuessMyNumberC/main.c
	i686-w64-mingw32-gcc -o bin/UnixTime32.exe PrintUnixTime/main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o bin/graphicStuff64.exe GraphicStuffC/main.c
	x86_64-w64-mingw32-gcc -o bin/guessMyNumber64.exe GuessMyNumberC/main.c
	x86_64-w64-mingw32-gcc -o bin/UnixTime64.exe PrintUnixTime/main.c

# Note that the macOS executables can only be compiled on macOS.
# Also note that Intel builds can only be compiled on Intel Macs,
# and ARM builds can only be compiled on ARM Macs.
macX86:
	mkdir -p bin/
	$(CC) -target x86_64-apple-macos10.12 GraphicStuffC/main.c -o bin/graphicStuffX86
	$(CC) -target x86_64-apple-macos10.12 GuessMyNumberC/main.c -o bin/guessMyNumberX86
	$(CC) -target x86_64-apple-macos10.12 PrintUnixTime/main.c -o bin/UnixTime
	$(CC) -target x86_64-apple-macos10.12 RainbowType/main.c -lncurses -o bin/RainbowType

macARM:
	mkdir -p bin/
	$(CC) -target arm64-apple-macos11 GraphicStuffC/main.c -o bin/graphicStuffARM
	$(CC) -target arm64-apple-macos11 GuessMyNumberC/main.c -o bin/guessMyNumberARM
	$(CC) -target arm64-apple-macos11 PrintUnixTime/main.c -o bin/UnixTime
	$(CC) -target arm64-apple-macos11 RainbowType/main.c -lncurses -o bin/RainbowType

clean:
	rm -rf bin
