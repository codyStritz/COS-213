// Cody Stritz
// Written Assignment 3 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Represents complex numbers using two variables.
// One variable represents the real part, and the other represents the 
// imaginary part.
class Complex {
  public:
    // Default constructor - initializes data members with default values
    Complex() {}
    // Contstructor - initializes data members to custom values
    Complex(int real_part, int imaginary_part)
      : real_part_(real_part), imaginary_part_(imaginary_part) {}

    // Adds the real parts together and the imaginary parts together of 
    // the two operands.
    Complex add(Complex second_operand) {
      Complex sum;
      sum.real_part_ = this -> real_part_ + second_operand.real_part_;
      sum.imaginary_part_ = this -> imaginary_part_ + 
        second_operand.imaginary_part_;
      return sum;
    }

    // Subtracts the real and imaginary parts of the right operand from the
    // corresponding parts of the left operand (this).
    Complex substract(Complex right_operand) {
      Complex difference;
      difference.real_part_ = this -> real_part_ - right_operand.real_part_;
      difference.imaginary_part_ = this -> imaginary_part_ -
        right_operand.imaginary_part_;
      return difference;
    }

    // Returns a string representation of the complex number in the 
    // format (real_part, imaginary_part)
    string toString() {
      string complexString = "(" + to_string(real_part_) + "," + 
        to_string(imaginary_part_) + ")";
      return complexString;
    }

  // Private member variables for real and imaginary parts. Default value: 1
  private:
    int real_part_ {1};
    int imaginary_part_ {1};
};

// Prompts user for real and imaginary parts of a complex number and returns
// a Complex that represents the complex number.
Complex GetComplexFromUser() {
  int real_part, imaginary_part;
  char comma;  
  cout << 
    "Enter a Complex number with the real and imaginary parts separated by a " 
      << "comma: ";
  cin >> setw(1) >> real_part >> setw(1) >> comma >> setw(1) >> imaginary_part ;  
  return Complex(real_part, imaginary_part);
}

// Begins program execution
int main() {  
  Complex first = GetComplexFromUser();  // Get first complex number
  Complex second = GetComplexFromUser(); // Get second complex number

  Complex sum = first.add(second);  // Calculate sum
  Complex difference = first.substract(second); // Calculate difference

  // Print statement of the sum and difference of the complex numbers
  cout << "The sum of the two complex numbers is " << sum.toString() <<
    " and the difference is " << difference.toString() << endl;

  system("pause"); // Pause command window
  return 0;
}

