CC = gcc
CCMAC = gcc-11
CFLAGS = -Wall -O2
TARGET = RainbowType
LIBS = -lncurses

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(CFLAGS) $(LIBS) -o bin/$(TARGET)

mac:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) $(LIBS) -o bin/$(TARGET)X86
macARM:
	mkdir -p bin/
	$(CCMAC) main.c $(CFLAGS) $(LIBS) -o bin/$(TARGET)ARM

clean:
	rm -rf bin
