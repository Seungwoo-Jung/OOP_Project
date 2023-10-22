#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <string>

#include "Plant.h"

using namespace std;

class Fruit : public Plant {
 private:
  int productionRate;
  int currentFruit;
  int productionTracker;

 public:
  Fruit();
  Fruit(int ID, string name, int life, int setRate);
  ~Fruit() override;
  void plantGrow(int growthRate) override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
  void planted() override;
};
#endif