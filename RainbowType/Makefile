CC = gcc
TARGET = RainbowType
LIBS = -lncurses

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(LIBS) -o bin/$(TARGET)

mac:
	mkdir -p bin/
	$(CC) -o bin/$(TARGET)X86 main.c $(LIBS) -target x86_64-apple-macos10.12

macARM:
	mkdir -p bin/
	$(CC) -o bin/$(TARGET)ARM main.c $(LIBS) -target arm64-apple-macos11

clean:
	rm -rf bin
