CC = gcc
CCMAC = gcc-11
CFLAGS = -Wall -O2
TARGET = WordGenerator

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) -o bin/$(TARGET)
	cp words.txt bin/words.txt

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc main.c -o bin/$(TARGET)32.exe
	cp words.txt bin/words.txt

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc main.c -o bin/$(TARGET)64.exe
	cp words.txt bin/words.txt

# Note that the mac executables can only be compiled on mac
mac:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)X86
	cp words.txt bin/words.txt

macARM:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) -o bin/$(TARGET)ARM
	cp words.txt bin/words.txt

clean:
	rm -rf bin/
