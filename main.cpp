#include "Equipment.h"
#include "Field.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"
#include "Player.h"
#include "Shop.h"

#include <ncurses.h>
#include <menu.h>
#include <iostream>

WINDOW *dispCreateField(Field field){

    WINDOW *windowField;

  int windowY = field.get_sizeM() + 2;
  int windowX = (3 * (field.get_sizeN())) + 4;

    windowField = newwin(windowY, windowX, (getmaxy(stdscr) - windowY) / 2, (getmaxx(stdscr) - windowX) / 2);

  refresh();

    box(windowField, 0, 0);

    mvwprintw(windowField, 0, 1, "Field");

  for (int i = 1; i < windowY - 1; i++) {
    for (int j = 1; j < windowX - 1; j++) {
      if (j % 3 == 0) {
        attron(COLOR_PAIR(1));
        mvwaddch(windowField, i, j, '=');
        attroff(COLOR_PAIR(1));
      } else {
        attron(COLOR_PAIR(2));
        mvwaddch(windowField, i, j, '.');
        attroff(COLOR_PAIR(2));
      }
    }
  }

  wrefresh(windowField);

  return windowField;
}

void dispFieldUpdate(WINDOW *window, Field field) {
  for (int i = 0; i < field.get_sizeM(); i++) {
    for (int j = 0; j < field.get_sizeN(); j++) {
      if (field.get_plant(i, j) != 0) {
        mvwaddch(window, i + 1, (j + 1) * 3, '#');
      } else {
        mvwaddch(window, i + 1, (j + 1) * 3, '=');
      }
    }
  }

  wrefresh(window);
}

int main() {
  std::cout << has_colors() << std::endl;

    initscr();
    noecho();
    keypad(stdscr, true);
    start_color();

    // Defining colours //
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);

    bool gameRunning = true;

    while (gameRunning == true){

        Field field(5, 6);
        WINDOW *window;

        window = dispCreateField(field);

        getch();

        Grain grain(2, "Wheat", 5, 10, 2);

        field.set_plant(&grain, 1, 1);

        dispFieldUpdate(window, field);

        getch();

        gameRunning = false;
    }

    endwin();
    return 0;
}