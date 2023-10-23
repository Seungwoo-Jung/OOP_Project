#include <menu.h>
#include <ncurses.h>

#include <iostream>

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

WINDOW *dispCreateField(Field &field){

    WINDOW *windowField;

    int windowY = field.get_sizeM() + 2;
    int windowX = (3 * (field.get_sizeN())) + 4;

    windowField = newwin(windowY, windowX, (getmaxy(stdscr) - windowY) / 2, (getmaxx(stdscr) / 2) - windowX);

    refresh();

    box(windowField, 0, 0);

    mvwprintw(windowField, 0, 1, "Field");

    for (int i = 1; i < windowY - 1; i++) {
        for (int j = 1; j < windowX - 1; j++) {
        if (j % 3 == 0) {
            // attron(COLOR_PAIR(1));
            mvwaddch(windowField, i, j, '=');
            // attroff(COLOR_PAIR(1));
        } else {
            // attron(COLOR_PAIR(2));
            mvwaddch(windowField, i, j, '.');
            // attroff(COLOR_PAIR(2));
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
    initscr();
    noecho();
    keypad(stdscr, true);
    // start_color();

    // Defining colours //
    // init_pair(1, COLOR_RED, COLOR_BLACK);
    // init_pair(2, COLOR_WHITE, COLOR_BLACK);
    // init_pair(3, COLOR_GREEN, COLOR_BLACK);

    std::string titleStrings[] = {
        "The Farming Game", 
        "Press any key to continue", 
        "Field Creation", 
        "Enter desired rows: ", 
        "Enter desired columns: "
    };

    mvprintw((getmaxy(stdscr) / 2) - 1, (getmaxx(stdscr) - titleStrings[0].length()) / 2, "%s", titleStrings[0].c_str());
    mvprintw((getmaxy(stdscr) / 2) + 1, (getmaxx(stdscr) - titleStrings[1].length()) / 2, "%s", titleStrings[1].c_str());

    refresh();

    getch();

    clear();

    int fieldrows, fieldcolumns;

    mvprintw((getmaxy(stdscr) / 2) - 2, (getmaxx(stdscr) - titleStrings[2].length()) / 2, "%s", titleStrings[2].c_str());
    mvprintw((getmaxy(stdscr) / 2), (getmaxx(stdscr) - titleStrings[3].length()) / 2, "%s", titleStrings[3].c_str());

    refresh();

    echo();

    int posY, posX;
    getyx(stdscr, posY, posX);

    while (true){
        move(posY, posX);
        fieldrows = getch();
        if (fieldrows > 57 || fieldrows < 49){
            std::string badInput = "Invalid input. Please enter a number within the range 1-9";
            mvprintw((getmaxy(stdscr) / 2) + 3, (getmaxx(stdscr) - badInput.length()) / 2, "%s", badInput.c_str());
            refresh();
        } else {
            break;
        }
    }

    refresh();

    mvprintw((getmaxy(stdscr) / 2) + 1, (getmaxx(stdscr) - titleStrings[4].length()) / 2, "%s", titleStrings[4].c_str());

    getyx(stdscr, posY, posX);

    while (true){
        move(posY, posX);
        fieldcolumns = getch();
        if (fieldcolumns > 57 || fieldcolumns < 49){
            std::string badInput = "Invalid input. Please enter a number within the range 1-9";
            mvprintw((getmaxy(stdscr) / 2) + 3, (getmaxx(stdscr) - badInput.length()) / 2, "%s", badInput.c_str());
            refresh();
        } else {
            break;
        }
    }

    noecho();

    refresh();

    clear();

    Field field(fieldrows - 48, fieldcolumns - 48);
    WINDOW *fieldWindow;

    fieldWindow = dispCreateField(field);

    const char *menuChoices[] = {"Field", "Inventory", "Shop", "Pass Time", "Exit"};
    int itemCount = sizeof(menuChoices) / sizeof(menuChoices[0]);
    ITEM **menuItems = (ITEM **)calloc(itemCount + 1, sizeof(ITEM *));

    for (int i = 0; i < itemCount; i++){
        menuItems[i] = new_item(menuChoices[i], menuChoices[i]);
    }

    MENU *menu;
    WINDOW *menuWindow;

    menu = new_menu(menuItems);
    menuWindow = newwin(itemCount + 2, 25, (getmaxy(stdscr) - (itemCount + 2)) / 2, getmaxx(stdscr) / 2);
    keypad(menuWindow, true);

    set_menu_win(menu, menuWindow);
    set_menu_sub(menu, derwin(menuWindow, itemCount, 23, 1, 1));

    box(menuWindow, 0, 0);

    post_menu(menu);

    wrefresh(menuWindow);

    int c;

    bool running = true;

    while (running == true){
        while ((c = wgetch(menuWindow)) != KEY_BACKSPACE) {
            switch (c) {
                case KEY_DOWN:
                    menu_driver(menu, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(menu, REQ_UP_ITEM);
                    break;
                case 10: /* Enter Key */

                    break;
            }
            wrefresh(menuWindow);
        }
    }

    unpost_menu(menu);
    free_menu(menu);

    for (int i = 0; i < 5; i++) {
        free_item(menuItems[i]);
    }

    endwin();
    return 0;
}