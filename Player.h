#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
<<<<<<< HEAD
#include <map>
#include <string>
=======
#include <string>
#include <vector>
#include <map>
#include "Item.h"
>>>>>>> 25f174546402ee47766097f73d4208065f575038

using namespace std;

class Player {
<<<<<<< HEAD
 private:
  int userID;
  int timepassed;
  bool validInput;
  map<string, int> inventory;

 public:
  Player();
  void loadData();
  void saveData();
  void passTime();
  char Navigate();
  void changeFarm();
  void exchangeItem();

  ~Player();
=======
    private:
        int userID;
        int Currency;
        map<string, int> inventory;

    public:
        Player(int initialMoney);
        void loadData();
        void saveData();
        ~Player();
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};
#endif
