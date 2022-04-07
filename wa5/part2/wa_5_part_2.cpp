#include <iostream>
#include <iomanip>
#include <string>
#include "Array.h"
using namespace std;

int main() {
  Array<int> integer_array;       // int Array
  Array<string> string_array{5};  // string Array

  cout << "Enter 10 integers: ";  // get integers
  cin >> integer_array;

  // print int Array
  cout << "Integer array contains: " << integer_array << endl;  

  cout << "Enter 5 strings: ";  // get strings
  cin >> string_array;

  // print string Array
  cout << "String array contains: " << string_array << endl;

  system("pause");
  return 0;
}

