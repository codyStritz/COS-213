using namespace std;

#ifndef BANK_ACCOUNT_H    // include guards
#define BANK_ACCOUNT_H

// BankAccount interface
class BankAccount {
  public:
    BankAccount(double);
    virtual void credit(double);  // virtual
    virtual bool debit(double);   // virtual
    double getBalance();
  private:
    double balance_;
};

// Savings interface
class Savings: public BankAccount {
  public:
    Savings(double, double);
    virtual void credit(double) override; // override base class credit()
    double calculateInterest();
  private:
    double interest_rate_;
};

// Checking interface
class Checking: public BankAccount {
  public:
    Checking(double, double);
    virtual void credit(double) override; // override base class credit()
    virtual bool debit(double) override;  // override base class debit()
  private:
    double fee_;
};

#endif // BANK_ACCOUNT_H