#include "shapes.h"

// Default constructor
Square::Square() {}

// Overloaded constructor
Square::Square(double side) {
  this->side = side;
}

// Returns area of Square
double Square::calcVal() {
  return side * side;
}