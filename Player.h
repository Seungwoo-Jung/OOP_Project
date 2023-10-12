#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Player {
    private:
        int userID;
        int Currency;
        map<string, int> inventory;
    public:
        Player();
        void loadData();
        void saveData();
        ~Player();
};
#endif
