// Jacob Mader
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

FILE *user; // File Pointer
char who[100]; // global user variable
int gx; // global variable for max x of screen
int gy; // global variable for max y of screen
int boardheight = 6;
int boardwidth = 7;
int boardwinsize = 4;
int boardx;
int boardy;
int playeronecolor = 1;
int playertwocolor = 2;
int playerthreecolor = 3;
int playerfourcolor = 4;
int textcolor = 0;
int backgroundcolor = 7;
int computercolor = 2;
int currentplayer = 1;
int lastmove = 0;
int seclastmove = 1;
int gseed = 0;
int moves = 0;
int wins = 0;
int ties = 0;
int loses = 0;
int games = 0;

void makecolor(WINDOW* gameboard, int playercolor, int backgroundcolor){
  start_color();
  switch(backgroundcolor){
    case 0:
    switch(playercolor){
      case 0:
        init_pair(0,COLOR_BLACK,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(0));
        break;
      case 1:
        init_pair(1,COLOR_RED,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(1));
        break;
      case 2:
        init_pair(2,COLOR_GREEN,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(2));
        break;
      case 3:
        init_pair(3,COLOR_YELLOW,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(3));
        break;
      case 4:
        init_pair(4,COLOR_BLUE,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(4));
        break;
      case 5:
        init_pair(5,COLOR_MAGENTA,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(5));
        break;
      case 6:
        init_pair(6,COLOR_CYAN,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(6));
        break;
      case 7:
        init_pair(7,COLOR_WHITE,COLOR_BLACK); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(7));
        break;
    }
    break;
    case 1:
    switch(playercolor){
      case 0:
        init_pair(10,COLOR_BLACK,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(10));
        break;
      case 1:
        init_pair(11,COLOR_RED,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(11));
        break;
      case 2:
        init_pair(12,COLOR_GREEN,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(12));
        break;
      case 3:
        init_pair(13,COLOR_YELLOW,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(13));
        break;
      case 4:
        init_pair(14,COLOR_BLUE,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(14));
        break;
      case 5:
        init_pair(15,COLOR_MAGENTA,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(15));
        break;
      case 6:
        init_pair(16,COLOR_CYAN,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(16));
        break;
      case 7:
        init_pair(17,COLOR_WHITE,COLOR_RED); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(17));
        break;
    }
    break;
    case 2:
    switch(playercolor){
      case 0:
        init_pair(20,COLOR_BLACK,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(20));
        break;
      case 1:
        init_pair(21,COLOR_RED,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(21));
        break;
      case 2:
        init_pair(22,COLOR_GREEN,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(22));
        break;
      case 3:
        init_pair(23,COLOR_YELLOW,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(23));
        break;
      case 4:
        init_pair(24,COLOR_BLUE,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(24));
        break;
      case 5:
        init_pair(25,COLOR_MAGENTA,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(25));
        break;
      case 6:
        init_pair(26,COLOR_CYAN,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(26));
        break;
      case 7:
        init_pair(27,COLOR_WHITE,COLOR_GREEN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(27));
        break;
    }
    break;
    case 3:
    switch(playercolor){
      case 0:
        init_pair(30,COLOR_BLACK,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(30));
        break;
      case 1:
        init_pair(31,COLOR_RED,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(31));
        break;
      case 2:
        init_pair(32,COLOR_GREEN,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(32));
        break;
      case 3:
        init_pair(33,COLOR_YELLOW,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(33));
        break;
      case 4:
        init_pair(34,COLOR_BLUE,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(34));
        break;
      case 5:
        init_pair(35,COLOR_MAGENTA,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(35));
        break;
      case 6:
        init_pair(36,COLOR_CYAN,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(36));
        break;
      case 7:
        init_pair(37,COLOR_WHITE,COLOR_YELLOW); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(37));
        break;
    }
    break;
    case 4:
    switch(playercolor){
      case 0:
        init_pair(40,COLOR_BLACK,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(40));
        break;
      case 1:
        init_pair(41,COLOR_RED,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(41));
        break;
      case 2:
        init_pair(42,COLOR_GREEN,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(42));
        break;
      case 3:
        init_pair(43,COLOR_YELLOW,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(43));
        break;
      case 4:
        init_pair(44,COLOR_BLUE,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(44));
        break;
      case 5:
        init_pair(45,COLOR_MAGENTA,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(45));
        break;
      case 6:
        init_pair(46,COLOR_CYAN,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(46));
        break;
      case 7:
        init_pair(47,COLOR_WHITE,COLOR_BLUE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(47));
        break;
    }
    break;
    case 5:
    switch(playercolor){
      case 0:
        init_pair(50,COLOR_BLACK,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(50));
        break;
      case 1:
        init_pair(51,COLOR_RED,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(51));
        break;
      case 2:
        init_pair(52,COLOR_GREEN,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(52));
        break;
      case 3:
        init_pair(53,COLOR_YELLOW,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(53));
        break;
      case 4:
        init_pair(54,COLOR_BLUE,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(54));
        break;
      case 5:
        init_pair(55,COLOR_MAGENTA,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(55));
        break;
      case 6:
        init_pair(56,COLOR_CYAN,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(56));
        break;
      case 7:
        init_pair(57,COLOR_WHITE,COLOR_MAGENTA); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(57));
        break;
    }
    break;
    case 6:
    switch(playercolor){
      case 0:
        init_pair(60,COLOR_BLACK,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(60));
        break;
      case 1:
        init_pair(61,COLOR_RED,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(61));
        break;
      case 2:
        init_pair(62,COLOR_GREEN,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(62));
        break;
      case 3:
        init_pair(63,COLOR_YELLOW,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(63));
        break;
      case 4:
        init_pair(64,COLOR_BLUE,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(64));
        break;
      case 5:
        init_pair(65,COLOR_MAGENTA,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(65));
        break;
      case 6:
        init_pair(66,COLOR_CYAN,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(66));
        break;
      case 7:
        init_pair(67,COLOR_WHITE,COLOR_CYAN); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(67));
        break;
    }
    break;
    case 7:
    switch(playercolor){
      case 0:
        init_pair(70,COLOR_BLACK,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(70));
        break;
      case 1:
        init_pair(71,COLOR_RED,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(71));
        break;
      case 2:
        init_pair(72,COLOR_GREEN,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(72));
        break;
      case 3:
        init_pair(73,COLOR_YELLOW,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(73));
        break;
      case 4:
        init_pair(74,COLOR_BLUE,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(74));
        break;
      case 5:
        init_pair(75,COLOR_MAGENTA,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(75));
        break;
      case 6:
        init_pair(76,COLOR_CYAN,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(76));
        break;
      case 7:
        init_pair(77,COLOR_WHITE,COLOR_WHITE); // colors the ncurses terminal
        wattron(gameboard, COLOR_PAIR(77));
        break;
    }
    break;
  }
}

