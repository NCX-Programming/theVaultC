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
    return(0);
  #endif
  #ifdef unix
    system("clear");
    return(0);
  #endif
  #ifdef __APPLE__
    system( "clear" );
    return(0);
  #endif
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
  printf("Welcome to RNGTool v0.1.0\n");
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
        break;
      case 50:
        break;
      case 51:
        break;
      case 52:
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
