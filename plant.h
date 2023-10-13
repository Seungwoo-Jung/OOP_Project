#ifndef PLANT_H
#define PLANT_H
#include <string>

#include "item.h"
using namespace std;

class plant : public item {
 protected:
  float areaUsed;
  int lifespan;
  string species;
  int age;
  double water;

 public:
  plant();
  plant(int ID, string name, float area, int life, string type);
  virtual void plantGrow();
  virtual int plantHarvest();
  virtual void plantWater();
  ~plant();
};

#endif