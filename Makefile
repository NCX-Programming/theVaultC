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
PROJECT6 = WordGenerator

all: linux win32 win64

linux:
	mkdir -p bin/
	$(CC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)
	$(CC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)
	$(CC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)
	$(CC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(PROJECT4)
	$(CC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)
	$(CC) $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)
	cp WordGenerator/words.txt bin/words.txt

win32:
	mkdir -p bin/
	i686-w64-mingw32-gcc $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)32.exe
	i686-w64-mingw32-gcc $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)32.exe
	i686-w64-mingw32-gcc $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)32.exe
	i686-w64-mingw32-gcc $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)32.exe
	i686-w64-mingw32-gcc $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)32.exe
	cp WordGenerator/words.txt bin/words.txt

win64:
	mkdir -p bin/
	x86_64-w64-mingw32-gcc $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)64.exe
	x86_64-w64-mingw32-gcc $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)64.exe
	cp WordGenerator/words.txt bin/words.txt

# Note that the macOS executables can only be compiled on macOS.
# Also note that Intel builds can only be compiled on Intel Macs,
# and ARM builds can only be compiled on ARM Macs.
mac:
	mkdir -p bin/
	$(CCMAC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)X86
	$(CCMAC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)X86
	$(CCMAC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)X86
	$(CCMAC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(PROJECT4)X86
	$(CCMAC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)
	$(CCMAC) $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)
	cp WordGenerator/words.txt bin/words.txt

macARM:
	mkdir -p bin/
	$(CCMAC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)ARM
	$(CCMAC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)ARM
	$(CCMAC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)ARM
	$(CCMAC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(PROJECT4)ARM
	$(CCMAC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)
	$(CCMAC) $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)
	cp WordGenerator/words.txt bin/words.txt

clean:
	rm -rf bin/
