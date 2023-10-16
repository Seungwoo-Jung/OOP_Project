#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

Player::Player(int initialMoney) : Currency(initialMoney) {};

void Player::loadData() {
    ifstream loadFile("player.txt");
    loadFile >> userID >> Currency;
    loadFile.close();
}

void Player::saveData() {
    ofstream saveFile("player.txt");
    saveFile << userID << "\n" << Currency << "\n";
    saveFile.close();
}

Player::~Player() {
    
}