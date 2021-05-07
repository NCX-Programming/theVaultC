#include <ncurses.h>

int checkch(int z){
  if(z==KEY_UP){
    return(0);
  }
  else if(z==KEY_DOWN){
    return(0);
  }
  else if(z==KEY_LEFT){
    return(0);
  }
  else if(z==KEY_RIGHT){
    return(0);
  }
  else{
    printw("%c",z);
  }
}
int main(){
  int ch;
  int color=0;
  int x;
  int y;

	initscr();
  // Color stuff
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  // End of color stuff
	raw();
	keypad(stdscr, TRUE);
	noecho();

  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  printw("Type some characters and see them in rainbow. (F1 to exit, F2 to clear screen)\n");
  refresh();

  while(1){
    ch = getch();
    color++;
    if(ch==KEY_F(1)){
      break;
    }
    else if(ch==KEY_F(2)){
      int i;
      while(i<=max_y){
        move(i,0);
        clrtoeol();
        i++;
      }
    }
    else if(ch==KEY_BACKSPACE){
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
      color=7;
    }
    else if(ch==KEY_UP){
      getyx(stdscr,y,x);
      move(y-1,x);
    }
    else if(ch==KEY_DOWN){
      getyx(stdscr,y,x);
      move(y+1,x);
    }
    else if(ch==KEY_LEFT){
      getyx(stdscr,y,x);
      move(y,x-1);
    }
    else if(ch==KEY_RIGHT){
      getyx(stdscr,y,x);
      move(y,x+1);
    }
    switch(color){
      case 1:
        attron(COLOR_PAIR(1));
        checkch(ch);
        attroff(COLOR_PAIR(1));
        break;
      case 2:
        attron(COLOR_PAIR(2));
        checkch(ch);
        attroff(COLOR_PAIR(2));
        break;
      case 3:
        attron(COLOR_PAIR(3));
        checkch(ch);
        attroff(COLOR_PAIR(3));
        break;
      case 4:
        attron(COLOR_PAIR(4));
        checkch(ch);
        attroff(COLOR_PAIR(4));
        break;
      case 5:
        attron(COLOR_PAIR(5));
        checkch(ch);
        attroff(COLOR_PAIR(5));
        break;
      case 6:
        attron(COLOR_PAIR(6));
        checkch(ch);
        attroff(COLOR_PAIR(6));
        color=0;
        break;
      case 7:
        // "Skip" function
        color=0;
        break;
    }
  }

  refresh();
	endwin();
	return 0;
}
