#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// Declare variables
int menuChoice=1;
// Declare functions that need to always be accessible
int Menu();
// Start code
int clrScrn() {
    // Screen clear fucntion, checks OS first for compatibility:tm:
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef unix
        system("clear");
    #endif
}
int Colors(){
    clrScrn();
    // Output all available foreground colors
    printf("Foreground Colors:\n");
    printf("\e[0;30m\e[47mBlack\n\e[40m");
    printf("\e[0;90mGrey\n");
    printf("\e[0;31mDark Red\n");
    printf("\e[0;32mDark Green\n");
    printf("\e[0;33mDark Yellow\n");
    printf("\e[0;34mDark Blue\n");
    printf("\e[0;35mDark Magenta\n");
    printf("\e[0;36mDark Cyan\n");
    printf("\e[0;91mRed\n");
    printf("\e[0;92mGreen\n");
    printf("\e[0;93mYellow\n");
    printf("\e[0;94mBlue\n");
    printf("\e[0;95mMagenta\n");
    printf("\e[0;96mCyan\n");
    printf("\e[0;97mHigh Intesnity White\n");
    printf("\e[0;37mWhite\n");
    sleep(1);
    // Output all available foreground colors

}
int Menu(){
    clrScrn();
    // Draw example selection menu
    printf("============================================================\n");
    printf("| Choose an example to try:                                |\n");
    printf("|                                                          |\n");
    printf("|                                                          |\n");
    printf("| 1. Color Test                                            |\n");
    printf("|                                                          |\n");
    printf("| 2. Menu Style Test (WIP, but functional)                 |\n");
    printf("|                                                          |\n");
    printf("| 3. Misc Things I tried to 'draw' (WIP)                   |\n");
    printf("|                                                          |\n");
    printf("| 4. About                                                 |\n");
    printf("|                                                          |\n");
    printf("| 5. Exit                                                  |\n");
    printf("|                                                          |\n");
    printf("============================================================\n");
    // Read menu selection
    while(menuChoice!=0){
        menuChoice=0;
        menuChoice=fgetc(stdin);
        // Get settings menu choice
        if(menuChoice==49) Colors();
        if(menuChoice==50){}
        if(menuChoice==51){}
        if(menuChoice==52){}
        if(menuChoice==53) exit(0);
    }
}
int main(){
    clrScrn();
    // Draw main screen
    printf("===============================\n");
    printf("|       'Graphics' Test       |\n");
    printf("|           theVault          |\n");
    printf("|                             |\n");
    printf("|   ");
    // White highlighted section
    printf("\e[0;30m\e[47mPress ENTER to continue\e[0;37m\e[40m");
    printf("   |\n");
    // End of white highlighted section
    printf("|                             |\n");
    printf("|                             |\n");
    printf("===============================\n");
    getchar();
    Menu();
}