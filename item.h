#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item {
 protected:
  int ID;
  string name;
  string status;

 public:
  item() {
    ID = 0;
    name = "null";
    status = "null";
  }
  item(int setID, string setname, string setstatus) {
    ID = setID;
    name = setname;
    status = setstatus;
  }
  virtual void getStatus() = 0;
  ~item() {}
};

#endif