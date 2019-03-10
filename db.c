// Jacob Mader
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
//int argc, char const *argv[]

int main() {
  initscr(); // ncurses constructor function
  cbreak();
  start_color();
  init_pair(1,COLOR_YELLOW,COLOR_BLACK); // colors the ncurses terminal
  attron(COLOR_PAIR(1));
  WINDOW *tui = newwin(10,10,0,0);
  init_pair(1,COLOR_YELLOW,COLOR_BLACK); // colors the ncurses terminal
  attron(COLOR_PAIR(1));
  noecho();
  getch();
  int c = '*';
  wborder(tui,c,c,c,c,c,c,c,c);
  wrefresh(tui);
  wprintw(tui,"Hello World \n");
  wrefresh(tui);
  getch();

  clear();
  wprintw(tui,"Refreshed");
  refresh();
  getch();

  clear();
  mvprintw(12,30,"Moved");
  refresh();
  getch();

  clear();
  noecho();
  attron(A_BLINK);
  for(int x = 100; x >= 0; x--){
    mvprintw(6,20,"%d   ", x);
    getch();
  }
  mvprintw(6,20,"Refreshed");
  attroff(A_BLINK);
  refresh();
  getch();

  getch();
  attroff(COLOR_PAIR(1));


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
