#include "Field.h"

#include <string>

#include "Fruit.h"
#include "Grain.h"
#include "Item.h"
#include "Plant.h"

// default construcior sets size of the field to be 0
Field::Field() {
  soilState = "default";
  fieldSizeM = 0;
  fieldSizeN = 0;
  isFull = false;
  isEmpty = true;
  isOpen = false;
}

// Standard constructor takes 2 inputs to determine the size of the field, and
// creates a field of that size
Field::Field(int size_row, int size_column) {
  isFull = false;
  isEmpty = true;
  isOpen = false;
  int i = 0, j = 0;
  soilState = "default";
  fieldSizeM = size_row;
  fieldSizeN = size_column;

  fieldMatrix.resize(fieldSizeM);

  for (i = 0; i < fieldSizeM; i++) {
    fieldMatrix[i].resize(fieldSizeN);
  }

  for (i = 0; i < fieldSizeM; i++) {
    for (j = 0; j < fieldSizeN; j++) {
      fieldMatrix[i][j] = nullptr;
    }
  }
}

// adds a plant into the position on the field
void Field::set_plant(Plant* plant, int row, int column) {
  fieldMatrix[row][column] = plant;
  fieldMatrix[row][column]->planted();
}

// emoves a plant from that position on the field, after harvesting and deleting
// it and deletes the object
void Field::remove_plant(int row, int column) {
  // fieldMatrix[row].erase(fieldMatrix[row].begin() + column);
  delete fieldMatrix[row][column];
  fieldMatrix[row][column] = nullptr;
}

// returns the number of rows in the field
int Field::get_sizeM() { return fieldMatrix.size(); }

// returns the number of columns in the field
int Field::get_sizeN() { return fieldMatrix[0].size(); }

// returns the entire field for use in other classes
std::vector<std::vector<Plant*>> Field::getField() { return fieldMatrix; }

// returns a plant from the field
Plant* Field::get_plant(int row, int column) {
  return fieldMatrix[row][column];
}

// checks if the field is full and returns the result
bool Field::Full() {
  isFull = true;
  int i = 0, j = 0;
  for (i = 0; i < fieldSizeM; i++) {
    for (j = 0; j < fieldSizeN; j++) {
      if (fieldMatrix[i][j] == nullptr) {
        isFull = false;
      }
    }
  }
  return isFull;
}

// checks if the field is empty and returns the result
bool Field::Empty() {
  isEmpty = true;
  int i = 0, j = 0;
  for (i = 0; i < fieldSizeM; i++) {
    for (j = 0; j < fieldSizeN; j++) {
      if (fieldMatrix[i][j] != nullptr) {
        isEmpty = false;
      }
    }
  }
  return isEmpty;
}

// returns the contents by getting the status of everythig in the field
void Field::getContents() {
  int i = 0, j = 0;
  if (Empty() != true) {
    for (i = 0; i < fieldSizeM; i++) {
      for (j = 0; j < fieldSizeN; j++) {
        if (fieldMatrix[i][j] != nullptr) {
          cout << "Plant in position " << i << "," << j << ":" << endl;
          fieldMatrix[i][j]->getStatus();
        }
      }
    }
  } else {
    cout << "Nothing to display, Field is empty" << endl;
  }
}

// opens the field
void Field::openField() {
  cout << "Opening Field:" << endl;
  isOpen = true;
}

// closes the field
void Field::closeField() {
  cout << "Closing Field:" << endl;
  isOpen = false;
}

Field::~Field() {
  int i = 0, j = 0;
  for (i = 0; i < fieldSizeM; i++) {
    for (j = 0; j < fieldSizeN; j++) {
      if (fieldMatrix[i][j] != nullptr) {
        delete fieldMatrix[i][j];
      }
    }
  }
  cout << "Field was deleted" << endl;
};