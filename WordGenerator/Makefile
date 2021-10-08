CC = gcc
CFLAGS = -Wall -O2
TARGET = WordGenerator

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -o bin/$(TARGET)
	cp words.txt bin/words.txt

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc main.c -o bin/$(TARGET)64.exe
	cp words.txt bin/words.txt

# Note that the mac executables can only be compiled on mac
macX86:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -target x86_64-apple-macos10.12 -o bin/$(TARGET)X86
	cp words.txt bin/words.txt

macARM:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -target arm64-apple-macos11 -o bin/$(TARGET)ARM
	cp words.txt bin/words.txt

mac: macX86 macARM
	lipo -create bin/$(TARGET)X86 bin/$(TARGET)ARM -output bin/$(TARGET)-macOS
	rm bin/$(TARGET)X86
	rm bin/$(TARGET)ARM

clean:
	rm -rf bin/
