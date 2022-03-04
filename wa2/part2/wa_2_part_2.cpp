// Cody Stritz
// Written Assignment 2 - Exercise 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <iomanip>
using namespace std;

// Gets numerical score from user, saves it, and prints it
void getScore(int& score) {
  cout << "Enter numerical score: ";
  cin >> score;
  cout << score << " = ";
}

// Prints the letter grade based on numerical score
void printGrade(int score) {
  char grade;

  if(score > 100 || score < 0) {  // Check for invalid score
    cout << "Invalid score" << endl;
  } else {
    switch(score / 10) {
      case 10:
      case 9:
        grade = 'A';
        break;
      case 8:
        grade = 'B';
        break;
      case 7:
        grade = 'C';
        break;
      case 6:
        grade = 'D';
        break;
      default:
        grade = 'F';
        break;
    }
    cout << "Grade " << grade << endl;
  }
}

// Begins program execution
int main() {
  int score; // Declare score variable 
  getScore(score);  // Get score from user
  printGrade(score);  // Print letter grade for score
  system("pause");  // Pause command window
  return 0;
}