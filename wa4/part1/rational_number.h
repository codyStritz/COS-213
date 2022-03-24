#include <string>
using namespace std;
// Prevent multiple inclusions of header
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

// RationalNumber interface
class RationalNumber {
  public:
    explicit RationalNumber(int = 1, int = 1); // default constructor
    string toRationalString() const;
    double toDouble() const;
    RationalNumber operator+(RationalNumber& other);
    RationalNumber operator-(RationalNumber& other);
    RationalNumber operator*(RationalNumber& other);
    RationalNumber operator/(RationalNumber& other);
    bool operator<(RationalNumber& other);
    bool operator>(RationalNumber& other);
    bool operator<=(RationalNumber& other);
    bool operator>=(RationalNumber& other);

  private:
    int numerator;
    int denominator;
    int getGCD(int, int);
    int getLCM(int, int);
};


#endif //RATIONAL_NUMBER_H