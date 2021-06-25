/*theVaultC/GraphicStuffC "main.c"
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
// Declare variables
int menuChoice=1;
// Declare functions that need to always be accessible
void Menu();
// Start code
void clrScrn() {
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
void Colors(){
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
    printf("\e[0;97mHigh-Intensity White\n");
    printf("\e[0;37mWhite\e[0m\n");
    sleep(3);
    printf("Press ENTER To Return to the Main Menu\n");
    getchar();
    getchar();
    Menu();
}
void MenuTests(){
    // Explain example 1
    clrScrn();
    printf("Example 1, a message box\n");
    sleep(2);
    // Draw example 1
    clrScrn();
    printf("*====================================*\n");
    printf("|            Message Box             |\n");
    printf("*====================================*\n");
    printf("|                                    |\n");
    printf("|         I'm a message box!         |\n");
    printf("|                                    |\n");
    printf("|                                    |\n");
    printf("|  1. Ok                  2. Cancel  |\n");
    printf("*====================================*\n");
    // Wait briefly, and then prompt to continue
    sleep(2);
    printf("Press ENTER to continue\n");
    getchar();
    getchar();
    // Explain example 2
    clrScrn();
    printf("Example 2, a selection menu\n");
    sleep(2);
    // Draw example 2
    clrScrn();
    printf("*====================================*\n");
    printf("| Example Title                      |\n");
    printf("*=======*============================*\n");
    printf("|       |                            |\n");
    printf("|  (1)  |   Example Item 1           |\n");
    printf("|       |                            |\n");
    printf("|  (2)  |   Example Item 2           |\n");
    printf("|       |                            |\n");
    printf("|  (3)  |   Example Item 3           |\n");
    printf("|       |                            |\n");
    printf("|  (4)  |   Example Item 4           |\n");
    printf("|       |                            |\n");
    printf("|  (5)  |   Example Item 5           |\n");
    printf("|       |                            |\n");
    printf("|  (6)  |   Example Item 6           |\n");
    printf("|       |                            |\n");
    printf("|  (7)  |   Example Item 7           |\n");
    printf("|       |                            |\n");
    printf("*=======*============================*\n");
    // Wait briefly, and then prompt to continue
    sleep(2);
    printf("Press ENTER to continue\n");
    getchar();
    Menu();
}
void About(){
    clrScrn();
    // Draw about screen
    printf("==============================\n");
    printf("|      'Graphics' Test       |\n");
    printf("|         theVaultC          |\n");
    printf("|                            |\n");
    printf("|     © NinjaCheetah 2021    |\n");
    printf("|   © NCX-Programming 2021   |\n");
    printf("|                            |\n");
    printf("|Thanks for actually stopping|\n");
    printf("|       to read this :p      |\n");
    printf("|                            |\n");
    printf("|   Press ENTER to go back   |\n");
    printf("==============================\n");
    getchar();
    getchar();
    Menu();
}
void Menu(){
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
        if(menuChoice==50) MenuTests();
        if(menuChoice==51){}
        if(menuChoice==52) About();
        if(menuChoice==53) exit(0);
    }
}
int main(void){
    clrScrn();
    // Draw main screen
    printf("\e[0;97m===============================\n");
    printf("|       'Graphics' Test       |\n");
    printf("|          theVaultC          |\n");
    printf("|                             |\n");
    printf("|   ");
    // White highlighted section
    printf("\e[0;30m\e[107mPress ENTER to continue\e[0m");
    printf("   |\n");
    // End of white highlighted section
    printf("|                             |\n");
    printf("|                             |\n");
    printf("===============================\n");
    getchar();
    Menu();
}
