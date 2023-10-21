
#include "Fruit.h"

#include <iostream>
#include <string>

#include "Plant.h"
using namespace std;

// the default contructor sets some values as 0 or null, and activates the
// default Plant constructor
Fruit::Fruit() : Plant() {
  productionRate = 0;
  currentFruit = 0;
  productionTracker = 0;
}

// the standard contructor takes input values and feeds some to the plant
// constructor, while setting the production rate via the input value, and
// currentfruit/production tracker are set at -1 for the purposes of
// calculations
Fruit::Fruit(int ID, string name, int life, int setRate)
    : Plant(ID, name, life) {
  productionRate = setRate;
  currentFruit = -1;
  productionTracker = -1;
}

// the destructor prints out a message detailing the deletion
Fruit::~Fruit() { cout << name << " with ID " << ID << " was deleted" << endl; }

// the plantGrow function has multiple parts to manage the growth of the plant.
// Nothing at all will occur if the pant is not alive or does not exist
void Fruit::plantGrow(int setGrowthRate) {
  // sets the input value as the growth rate for calculations
  growthRate = setGrowthRate;

  if (status != "null" && status != "dead") {
    // this part focuses on aging. Based on the current growth rate, the plant
    // ages faster in the growing stage, slower in the declining phase, and
    // standard in the mature phase. water is also decreased by 5% each time the
    // plant ages, no matter the speed. Growth only occurrs if the plant is
    // younger than it's lifespan, and has more than 0% water
    if (status == "growing" && age < lifespan && water > 0) {
      age = age + growthRate;
      water = water - 5;
    } else if (status == "mature" && age < lifespan && water > 0) {
      age = age + 1;
      water = water - 5;
    } else if (status == "declining" && age < lifespan && water > 0) {
      age = age + (static_cast<double>(1) / growthRate);
      water = water - 5;
    }

    // this part sets the status of the plant depending on it's current age and
    // existing status
    double result = (age / lifespan);
    if (age == lifespan) {
      status = "dead";
    } else if (status != "declining" && result >= 0.8) {
      status = "declining";
    } else if (status != "mature" && status != "declining" && result >= 0.2) {
      status = "mature";
      water = 100;
    }

    // this part sets the plant to be either declining or dead if it has little
    // or no water left respectively
    if (water == 0) {
      status = "dead";
    } else if (water <= 40) {
      status = "declining";
    }

    // unique to fruit plants, this section focuses on tracking the current
    // growth of fruit for harvest. Once the plant reaches maturity, it will
    // grow one fruit every predetermined amount of days, which is tracked here
    // by a productionTracker variable. This is because the different speeds of
    // aging do not impact the production rate, so age cannot be used as a
    // variable for tracking fruit production

    // if plant is not growing, and is old enough for maturity (specified to
    // prevent gaining fruit early due to water deprivation causing plant to
    // decline before maturity), then productionTracker will count up each time
    // the plant ages, no matter the speed
    if (status != "growing" && age > (static_cast<double>(lifespan) * 0.2)) {
      productionTracker = productionTracker + 1;
    }

    // if the productionRate is divisable by the currentproductionTracker, then
    // 1 fruit will be added. fruit starts at -1 so once the plant reaches
    // maturity it will not gain a fruit instantly from the tracker having a
    // value of 1
    if (productionRate > 0 && (productionTracker % productionRate) == 0) {
      currentFruit = currentFruit + 1;
    }
  }

  // this part sets the water to 0 if the plant is dead, to avoid confucion when
  // printing status. occurs regardless of if the plant exists or not since it
  // functions correctly at all times
  if (status == "dead") {
    water = 0;
  }
}

// plantHarvest function activates only if plant is alive and exists. it removes
// all fruit from the plant, returning the amount there were. Unlike grain,
// fruit trees are not kiled when being harvested so the status remains the same
int Fruit::plantHarvest() {
  if (status != "dead" && status != "null") {
    int yield = currentFruit;
    currentFruit = 0;
    cout << " A Yield of " << yield << " " << name << " was received." << endl;
    return yield;
  } else {
    cout << "No " << name << " received, plant is dead." << endl;
  }
  return 0;
}

// the plantWater function refills the plant water to 100%, provided that the
// plant is alive and exists. the function changes the status to be
// growing/mature depending on the age of the plant if it was declining from a
// lack of water.
void Fruit::plantWater() {
  if (status != "dead" && status != "null") {
    water = 100;
    double result = (age / lifespan);
    if (result <= 0.2) {
      status = "growing";
    } else if (result <= 0.8) {
      status = "mature";
    }
  }
}

// the getStatus function prints a message detailing all aspects of the plant
// which are important, with explanations. To avoid unreasoable output, the
// default fruit amount of -1 is printed as 0
void Fruit::getStatus() {
  cout << "Plant of type Fruit, species " << name << " with ID " << ID
       << ". Age is " << age << " out of " << lifespan
       << " lifespan. Produces 1 fruit per " << productionRate << " days. "
       << "Current status: " << status << ", with growth rate " << growthRate
       << ", " << water << "% water and ";
  if (currentFruit == -1) {
    cout << "0";
  } else {
    cout << currentFruit;
  }
  cout << " fruit." << endl;
}
