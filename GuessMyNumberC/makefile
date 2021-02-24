all: linux win32 win64

linux:
	mkdir -p bin/
	gcc main.c -o bin/guessMyNumber
win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o -O bin/guessMyNumber32.exe main.c
win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o -O bin/guessMyNumber64.exe main.c
clean:
	rm -f bin/* rm -d bin/