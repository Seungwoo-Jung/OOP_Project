#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Equipment.h"
#include "Field.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"
#include "Shop.h"

using namespace std;

class Player {
 private:
  int userID;
  int Currency;
  bool validInput;
  int timepassed;
  bool done;

 public:
  Player();
  int Navigate(Inventory* inv, Shop* shop, Field* field);
  int loadData();
  void saveData();
  void passTime(Field* field, Inventory* inv);
  void shopAction(Shop* shop, Inventory& inv);
  void invAction(Inventory* inv);
  void fieldAction(Field* field, Inventory* inv);
  ~Player();
};
#endif
