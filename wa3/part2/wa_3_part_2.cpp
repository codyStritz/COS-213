// Cody Stritz
// Written Assignment 2 - Exercise 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include <iomanip>
using namespace std;

// Savings account with a balance and annual interest rate.
class SavingsAccount {
  private:
    static double annualInterestRate_;  // Static annual interest rate.
    double savingsBalance_;  // Encapsulated balance

  public:
    SavingsAccount(double savingsBalance)   // Constructor
      : savingsBalance_(savingsBalance) {}

    // Calculates monthly interest based on interest rate and current balance
    double CalculateMonthlyInterest() {
      double interestDecimal = annualInterestRate_ / 100;
      double monthlyInterest =  savingsBalance_ * interestDecimal / 12;
      return monthlyInterest;
    }

    // Sets a new annual interest rate
    static void ModifyInterestRate(double annualInterestRate) {
      annualInterestRate_ = annualInterestRate;
    }

    // Returns savings balance
    double GetSavingsBalance() {
      return savingsBalance_;
    }

    // Adds given amount to savings balance
    void AddToSavings(double amount) {
      savingsBalance_ += amount;
    }
};

double SavingsAccount::annualInterestRate_{0.0}; // Initializer

// Returns a new SavingsAccount based on user input
SavingsAccount CreateSavingsAccount(int accountNumber) {
  double savingsBalance;
  cout << "Please enter the savings balance of account " << accountNumber << 
    ": ";
  cin >> savingsBalance;
  return SavingsAccount(savingsBalance);
}

// Changes the annual interest rate based on user input
void ChangeAnnualInterestRate() {
  double interestRate;
  cout << "Please enter the annual interest rate: ";
  cin >> interestRate;
  SavingsAccount::ModifyInterestRate(interestRate);
}

// Begins program execution
int main() {
  // Create two SavingsAccounts
  SavingsAccount accountOne = CreateSavingsAccount(1);
  SavingsAccount accountTwo = CreateSavingsAccount(2);
  double accountOneInterest, accountOneBalance;
  double accountTwoInterest, accountTwoBalance;

  // While loop to allow user to compare multiple interest rates
  char loop = 'Y';
  while (loop != 'N' && loop != 'n') { 
    if (loop != 'Y' && loop != 'y') {
      cout << "Invalid input." << endl; // User did not enter y/Y or n/N
    } else {
      ChangeAnnualInterestRate(); // User sets interest rate

      // Calculate monthly interest, balance for account one
      accountOneInterest = accountOne.CalculateMonthlyInterest();
      accountOneBalance = accountOne.GetSavingsBalance() + accountOneInterest;

      // Calculate monthly interest, balance for account two
      accountTwoInterest = accountTwo.CalculateMonthlyInterest();
      accountTwoBalance = accountTwo.GetSavingsBalance() + accountTwoInterest;

      // Print statements showing monthly interest, balance for each account
      printf("The interest for account 1 would be $%.2f and the balance after " 
      "one month would be %.2f \n", accountOneInterest, accountOneBalance);
      printf("The interest for account 2 would be $%.2f and the balance after " 
      "one month would be %.2f \n", accountTwoInterest, accountTwoBalance);
    }
    // Ask user if they would like to change the interest rate
    cout << "Would you like to change the interest rate? (Y or N): ";
    cin >> setw(1) >> loop;
  }
  // Add calculated interest at decided rate to each account
  accountOne.AddToSavings(accountOneInterest);
  accountTwo.AddToSavings(accountTwoInterest);
  cout << "Goodbye!" << endl;
  system("pause");  // Pause command window
  return 0;
}