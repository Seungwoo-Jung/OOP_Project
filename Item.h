#ifndef ITEM_H
#define ITEM_H
#include <fstream>
#include <string>

using namespace std;

class Item {
 protected:
  int ID;
  string name;
  string status;
  int lifespan;
  double price;

 public:
  Item();
  Item(int setID, string setname, string setstatus, int lifespan,
       double setPrice);

  // function set as 0 to make class abstract
  virtual void getStatus() = 0;
  int getID() const;
  double getPrice();
  void setPrice(double newPrice);
  virtual ~Item();
};

#endif