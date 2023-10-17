#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>

#include "Equipment.h"
#include "Plant.h"

using namespace std;

class Inventory {
 private:
  bool exists;
  int plantCapacity;
  int equipmentCapacity;
  int funds;
  int wheat;
  int rye;
  int apple;
  int rice;
  int banana;
  int pear;
  bool isOpen;
  bool plantFull;
  bool equipFull;

  bool plantEmpty;
  bool equipEmpty;
  unordered_map<int, Plant*> plantInventory;
  unordered_map<int, Equipment*> equipInventory;

 public:
  Inventory();
  Inventory(int p, int e);

  void openInventory();
  void closeInventory();
  bool inventoryOpen();

  void getContents();
  unordered_map<int, Equipment*> getEquipment();

  bool pFull();
  bool eFull();
  bool pEmpty();
  bool eEmpty();

  void changeFunds(int amount);
  void changeWheat(int amount);
  void changeRye(int amount);
  void changeRice(int amount);
  void changePear(int amount);
  void changeApple(int amount);
  void changeBanana(int amount);

  int getFunds();
  int getWheat();
  int getRye();
  int getRice();
  int getPear();
  int getApple();
  int getBanana();

  void addPlant(Plant* p1);
  void removePlant(int ID);

  void addEquipment(Equipment* e1);
  void removeEquipment(int ID);
  ~Inventory();
};
#endif