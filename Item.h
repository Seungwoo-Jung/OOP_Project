#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <fstream>

using namespace std;

class Item {

protected:
    int ID;
    string name;
    string status;
    int lifespan;
    int price;

public:
    Item();
    Item(int setID, string setname, string setstatus, int lifespan, int setPrice);

    // function set as 0 to make class abstract
    virtual void getStatus() = 0;
    int getID() const;
    virtual ~Item();
};

#endif