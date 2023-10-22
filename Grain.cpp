#include "Grain.h"

#include <iostream>
#include <string>

#include "Plant.h"
using namespace std;

// the default contructor sets some values as 0 or null, and activates the
// default Plant constructor
Grain::Grain() : Plant() { yield = 0; }

// the standard contructor takes input values and feeds some to the plant
// constructor, while setting the yield as the input value
Grain::Grain(int ID, string name, int life, int setyield)
    : Plant(ID, name, life) {
  yield = setyield;
}

// destructor
Grain::~Grain() {}

// the plantGrow function has multiple parts to manage the growth of the plant.
// Nothing at all will occur if the pant is not alive or does not exist
void Grain::plantGrow(int setGrowthRate) {
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
    } else if (status != "declining" && result >= 0.75) {
      status = "declining";
    } else if (status != "mature" && status != "declining" && result >= 0.5) {
      status = "mature";
    }

    // this part sets the plant to be either declining or dead if it has little
    // or no water left respectively
    if (water == 0) {
      status = "dead";
    } else if (water <= 40) {
      status = "declining";
    }
  }

  // this part sets the water to 0 if the plant is dead, to avoid confucion when
  // printing status. occurs regardless of if the plant exists or not since it
  // functions correctly at all times
  if (status == "dead") {
    water = 0;
  }
}

// plantHarvest function activates only if plant is alive and exists. it sets
// the status as dead and returns the yield, provided the plant is mature or
// declining If the plant is harvested early it will return nothing
int Grain::plantHarvest() {
  if (status != "dead" && status != "null") {
    water = 0;
    if (status != "growing") {
      cout << " A Yield of " << yield << " " << name << " was received."
           << endl;
      status = "dead";
      return yield;
    } else {
      cout << "A Yield of 0 " << name << " was received." << endl;
      status = "dead";
      return 0;
    }
    status = "dead";
  } else {
    cout << "No " << name << " received, plant is dead." << endl;
  }
  return 0;
}

// the plantWater function refills the plant water to 100%, provided that the
// plant is alive and exists. the function changes the status to be
// growing/mature depending on the age of the plant if it was declining from a
// lack of water.
void Grain::plantWater() {
  if (status != "dead" && status != "null") {
    water = 100;
    double result = (age / lifespan);
    if (water > 40 && result <= 0.5) {
      status = "growing";
    } else if (water > 40 && result <= 0.75) {
      status = "mature";
    }
  }
}

// the getStatus function prints a message detailing all aspects of the plant
// which are important, with explanations. To avoid unreasoable output, the
// default fruit amount of -1 is printed as 0
void Grain::getStatus() {
  cout << "Plant of type Grain, species " << name << " with ID " << ID
       << ". Age is " << age << " out of " << lifespan << " lifespan. Yield is "
       << yield << " once mature.";
  if (isPlanted == false) {
    cout << endl;
  } else if (isPlanted == true) {
    cout << " Current status: " << status << ", with growth rate " << growthRate
         << " and " << water << "% water." << endl;
  }
}

// sets the isPlanted value to be true, so status will print out growth state
void Grain::planted() { isPlanted = true; }
