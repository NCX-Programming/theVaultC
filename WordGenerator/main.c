/*theVaultC/WordGenerator "main.c"
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
#include <string.h>
#include <time.h>
// Code start
int countWords(char *buffer,int size){
  // Count number of words in the file based on newlines
  int numWords=0,i;
  for(i=0;i<size;i++){
    char c=buffer[i];
    if(c=='\n'||i==size-1)numWords++;
  }
  return numWords;
}
int main(int argc,char *argv[]){
  // Seed rand()
  srand(time(0));
  char *buffer;
  int size;
  // Open word list file
  // Read contents to buffer and size to size
  FILE *fp=fopen("words.txt","rb");
  // Make sure the file exists
  // If it doesn't, exit as early as possible
  if(fp==NULL){
    printf("\e[0;91mError:\e[0m Could not find \"words.txt\"! Exiting...\n");
    return(-1);
  }
  fseek(fp,0,SEEK_END);
  size=ftell(fp);
  buffer=malloc(size);
  fseek(fp,0,SEEK_SET);
  fread(buffer,size,1,fp);
  fclose(fp);
  // Make sure the final character before the null byte is a newline
  if(buffer[size-1]!=10){
    printf("\e[0;91mError:\e[0m File \"words.txt\" is improperly formatted! Expected \"\\n\" at position %d but got \"%c\"!\n",size-1,buffer[size-1]);
    return(-2);
  }
  // Initialize all variables
  int numWords=countWords(buffer,size);
  char **wordArray=malloc(numWords*sizeof(char *));
  int nextCharBeginsWord=1;
  int nCountedWords=0;
  int i;
  int ii;
  int numPrintWords;
  // Loop through the entire buffer based on the number of words
  // returned by countWords() and figure out the starting
  // position of each word in the array
  for(i=0;i<size;i++){
    if(nextCharBeginsWord==1)wordArray[nCountedWords++]=buffer+i;
    char c=buffer[i];
    if(c=='\n'){
      nextCharBeginsWord=1;
      buffer[i]='\0';
    }
    else nextCharBeginsWord=0;
  }
  if(argc==2){
    // If an argument was supplied, check if it's help, and if it isn't then
    // use it as the number of words to generate
    if(strcmp(argv[1],"--help")==0||strcmp(argv[1],"-h")==0){
      printf("\nWordGenerator Usage\n\n");
      printf("./WordGenerator [--help] [--version] [int]\n");
      printf("                [-h]     [-v]\n\n");
      printf("Specify an integer to generate that many words.\n");
      printf("If no integer is supplied, a random number of words will be generated.\n\n");
    }
    else if(strcmp(argv[1],"--version")==0||strcmp(argv[1],"-v")==0){
      printf("\nWordGenerator by NCX Programming\n");
      printf("Version 1.0.2\n\n");
    }
    else {
      numPrintWords=atoi(argv[1]);
      if(numPrintWords==0){
        printf("Invalid argument, try --help\n");
        return(1);
      }
      printf("Out of %d total words, your %d words are:\n",numWords,numPrintWords);
      for(ii=0;ii<numPrintWords;ii++){
        printf("%s ",wordArray[rand()%nCountedWords]);
      }
      printf("\n");
    }
  }
  else if(argc==1){
    // If no argument was supplied, generate a random number of words to generate
    numPrintWords=1+rand()%(7-1);
    printf("Out of %d total words, your %d words are:\n",numWords,numPrintWords);
    for(ii=0;ii<numPrintWords;ii++){
      printf("%s ",wordArray[rand()%nCountedWords]);
    }
    printf("\n");
  }
  else {
    printf("Invalid arguments, try --help\n");
  }
  return(0);
}
