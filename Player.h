#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Player {
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
};
#endif
