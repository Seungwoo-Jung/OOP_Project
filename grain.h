#ifndef GRAIN_H
#define GRAIN_H
#include <iostream>
#include <string>
#include "Plant.h"

using namespace std;

class grain : public plant {
    private:
        int yield;

    public:
        grain() : plant() { yield = 0; }
        grain(int ID, string name, float area, int life, string type, int setyield)
            : plant(ID, name, area, life, type) {
            yield = setyield;
        }
        ~grain() { cout << "grain with ID " << ID << " was deleted" << endl; }
        void plantGrow() override {
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
        void plantHarvest(){};
        void plantWater() override { water = 100; };
        void getStatus() override {
            cout << "Plant of type " << species << " with ID " << ID << ". name "
                << name << ", using " << areaUsed << " area. Age is " << age
                << " out of " << lifespan << " lifespan. Yield is " << yield << "."
                << " Current status: " << status << ", with " << water << "% water."
                << endl;
        }
};
#endif