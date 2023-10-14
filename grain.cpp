#include "grain.h"

#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

Grain::Grain() : Plant() { yield = 0; }
Grain::Grain(int ID, string name, float area, int life, string type,
             int setyield)
    : Plant(ID, name, area, life, type) {
  yield = setyield;
}
Grain::~Grain() { cout << "grain with ID " << ID << " was deleted" << endl; }
void Grain::plantGrow() {
  if (status != "null" && status != "dead") {
    if (age < lifespan && water > 0) {
      age = age + 1;
      water = water - 5;
    }
    double result = static_cast<double>(age) / lifespan;
    if (age == lifespan) {
      status = "dead";
    } else if (status != "declining" && result >= 0.75) {
      status = "declining";
    } else if (status != "mature" && status != "declining" && result >= 0.5) {
      status = "mature";
    }

    if ((water - 5) == 0) {
      status = "dead";
    } else if ((water - 5) < 40) {
      status = "declining";
    }
  }
}
int Grain::plantHarvest() {
  if (status != "dead") {
    status = "dead";
    return yield;
  }
  return 0;
};
void Grain::plantWater() { water = 100; };
void Grain::getStatus() {
  cout << "Plant of type " << species << " with ID " << ID << ". name " << name
       << ", using " << areaUsed << " area. Age is " << age << " out of "
       << lifespan << " lifespan. Yield is " << yield << "."
       << " Current status: " << status << ", with " << water << "% water."
       << endl;
}