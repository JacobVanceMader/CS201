// Jacob Mader
#include <stdio.h>
#include <string.h>
#include <curses.h>

FILE *user; // File Pointer
char who[100]; // global user variable
int gx; // global variable for max x of screen
int gy; // global variable for max y of screen
int boardheight;
int boardwidth;
int boardx;
int boardy;
int playeronecolor;
int playertwocolor;
int playerthreecolor;
int playerfourcolor;
int computercolor;
int currentplayer;

void wBlankScreen(WINDOW * win, int c, int y, int x){
  wattrset(win, COLOR_PAIR(c));
  for(int i = 0; i <= y; i++){
    for(int j = 0; j <= x; j++){
      wprintw(win," ");
    }
  }
  mvwprintw(win,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(win,y-2,x/2 - 11,"Press Enter to Select");
  wrefresh(win);
}

void wBackground(WINDOW *win, int c, int y, int x ){
  wBlankScreen(win, c, y, x);
  int b = '*';
  wborder(win,b,b,b,b,b,b,b,b);
}
int openStartMenu(){
  int x,y;
  WINDOW *tui = newwin(0,0,0,0);
  getmaxyx(tui,y,x);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,1,y,x);
  wrefresh(tui);
  wclear(tui);
  wBackground(tui,1,y,x);
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
  return option;

}

void openUI(){
  int x,y;
  WINDOW *tui = newwin(0,0,0,0);
  getmaxyx(tui,y,x);
  gy = y;
  gx = x;
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,1,y,x);
  wrefresh(tui);

  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Hello World!");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Welcome to Mader Connect Four");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Here you can play Connect Four");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"You can customize the rules");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Or play the traditional game");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"You can play against friends");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
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
  int x, y;
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
  init_pair(2,COLOR_BLUE,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  char selections[2][14];
  strcpy(selections[0], "New User");
  strcpy(selections[1], "Existing User");
  int option = 0;
  wBackground(menu,2,y,x);
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
  init_pair(2,COLOR_BLUE,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  wBackground(menu,2,y,x);
  if(selection ==  0){
    echo();
    wrefresh(menu);
    mvwprintw(menu,1,x/2 - 11,"Mader Connect Four User Menu");
    mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
    mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Your Name:");
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
      wprintw(menu, "No Users Exist!");
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
  init_pair(2,COLOR_BLUE,COLOR_WHITE); // colors the ncurses terminal
  wattron(menu, COLOR_PAIR(2));
  keypad(menu, true);
  wBackground(menu,2,y,x);
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
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,1,y,x);
  wrefresh(tui);
  wclear(tui);
  wBackground(tui,1,y,x);
  char selections[4][20];
  strcpy(selections[0], "One Player");
  strcpy(selections[1], "Two Player");
  strcpy(selections[2], "Party Mode");
  strcpy(selections[3], "Options");
  mvwprintw(tui,1,x/2 - 11,"Mader Connect Four");
  mvwprintw(tui,y-2,x/2 - 11,"Press Enter to Select");
  mvwprintw(tui,y-3,x/2 - 11,"Press Arrow keys to Navigate");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,2,1,"User: %s", who);
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
  delwin(tui);
  return option;
}



