#include "shapes.h"

// Default constructor
Cube::Cube() {}

// Overloaded constructor
Cube::Cube(double side) {
  this->side = side;
}

// Calculates volume of cube 
// by multiplying side by Square::calcVal()
double Cube::calcVal() {
  return side * Square::calcVal();
}

