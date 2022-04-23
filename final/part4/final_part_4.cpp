// Cody Stritz
// Final - Part 4
// 2022FEB
// C++ Programming
// COS-213 

#include<iostream>
using namespace std;

// Template that swaps the values of the two arguments
template <class T>
void Swap(T&a,T&b) {
  T temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a = 2, b = 8;  
  long c = 300, d = 6000;

  // print initial values of ints
  cout << "Initial int values:" << endl;
  cout << "a = " << a << " and b = " << b << endl;

  Swap(a,b);  // swap ints

  // print swapped values of ints
  cout << "After calling Swap(a,b):" << endl;
  cout << "a = " << a << " and b = " << b << endl << endl;
  
  // print initial values of longs
  cout << "Initial long values:" << endl;
  cout << "c = " << c << " and d = " << d << endl;

  Swap(c,d);  // swap longs

  // print swapped values of longs
  cout << "After calling Swap(c,d):" << endl;
  cout << "c = " << c << " and d = " << d << endl << endl;

  system("pause");
  return 0;
}