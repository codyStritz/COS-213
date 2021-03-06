#include "tortoise_hare.h"

// Constructor
Tortoise::Tortoise() : Contestant("Tortoise", "T") {}

// Makes move based on roll
void Tortoise::Move(int roll) {
  if (roll < 6) FastPlod();
  else if (roll > 7) SlowPlod();
  else Slip();
}

// Movements
void Tortoise::FastPlod() {
  AdjustPosition(3);
}
void Tortoise::SlowPlod() {
  AdjustPosition(1);
}
void Tortoise::Slip() {
  AdjustPosition(-6);
}
