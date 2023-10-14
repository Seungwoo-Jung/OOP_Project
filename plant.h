#ifndef PLANT_H
#define PLANT_H
#include <string>

#include "item.h"
using namespace std;

class Plant : public Item {
 protected:
  float areaUsed;
  int lifespan;
  string species;
  int age;
  double water;

 public:
  Plant();
  Plant(int ID, string name, float area, int life, string type);
  virtual void plantGrow();
  virtual int plantHarvest();
  virtual void plantWater();
  ~Plant();
};

#endif