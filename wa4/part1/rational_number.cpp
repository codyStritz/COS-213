#include "rational_number.h"
using namespace std;

// Constructor
RationalNumber::RationalNumber(int numerator, int denominator) {
  if (denominator == 0) denominator = 1;  // Avoid denominator of 0
  if (denominator < 0) {  // Swap neg from denominator to numerator
    denominator *= -1;
    numerator *= -1;
  }
  int gcd = getGCD(numerator, denominator); 
  this->numerator = numerator / gcd;      // simplify numerator
  this->denominator = denominator / gcd;  // simplify denominator
}

// Returns string representation of RationalNumber
string RationalNumber::toRationalString() const {
  string s = to_string(numerator) + "/" + to_string(denominator);
  return s;
}

// Returns RationalNumber as double
double RationalNumber::toDouble() const {
  return (double) numerator / (double) denominator;
}

// Overloaded Binary Arithmetic Operators
// addition
RationalNumber RationalNumber::operator+(RationalNumber& other) {
  int denom_lcm = getLCM(this->denominator, other.denominator);
  int this_num = this->numerator * denom_lcm / this->denominator;
  int other_num = other.numerator * denom_lcm / other.denominator;
  int num_sum = this_num + other_num;
  return RationalNumber(num_sum, denom_lcm);
}
// subtraction
RationalNumber RationalNumber::operator-(RationalNumber& other) {
  int denom_lcm = getLCM(this->denominator, other.denominator);
  int this_num = this->numerator * denom_lcm / this->denominator;
  int other_num = other.numerator * denom_lcm / other.denominator;
  int num_diff = this_num - other_num;
  return RationalNumber(num_diff, denom_lcm);
}
// multiplication
RationalNumber RationalNumber::operator*(RationalNumber& other) {
  int num_product = this->numerator * other.numerator;
  int denom_product = this->denominator * other.denominator;
  return RationalNumber(num_product, denom_product);
}
// division
RationalNumber RationalNumber::operator/(RationalNumber& other) {
  int num_quot = this->numerator * other.denominator;
  int denom_quot = this->denominator * other.numerator;
  return RationalNumber(num_quot, denom_quot);
}

// Overloaded Relational Operators
// less than
bool RationalNumber::operator<(RationalNumber& other) {
  return this->toDouble() < other.toDouble();
}
// greater than
bool RationalNumber::operator>(RationalNumber& other) {
  return this->toDouble() > other.toDouble();
}
// less than or equal to
bool RationalNumber::operator<=(RationalNumber& other) {
  return this->toDouble() <= other.toDouble();
}
// greater than or equal to
bool RationalNumber::operator>=(RationalNumber& other) {
  return this->toDouble() >= other.toDouble();
}

// Returns the GCD of two ints
int RationalNumber::getGCD(int a, int b) {
  if (b == 0) return a > -a ? a : -a; // always return positive
  return getGCD(b, a % b);  // recursive call
}

// Returns the LCM of two ints
int RationalNumber::getLCM(int a, int b) {
  return (a * b)/getGCD(a, b);
}