void breakcolor(WINDOW* gameboard, int playercolor, int backgroundcolor){
  switch(backgroundcolor){
    case 0:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(0));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(1));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(2));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(3));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(4));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(5));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(6));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(7));
        break;
    }
    break;
    case 1:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(10));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(11));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(12));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(13));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(14));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(15));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(16));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(17));
        break;
    }
    break;
    case 2:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(20));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(21));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(22));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(23));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(24));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(25));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(26));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(27));
        break;
    }
    break;
    case 3:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(30));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(31));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(32));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(33));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(34));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(35));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(36));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(37));
        break;
    }
    break;
    case 4:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(40));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(41));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(42));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(43));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(44));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(45));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(46));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(47));
        break;
    }
    break;
    case 5:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(50));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(51));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(52));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(53));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(54));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(55));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(56));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(57));
        break;
    }
    break;
    case 6:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(60));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(61));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(62));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(63));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(64));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(65));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(66));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(67));
        break;
    }
    break;
    case 7:
    switch(playercolor){
      case 0:
        wattroff(gameboard, COLOR_PAIR(70));
        break;
      case 1:
        wattroff(gameboard, COLOR_PAIR(71));
        break;
      case 2:
        wattroff(gameboard, COLOR_PAIR(72));
        break;
      case 3:
        wattroff(gameboard, COLOR_PAIR(73));
        break;
      case 4:
        wattroff(gameboard, COLOR_PAIR(74));
        break;
      case 5:
        wattroff(gameboard, COLOR_PAIR(75));
        break;
      case 6:
        wattroff(gameboard, COLOR_PAIR(76));
        break;
      case 7:
        wattroff(gameboard, COLOR_PAIR(77));
        break;
    }
    break;
  }
  wrefresh(gameboard);
}

int **makeTracker(int boardheight, int boardwidth){
  int **track;
    track = malloc(sizeof(int*) * boardheight);
  for(int i = 0; i < boardheight; i++) {
        track[i] = malloc(sizeof(int*) * boardwidth);
  }
  for(int i = 0; i < boardheight; i++){
    for(int j = 0; j < boardwidth; j++){
      track[i][j] = 0;
    }
  }
  return track;
}

void killTracker(int** tracker){
  for(int i = 0; i < boardheight; i++) {
        free(tracker[i]);
  }
  free(tracker);
}

int** updateTracker(int** tracker, int x, int who){
  int move = 0;
  int **track = makeTracker(boardheight,boardwidth);
  for(int i = 0; i < boardheight; i++){
    for(int j = 0; j < boardwidth; j++){
      track[i][j] = tracker[i][j];
    }
  }
  for(int i = 0; i < boardheight; i++){
    if(track[0][x] == 0){
      track[0][x] = who;
      move = 1;
    }
    else if(track[i][x] == 0 && (track[i-1][x] == 1 || track[i-1][x] == 2 || track[i-1][x] == 3 || track[i-1][x] == 4) && move == 0){
      track[i][x] = who;
      move = 1;
    }
  }
  return track;
}

