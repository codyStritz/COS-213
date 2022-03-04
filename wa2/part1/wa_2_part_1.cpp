// Cody Stritz
// Written Assignment 2 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
#include <array>
using namespace std;

const size_t arraySize{20}; // Constant for array size
using IntArray = array<int, arraySize>; // Type alias for array

// Initializes third array to the sums of first and second arrays' elements
void InitializeThirdArray(const IntArray& first_array, 
                          const IntArray& second_array, 
                          IntArray& third_array) {
  for (size_t i{0}; i < arraySize; i++) {
    third_array[i] = first_array[i] + second_array[i];
  }
}

// Prints summary showing elements of first and second array
// and the sums of their elements in third array
void PrintSummary(const IntArray& first_array, const IntArray& second_array, 
                      const IntArray& third_array) {
  cout << "Array 1" << setw(5) << "+" << setw(11) << "Array 2" 
    << setw(5) << "=" << setw(11) << "Array 3" << endl;

  for (size_t i{0}; i < arraySize; i++) {
    cout << setw(7) << first_array[i] << setw(5) << "+"
      << setw(11) << second_array[i] << setw(5) << "="
      << setw(11) << third_array[i] << endl;
  }
}

// Begins program execution
int main() {
  // Declare three arrays
  IntArray first_array;
  IntArray second_array;
  IntArray third_array;

  // Initialize the first and second array
  for (size_t i{0}; i < arraySize; i++) {
    first_array[i] = (i+1) * 5; 
    second_array[i] = i + 1; 
  } 

  // Initialize the third array
  InitializeThirdArray(first_array, second_array, third_array);
  // Print results
  PrintSummary(first_array, second_array, third_array);
  system("pause"); // Pause command window
  return 0; 
}