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
#include <iostream>

WINDOW *dispCreateField(Field field){

    WINDOW *windowField;

    int windowY = field.get_sizeM() + 2;
    int windowX = (3 * (field.get_sizeN())) + 1;

    windowField = newwin(windowY, windowX, 0, 0);

    refresh();

    box(windowField, 0, 0);

    for (int i = 1; i < windowY - 1; i++){
        for (int j = 1; j < windowX - 1; j++){
            if (j % 3 == 0){
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

void dispFieldUpdate(){

}

int main(){

    std::cout << has_colors() << std::endl;

    initscr();
    noecho();
    start_color();

    // Defining colours //
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);

    Field field(5, 5);
    WINDOW *window;

    window = dispCreateField(field);

    getch();

    endwin();
    return 0;
}