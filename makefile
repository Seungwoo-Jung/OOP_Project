fieldTest: fieldTest.cpp Field.cpp Plant.cpp Grain.cpp Item.cpp
	clang++ fieldTest.cpp Field.cpp Plant.cpp Grain.cpp Item.cpp -o fieldTest
	./fieldTest

main: main.cpp Equipment.cpp Field.cpp Fruit.cpp Grain.cpp Inventory.cpp Item.cpp Plant.cpp Player.cpp Shop.cpp
	g++ main.cpp Equipment.cpp Field.cpp Fruit.cpp Grain.cpp Inventory.cpp Item.cpp Plant.cpp Player.cpp Shop.cpp -lmenu -lncurses -o main
	./main