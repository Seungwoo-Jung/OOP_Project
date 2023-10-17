#ifndef ITEM_H
#define ITEM_H
#include <string>
<<<<<<< HEAD
=======
#include <fstream>
>>>>>>> 25f174546402ee47766097f73d4208065f575038

using namespace std;

class Item {
<<<<<<< HEAD
 protected:
  int ID;
  string name;
  string status;
  int lifespan;

 public:
  Item();
  Item(int setID, string setname, string setstatus, int lifespan);

  // function set as 0 to make class abstract
  virtual void getStatus() = 0;
  int getID() const;
  virtual ~Item();
=======

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
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};

#endif