int difficulty(WINDOW *tui, int y, int x){
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,1,y,x);
  wrefresh(tui);
  wclear(tui);
  wBackground(tui,1,y,x);
  char selections[3][20];
  strcpy(selections[0], "Easy");
  strcpy(selections[1], "Medium");
  strcpy(selections[2], "Hard");
  mvwprintw(tui,2,x/2 - 11,"Single Player Mode");
  wrefresh(tui);
  keypad(tui, true);
  int option = 0;
  int choice;
  while(true){
    for(int q = 0; q < 3; q++){
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
        if(option == 3){
          option = 2;
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

void create(){
  char diary[100];
  strcpy(diary,who);
  user = fopen(strcat(diary,".txt"), "a");
  fprintf(user, "%s's User Diary\n", who);
  fclose(user);
}

void retreive(){
  user = fopen(strcat(who,".txt"), "a");
  fprintf(user, "Retrieved!\n");
  fclose(user);

}

void update(){
  user = fopen(strcat(who,".txt"), "a");
  fprintf(user, "Updated!\n");
  fclose(user);

}
void delete(){
  remove(strcat(who,".txt"));
}
int mode(int act){
  int y = gy;
  int x = gx;
  int mode;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(menu,1,y,x);
  switch(act){
    case 0:
      mode = difficulty(menu, y, x);
      create();
      break;
    case 1:
      mvwprintw(menu,2,x/2 - 11,"Two Player");
      mode = 3;
      retreive();
      break;
    case 2:
      mvwprintw(menu,2,x/2 - 11,"Party Mode");
      mode = 4;
      update();
      break;
    case 3:
      mvwprintw(menu,2,x/2 - 11,"Options");
      mode = 5;
      delete();
      break;
  }
  wrefresh(menu);
  return mode;
}



WINDOW* makegameboard(){
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(tui,y,x);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(tui,1,y,x);
  int track[boardheight][boardheight];

  // This section initializes the gameboard to blank spots, represented by 0.
  for(int i = 0; i < boardheight; i++){
    for(int j = 0; j < boardwidth; j++){
      track[i][j] = 0;
      if(track[i][j] == 0){
        mvwprintw(tui,y/2 - y/4 + 2*i, x/2 - x/4 + 5*j, "X");
      }
    }
    wrefresh(tui);
  }
  boardx = x;
  boardy = y;
  return tui;
}

void playermove(WINDOW* tui){
  int y = boardy;
  int x = boardx;
  int option = 0;
  int choice;
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
    if(choice == 10){
      break;
    }
  }
  /*for(int i = 0; i < boardheight; i++){
    if(track[i][option] == 0){
      track[i][option] == 1;
      break;
    }
  }*/
  mvwprintw(tui,y/2 - y/4 + 2*boardheight - 2, x/2 - x/4 + 5*option, "O");
  wrefresh(tui);
}

void assignboardheight(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_WHITE);
  wBackground(menu,1,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Height");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Board Height:");
  wattron(menu, A_BLINK | COLOR_PAIR(2));
  int height = 6;
  wscanw(menu,"%d", &height);
  boardheight = height;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,1,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Board Height has been set to %d", boardheight);
  wrefresh(menu);
}

void assignboardwidth(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_WHITE);
  wBackground(menu,1,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Width");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Board Width:");
  wattron(menu, A_BLINK | COLOR_PAIR(2));
  int width = 7;
  wscanw(menu,"%d", &width);
  boardwidth = width;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,1,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Board Width has been set to %d", boardwidth);
  wrefresh(menu);
}

void assignwinsize(){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_WHITE);
  wBackground(menu,1,y,x);
  echo();
  wrefresh(menu);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-3,x/2 - 11,"Blank or Invalid Entries will default to Standard Win Size");
  mvwprintw(menu,y-2,x/2 - 11,"Press Enter to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Enter Custom Win Size:");
  wattron(menu, A_BLINK | COLOR_PAIR(2));
  int winsize = 4;
  wscanw(menu,"%d", &winsize);
  if(winsize > boardheight && winsize > boardwidth){
    winsize = 4;
  }
  boardwinsize = winsize;
  wattroff(menu, A_BLINK);
  wclear(menu);
  wBackground(menu,1,y,x);
  mvwprintw(menu,2,x/2 - 11,"Options Menu");
  mvwprintw(menu,y-2,x/2 - 11,"Press Any Key to Continue");
  mvwprintw(menu,y/2 + 1,x/2 - 11,"Win Size has been set to %d", boardwidth);
  wrefresh(menu);
}