void wBlankScreen(WINDOW * win, int y, int x){
  makecolor(win,textcolor,backgroundcolor);
  for(int i = 0; i <= y; i++){
    for(int j = 0; j <= x; j++){
      wprintw(win," ");
    }
  }
  mvwprintw(win,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(win,y-2,x/2 - 11,"Press Enter to Select");
  wrefresh(win);
}

void wBackground(WINDOW *win,  int y, int x ){
  wBlankScreen(win, y, x);
  int b = '*';
  wborder(win,b,b,b,b,b,b,b,b);
}
int openStartMenu(){
  curs_set(0);
  int x,y;
  WINDOW *tui = newwin(0,0,0,0);
  getmaxyx(tui,y,x);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,y,x);
  wrefresh(tui);
  wclear(tui);
  wBackground(tui,y,x);
  char selections[2][20];
  strcpy(selections[0], "Enter");
  strcpy(selections[1], "Exit");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,y-2,x/2 - 11,"Press Enter to Select");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(true){
    for(int q = 0; q < 2; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 2){
          option = 1;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  //killWords(selections,2);
  delwin(tui);
  return option;
}

void openUI(){
  curs_set(0);
  int x,y;
  WINDOW *tui = newwin(0,0,0,0);
  getmaxyx(tui,y,x);
  gy = y;
  gx = x;
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,y,x);
  wrefresh(tui);

  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Hello World!");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Welcome to Mader Connect Four");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Here you can play Connect Four");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"You can customize the rules and settings");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Or play the traditional game");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"You can play against friends");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"or against me");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  mvwprintw(tui,y-2,x/2 - 11,"Press Enter to Select");
  wrefresh(tui);
  delwin(tui);
}

void startProgram(){
  initscr(); // ncurses constructor function
  cbreak();
  noecho();
  refresh();
  openUI();
}

