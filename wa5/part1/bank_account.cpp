#include <iostream>
#include "bank.h"
using namespace std;

// Constructor
// if given balance is less than 0.0, sets balance to 0.0
BankAccount::BankAccount(double balance) {
  if (balance < 0.0)  {
    cout << "Invalid balance input. Balance set to 0.0" << endl;
    this->balance_ = 0.0;
  } else {
    this->balance_ = balance;
  }
}

// Credits (deposits) amount to account balance
void BankAccount::credit(double amount) {
  this->balance_ += amount;
}

// Debits (withdraws) amount from account balance if sufficient funds available
// returns boolean based on whether debit was successful
bool BankAccount::debit(double amount) {
  if (amount > this->balance_) {
    cout << "The balance is less than the debit amount." << endl << endl;
    return false;
  } else {
    this->balance_ -= amount;
    return true;
  }
}

// Returns account balance
double BankAccount::getBalance() { return this->balance_; }