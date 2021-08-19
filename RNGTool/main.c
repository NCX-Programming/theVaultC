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
#include <unistd.h>
#include <time.h>
// Code start
int clrScrn(){
  // Screen clear fucntion, checks OS first for compatibility:tm:
  #ifdef _WIN32
    system("cls");
  #endif
  #ifdef unix
    system("clear");
  #endif
  #ifdef __APPLE__
    system( "clear" );
  #endif
  return(0);
}
int main(void){
  // Control variables
  int menuChoice;
  int execLoop=1;
  // RNG variables
  int usrSeed=0;
  int randomNumber=0;
  int maxNumber=100;
  int minNumber=0;
  clrScrn();
  printf("Welcome to RNGTool v0.3.0\n");
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
        fflush(stdout);
        usleep(750000);
        break;
      case 50:
        printf("\nEnter the new maximum number: (must be smaller than maximum number)\n");
        // Input number, reset to 100 if less than 1
        scanf("%d",&minNumber);
        if(minNumber>=maxNumber)minNumber=0;
        clrScrn();
        printf("New minimum number set: %d\n",minNumber);
        fflush(stdout);
        usleep(1000000);
        break;
      case 51:
        printf("\nEnter the seed you'd like to use to when generating a random number:\n");
        printf("Enter \"0\" to use time(0), which gets the seed from the seconds since Unix Time started\n");
        // Input seed, print a different message if 0 is selected
        scanf("%d",&usrSeed);
        clrScrn();
        if(usrSeed==0)printf("The seed will be generated using time(0)\n");
        else printf("New seed set to: %d\n",usrSeed);
        fflush(stdout);
        usleep(750000);
        break;
      case 52:
        // Get the random number, using the max/min numbers and the seed provided by the user
        if(usrSeed==0)srand(time(0));
        else srand(usrSeed);
        randomNumber=minNumber+rand()%(maxNumber+1-minNumber);
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
