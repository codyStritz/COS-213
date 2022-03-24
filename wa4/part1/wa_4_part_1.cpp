#include <iostream>
#include <iomanip>
#include <string>
#include "rational_number.h"
using namespace std;


int main() {
  RationalNumber frac1 = RationalNumber(7,5);
  RationalNumber frac2 = RationalNumber(1,4);
  RationalNumber sum = frac1 + frac2;
  RationalNumber diff = frac1 - frac2;
  RationalNumber prod = frac1 * frac2;
  RationalNumber quot = frac1 / frac2;
  cout << "frac1 = " << frac1.toRationalString() << endl;
  cout << "frac1 double = " << frac1.toDouble() << endl;
  cout << "frac2 = " << frac2.toRationalString() << endl;
  cout << "frac2 double = " << frac2.toDouble() << endl;
  cout << "Sum = " << sum.toRationalString() << endl;
  cout << "Diff = " << diff.toRationalString() << endl;
  cout << "Prod = " << prod.toRationalString() << endl;
  cout << "Quot = " << quot.toRationalString() << endl;
  cout << "frac1 < frac2 = " << to_string(frac1<frac2) << endl;
  cout << "frac1 > frac2 = " << to_string(frac1>frac2) << endl;
  cout << "frac1 <= frac2 = " << to_string(frac1<=frac2) << endl;
  cout << "frac1 >= frac2 = " << to_string(frac1>=frac2) << endl;
  system("pause");
  return 0;
}
