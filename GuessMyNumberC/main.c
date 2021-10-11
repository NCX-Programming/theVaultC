/*theVaultC/GuessMyNumberC "main.c"
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
// Code to use different headers in Windows
#ifdef _WIN32
  #include <Windows.h>
  #define sleep(x) Sleep(x*1000)
  #define usleep(x) Sleep(x/1000)
#else
  #include <unistd.h>
#endif
// Declare variables
int g_menuChoice;
// Code start
int clrScrn() {
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
}
void PlayGame(int maxNumber,int maxGuesses){
  int guess;
  int randomNumber;
  int usedGuesses=0;
  // Get the random number, seed is taken from the time
  srand(time(0));
  randomNumber = rand() % maxNumber;
  // Start the game
  clrScrn();
  usedGuesses = 0;
  printf("I'm thinking of a number between 1 and %d!\n", maxNumber);
  for(usedGuesses=0;usedGuesses<maxGuesses;usedGuesses++){
    printf("Enter your guess: ");
    // Read input
    scanf("%d",&guess);
    if(guess==randomNumber){
      clrScrn();
      printf("Congratulations! You guessed the right number in %d guesses!\n", usedGuesses);
      printf("Play again? y/n ");
      while(g_menuChoice!=0){
        g_menuChoice=0;
        g_menuChoice=fgetc(stdin);
        if(g_menuChoice==89||g_menuChoice==121)PlayGame(maxNumber,maxGuesses);
        if(g_menuChoice==78||g_menuChoice==110)exit(0); }
    }
    // Answer too large
    else if(guess>randomNumber){
      clrScrn();
      printf("Too large! Try a smaller number.\n");
      usleep(500000);
      clrScrn();
    }
    // Answer too small
    else if(guess<randomNumber){
      clrScrn();
      printf("Too small! Try a larger number.\n");
      usleep(500000);
      clrScrn();
    }
  }
  // Game over; no more guesses
  clrScrn();
  printf("Game Over!\n");
  printf("You were unable to guess the number in %d guesses\n",maxGuesses);
  printf("The correct answer was: %d!\n",randomNumber);
  printf("Play again? y/n ");
  while(g_menuChoice!=0){
    g_menuChoice=0;
    g_menuChoice=fgetc(stdin);
    if(g_menuChoice==89||g_menuChoice==121)PlayGame(maxNumber,maxGuesses);
    if(g_menuChoice==78||g_menuChoice==110)exit(0); }
  exit(0);
}
int main(int argc,char *argv[]){
  int settingsLoop=0;
  // Integers that are passed when the game starts but need to be adjusted here first
  int maxNumber = 100;
  int maxGuesses = 10;
  int skipMenu=0;
  int i;
  if(argc>1){
    for(i=1;i<argc;i++){
      if(strcmp(argv[i],"--help")==0||strcmp(argv[i],"-h")==0){
        printf("\nGuessMyNumberC Usage\n\n");
        printf("./GuessMyNumberC [--help] [--play] [--max] <int> [--guesses] <int>\n");
        printf("                 [-h]     [-p]\n\n");
        printf("--play, Make game start as soon as command is entered, bypassing the menu\n\n");
        printf("--max, Specify a maximum number from the terminal\n\n");
        printf("--guesses, Specify the number of guesses allowed from the terminal\n\n");
        return(0);
      }
      else if(strcmp(argv[i],"--max")==0){
        printf("%s,%s\n",argv[i],argv[i+1]);
        if(argc>i+1){
          maxNumber=atoi(argv[i+1]);
          if(maxNumber<=0){
            printf("Invalid argument, try --help\n");
            return(-1);
          }
        }
        else{
          printf("Invalid argument, try --help\n");
          return(-1);
        }
      }
      else if(strcmp(argv[i],"--guesses")==0){
        printf("%s,%s\n",argv[i],argv[i+1]);
        if(argc>i+1){
          maxGuesses=atoi(argv[i+1]);
          if(maxGuesses<=0){
            printf("Invalid argument, try --help\n");
            return(-1);
          }
        }
        else{
          printf("Invalid argument, try --help\n");
          return(-1);
        }
      }
      else if(strcmp(argv[i],"--play")==0||strcmp(argv[i],"-p")==0){
        skipMenu=1;
      }
    }
  }
  // If you specified the --play flag, start the game without showing the menu
  if(skipMenu)PlayGame(maxNumber,maxGuesses);
  clrScrn();
  // Draw welcome screen/main menu
  printf("Welcome to Guess My Number! (theVault C Edition) [v1.1.0]\n");
  printf("Select an option by entering the number for your choice and pressing enter.\n");
  printf("1. Play     2. Exit\n");
  g_menuChoice=fgetc(stdin);
  if(g_menuChoice==49){
    while(settingsLoop!=1){
      g_menuChoice=0;
      clrScrn();
      printf("Game Settings\n");
      printf("Select a number to change it, then press 3 to start the game.\n");
      printf("1. Max Number: %d\n2. Max Guesses: %d\n3. Start\n",maxNumber,maxGuesses);
      g_menuChoice=fgetc(stdin);
      // Get settings menu choice
      if(g_menuChoice==49){
        // Set max number
        clrScrn();
        printf("Enter the max number, must be positive, larger than 1, and smaller than 255:\n");
        // Read input and reset to 100 if invalid
        // If the number is 255 it likely underflowed and therefor needs to be fixed
        scanf("%d",&maxNumber);
        if(maxNumber<1||maxNumber==255)maxNumber=100;
        // Output new max number and return to settings
        clrScrn();
        printf("Max number set to %d\n",maxNumber);
        sleep(1);
      }
      else if(g_menuChoice==50) {
        // Set max guesses
        clrScrn();
        printf("Enter the max number of guesses, must be positive, at least 1, and smaller than 255:\n");
        // Read input and reset to 100 if invalid
        scanf("%d",&maxGuesses);
        if(maxGuesses<1||maxGuesses==255)maxGuesses=10;
        // Output new max number and return to settings
        clrScrn();
        printf("Max guesses set to %d\n",maxGuesses);
        sleep(1);
      }
      else if(g_menuChoice==51)PlayGame(maxNumber,maxGuesses);
    }
  }
  else if(g_menuChoice==50)exit(0);
}
