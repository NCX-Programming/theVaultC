CC = gcc
CCMAC = gcc-11
TARGET = graphicStuff

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) main.c -o bin/$(TARGET)

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc -o bin/$(TARGET)32.exe main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc -o bin/$(TARGET)64.exe main.c

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	$(CCMAC) main.c -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CCMAC) main.c -o bin/$(TARGET)ARM

clean:
	rm -f bin/* rm -d bin/
