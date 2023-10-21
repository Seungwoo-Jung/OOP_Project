#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Field.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"
#include "Player.h"
#include "Shop.h"

int main() {
  Player* player = new Player();
  Inventory* inv = new Inventory(7, 7);
  Field* field = new Field(5, 5);
  Shop* shop = new Shop();
  player->Navigate(inv, shop, field);
  delete player;
  delete shop;
  delete field;
  delete inv;
  return 0;
}