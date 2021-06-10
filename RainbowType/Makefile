CC = gcc
CCMAC = gcc-11
TARGET = RainbowType
LIBS = -lncurses

all: linux

linux:
	mkdir -p bin/
	$(CC) main.c $(LIBS) -o bin/$(TARGET)

mac:
	mkdir -p bin/
	$(CCMAC) main.c $(LIBS) -o bin/$(TARGET)X86
macARM:
	mkdir -p bin/
	$(CCMAC) main.c $(LIBS) -o bin/$(TARGET)ARM

clean:
	rm -rf bin
