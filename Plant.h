#ifndef PLANT_H
#define PLANT_H
#include <string>

#include "item.h"
using namespace std;

class plant : public item {
    protected:
        float areaUsed;
        int lifespan;
        string species;
        int age;
        double water;

    public:
        plant() : item() {
            areaUsed = 0;
            lifespan = 0;
            species = "null";
            age = 0;
            water = 100;
        }
        plant(int ID, string name, float area, int life, string type) : item(ID, name, "growing") {
            areaUsed = area;
            lifespan = life;
            species = type;
            age = 0;
            water = 100;
        }
        virtual void plantGrow(){};
        void plantHarvest(){};
        virtual void plantWater(){};
        ~plant() {}
};
#endif