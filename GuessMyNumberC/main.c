#include <stdio.h>
#include <stdlib.h>

int clrScrn() {
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef linux
        system("clear");
    #endif
}


int PlayGame() {
    printf("This worked\n");
}

int GameSettings() {
    
}

int main() {

    // Declare variables
    int menuChoice;
    int guess;
    int randomNumber;
    int maxNumber = 0;
    int maxGuesses = 0;
    int usedGuesses = 0;

    clrScrn();    
    
    // Welcome
    printf("Welcome to Guess My Number! (theVault C Edition)\n");
    printf("Press ENTER to begin.\n");
    getchar();

    clrScrn();    

    // Main Menu
    printf("Main Menu\n");
    printf("Select an option by pressing the number on your keyboard.\n");
    printf("1. Play     2. Game Settings     3. Exit\n");    
    menuChoice =fgetc(stdin);
    if(menuChoice == 49) PlayGame();
    if(menuChoice == 50) GameSettings();
    if(menuChoice == 51) exit(0);
}

