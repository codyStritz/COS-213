// Cody Stritz
// Written Assignment 2 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
#include <array>
using namespace std;

// Returns the first (alphabetical) letter of the two provided
// based on ASCII value
char FirstLetter (char x, char y) {
  return x < y ? x : y;
}

// Begins program execution
int main()
{
  char first = 'z';   // Keeps track of current first letter
  char input;

  for (int i = 0; i < 10; i++) {    // Loop 10 times
    if (i == 0) {
      cout << "Please enter the first letter: ";  // Prompt user for input
    } else {
      cout << "Please enter the next letter: ";
    }
    cin >> setw(1) >> input;    // Get user input
    // Check that input is alphabetical
    bool too_low = input < 'a';
    bool too_high = input > 'z';
    if (too_low || too_high) {
      cout << "Invalid input. Please enter lowercase letters only." << endl;
      i--;
      continue;
    }
    // Find first letter between first and input; update first
    first = FirstLetter(first, input);
  }
  // Print first letter and ASCII code
  cout << "First letter: " << first << endl;
  cout << "ASCII value (decimal) of " << first << " is " << int(first) << endl;
  system("pause");  // Pause command window
  return 0;
}
