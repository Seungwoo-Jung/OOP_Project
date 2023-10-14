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
  item();
  item(int setID, string setname, string setstatus);
  virtual void getStatus() = 0;
  ~item();
};

#endif