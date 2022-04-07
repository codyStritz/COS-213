#include <iostream>
#include "bank.h"
using namespace std;

// Constructor
Checking::Checking(double balance, double fee)
  : BankAccount(balance), fee_(fee) {}

// Credits (deposits) amount to balance if the transaction fee can be paid
void Checking::credit(double amount) {
  if(BankAccount::debit(fee_)) BankAccount::credit(amount); // balance pays fee
  else {
    if (amount >= fee_) BankAccount::credit(amount - fee_); // deposit pays fee
    else cout << "Insufficient funds." << endl << endl;
  }
}

// Debits (withdraws) amount from balance if the transaction fee can be paid
bool Checking::debit(double amount) {
  return BankAccount::debit(amount + fee_);  // only charge fee if debit is successful
}