void assigncolor(int player){
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(tui,y,x);
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_WHITE);
  wBackground(tui,1,y,x);
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
      wBackground(tui,1,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 1's Color has been set to %s", selections[option]);
      playeronecolor = option;
      break;
    case 2:
      wclear(tui);
      wBackground(tui,1,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 2's Color has been set to %s", selections[option]);
      playertwocolor = option;
      break;
    case 3:
      wclear(tui);
      wBackground(tui,1,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 3's Color has been set to %s", selections[option]);
      playerthreecolor = option;
      break;
    case 4:
      wclear(tui);
      wBackground(tui,1,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Player 4's Color has been set to %s", selections[option]);
      playerfourcolor = option;
      break;
    case 5:
      wclear(tui);
      wBackground(tui,1,y,x);
      mvwprintw(tui,2,x/2 - 11,"Options Menu");
      mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
      mvwprintw(tui,y/2 + 1,x/2 - 11,"Computers's Color has been set to %s", selections[option]);
      computercolor = option;
      break;
}
wrefresh(tui);
}

void optionsMenu(){
  int y = gy;
  int x = gx;
  WINDOW *tui = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(tui,y,x);
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_WHITE);
  wBackground(tui,1,y,x);
  char selections[8][20];
  strcpy(selections[0], "Board Height");
  strcpy(selections[1], "Board Width");
  strcpy(selections[2], "Player 1 Color");
  strcpy(selections[3], "Player 2 Color");
  strcpy(selections[4], "Player 3 Color");
  strcpy(selections[5], "Player 4 Color");
  strcpy(selections[6], "Computer Color");
  strcpy(selections[7], "Win Size");
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
  switch(option){
    case 0:
      assignboardheight();
      break;
    case 1:
      assignboardwidth();
      break;
    case 2:
      assigncolor(1);
      break;
    case 3:
      assigncolor(2);
      break;
    case 4:
    assigncolor(3);
      break;
    case 5:
    assigncolor(4);
      break;
    case 6:
    assigncolor(5);
      break;
    case 7:
    assignwinsize();
  wrefresh(tui);
  delwin(tui);
}
}

void modeselector(int mode){
  switch(mode){
    case 0:
      playgame(1);
      break;
    case 1:
      playgame(2);
      break;
    case 2:
      playgame(3);
      break;
    case 3:
      playgame(4);
      break;
    case 4:
      playgame(5);
      break;
    case 5:
    optionsMenu();
      break;
  }
}

void playgame(int mode){
  switch(mode){
    case 0:
      WINDOW *gameboard = makegameboard();

      playermove(gameboard);
      break;
    case 1:
      playgame(2);
      break;
    case 2:
      playgame(3);
      break;
    case 3:
      playgame(4);
      break;
    case 4:
      playgame(5);
      break;
    case 5:
    optionsMenu();
      break;
  }

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
  wBackground(stdscr, 1, gy, gx);
  mvwprintw(stdscr,1,1,"Press Control C to Close This Application");
  mvwprintw(stdscr,2,1,"User: %s", who);
  refresh();
  go = mainMenu();
  modeselector(mode(go));
  boardwidth = 7;
  boardheight = 6;
  int track[boardheight][boardwidth];
  /*WINDOW *gameboard = makegameboard();
  playermove(gameboard);*/




  getch();




  endwin(); // ncurses destructor function
  return 0;
}









  /*
  char myName[30]; // Progranm Name
  char yourName[30]; // User Name
  char fileName[30]; // File Name
  FILE *user; // File Pointer
  char prevUser[30]; // Previous User Identifier

  // Name Program
  printf("Hello World!\n");
  printf("Have we met before? Y/N\n");
  scanf("%s", prevUser);
  if(strcmp(prevUser, "N") == 0){
    printf("What is my name?\n");
    scanf("%s", myName);
    printf("So my name is %s, thank you for telling me.\n", myName);
    // Name Program

    // Name User
    printf("What is your name?\n");
    scanf("%s", yourName);
    printf("Nice to meet you %s, I am %s\n", yourName, myName);
    // Name User

    // Create User File
    printf("Let's try to remember eachother, I'm going to make us a storage file. What do you want to call it?\n");
    scanf("%s", fileName);
    printf("%s, ok!\n", fileName);
    user = fopen(strcat(fileName, ".txt"), "w");
    fprintf(user, "%s %s %s", fileName, myName, yourName);
    fclose(user);
    printf("%s has been created!\n", fileName);
    // Create User File
  }
  else{
    printf("What was your file named?\n");
    scanf("%s", fileName);
    user = fopen(strcat(fileName, ".txt"), "r");
    fscanf(user,"%*s %s", myName);
    fscanf(user,"%s", yourName);
    fclose(user);
    printf("Good to see you again %s, its %s\n", yourName, myName);

  }



  printf("Do you want to play a game? Y/N or Q to quit.\n");
  char choice;
  scanf("%s", &choice);
  int path;

  if (choice == 'Y'){
    printf("Sounds cool, do you like Battleship? Y/N\n");
    path = 1;
  }
  else if (choice == 'N'){
    printf("Would you want to watch a movie? Y/N\n");
    path = 2;
  }
  else if (choice == 'Q'){
    printf("Goodbye %s\n", yourName);
  }
  else{
    while (choice != 'Y' && choice != 'N' && choice != 'Q'){
      printf("Y/N only, or Q to quit.\n");
      scanf("%s", &choice);
    }
    if (choice == 'Y'){printf("Sounds cool, do you like Battleship?\n");}
    if (choice == 'N'){printf("Would you want to watch a movie?\n");}
    if (choice == 'Q'){printf("Goodbye %s\n", yourName);}
  }
  if (path == 1){
    scanf("%s", &choice);
    if (choice == 'Y'){
      printf("Cool lets play!\n");
    }
    if (choice == 'N'){
      printf("Lets play a different game then, do you like Chess? Y/N\n");
    }
  }
  if (path == 2){
    scanf("%s", &choice);
    if (choice == 'Y'){
      printf("Cool, I love movies!\n");
    }
    if (choice == 'N'){
      printf("%s, you don't seem very fun, Goodbye\n", yourName);
    }
  }

  return 0;
  */
