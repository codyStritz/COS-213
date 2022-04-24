#ifndef SHAPES_H  // include guards
#define SHAPES_H

// Square definition
class Square {
  public:
    Square();
    Square(double);
    double calcVal();
  protected:
    double side = 1.0; 
};

// Cube definition
class Cube: public Square {
  public:
    Cube();
    Cube(double);
    double calcVal();
};

#endif SHAPES_H