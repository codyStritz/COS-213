#include <iostream>
#include "bank.h"
using namespace std;

int main() {
  // Instantiate each type of account
  BankAccount bank_acct = BankAccount(100.00);
  Savings savings = Savings(5000.50, 3.75);
  Checking checking = Checking(650.25, 1.50);

  // Print initial balances
  cout << "Initial balances:" << endl;
  cout << "Bank account: " << bank_acct.getBalance() << endl;
  cout << "Savings: " << savings.getBalance() << endl;
  cout << "Checking: " << checking.getBalance() << endl << endl;

  // Debit (attempt) same amount from each account
  double debit_amt = 200.00;
  bank_acct.debit(debit_amt);
  savings.debit(debit_amt);
  checking.debit(debit_amt);

  // Print updated balances after debit
  cout << "Balances after debit 200.00:" << endl;
  cout << "Bank account: " << bank_acct.getBalance() << endl;
  cout << "Savings: " << savings.getBalance() << endl;
  cout << "Checking: " << checking.getBalance() << endl << endl;

  // Credit same amount to each account
  double credit_amt = 100.00;
  bank_acct.credit(credit_amt);
  savings.credit(credit_amt);
  checking.credit(credit_amt);
  
  // Print updated balances after credit
  cout << "Balances after credit 100.00:" << endl;
  cout << "Bank account: " << bank_acct.getBalance() << endl;
  cout << "Savings: " << savings.getBalance() << endl;
  cout << "Checking: " << checking.getBalance() << endl << endl;

  // Add savings interest to savings balance; print updated balance
  double savings_interest = savings.calculateInterest();
  cout << "Savings interest: " << savings_interest << endl;
  savings.credit(savings_interest);
  cout << "Savings after interest: " << savings.getBalance() << endl;
  system("pause");
  return 0;
}