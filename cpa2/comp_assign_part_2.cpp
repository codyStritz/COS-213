// Cody Stritz
// Comprehensive Programming Assignment
// Problem 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
using namespace std;

// Gets temperature from user and stores input at temp reference
void getTemp(int& temp) {
  cout << "Please enter the temperature (F): ";
  cin >> setw(3) >> temp;
}

// Determines and prints activity based on temp
void printActivity(int temp) {
  string activity = "No Activity - Sending Everyone Home";  // temp <= 32
  if (temp > 85) activity = "Swimming";       // temp > 85
  else if (temp > 70) activity = "Baseball";  // 70 < temp <= 85
  else if (temp > 32) activity = "Basketball";  // 32 < temp <= 70
  printf("The temperature for today of %d is considered to be a good"
  " temperature for the following activity %s.\n", temp, activity.c_str());
}

// Begins program execution
int main()
{
  int temp;             // Declare temp variable
  getTemp(temp);        // Get temp from user
  printActivity(temp);  // Print activity based on temp
  system("pause");      // Pause command window
  return 0;
}
