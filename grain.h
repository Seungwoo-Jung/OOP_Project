#ifndef GRAIN_H
#define GRAIN_H
#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

class Grain : public Plant {
 private:
  int yield;

 public:
  Grain();
  Grain(int ID, string name, float area, int life, string type, int setyield);
  ~Grain();
  void plantGrow() override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
};
#endif