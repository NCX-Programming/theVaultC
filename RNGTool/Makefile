CC = gcc
CCMAC = gcc-11
CFLAGS = -Wall -O2
TARGET = RNGTool

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -o bin/$(TARGET)

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc main.c -o bin/$(TARGET)32.exe

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc main.c -o bin/$(TARGET)64.exe

# Note that the mac executables can only be compiled on mac
mac:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)ARM

clean:
	rm -rf bin/
