#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Item.h"

using namespace std;

class Player {
 private:
  int userID;
  int Currency;
  bool validInput;
  int timepassed;
  map<string, int> inventory;

 public:
  Player();
  char Navigate();
  int loadData();
  void saveData();
  void passTime();
  ~Player();
};
#endif
