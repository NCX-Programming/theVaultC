# Basic settings
CC = gcc
CFLAGS = -Wall -O2
WINFLAGS = /W3 /O1 /GS-
CFLAGS86 = -Wall -O2 -target x86_64-apple-macos10.12
CFLAGSARM = -Wall -O2 -target arm64-apple-macos11
DEBUG =
# All targets/projects
PROJECT1 = GraphicStuffC
PROJECT2 = GuessMyNumberC
PROJECT3 = PrintUnixTime
PROJECT4 = RainbowType
PROJECT5 = RNGTool
PROJECT6 = WordGenerator

all: linux win64

linux:
	mkdir -p bin/
	$(CC) $(PROJECT1)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT1)
	$(CC) $(PROJECT2)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT2)
	$(CC) $(PROJECT3)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT3)
	$(CC) $(PROJECT4)/main.c $(CFLAGS) $(DEBUG) -lncurses -o bin/$(PROJECT4)
	$(CC) $(PROJECT5)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT5)
	$(CC) $(PROJECT6)/main.c $(CFLAGS) $(DEBUG) -o bin/$(PROJECT6)
	cp WordGenerator/words.txt bin/words.txt

win:
	mkdir bin
	cl $(WINFLAGS) $(PROJECT1)\main.c /link /out:bin\$(PROJECT1).exe
	cl $(WINFLAGS) $(PROJECT2)\main.c /link /out:bin\$(PROJECT2).exe
	cl $(WINFLAGS) $(PROJECT3)\main.c /link /out:bin\$(PROJECT3).exe
	cl $(WINFLAGS) $(PROJECT5)\main.c /link /out:bin\$(PROJECT5).exe
	cl $(WINFLAGS) $(PROJECT6)\main.c /link /out:bin\$(PROJECT6).exe
	cp WordGenerator/words.txt bin/words.txt

# Note that the macOS executables can only be compiled on macOS.
# Also note that Intel builds can only be compiled on Intel Macs,
# and ARM builds can only be compiled on ARM Macs.
macX86:
	mkdir -p bin/
	$(CC) $(PROJECT1)/main.c $(CFLAGS86) $(DEBUG) -o bin/$(PROJECT1)X86
	$(CC) $(PROJECT2)/main.c $(CFLAGS86) $(DEBUG) -o bin/$(PROJECT2)X86
	$(CC) $(PROJECT3)/main.c $(CFLAGS86) $(DEBUG) -o bin/$(PROJECT3)X86
	$(CC) $(PROJECT4)/main.c $(CFLAGS86) $(DEBUG) -lncurses -o bin/$(PROJECT4)X86
	$(CC) $(PROJECT5)/main.c $(CFLAGS86) $(DEBUG) -o bin/$(PROJECT5)X86
	$(CC) $(PROJECT6)/main.c $(CFLAGS86) $(DEBUG) -o bin/$(PROJECT6)X86
	cp WordGenerator/words.txt bin/words.txt

macARM:
	mkdir -p bin/
	$(CC) $(PROJECT1)/main.c $(CFLAGSARM) $(DEBUG) -o bin/$(PROJECT1)ARM
	$(CC) $(PROJECT2)/main.c $(CFLAGSARM) $(DEBUG) -o bin/$(PROJECT2)ARM
	$(CC) $(PROJECT3)/main.c $(CFLAGSARM) $(DEBUG) -o bin/$(PROJECT3)ARM
	$(CC) $(PROJECT4)/main.c $(CFLAGSARM) $(DEBUG) -lncurses -o bin/$(PROJECT4)ARM
	$(CC) $(PROJECT5)/main.c $(CFLAGSARM) $(DEBUG) -o bin/$(PROJECT5)ARM
	$(CC) $(PROJECT6)/main.c $(CFLAGSARM) $(DEBUG) -o bin/$(PROJECT6)ARM
	cp WordGenerator/words.txt bin/words.txt

mac: macX86 macARM
	lipo -create bin/$(PROJECT1)X86 bin/$(PROJECT1)ARM -output bin/$(PROJECT1)-macOS
	lipo -create bin/$(PROJECT2)X86 bin/$(PROJECT2)ARM -output bin/$(PROJECT2)-macOS
	lipo -create bin/$(PROJECT3)X86 bin/$(PROJECT3)ARM -output bin/$(PROJECT3)-macOS
	lipo -create bin/$(PROJECT4)X86 bin/$(PROJECT4)ARM -output bin/$(PROJECT4)-macOS
	lipo -create bin/$(PROJECT5)X86 bin/$(PROJECT5)ARM -output bin/$(PROJECT5)-macOS
	lipo -create bin/$(PROJECT6)X86 bin/$(PROJECT6)ARM -output bin/$(PROJECT6)-macOS
	find bin -type f -name "*ARM*" -delete
	find bin -type f -name "*X86*" -delete

clean:
	rm -rf bin/
