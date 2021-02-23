#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare variables
int menuChoice;
int guess;
int randomNumber;
int maxNumber = 100;
int maxGuesses = 0;
int usedGuesses = 0;

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
    // Get the random number, seed is taken from the time
    srand(time(0));
    randomNumber = rand() % maxNumber;
    printf("This worked: %d\n", randomNumber);
    // Start the game
    clrScrn();
    usedGuesses = 0;
    printf("I'm thinking of a number between 1 and %d\n", randomNumber);
    printf("Enter your guess:");
    
}

int GameSettings() {
    
}

int main() {
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

