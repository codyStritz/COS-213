// Cody Stritz
// Written Assignment 2 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
#include <array>
using namespace std;

char FirstLetter (char x, char y) {
  return x < y ? x : y;
}

int main()
{
  char first = 'z';
  char input;
  for (int i = 0; i < 10; i++) {
    //TODO: if user input invalid do i-- and break
    if (i == 0) {
      cout << "Please enter the first letter: ";
    } else {
      cout << "Please enter the next letter: ";
    }
    cin >> setw(1) >> input;
    // Check that input is alphabetical
    bool too_low = input < 'a';
    bool too_high = input > 'z';
    if (too_low || too_high) {
      cout << "Invalid input. Please enter lowercase letters only." << endl;
      i--;
      continue;
    }
    first = FirstLetter(first, input);
  }
  // Todo: add ASCII code
  cout << "First letter: " << first << endl;
  cout << "ASCII value (decimal) of " << first << " is " << int(first) << endl;
  system("pause");
  return 0;
}
