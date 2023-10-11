#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

class fruit : public plant {
 private:
  int productionRate;

 public:
  fruit() { productionRate = 0; }
  fruit(int ID, string name, float area, int life, string type, int setRate)
      : plant(ID, name, area, life, type) {
    productionRate = setRate;
  }
  ~fruit() { cout << "fruit with ID " << ID << " was deleted" << endl; }
  void plantGrow() override {
    if (status != "null" && status != "dead") {
      if (status == "growing" && age < lifespan && water > 0) {
        age = age + 1;
        water = water - 5;
      }
      double result = static_cast<double>(age) / lifespan;
      if (age == lifespan) {
        status = "dead";
      } else if (status != "declining" && result >= 0.8) {
        status = "declining";
      } else if (status != "mature" && status != "declining" && result >= 0.2) {
        status = "mature";
        water = 100;
      }

      if ((water - 5) == 0) {
        status = "dead";
      } else if ((water - 5) < 40) {
        status = "declining";
      }
    }
  }
  void plantHarvest(){};
  void plantWater() override { water = 100; };
  void getStatus() override {
    cout << "Plant of type " << species << " with ID " << ID << ". name "
         << name << ", using " << areaUsed << " area. Age is " << age
         << " out of " << lifespan << " lifespan. Produces 1 fruit per "
         << productionRate << " days. "
         << "Current status: " << status << ", with " << water << "% water."
         << endl;
  }
};

#endif