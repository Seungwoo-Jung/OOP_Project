#ifndef GRAIN_H
#define GRAIN_H
#include <iostream>
#include <string>

#include "Plant.h"

using namespace std;

class Grain : public Plant {
 private:
  int yield;

 public:
  Grain();
  Grain(int ID, string name, int life, int setyield);
  ~Grain() override;
  void plantGrow(int growthRate) override;
  int plantHarvest() override;
  void plantWater() override;
  void getStatus() override;
  void planted() override;
};
#endif