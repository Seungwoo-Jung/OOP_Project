#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <vector>

#include "Plant.h"

class Field {
 private:
  std::vector<std::vector<Plant *>> fieldMatrix;
  int fieldSizeM;
  int fieldSizeN;
  std::string soilState;
  bool isFull;
  bool isEmpty;
  bool isOpen;

 public:
  Field();
  Field(int size_row, int size_column);

  void set_plant(Plant *plant, int row, int column);
  void remove_plant(int row, int column);

  int get_sizeM();
  int get_sizeN();
  std::string get_soilState();
  Plant *get_plant(int row, int column);

  std::vector<std::vector<Plant *>> getField();

  bool Full();
  bool Empty();

  void getContents();
  void openField();
  void closeField();

  ~Field();
};

#endif