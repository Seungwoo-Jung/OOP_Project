#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item {
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
  ~Item();
};

#endif