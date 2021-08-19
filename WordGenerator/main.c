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
#include <time.h>
// Code start
int countWords(char *buffer,int size){
  int numWords=0,i;
  for(i=0;i<size;i++){
    char c=buffer[i];
    if(c=='\n'||i==size-1)numWords++;
  }
  return numWords;
}
int main(void){
  srand(time(0));
  char *buffer;
  int size;
  FILE *fp=fopen("words.txt","rb");
  fseek(fp,0,SEEK_END);
  size=ftell(fp);
  buffer=malloc(size);
  fseek(fp,0,SEEK_SET);
  fread(buffer,size,1,fp);
  fclose(fp);
  int numWords=countWords(buffer,size);
  char **wordArray=malloc(numWords*sizeof(char *));
  int nextCharBeginsWord=1;
  int nCountedWords=0;
  int i;
  int ii;
  int numPrintWords;
  for(i=0;i<size;i++){
    if(nextCharBeginsWord==1)wordArray[nCountedWords++]=buffer+i;
    char c=buffer[i];
    if(c=='\n'){
      nextCharBeginsWord=1;
      buffer[i]='\0';
    }
    else nextCharBeginsWord=0;
  }
  numPrintWords=1+rand()%(7-1);
  printf("Out of %d total words, your %d words are:\n",numWords,numPrintWords);
  for(ii=0;ii<numPrintWords;ii++){
    printf("%s ",wordArray[rand()%nCountedWords]);
  }
  printf("\n");
}
