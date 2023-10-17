#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <string>
<<<<<<< HEAD

#include "Plant.h"
=======
#include "Plant.h"

>>>>>>> 25f174546402ee47766097f73d4208065f575038
using namespace std;

class Fruit : public Plant {
 private:
  int productionRate;
  int currentFruit;
  int productionTracker;
<<<<<<< HEAD

 public:
  Fruit();
  Fruit(int ID, string name, int life, int setRate);
=======
  int price;

public:
  Fruit();
  Fruit(int ID, string name, int life, int setRate, int setPrice);
>>>>>>> 25f174546402ee47766097f73d4208065f575038
  ~Fruit() override;
  void plantGrow(int growthRate) override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif