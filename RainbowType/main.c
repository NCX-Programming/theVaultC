/*theVaultC/RainbowType "main.c"
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
#include <ncurses.h>
// Color-setting function to reduce the number of lines used later in the code
// Now prints the character after the check
int setcolor(int col,int w){
  attron(COLOR_PAIR(col));
  if(!(w==KEY_UP||w==KEY_DOWN||w==KEY_LEFT||w==KEY_RIGHT||w==KEY_BACKSPACE||w==127)){
    printw("%c",w);
  }
  attroff(COLOR_PAIR(col));
  return(0);
}
int main(){
  int ch;
  int8_t color=0;
  int y,x;
  int i=0;
  int8_t charcheck=1;
	initscr();
  // Set color pairs
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  // Initialization stuff
	raw();
	keypad(stdscr, TRUE);
	noecho();
  // Get the size of the terminal window
  int max_y,max_x;
  getmaxyx(stdscr, max_y, max_x);
  // End initialization, print welcome text, and begin watching for key presses
  printw("Type some characters and see them in rainbow.  [v1.0.0]\n(F1 to exit, F2 to clear screen)\n");
  refresh();
  // Key press detection loop
  while(charcheck==1){
    ch=getch();
    color++;
    // Detect F1, which breaks the loop and leads to de-initialization
    getyx(stdscr,y,x);
    switch(ch){
      // F1 code, sets the while() variable to false, ending the loop and exiting
      case KEY_F(1):
        charcheck=0;
        break;
      // F2 code, clears the screen line by line
      case KEY_F(2):
        while(i<=max_y){
          move(i,0);
          clrtoeol();
          i++;
        }
        move(0,0);
        i=0;
        break;
      // Backspace code, 127 is for the 'delete' key on Macs
      case KEY_BACKSPACE:
      case 127:
        getyx(stdscr,y,x);
        if(x==0){
          mvprintw(y-1,max_x+1,"");
          mvprintw(y-1,max_x-1,"");
          move(y-1,max_x-1);
        }
        else{
          move(y,x-1);
          printw(" ");
          move(y,x-1);
        }
        break;
      // Arrow keys
      case KEY_UP:
        move(y-1,x);
        break;
      case KEY_DOWN:
        move(y+1,x);
        break;
      case KEY_LEFT:
        move(y,x-1);
        break;
      case KEY_RIGHT:
        move(y,x+1);
        break;
    }
    // Call setcolor() with the current color, and if it's 6 then reset it after
    setcolor(color,ch);
    if(color==6)color=0;
  }
  refresh();
	endwin();
	return(0);
}
