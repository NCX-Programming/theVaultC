//theVaultC/GuessMyNumberC "main.c"
//Copyright (C) 2021 NinjaCheetah
//Copyright (C) 2021 NCX-Programming
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
// Declare variables
int menuChoice;
int guess;
int randomNumber;
int maxNumber = 0;
int maxGuesses = 0;
int usedGuesses = 0;
char guessString[30];
// Declare functions
int GuessAgain();
int CheckAnswer();
int PlayGame();
// Code start
int clrScrn() {
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
}
int CheckAnswer() {
    // Correct answer
    if(guess==randomNumber){
        clrScrn();
        printf("Congratulations! You guessed the right number in %d guesses!\n", usedGuesses);
        printf("Play again? y/n ");
        while (menuChoice!=0){
            menuChoice=0;
            menuChoice=fgetc(stdin);
            if(menuChoice==89||menuChoice==121) PlayGame();
            if(menuChoice==78||menuChoice==110) exit(0); }
    }
    // Answer too large
    if(guess>randomNumber){
        clrScrn();
        printf("Too large! Try a smaller number.\n");
        GuessAgain();
    }
    // Answer too small
    if(guess<randomNumber){
        clrScrn();
        printf("Too small! Try a larger number.\n");
        GuessAgain();
    }
}
int GuessAgain() {
    // Check if there are any guesses remaining
    if(usedGuesses==maxGuesses){
        // Game over; no more guesses
        clrScrn();
        printf("Game Over!\n");
        printf("You were unable to guess the number in %d guesses\n", maxGuesses);
        printf("Play again? y/n ");
        while(menuChoice!=0){
            menuChoice=0;
            menuChoice=fgetc(stdin);
            if(menuChoice==89||menuChoice==121) PlayGame();
            if(menuChoice==78||menuChoice==110) exit(0); }
    }else{
        // Repeating guess code
        sleep(1);
        clrScrn();
        printf("Enter your guess: ");
        scanf("%s", guessString);
        guess = atoi(guessString);
        usedGuesses++;
        CheckAnswer();
    }
}
int PlayGame() {
    // Fix unset variables
    if(maxGuesses==0) maxGuesses=10;
    if(maxNumber==0) maxNumber=100;
    // Get the random number, seed is taken from the time
    srand(time(0));
    randomNumber = rand() % maxNumber;
    // Start the game
    clrScrn();
    usedGuesses = 0;
    printf("I'm thinking of a number between 1 and %d\n", maxNumber);
    printf("Enter your guess: ");
    // Read input and convert to integer
    scanf("%s", guessString);
    guess = atoi(guessString);
    usedGuesses++;
    CheckAnswer();
}
int GameSettings() {
    // Declare temp string variables
    char maxNumStr[30];
    char maxGuessStr[30];
    clrScrn();
    // Draw settings screen
    printf("Game Settings\n");
    printf("Select an option by entering one of the numbers below.\n");
    printf("1. Change Max Number     2. Change Max Guesses     3. Play\n");
    while(menuChoice!=0){
        menuChoice=0;
        menuChoice=fgetc(stdin);
        // Get settings menu choice
        if(menuChoice==49){
            // Set max number
            while(maxNumber<=1){
                clrScrn();
                printf("Enter the max number, must be positive, larger than 1, and an integer:\n");
                // Read input and convert to integer
                scanf("%s",maxNumStr);
                maxNumber=atoi(maxNumStr); }
                // Output new max number and return to settings
                clrScrn();
                printf("Max number set to %d\n",maxNumber); 
                sleep(1);
                GameSettings();
        }if(menuChoice==50) {
            // Set max guesses
            while(maxGuesses<=0){
                clrScrn();
                printf("Enter the max number of guesses, must be positive, at least 1, and an integer:\n");
                // Read input and convert to integer
                scanf("%s",maxGuessStr);
                maxGuesses=atoi(maxGuessStr); }
                // Output new max number and return to settings
                clrScrn();
                printf("Max guesses set to %d\n",maxGuesses);
                sleep(1);
                GameSettings(); 
        }if(menuChoice==51) PlayGame(); }
}
int main() {
    clrScrn();    
    // Welcome
    printf("Welcome to Guess My Number! (theVault C Edition)\n");
    printf("Press ENTER to begin.\n");
    getchar();
    // Draw Main Menu
    clrScrn();
    printf("Main Menu\n");
    printf("Select an option by pressing the number on your keyboard.\n");
    printf("1. Play     2. Game Settings     3. Exit\n");    
    menuChoice =fgetc(stdin);
    if(menuChoice==49) PlayGame();
    if(menuChoice==50) GameSettings();
    if(menuChoice==51) exit(0);
}