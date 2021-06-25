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
// Function used to ignore arrow key presses and print any other key presses
int checkch(int z){
  if(z==KEY_UP||z==KEY_DOWN||z==KEY_LEFT||z==KEY_RIGHT||z==KEY_BACKSPACE||z==127){
    return(0);
  }
  else{
    printw("%c",z);
    return(0);
  }
}
// Color-setting function to reduce the number of lines used later in the code
int setcolor(int col,int w){
  attron(COLOR_PAIR(col));
  checkch(w);
  attroff(COLOR_PAIR(col));
  return(0);
}
int main(){
  int ch;
  int color=0;
  int x;
  int y;

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
  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);
  // End initialization, print welcome text, and begin watching for key presses
  printw("Type some characters and see them in rainbow. (F1 to exit, F2 to clear screen)\n");
  refresh();
  // Key press detection loop
  while(1){
    ch=getch();
    color++;
    // Detect F1, which breaks the loop and leads to de-initialization
    if(ch==KEY_F(1)){
      break;
    }
    // Detect F2, which uses a loop to clear every line
    else if(ch==KEY_F(2)){
      int i=0;
      while(i<=max_y){
        move(i,0);
        clrtoeol();
        i++;
      }
      move(0,0);
    }
    // Backspace detection, 127 is the code for the delete key on Macs
    else if(ch==KEY_BACKSPACE||ch==127){
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
    }
    // Arrow key presses, just moves the cursor in that direction
    getyx(stdscr,y,x);
    switch(ch){
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
    // Color switch used to cycle through the colors pairs generated earlier
    switch(color){
      case 1:
        setcolor(1,ch);
        break;
      case 2:
        setcolor(2,ch);
        break;
      case 3:
        setcolor(3,ch);
        break;
      case 4:
        setcolor(4,ch);
        break;
      case 5:
        setcolor(5,ch);
        break;
      case 6:
        setcolor(6,ch);
        color=0;
        break;
    }
  }
  refresh();
	endwin();
	return 0;
}
