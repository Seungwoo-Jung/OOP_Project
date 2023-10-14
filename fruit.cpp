#include "fruit.h"

#include <iostream>
#include <string>

#include "plant.h"
using namespace std;

fruit::fruit() : plant() { productionRate = 0; }
fruit::fruit(int ID, string name, float area, int life, string type,
             int setRate)
    : plant(ID, name, area, life, type) {
  productionRate = setRate;
  currentFruit = 0;
}
fruit::~fruit() { cout << "fruit with ID " << ID << " was deleted" << endl; }
void fruit::plantGrow() {
  if (status != "null" && status != "dead") {
    if (status == "growing" && age < lifespan && water > 0) {
      age = age + 1;
      water = water - 5;
      if ((age % productionRate) == 0) {
        currentFruit = currentFruit + 1;
      }
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
int fruit::plantHarvest() {
  if (status != "dead") {
    int yield = currentFruit;
    currentFruit = 0;
    return yield;
  }
  return 0;
};
void fruit::plantWater() { water = 100; };
void fruit::getStatus() {
  cout << "Plant of type " << species << " with ID " << ID << ". name " << name
       << ", using " << areaUsed << " area. Age is " << age << " out of "
       << lifespan << " lifespan. Produces 1 fruit per " << productionRate
       << " days. "
       << "Current status: " << status << ", with " << water << "% water."
       << endl;
}