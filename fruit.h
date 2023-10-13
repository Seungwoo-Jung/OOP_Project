#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

class fruit : public plant {
 private:
  int productionRate;
  int currentFruit;

 public:
  fruit();
  fruit(int ID, string name, float area, int life, string type, int setRate);
  ~fruit();
  void plantGrow() override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif