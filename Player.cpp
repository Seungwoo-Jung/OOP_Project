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

int Player::loadData() {
  ifstream loadFile("player.txt");
  if (loadFile.is_open()) {
    loadFile >> userID >> Currency;
    loadFile.close();
  }
  return userID, Currency;
}

void Player::saveData() {
  ofstream saveFile("player.txt");
  if (saveFile.is_open()) {
    saveFile << userID << "\n" << Currency << "\n";
    saveFile.close();
  } else {
    cout << "unable to open file" << endl;
  }
}

Player::~Player() {}