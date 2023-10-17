#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Player {
    private:
        int userID;
        int Currency;
        map<string, int> inventory;

    public:
        Player(int initialMoney);
        void loadData();
        void saveData();
        ~Player();
};
#endif
