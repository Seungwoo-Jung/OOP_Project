#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item {
 protected:
  int ID;
  string name;
  string status;

 public:
  Item();
  Item(int setID, string setname, string setstatus);
  virtual void getStatus() = 0;
  ~Item();
};

#endif