/*
Cody Stritz
Written Assignment 1 - Exercise 2
2022FEB
C++ Programming
COS-213 */

// enables program to perform input and output
#include <iostream>
// enables program to use string objects
#include <string>
// enables program to use all the names in any standard C++ header 
using namespace std;

// function PrintNumberWord prototype
void PrintNumberWord(int number);

// function main begins program execution
int main() {
    int user_input; // variable declaration
    cout << "Enter a number in the range 1-5: "; // prompt user for input
    cin >> user_input; // read input into user_input
    PrintNumberWord(user_input); // call PrintNumberWord on user_input
    system("pause"); // pause command window
    return 0; // return 
}

// function prints the word equivalent for an int from 1-5
void PrintNumberWord(int number) {
    // display message according to value of number
    if (number == 1) {
        cout << "You entered the number one." << endl;
    }
    else if (number == 2) {
        cout << "You entered the number two." << endl;
    }
    else if (number == 3) {
        cout << "You entered the number three." << endl;
    }
    else if (number == 4) {
        cout << "You entered the number four." << endl;
    }
    else if (number == 5) {
        cout << "You entered the number five." << endl;
    }
    else {
        cout << "You entered an invalid number." << endl;
    }
    return; // return 
}