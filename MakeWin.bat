mkdir bin
cl /Wall GraphicStuffC\main.c /link /O2 /out:bin\GraphicStuffC.exe
cl /Wall GuessMyNumberC\main.c /link /O2 /out:bin\GuessMyNumberC.exe
cl /Wall PrintUnixTime\main.c /link /O2 /out:bin\PrintUnixTime.exe
cl /Wall RNGTool\main.c /link /O2 /out:bin\RNGTool.exe
cl /Wall WordGenerator\main.c /link /O2 /out:bin\WordGenerator.exe
cp WordGenerator/words.txt bin/words.txt
