#ifndef GRAIN_H
#define GRAIN_H
#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

class grain : public plant {
 private:
  int yield;

 public:
  grain();
  grain(int ID, string name, float area, int life, string type, int setyield);
  ~grain();
  void plantGrow() override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif