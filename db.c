// Jacob Mader
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

FILE *user; // File Pointer
char who[100]; // global user variable
int gx; // global variable for max x of screen
int gy; // global variable for max y of screen

void wBlankScreen(WINDOW * win, int c, int y, int x){
  wattrset(win, COLOR_PAIR(c));
  for(int i = 0; i <= y; i++){
    for(int j = 0; j <= x; j++){
      wprintw(win," ");
    }
  }
  mvwprintw(win,1,x/2 - 11,"Mader Food Database");
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
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
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
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Welcome to the Mader Food Database");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Here you can search for food");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"and find information");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"such as calories, carbs, fats, and proteins");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"Search by name");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
  mvwprintw(tui,1,1,"Press Control C to Close This Application");
  mvwprintw(tui,y-2,x/2 - 11,"Press Any Key to Continue");
  wrefresh(tui);
  getch();

  wclear(tui);
  wBackground(tui,1,y,x);
  mvwprintw(tui,y/2,x/2 - 11,"and build your user diary");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
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
  mvwprintw(menu,1,x/2 - 11,"Mader Food Database User Menu");
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
    mvwprintw(menu,1,x/2 - 11,"Mader Food Database User Menu");
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
    mvwprintw(menu,1,x/2 - 11,"Mader Food Database User Menu");
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
  mvwprintw(menu,1,x/2 - 11,"Mader Food Database User Menu");
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
  strcpy(selections[0], "Create User Diary");
  strcpy(selections[1], "Retreive User Diary");
  strcpy(selections[2], "Update User Diary");
  strcpy(selections[3], "Delete User Diary");
  mvwprintw(tui,1,x/2 - 11,"Mader Food Database");
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
void action(int act){
  int y = gy;
  int x = gx;
  WINDOW *menu = newwin(y/2,x/2,y/2 - y/4,x/2 - x/4);
  getmaxyx(menu,y,x);
  start_color();
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  wBackground(menu,1,y,x);
  switch(act){
    case 0:
      mvwprintw(menu,2,x/2 - 11,"Create User Diary");
      create();
      break;
    case 1:
      mvwprintw(menu,2,x/2 - 11,"Retreive User Diary");
      retreive();
      break;
    case 2:
      mvwprintw(menu,2,x/2 - 11,"Update User Diary");
      update();
      break;
    case 3:
      mvwprintw(menu,2,x/2 - 11,"Delete User Diary");
      delete();
      break;
  }
  wrefresh(menu);
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
  action(go);



  getch();




  endwin(); // ncurses destructor function
  return 0;









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
}
