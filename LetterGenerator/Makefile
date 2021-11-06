# Basic settings
CC = gcc
CFLAGS = -Wall -O2
WINFLAGS = /W3 /O1 /GS-
CFLAGS86 = -Wall -O2 -target x86_64-apple-macos10.12
CFLAGSARM = -Wall -O2 -target arm64-apple-macos11
TARGET = LetterGenerator

all: linux win64

linux:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -o bin/$(TARGET)

win:
	mkdir bin
	cl $(WINFLAGS) main.c /link /out:bin\$(TARGET).exe

# Note that the macOS executables can only be compiled on macOS.
# Also note that Intel builds can only be compiled on Intel Macs,
# and ARM builds can only be compiled on ARM Macs.
macX86:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS86) -o bin/$(TARGET)X86

macARM:
	mkdir -p bin/
	$(CC) main.c $(CFLAGSARM) -o bin/$(TARGET)ARM

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)-macOS
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

clean:
	rm -rf bin/
