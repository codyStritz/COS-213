#include <iostream>
#include "tortoise_hare.h"

//Constructor
Contestant::Contestant(string name, string symbol) {
  this->name_ = name;
  this->symbol_ = symbol;
}

// Getters
string Contestant::GetName() { return this->name_; }
string Contestant::GetSymbol() { return this->symbol_; }
int Contestant::GetPosition() { return this->position_; }

// Adjusts the Contestant's position by given amount
// If the new position is going to be < 1, set position = 1
void Contestant::AdjustPosition(int amount) {
  if (this->position_ + amount < 1) {
    this->position_ = 1;
  }
  else this->position_ += amount;
}

