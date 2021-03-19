CC = gcc

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) GraphicStuffC/main.c -o bin/graphicStuff
	$(CC) GuessMyNumberC/main.c -o bin/guessMyNumber
	$(CC) PrintUnixTime/main.c -o bin/UnixTime

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o bin/graphicStuff32.exe GraphicStuffC/main.c
	i686-w64-mingw32-gcc -o bin/guessMyNumber32.exe GuessMyNumberC/main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o bin/graphicStuff64.exe GraphicStuffC/main.c
	x86_64-w64-mingw32-gcc -o bin/guessMyNumber64.exe GuessMyNumberC/main.c

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	$(CC) -o bin/graphicStuffX86 -target x86_64-apple-macos10.12 GraphicStuffC/main.c
	$(CC) -o bin/guessMyNumberX86 -target x86_64-apple-macos10.12 GuessMyNumberC/main.c
	$(CC) -o bin/UnixTime -target x86_64-apple-macos10.12 PrintUnixTime/main.c

macARM:
	mkdir -p bin/
	$(CC) -o bin/graphicStuffARM -target arm64-apple-macos11 GraphicStuffC/main.c
	$(CC) -o bin/guessMyNumberARM -target arm64-apple-macos11 GuessMyNumberC/main.c
	$(CC) -o bin/UnixTime -target arm64-apple-macos11 PrintUnixTime/main.c

clean:
	rm -f bin/* rm -d bin/
