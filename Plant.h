#ifndef PLANT_H
#define PLANT_H
#include <string>

#include "Item.h"
using namespace std;

class Plant : public Item {
 protected:
  string species;
  double age;
  double water;
  int growthRate;

 public:
  Plant();
  Plant(int ID, string name, int life, string type);
  virtual void plantGrow(int growthRate);
  virtual int plantHarvest();
  virtual void plantWater();
  ~Plant();
};

#endif