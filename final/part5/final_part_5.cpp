// Cody Stritz
// Final - Part 5
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include "shapes.h"
using namespace std;

int main() {
  Square square1;
  Square square2(3.0);
  Cube cube1;
  Cube cube2(3.0);

  // Detailed description of the process that took place in 
  // developing the solution to the question.  

  cout << "The following are the steps that were taken to "
    << "implement the solution to this problem:\n\nFirst, I "
    << "created a header file in which I defined the interfaces "
    << "for the Square and Cube classes. I ensured that Square's "
    << "member variable side was protected and given a default value "
    << "of 1.0. I also defined Cube as a child class of Square.\n\n"
    << "Second, I created the implementations for each class's methods. "
    << "I provided overloaded constructors for each class to allow member "
    << "variable side to be set. The implemenatation for Cube::calcVal() "
    << "returns side * Square::calcVal()\n" << endl;

  cout << "Examples:" << endl;
  cout << "Square1 calcVal = " << square1.calcVal() << endl;
  cout << "Square2 calcVal = " << square2.calcVal() << endl;
  cout << "Cube1 calcVal = " << cube1.calcVal() << endl;
  cout << "Cube2 calcVal = " << cube2.calcVal() << endl;

  system("pause");
  return 0;
}