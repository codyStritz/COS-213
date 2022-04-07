// Cody Stritz
// Written Assignment 5 - Exercise 1
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <vector>
#include "bank.h"
using namespace std;

int main() {
  // Instantiate some accounts
  Savings savings_1{5000.50, 3.75};
  Savings savings_2{1005.75, 3.20};
  Checking checking_1{650.25, 1.50};
  Checking checking_2{1210.49, 1.25};

  // Debit/credit amount variables
  double debit_amt = 0.0;
  double credit_amt = 0.0;

  // Create/initialize vector 
  vector<BankAccount *> accounts{&savings_1, &checking_1, &savings_2, 
    &checking_2};

  // Process each of the accounts using dynamic binding
  for (BankAccount* accountPtr : accounts) {
    cout << "Original Account Balance: " << accountPtr->getBalance() << endl;
    cout << "Enter debit amount: ";
    cin >> debit_amt;
    cout << "Enter credit amount: ";
    cin >> credit_amt;
    accountPtr->credit(credit_amt);
    accountPtr->debit(debit_amt);
    cout << "New Account Balance: " << accountPtr->getBalance() << endl << endl;
  }

  system("pause");
  return 0;
}