# Basic settings
CC = gcc
CCMAC = gcc-11
CFLAGS = -Wall -O2
DEBUG =
# All targets/projects
PROJECT1 = GraphicStuffC
PROJECT2 = GuessMyNumberC
PROJECT3 = PrintUnixTime
PROJECT4 = RainbowType
PROJECT5 = RNGTool
TARGET1 = graphicStuff
TARGET2 = guessMyNumber
TARGET3 = UnixTime
TARGET4 = RainbowType
TARGET5 = RNGTool

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET1)
	$(CC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET2)
	$(CC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET3)
	$(CC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(TARGET4)
	$(CC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET5)

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET1)32.exe
	i686-w64-mingw32-gcc $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET2)32.exe
	i686-w64-mingw32-gcc $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET3)32.exe

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET1)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET2)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET3)64.exe

# Note that the macOS executables can only be compiled on macOS.
# Also note that Intel builds can only be compiled on Intel Macs,
# and ARM builds can only be compiled on ARM Macs.
mac:
	mkdir -p bin/
	$(CCMAC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET1)X86
	$(CCMAC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET2)X86
	$(CCMAC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET3)X86
	$(CCMAC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(TARGET4)X86
	$(CCMAC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET5)

macARM:
	mkdir -p bin/
	$(CCMAC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET1)ARM
	$(CCMAC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET2)ARM
	$(CCMAC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET3)ARM
	$(CCMAC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(TARGET4)ARM
	$(CCMAC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(TARGET5)

clean:
	rm -rf bin/
