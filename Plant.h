#ifndef PLANT_H
#define PLANT_H
#include <string>
#include "Item.h"

<<<<<<< HEAD
#include "Item.h"
=======
>>>>>>> 25f174546402ee47766097f73d4208065f575038
using namespace std;

class Plant : public Item {
 protected:
  double age;
  double water;
  int growthRate;
<<<<<<< HEAD

 public:
  Plant();
  Plant(int ID, string name, int life);
=======
  int price;

public:
  Plant();
  Plant(int ID, string name, int life, int setPrice);
>>>>>>> 25f174546402ee47766097f73d4208065f575038
  virtual void plantGrow(int growthRate);
  virtual int plantHarvest();
  virtual void plantWater();
  virtual void getStatus();
  virtual ~Plant();
};

#endif