int openUserMenu(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  noecho();
  getmaxyx(menu,y,x);
  start_color();
  init_pair(2,COLOR_BLACK,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  char selections[2][20];
  strcpy(selections[0], "New User");
  strcpy(selections[1], "Existing User");
  int option = 0;
  wBackground(menu,y,x);
  mvwprintw(menu,1,x/2 - 11,"Mader Connect Four User Menu");
  mvwprintw(menu,y-3,x/2 - 11,"Press Arrow keys to Navigate");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Select");
  wmove(menu,y/2,x/2 - 11);
  int choice;
  while(true){
    for(int q = 0; q < 2; q++){
      if(q == option){
        wattron(menu, A_BLINK);
      }
      mvwprintw(menu,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(menu, A_BLINK);
    }
    choice = wgetch(menu);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 2){
          option = 1;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  wrefresh(menu);
  wattroff(menu, COLOR_PAIR(1));
  delwin(menu);
  return option;
}

void openMenu(int selection){
  int y, x;
  char yourName[100];
  WINDOW *info = newwin(0,0,0,0);
  getmaxyx(info,y,x);
  delwin(info);
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  noecho();
  getmaxyx(menu,y,x);
  start_color();
  init_pair(2,COLOR_BLACK,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  wBackground(menu,y,x);
  if(selection ==  0){
    echo();
    wrefresh(menu);
    mvwprintw(menu,1,x/2 - 11,"Mader Connect Four User Menu");
    mvwprintw(menu,y-3,x/2 - 11,"If you click enter without a username, cool stuff happens!");
    mvwprintw(menu,y-4,x/2 - 11,"No Spaces!");
    mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
    mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Your Username:");
    wattron(menu, A_BLINK | COLOR_PAIR(2));
    wscanw(menu,"%s", yourName);
    wattroff(menu, A_BLINK);
    mvwprintw(menu,y/2 + 1,x/2 - 11,"User %s has been Created!", yourName);
    user = fopen("USERS.txt", "a");
    fprintf(user, "%s ", yourName);
    fclose(user);
    wrefresh(menu);
    strcpy(who, yourName);
  }
  if(selection == 1){
    mvwprintw(menu,1,x/2 - 11,"Mader Connect Four User Menu");
    mvwprintw(menu,y-3,x/2 - 11,"Press Arrow keys to Navigate");
    mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Select");
    wmove(menu,y/2,x/2 - 11);
    wrefresh(menu);
    int current = 0;
    int choice;
    char dummy[100];
    char str[100];
    user = fopen("USERS.txt", "r");
    if (!user) {
      noecho();
      wprintw(menu, "No Users Exist!");
      mvwprintw(menu,y-3,x/2 - 11,"                              ");
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      strcpy(who,"ERROR");
      getch();
      return;
    }
    fclose(user);
    user = fopen("USERS.txt", "r");
    while(!feof(user)){
      fscanf(user, "%s ", dummy);
      current++;
    }
    fclose(user);
    char users[current][100];
    user = fopen("USERS.txt", "r");
    for(int i = 0; i < current; i++){
      fscanf(user,"%s", str);
      strcpy(users[i], str);
    }
    fclose(user);
    wrefresh(menu);
    int option = 0;
    while(true){
      for(int q = 0; q < current; q++){
        if(q == option){
          wattron(menu, A_BLINK);
        }
        mvwprintw(menu,y/2 + q,x/2 - 11, "%s", users[q]);
        wattroff(menu, A_BLINK);
      }
      choice = wgetch(menu);
      switch(choice){
        case KEY_UP:
          option--;
          if(option == -1){
            option = 0;
          }
          break;
        case KEY_DOWN:
          option++;
          if(option == current){
            option = current - 1;
          }
          break;
        default:
          break;
      }
      if(choice == 10){
        strcpy(who, users[option]);
        break;
      }
    }
  }
  wrefresh(menu);
  wattroff(menu, COLOR_PAIR(2));
  delwin(menu);
}

void userWelcome(char* user){
  int y = gy;
  int x = gx;
  char yourName[100];
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  noecho();
  getmaxyx(menu,y,x);
  start_color();
  init_pair(2,COLOR_BLACK,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  wBackground(menu,y,x);
  mvwprintw(menu,1,x/2 - 11,"Mader Connect Four User Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Welcome %s", user);
  wrefresh(menu);
  getch();
  wclear(menu);
  delwin(menu);
  wrefresh(menu);
}

int mainMenu(){
  int x,y;
  WINDOW *tui = newwin(0,0,0,0);
  getmaxyx(tui,y,x);
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  wrefresh(tui);
  wclear(tui);
  wBackground(tui,y,x);
  char selections[5][20];
  strcpy(selections[0], "One Player");
  strcpy(selections[1], "Two Player");
  strcpy(selections[2], "Party Mode");
  strcpy(selections[3], "Options");
  strcpy(selections[4], "Exit");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,y-2,x/2 - 11,"Press Enter to Select");
  mvwprintw(tui,y-3,x/2 - 11,"Press Arrow keys to Navigate");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,2,1,"User: %s", who);
  mvwprintw(tui,3,1,"Wins: %d Ties: %d Loses: %d Games: %d", wins, ties, loses, games);
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(true){
    for(int q = 0; q < 5; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 5){
          option = 4;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  wrefresh(tui);
  delwin(tui);
  return option;
}



int difficulty(WINDOW *tui, int y, int x){
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  wrefresh(tui);
  char selections[4][20];
  strcpy(selections[0], "Easy");
  strcpy(selections[1], "Medium");
  strcpy(selections[2], "Hard");
  strcpy(selections[3], "Exit");
  mvwprintw(tui,y/2,x/2 - 11,"                        ");
  mvwprintw(tui,2,x/2 - 11,"Single Player Mode");
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(true){
    for(int q = 0; q < 4; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 4){
          option = 3;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  wrefresh(tui);
  breakcolor(tui,textcolor,backgroundcolor);
  if(option == 3){
    option = 7;
  }
  return option;
}

int modewindow(int act){
  noecho();
  int y = gy;
  int x = gx;
  int mode = 0;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  makecolor(menu,textcolor,backgroundcolor);
  wBackground(menu,y,x);
  switch(act){
    case 0:
      mvwprintw(menu,y/2,x/2 - 11,"Single Player Mode");
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      getch();
      mode = difficulty(menu, y, x);
      break;
    case 1:
      mvwprintw(menu,y/2,x/2 - 11,"Two Player Mode");
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      getch();
      mode = 3;
      break;
    case 2:
      mvwprintw(menu,y/2,x/2 - 11,"Party Mode");
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      getch();
      mode = 4;
      break;
    case 3:
      mvwprintw(menu,y/2,x/2 - 11,"Options Mode");
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      getch();
      mode = 5;
      break;
    case 4:
      mvwprintw(menu,y/2,x/2 - 11,"Goodbye %s", who);
      mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
      wrefresh(menu);
      getch();
      mode = 6;
      break;
  }
  wrefresh(menu);
  delwin(menu);
  return mode;
}



WINDOW* makegameboard(){
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2+y/4,x/2+x/4,5,5);
  getmaxyx(tui,y,x);
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  // This section initializes the gameboard to blank spots, represented by 0.
  for(int i = 0; i < boardheight; i++){
    for(int j = 0; j < boardwidth; j++){
        mvwprintw(tui,y/2 - y/4 + 2*i, x/2 - x/4 + 5*j, "X");
      }
    }
    wrefresh(tui);
  boardx = x;
  boardy = y;
  return tui;
}

int findBest(int** tracker, int who){
  int maxwinner = 0;
  int winner = 0;
  int counth = 0;
  int countv = 0;
  int countd = 0;
  for(int i = 0; i < boardheight - boardwinsize + 1; i++){//bottom left sweep
    for(int j = 0; j  < boardwidth - boardwinsize + 1; j++){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j+y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == y+1){
          winner = j;
        }
        if(tracker[i+y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == y+1){
          winner = j;
        }
        if(tracker[i+y][j+y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == y+1){
          winner = j;
        }
        maxwinner = winner;
      }
    }
  }
  for(int i = 0; i < boardheight - boardwinsize + 1; i++){//bottom right sweep
    for(int j = boardwidth - 1; j  > boardwinsize - 2; j--){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j-y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == y+1){
          winner = j;
        }
        if(tracker[i+y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == y+1){
          winner = j;
        }
        if(tracker[i+y][j-y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == y+1){
          winner = j;
        }
        if(winner > maxwinner){
          maxwinner = winner;
        }
      }
    }
  }
  for(int i = boardheight - 1; i > boardwinsize - 2; i--){//top left sweep
    for(int j = 0; j  < boardwidth - boardwinsize + 1; j++){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j+y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == y+1){
          winner = j;
        }
        if(tracker[i-y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == y+1){
          winner = j;
        }
        if(tracker[i-y][j+y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == y+1){
          winner = j;
        }
        if(winner > maxwinner){
          maxwinner = winner;
        }
      }
    }
  }
  for(int i = boardheight - 1; i > boardwinsize - 2; i--){//top right sweep
    for(int j = boardwidth - 1; j  > boardwinsize - 2; j--){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j-y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == y+1){
          winner = j;
        }
        if(tracker[i-y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == y+1){
          winner = j;
        }
        if(tracker[i-y][j-y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == y+1){
          winner = j;
        }
        if(winner > maxwinner){
          maxwinner = winner;
        }
      }
    }
  }
}

int wincheck(int** tracker, int who){ // check the graph for wins
  int winner = 0;
  int counth = 0;
  int countv = 0;
  int countd = 0;
  for(int i = 0; i < boardheight - boardwinsize + 1; i++){//bottom left sweep
    for(int j = 0; j  < boardwidth - boardwinsize + 1; j++){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j+y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == boardwinsize){
          winner = who;
        }
        if(tracker[i+y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == boardwinsize){
          winner = who;
        }
        if(tracker[i+y][j+y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == boardwinsize){
          winner = who;
        }
      }
    }
  }
  for(int i = 0; i < boardheight - boardwinsize + 1; i++){//bottom right sweep
    for(int j = boardwidth - 1; j  > boardwinsize - 2; j--){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j-y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == boardwinsize){
          winner = who;
        }
        if(tracker[i+y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == boardwinsize){
          winner = who;
        }
        if(tracker[i+y][j-y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == boardwinsize){
          winner = who;
        }
      }
    }
  }
  for(int i = boardheight - 1; i > boardwinsize - 2; i--){//top left sweep
    for(int j = 0; j  < boardwidth - boardwinsize + 1; j++){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j+y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == boardwinsize){
          winner = who;
        }
        if(tracker[i-y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == boardwinsize){
          winner = who;
        }
        if(tracker[i-y][j+y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == boardwinsize){
          winner = who;
        }
      }
    }
  }
  for(int i = boardheight - 1; i > boardwinsize - 2; i--){//top right sweep
    for(int j = boardwidth - 1; j  > boardwinsize - 2; j--){
      counth = 0;
      countv = 0;
      countd = 0;
      for(int y = 0; y < boardwinsize; y++){
        if(tracker[i][j-y] == who){ // checking for horizontal wins
          counth++;
        }
        if(counth == boardwinsize){
          winner = who;
        }
        if(tracker[i-y][j] == who){ // checking for vertical wins
          countv++;
        }
        if(countv == boardwinsize){
          winner = who;
        }
        if(tracker[i-y][j-y] == who){ // checking for diagonal wins
          countd++;
        }
        if(countd == boardwinsize){
          winner = who;
        }
      }
    }
  }
  int tie = 0;
  for(int i = 0; i < boardwidth; i++){
    if(tracker[boardheight-1][i] != 0){
      tie++;
    }
    if(tie == boardwidth){
      winner = 5;
    }
  }
  return winner;
}

int **playermove(WINDOW* tui, int** track){
  int y = boardy;
  int x = boardx;
  int option = 0;
  int choice;
  makecolor(tui,textcolor,backgroundcolor);
  keypad(tui, true);
  while(true){
    for(int q = 0; q < boardwidth; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 - y/4 + 2*boardheight, x/2 - x/4 + 5*q, "*");
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_LEFT:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_RIGHT:
        option++;
        if(option == boardwidth){
          option = boardwidth - 1;
        }
        break;
      default:
        break;
    }
    if(choice == 10 && track[boardheight-1][option] == 0){
      break;
    }
  }
  breakcolor(tui,textcolor,backgroundcolor);
  int **tracker = updateTracker(track, option, currentplayer);
  int moveheight = 1;
  for(int i = 0;i < boardheight; i++){
    if(tracker[i][option] == 1 || tracker[i][option] == 2 || tracker[i][option] == 3 || tracker[i][option] == 4){
      moveheight++;
    }
  }
  switch(currentplayer){
    case 1:
      makecolor(tui, playeronecolor, backgroundcolor);
      break;
    case 2:
      makecolor(tui, playertwocolor, backgroundcolor);
      break;
    case 3:
      makecolor(tui, playerthreecolor, backgroundcolor);
      break;
    case 4:
      makecolor(tui, playerfourcolor, backgroundcolor);
      break;
  }
  mvwprintw(tui,y/2 - y/4 + 2*boardheight - 2*moveheight + 2, x/2 - x/4 + 5*option, "O");
  switch(currentplayer){
    case 1:
      breakcolor(tui, playeronecolor, backgroundcolor);
      break;
    case 2:
      breakcolor(tui, playertwocolor, backgroundcolor);
      break;
    case 3:
      breakcolor(tui, playerthreecolor, backgroundcolor);
      break;
    case 4:
      breakcolor(tui, playerfourcolor, backgroundcolor);
      break;
  }
  moves++;
  seclastmove = lastmove;
  lastmove = option;
  return tracker;
}

void assignboardheight(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  makecolor(menu,textcolor,backgroundcolor);
  wBackground(menu,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-4,x/2 - 11,"Your Recommended Height is %d or less", gy/5);
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Height (6)");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Board Height:");
  wattron(menu, A_BLINK);
  int height = 6;
  wscanw(menu,"%d", &height);
  if(height < boardwinsize || height < 2){
    height = 6;
  }
  boardheight = height;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Board Height has been set to %d", boardheight);
  wrefresh(menu);
  delwin(menu);
}

void assignboardwidth(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  makecolor(menu,textcolor,backgroundcolor);
  wBackground(menu,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-4,x/2 - 11,"Your Recommended Width is %d or less", gx/9);
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Width (7)");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Board Width:");
  wattron(menu, A_BLINK);
  int width = 7;
  wscanw(menu,"%d", &width);
  if(width < boardwinsize || width < 2){
    width = 7;
  }
  boardwidth = width;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Board Width has been set to %d", boardwidth);
  wrefresh(menu);
  delwin(menu);
}

void assignwinsize(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  makecolor(menu,textcolor,backgroundcolor);
  wBackground(menu,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Win Size");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Win Size:");
  wattron(menu, A_BLINK);
  int winsize = 4;
  wscanw(menu,"%d", &winsize);
  if((winsize > boardheight && winsize > boardwidth) || winsize < 3){
    winsize = 4;
  }
  boardwinsize = winsize;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Win Size has been set to %d", boardwinsize);
  wrefresh(menu);
  delwin(menu);
}

void assigncolor(int player){
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(tui,y,x);
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  char selections[8][20];
  strcpy(selections[0], "Black");
  strcpy(selections[1], "Red");
  strcpy(selections[2], "Green");
  strcpy(selections[3], "Yellow");
  strcpy(selections[4], "Blue");
  strcpy(selections[5], "Magneta");
  strcpy(selections[6], "Cyan");
  strcpy(selections[7], "White");
  mvwprintw(tui,2,x/2 - 11,"Options Menu");
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(true){
    for(int q = 0; q < 8; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 8){
          option = 7;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  switch(player){
    case 1:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 1's Color has been set to %s", selections[option]);
      playeronecolor = option;
      break;
    case 2:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 2's Color has been set to %s", selections[option]);
      playertwocolor = option;
      break;
    case 3:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 3's Color has been set to %s", selections[option]);
      playerthreecolor = option;
      break;
    case 4:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 4's Color has been set to %s", selections[option]);
      playerfourcolor = option;
      break;
    case 5:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Computers's Color has been set to %s", selections[option]);
      computercolor = option;
      break;
    case 6:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Text Color has been set to %s", selections[option]);
      textcolor = option;
      break;
    case 7:
      wclear(tui);
      wBackground(tui,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Background Color has been set to %s", selections[option]);
      backgroundcolor = option;
      break;
}
wrefresh(tui);
delwin(tui);
}

void optionsMenu(){
  noecho();
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(tui,y,x);
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  char selections[11][20];
  strcpy(selections[0], "Board Height");
  strcpy(selections[1], "Board Width");
  strcpy(selections[2], "Player 1 Color");
  strcpy(selections[3], "Player 2 Color");
  strcpy(selections[4], "Player 3 Color");
  strcpy(selections[5], "Player 4 Color");
  strcpy(selections[6], "Computer Color");
  strcpy(selections[7], "Text Color");
  strcpy(selections[8], "Background Color");
  strcpy(selections[9], "Win Size");
  strcpy(selections[10], "Exit");
  mvwprintw(tui,2,x/2 - 11,"Options Menu");
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(option != 10){
    makecolor(tui,textcolor,backgroundcolor);
    mvwprintw(tui,2,x/2 - 11,"Options Menu");
    wBackground(tui,y,x);
    noecho();
    mvwprintw(tui,y-2,x/2 - 11,"Press Enter to Select      ");
  while(true){
    for(int q = 0; q < 11; q++){
      if(q == option){
        wattron(tui, A_BLINK);
      }
      mvwprintw(tui,y/2 + q + 1,x/2 - 11, selections[q]);
      wattroff(tui, A_BLINK);
    }
    choice = wgetch(tui);
    switch(choice){
      case KEY_UP:
        option--;
        if(option == -1){
          option = 0;
        }
        break;
      case KEY_DOWN:
        option++;
        if(option == 11){
          option = 10;
        }
        break;
      default:
        break;
    }
    if(choice == 10){
      break;
    }
  }
  switch(option){
    case 0:
      assignboardheight();
      getch();
      break;
    case 1:
      assignboardwidth();
      getch();
      break;
    case 2:
      assigncolor(1);
      getch();
      break;
    case 3:
      assigncolor(2);
      getch();
      break;
    case 4:
      assigncolor(3);
      getch();
      break;
    case 5:
      assigncolor(4);
      getch();
      break;
    case 6:
      assigncolor(5);
      getch();
      break;
    case 7:
      assigncolor(6);
      getch();
      break;
    case 8:
      assigncolor(7);
      getch();
      break;
    case 9:
      assignwinsize();
      getch();
      break;
  //wrefresh(tui);
  //delwin(tui);
}
if (option != 10){
  for(int i = 0; i < x/2 - 3; i++){
    mvwprintw(tui,y/2 + 1,x/2 - 11 + i," ");
  }
}
}
wrefresh(tui);
delwin(tui);
}

int **easymove(WINDOW* tui, int** track){ // randomly makes a move
  int y = boardy;
  int x = boardx;
  makecolor(tui,computercolor,backgroundcolor);
  srand(gseed+lastmove*gy);
  int option = rand()%boardwidth;
  gseed = gseed+1*2+option;
  while(track[boardheight-1][option] != 0){
    option = option%2;
    if(option == 1){
      option = option + findBest(track,2);
    }
    if(option == 0){
      option = (findBest(track,2) + lastmove)%boardwidth;
    }
  }
  int moveheight = 1;
  for(int i = 0;i < boardheight - 1; i++){
    if(track[i][option] == 1 || track[i][option] == 2){
      moveheight++;
    }
  }
  mvwprintw(tui,y/2 - y/4 + 2*boardheight - 2*moveheight, x/2 - x/4 + 5*option, "O");
  breakcolor(tui,computercolor,backgroundcolor);
  wrefresh(tui);
  int **tracker = updateTracker(track, option, 2);
  moves++;
  seclastmove = lastmove;
  lastmove = option;
  return tracker;
}

int **hardmove(WINDOW* tui, int** track){ // computer calculates best move by determining which open spot has the most pieces in a row
  int y = boardy;
  int x = boardx;
  int bestmove = 0;
  int option = lastmove;
  makecolor(tui,computercolor,backgroundcolor);
  option = findBest(track, 2);
  while(track[boardheight-1][option] != 0 || option == seclastmove){
    option = rand()%boardwidth;
  }
  int moveheight = 1;
  for(int i = 0;i < boardheight - 1; i++){
    if(track[i][option] == 1 || track[i][option] == 2){
      moveheight++;
    }
  }
  mvwprintw(tui,y/2 - y/4 + 2*boardheight - 2*moveheight, x/2 - x/4 + 5*option, "O");
  breakcolor(tui,computercolor,backgroundcolor);
  wrefresh(tui);
  int **tracker = updateTracker(track, option, 2);
  moves++;
  seclastmove = lastmove;
  lastmove = option;
  return tracker;
}

int **mediummove(WINDOW* tui, int** track){ // randomly makes either an easy move or a hard move
  int y = boardy;
  int x = boardx;
  makecolor(tui,computercolor,backgroundcolor);
  int winner = 0;
  int **tracker;
  srand(gseed);
  int option = moves%2;
  switch(option){
    case 0:
      tracker = easymove(tui, track);
      break;
    case 1:
      tracker = hardmove(tui, track);
      break;
  }
  breakcolor(tui,computercolor,backgroundcolor);
  moves++;
  gseed = option;
  seclastmove = lastmove;
  lastmove = option;
  wrefresh(tui);
  return tracker;
}

int playgame(int mode){
  WINDOW *gameboard = makegameboard();
  wrefresh(gameboard);
  int **tracker = makeTracker(boardheight,boardwidth);
  int winner = 0;
  int **track;
  switch(mode){
    case 0://easy
      currentplayer = 1;
      track = playermove(gameboard, tracker);
      winner = wincheck(track, 1);
      while(winner != 1 && winner != 2){
        track = easymove(gameboard, track);
        winner = wincheck(track, 2);
        if (winner == 2 || winner == 5){
          break;
        }
        else{
          track = playermove(gameboard, track);
          winner = wincheck(track, 1);
        }
        if (winner == 1 || winner == 5){
          break;
        }
      }
      break;
    case 1://medium
      currentplayer = 1;
      track = playermove(gameboard, tracker);
      winner = wincheck(track, 1);
      while(winner != 1 && winner != 2){
        track = mediummove(gameboard, track);
        winner = wincheck(track, 2);
        if (winner == 2 || winner == 5){
          break;
        }
        else{
          track = playermove(gameboard, track);
          winner = wincheck(track, 1);
        }
        if (winner == 1 || winner == 5){
          break;
        }
      }
      break;
    case 2://hard
      currentplayer = 1;
      track = playermove(gameboard, tracker);
      winner = wincheck(track, 1);
      while(winner != 1 && winner != 2){
        track = hardmove(gameboard, track);
        winner = wincheck(track, 2);
        if (winner == 2 || winner == 5){
          break;
        }
        else{
          track = playermove(gameboard, track);
          winner = wincheck(track, 1);
        }
        if (winner == 1 || winner == 5){
          break;
        }
      }
      break;
    case 3:// 2 player
      currentplayer = 1;
      track = playermove(gameboard, tracker);
      while(winner != 1 && winner != 2){
        currentplayer = 2;
        track = playermove(gameboard, track);
        winner = wincheck(track, 2);
        if (winner == 2 || winner == 5){
          break;
        }
        currentplayer = 1;
        track = playermove(gameboard, track);
        winner = wincheck(track, 1);
        if (winner == 1 || winner == 5){
          break;
        }
      }//2 player
      break;
    case 4:
      currentplayer = 1;
      track = playermove(gameboard, tracker);
      while(winner != 1 && winner != 2 && winner != 3 && winner != 4){
        currentplayer = 2;
        track = playermove(gameboard, track);
        winner = wincheck(track, 2);
        if (winner == 2 || winner == 5){
          break;
        }
        currentplayer = 3;
        track = playermove(gameboard, track);
        winner = wincheck(track, 3);
        if (winner == 3 || winner == 5){
          break;
        }
        currentplayer = 4;
        track = playermove(gameboard, track);
        winner = wincheck(track, 4);
        if (winner == 4 || winner == 5){
          break;
        }
        currentplayer = 1;
        track = playermove(gameboard, track);
        winner = wincheck(track, 1);
        if (winner == 1 || winner == 5){
          break;
        }
      }//party mode
      break;
  }
  wrefresh(gameboard);
  delwin(gameboard);
  return winner;
}

void winnerscreen(int winner){
  int y = boardy;
  int x = boardx;
  games++;
  WINDOW *tui = newwin(gy-boardy,gx-boardx,boardy+1,boardx+1);
  getmaxyx(tui,y,x);
  makecolor(tui,textcolor,backgroundcolor);
  wBackground(tui,y,x);
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  switch(winner){
    case 1:
      mvwprintw(tui,y/2 + 1,x/2 - 11,"%s Won!", who);
      wins++;
      break;
    case 2:
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 2 / Computer Won!");
      loses++;
      break;
    case 3:
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 3 Won!");
      loses++;
      break;
    case 4:
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 4 Won!");
      loses++;
      break;
    case 5:
      mvwprintw(tui,y/2 + 1,x/2 - 11,"You Tied!");
      ties++;
      break;
  }
  wrefresh(tui);
  delwin(tui);
  getch();
}

int modeselector(int mode){
  int winner = 0;
  int endgame = 0;
  switch(mode){
    case 0:
      winner = playgame(0);//easy computer
      winnerscreen(winner);
      break;
    case 1:
      winner = playgame(1);// medium computer
      winnerscreen(winner);
      break;
    case 2:
      winner = playgame(2);//hard computer
      winnerscreen(winner);
      break;
    case 3:
      winner = playgame(3);//2 player
      winnerscreen(winner);
      break;
    case 4:
      winner = playgame(4);//party mode
      winnerscreen(winner);
      break;
    case 5:
      optionsMenu();
      break;
    case 6:
      endgame = 6;
  }
  return endgame;
}

int main(int argc, char const *argv[]) {
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  startProgram();
  int go = openStartMenu();
  if(go == 1){
    endwin();
    return 0;
  }
  int selection = openUserMenu();
  openMenu(selection);
  while(strcmp(who,"ERROR") == 0){
    refresh();
    selection = openUserMenu();
    openMenu(selection);
  }
  userWelcome(who);
  wBackground(stdscr, gy, gx);
  mvwprintw(stdscr,1,1,"Press Control C to Close This Application");
  mvwprintw(stdscr,2,1,"User: %s", who);
  refresh();
  int what = 0;
  while(what != 6){
      go = mainMenu();
      what = modewindow(go);
      go = modeselector(what);
  }
  endwin(); // ncurses destructor function
  return 0;
}
