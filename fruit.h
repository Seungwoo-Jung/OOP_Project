#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

class Fruit : public Plant {
 private:
  int productionRate;
  int currentFruit;

 public:
  Fruit();
  Fruit(int ID, string name, float area, int life, string type, int setRate);
  ~Fruit();
  void plantGrow() override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif