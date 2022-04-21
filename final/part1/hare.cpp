#include "tortoise_hare.h"

// Constructor
Hare::Hare() : Contestant("Hare", "H") {}

void Hare::Move(int roll) {
  if (roll < 3) Sleep();  // 1 or 2 == 20%
  else if (roll < 5) BigHop(); // 3 or 4 == 20%
  else if (roll = 5) BigSlip(); // 5 == 10%
  else if (roll < 9) SmallHop(); // 6 or 7 or 8 == 30%
  else SmallSlip(); // 9 or 10 == 20%
}

void Hare::Sleep() {
  AdjustPosition(0);
}
void Hare::BigHop() {
  AdjustPosition(9);
}
void Hare::BigSlip() {
  AdjustPosition(-12);
}
void Hare::SmallHop() {
  AdjustPosition(1);
}
void Hare::SmallSlip() {
  AdjustPosition(-2);
}