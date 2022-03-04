/*
Cody Stritz
Written Assignment 1 - Exercise 1
2022FEB
C++ Programming
COS-213 */

// enables program to perform input and output
#include <iostream>
// enables program to use all the names in any standard C++ header 
using namespace std; 

// function larger prototype
double larger(double x, double y);

// function main begins program execution 
int main() {
    double max, num; // declare variables

    cout << "Enter 15 numbers\n"; // prompt user for input
    cin >> max; // read first double from user into max

    // loop 14 times
    for(int i = 0; i < 14; i++) {
        cin >> num; // read next double from user into num
        // call larger on max, num and assign return value to max
        max = larger(max, num); 
    }

    cout << "The largest number is " << max << endl; // display largest number message
    system("pause"); // pause command window
    return 0; // return
}

// function returns the larger of two doubles
double larger(double x, double y) {
    return (x > y) ? x : y; // if (x > y) return x, else return y
}