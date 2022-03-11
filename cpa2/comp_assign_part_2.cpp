// Cody Stritz
// Comprehensive Programming Assignment
// Problem 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
using namespace std;

// Gets temperature in (F) from user and saves it to temp reference
void getTemp(int& temp) {
  cout << "Please enter the temperature (F): ";
  cin >> setw(3) >> temp;
}

void printActivity(int temp) {
  string activity = "No Activity - Sending Everyone Home";
  if (temp > 85) activity = "Swimming";
  // else if (temp )

}

int main()
{
  // TODO: Implement main()
  int temp;
  getTemp(temp);
  cout << temp << endl;
  return 0;
}
