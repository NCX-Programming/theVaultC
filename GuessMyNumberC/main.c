#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Declare variables
int menuChoice;
int guess;
int randomNumber;
int maxNumber = 100;
int maxGuesses = 10;
int usedGuesses = 0;
char guessString[30];
// Declare functions
int GuessAgain();
int CheckAnswer();
int PlayGame();

int clrScrn() {
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef linux
        system("clear");
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
    if(menuChoice==49) PlayGame();
    if(menuChoice==50) GameSettings();
    if(menuChoice==51) exit(0);
}