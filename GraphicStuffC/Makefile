all: linux win32 win64

linux:
	mkdir -p bin/
	gcc main.c -o bin/graphicStuff

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o bin/graphicStuff32.exe main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o bin/graphicStuff64.exe main.c

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	gcc -o bin/graphicStuffX86 -target x86_64-apple-macos10.12 main.c

macARM:
	mkdir -p bin/
	gcc -o bin/graphicStuffARM -target arm64-apple-macos11 main.c

clean:
	rm -f bin/* rm -d bin/
