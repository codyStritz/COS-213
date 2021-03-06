using namespace std;

#ifndef BANK_ACCOUNT_H    // include guards
#define BANK_ACCOUNT_H

// BankAccount interface
class BankAccount {
  public:
    BankAccount(double);
    virtual void credit(double);
    virtual bool debit(double);
    double getBalance();
  private:
    double balance_;
};

// Savings interface
class Savings: public BankAccount {
  public:
    Savings(double, double);
    virtual void credit(double) override;
    double calculateInterest();
  private:
    double interest_rate_;
};

// Checking interface
class Checking: public BankAccount {
  public:
    Checking(double, double);
    virtual void credit(double) override;
    virtual bool debit(double) override; 
  private:
    double fee_;
};

#endif // BANK_ACCOUNT_H