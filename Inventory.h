#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
<<<<<<< HEAD

=======
>>>>>>> 25f174546402ee47766097f73d4208065f575038
#include "Equipment.h"
#include "Plant.h"

using namespace std;

class Inventory {
<<<<<<< HEAD
 private:
  bool exists;
  int plantCapacity;
  int equipmentCapacity;
  double funds;
  int grain;
  int fruit;
  bool isOpen;
  unordered_map<int, Plant*> plantInventory;
  unordered_map<int, Equipment*> equipInventory;

 public:
  Inventory();
  Inventory(int p, int e);

  void openInventory();
  void closeInventory();
  bool inventoryOpen();

  void getContents();

  void changeFunds(double amount);
  void changeGrain(int amount);
  void changeFruit(int amount);

  double getFunds();
  int getGrain();
  int getFruit();

  void addPlant(Plant* p1);
  void removePlant(int ID);

  void addEquipment(Equipment* e1);
  void removeEquipment(int ID);
  ~Inventory();
=======
    private:
    bool exists;
    int plantCapacity;
    int equipmentCapacity;
    double funds;
    int grain;
    int fruit;
    bool isOpen;
    unordered_map<int, Plant*> plantInventory;
    unordered_map<int, Equipment*> equipInventory;

    public:
    Inventory();
    Inventory(int p, int e);

    void openInventory();
    void closeInventory();
    bool inventoryOpen();

    void getContents();

    void changeFunds(double amount);
    void changeGrain(int amount);
    void changeFruit(int amount);

    double getFunds();
    int getGrain();
    int getFruit();

    void addPlant(Plant* p1);
    void removePlant(int ID);

    void addEquipment(Equipment* e1);
    void removeEquipment(int ID);
    ~Inventory();
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};
#endif