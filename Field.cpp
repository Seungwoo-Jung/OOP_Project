#include "Field.h"

#include <string>

Field::Field() {
	soilState = "default";
	fieldSizeM = 1;
	fieldSizeN = 1;
}

Field::Field(int size_row, int size_column) {
	soilState = "default";
	fieldSizeM = size_row;
	fieldSizeN = size_column;

	fieldMatrix.resize(fieldSizeM);

	for (int i = 0; i < fieldSizeM; i++){
		fieldMatrix[i].resize(fieldSizeN);
	}
}

void Field::set_plant(Plant *plant, int row, int column){
	fieldMatrix[row][column] = plant;
}

int Field::get_sizeM(){
	return fieldMatrix.size();
}

int Field::get_sizeN(){
	return fieldMatrix[0].size();
}

Plant *Field::get_plant(int row, int column){
	return fieldMatrix[row][column];
}