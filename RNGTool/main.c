/*theVaultC/RNGTool "main.c"
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
// Code to use different headers in Windows
#ifdef _WIN32
  #include <Windows.h>
  #define usleep(x) Sleep(x/1000)
#else
  #include <unistd.h>
#endif
// Version number for easy incrementing
char g_version[7]="0.4.1";
// Code start
int clrScrn(){
  // Screen clear fucntion, checks OS first for compatibility:tm:
  #ifdef _WIN32
    system("cls");
  #endif
  #ifdef unix
    return(system("clear"));
  #endif
  #ifdef __APPLE__
    return(system( "clear" ));
  #endif
  return(0);
}
int getNum(int max,int min){
  return(min+rand()%(max+1-min));
}
int main(int argc,char *argv[]){
  // Control variables
  int menuChoice;
  int execLoop=1;
  int printToTerm=0;
  // RNG variables
  int usrSeed=0;
  int randomNumber=0;
  int maxNumber=100;
  int minNumber=0;
  // Seed rand()
  srand(time(0));
  // Now that variables are set, check arguments
  int i;
  if(argc>1){
    for(i=1;i<argc;i++){
      if(strcmp(argv[i],"--help")==0||strcmp(argv[i],"-h")==0){
        printf("\nRNGTool Usage\n\n");
        printf("./RNGTool [--help | -h] [--version | -v] [--generate | -g] [--max] <int> [--guesses] <int>\n\n");
        printf("--generate, Use the current values to generate a number, skipping the menus\n\n");
        printf("--max, Specify a maximum number from the terminal, must be larger than min\n\n");
        printf("--min, Specify a minimum number from the terminal, must be smaller than max\n\n");
        printf("RNGTool currently does not support seeding outside of the menus.\n\n");
        return(0);
      }
      else if(strcmp(argv[1],"--version")==0||strcmp(argv[1],"-v")==0){
        printf("\nRNGTool by NCX Programming\n");
        printf("Version %s\n\n",g_version);
        return(0);
      }
      else if(strcmp(argv[i],"--max")==0){
        if(argc>i+1){
          maxNumber=atoi(argv[i+1]);
          if(maxNumber<=minNumber||maxNumber<=0){
            printf("Invalid argument, try --help\n");
            return(-1);
          }
        }
        else{
          printf("Invalid argument, try --help\n");
          return(-1);
        }
      }
      else if(strcmp(argv[i],"--min")==0){
        if(argc>i+1){
          minNumber=atoi(argv[i+1]);
          if(maxNumber<=minNumber){
            printf("Invalid argument, try --help\n");
            return(-1);
          }
        }
        else{
          printf("Invalid argument, try --help\n");
          return(-1);
        }
      }
      else if(strcmp(argv[i],"--generate")==0||strcmp(argv[i],"-g")==0)printToTerm=1;
    }
  }
  // Check to see if we should be skipping the menus and printing now
  if(printToTerm){
    printf("Your random number is: %d\n",getNum(maxNumber,minNumber));
    return(0);
  }
  clrScrn();
  printf("Welcome to RNGTool v%s\n",g_version);
  usleep(1000000);
  while(execLoop==1){
    menuChoice=0;
    clrScrn();
    printf("Current number: %d\n\n",randomNumber);
    printf("Options\n");
    printf("1. Maximum Number: %d\n",maxNumber);
    printf("2. Minimum Number: %d\n",minNumber);
    if(usrSeed==0)printf("3. Seed: time(0) (Seed taken from time)\n");
    else printf("3. Seed: %d\n",usrSeed);
    printf("4. Generate!\n");
    printf("5. Exit\n");
    menuChoice=fgetc(stdin);
    switch(menuChoice){
      case 49:
        printf("\nEnter the new maximum number: (must be positive)\n");
        // Input number, reset to 100 if less than 1
        scanf("%d",&maxNumber);
        if(maxNumber<1)maxNumber=100;
        clrScrn();
        printf("New maximum number set: %d\n",maxNumber);
        usleep(750000);
        break;
      case 50:
        printf("\nEnter the new minimum number: (must be smaller than maximum number)\n");
        // Input number, reset to 100 if less than 1
        scanf("%d",&minNumber);
        if(minNumber>=maxNumber)minNumber=0;
        clrScrn();
        printf("New minimum number set: %d\n",minNumber);
        usleep(1000000);
        break;
      case 51:
        printf("\nEnter the seed you'd like to use to when generating a random number:\n");
        printf("Enter \"0\" to use time(0), which gets the seed from the seconds since Unix Time started\n");
        // Input seed, print a different message if 0 is selected
        scanf("%d",&usrSeed);
        clrScrn();
        if(usrSeed==0){
          printf("The seed will be generated using time(0)\n");
          srand(time(0));
        }
        else{
          printf("New seed set to: %d\n",usrSeed);
          srand(usrSeed);
        }
        usleep(750000);
        break;
      case 52:
        // Get the random number, using the max/min numbers and the seed provided by the user
        randomNumber=getNum(maxNumber,minNumber);
        break;
      case 53:
        execLoop=0;
        break;
      default:
        break;
    }
  }
  return(0);
}
