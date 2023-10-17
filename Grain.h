#ifndef GRAIN_H
#define GRAIN_H
#include <iostream>
#include <string>
<<<<<<< HEAD

#include "Plant.h"
=======
#include "Plant.h"

>>>>>>> 25f174546402ee47766097f73d4208065f575038
using namespace std;

class Grain : public Plant {
 private:
  int yield;
<<<<<<< HEAD

 public:
  Grain();
  Grain(int ID, string name, int life, int setyield);
=======
  int price;

public:
  Grain();
  Grain(int ID, string name, int life, int setyield, int setPrice);
>>>>>>> 25f174546402ee47766097f73d4208065f575038
  ~Grain() override;
  void plantGrow(int growthRate) override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif