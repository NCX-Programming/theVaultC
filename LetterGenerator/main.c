/*theVaultC/LetterGenerator "main.c"
Copyright (C) 2021 NinjaCheetah
Copyright (C) 2021 NCX Programming
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc,char *argv[]){
  // Create array with the alphabet
  char* alphabet[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  // Seed rand()
  srand(time(0));
  int i;
  int numLetters=0;
  int newlines=0;
  if(argc>1){
    for(i=1;i<argc;i++){
      if(strcmp(argv[i],"--help")==0||strcmp(argv[i],"-h")==0){
        printf("\nLetterGenerator Usage\n\n");
        printf("./LetterGenerator [--help | -h] [--version | -v] [--nl] [int]\n\n");
        printf("Specify an integer to generate that many letters.\n");
        printf("If no integer is supplied, a random number of letters will be generated.\n\n");
        printf("--nl, add a newline between each generated letter\n\n");
        return(0);
      }
      else if(strcmp(argv[i],"--version")==0||strcmp(argv[1],"-v")==0){
        printf("\nLetterGenerator by NCX Programming\n");
        printf("Version 1.0.0\n\n");
        return(0);
      }
      else if(strcmp(argv[i],"--nl")==0){
        newlines=1;
      }
      else{
        if((numLetters=atoi(argv[i]))==0){
          printf("Invalid argument, try --help\n");
          return(-1);
        }
      }
    }
  }
  if(!numLetters){
    printf("Your letters are: ");
    for(i=0;i<rand()%10+1;i++){
      if(newlines)printf("\n");
      printf("%s ",alphabet[rand()%26]);
    }
    printf("\n");
  }
  else{
    printf("Your letters are: ");
    for(i=0;i<numLetters;i++){
      if(newlines)printf("\n");
      printf("%s ",alphabet[rand()%26]);
    }
    printf("\n");
  }
  return(0);
}
