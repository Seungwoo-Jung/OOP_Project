#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Player::Player() {
  cout << "Enter numbers to create your userID: " << endl;
  cin >> userID;
  timepassed = 0;
  validInput = false;
}

char Player::Navigate() {
  char input = '0';
  cout << "What would you like to do?" << endl;
  cin >> input;
  return input;
}

void Player::passTime() { timepassed = timepassed + 1; }

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

Player::~Player() {}