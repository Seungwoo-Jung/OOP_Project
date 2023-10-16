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

	public:
		Field();
		Field(int size_row, int size_column);

		void grainPlant();
		void fruitPlant();

		void set_plant(Plant *plant, int row, int column);
		void remove_plant(int row, int column);

		int get_sizeM();
		int get_sizeN();
		std::string get_soilState();
		Plant *get_plant(int row, int column);

		void changeRows(int size_row);
		void changeColumns(int size_column);
};

#endif