
#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Plant.h"

int main() {
  Inventory* inv = new Inventory(10, 4);

  cout << inv->inventoryOpen() << endl;
  inv->openInventory();
  cout << inv->inventoryOpen() << endl;

  int j = 0;
  int i = 0;
  for (i = 0; i < 20; i++) {
    Fruit* j = new Fruit(i, "apple", 40, 2);
    inv->addPlant(*j);
    j++;
  }
  inv->removePlant(9);
  Grain* k = new Grain(30, "wheat", 50, 20);
  inv->addPlant(*k);

  k->getStatus();
  for (i = 0; i < 13; i++) {
    k->plantGrow(2);
  }
  k->getStatus();
  delete k;

  inv->removePlant(30);

  j = 0;
  for (i = 0; i < 20; i++) {
    Equipment* j = new Equipment(i, "Hoe", 20, 2);
    inv->addEquipment(*j);
    j++;
  }
  inv->removeEquipment(9);
  inv->removeEquipment(3);
  Equipment* m = new Equipment(200, "pick", 50, 3);
  inv->addEquipment(*m);
  inv->removeEquipment(200);

  inv->closeInventory();
  cout << inv->inventoryOpen() << endl;
  inv->addEquipment(*m);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  inv->changeFunds(9.7);
  inv->changeGrain(500);
  inv->changeFruit(9);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  inv->changeFunds(0);
  inv->changeGrain(0);
  inv->changeFruit(0);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  inv->changeFunds(-4.289);
  inv->changeGrain(-5);
  inv->changeFruit(-100);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  return 0;
}
