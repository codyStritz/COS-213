// Cody Stritz
// Written Assignment 6 - Exercise 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <exception>
using namespace std;

// Custom exception class for division by zero
class DivByZero : public runtime_error {
  public:
    // constructor specifies default error message
    DivByZero()
      : runtime_error{"Attempted to divide by zero!\n"} {}

    // returns the integer quotient of numerator and denominator
    // if denominator is 0 -> throws DivByZero exception
    int Quotient(int numerator, int denominator) {
      if (denominator == 0) throw(*this);
      else return numerator / denominator;
    } 
};

int main() {
  int numerator = 0;
  int denominator = 0;
  // get user input for numerator and denominator
  cout << "Enter numerator: ";
  cin >> numerator;
  cout << "Enter denominator: ";
  cin >> denominator;

  // try to calculate the quotient 
  try {
    DivByZero d;
    cout << d.Quotient(numerator, denominator) << endl;
  } 
  // catch DivByZero exception
  catch (DivByZero d) { 
    cout << d.what() << endl;
  }
  system("pause");
  return 0;
}