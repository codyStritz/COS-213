#include "bank.h"

// Constructor
// takes initial balance and interest rate (as percentage)
Savings::Savings(double balance, double interest_rate)
  : BankAccount(balance), interest_rate_(interest_rate) {}

// Credits (deposits) the given amount + any earned interest
void Savings::credit(double amount) {
  BankAccount::credit(calculateInterest() + amount);
}

// Calculates and returns account interest
double Savings::calculateInterest() { 
  double interest_rate_dec = interest_rate_ / 100;  // percentage -> decimal
  return this->getBalance() * interest_rate_dec;
}