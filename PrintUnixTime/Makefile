CC = gcc
CCMAC = gcc-11
CFLAGS = -Wall -O2
TARGET = UnixTime

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) main.c -o bin/$(TARGET)

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc $(CFLAGS) -o bin/$(TARGET)32.exe main.c

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc $(CFLAGS) -o bin/$(TARGET)64.exe main.c

# Note that the mac executables can only be compiled on mac
mac:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)ARM

clean:
	rm -rf bin/
