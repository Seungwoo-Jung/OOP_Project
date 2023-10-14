#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Plant.h"

using namespace std;

class Inventory {
 private:
  int currentSize;
  int maxSize;
  int plantCapacity;
  int equipmentCapacity;
  double funds;
  int grain;
  int fruit;
  bool isOpen;
  Plant** plantsInHand;
  Equipment** equipmentInHand;

 public:
  Inventory();

  void openInventory();
  void closeInventory();
  bool inventoryOpen();

  void changeFunds(double amount);
  void changeGrain(int amount);
  void changeFruit(int amount);

  void addPlant();
  void addEquipment();

  void removePlant();
  void removeEquipment();
};
#endif