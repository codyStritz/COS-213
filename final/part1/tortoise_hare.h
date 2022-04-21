#include <string>
using namespace std;

#ifndef CONTESTANT_H  // include guards
#define CONTESTANT_H

// Contestant interface
class Contestant {
  public:
    Contestant(string, string);
    int GetPosition();
    string GetName();
    string GetSymbol();
    void AdjustPosition(int);

  private:
    int position_ = 1;
    string name_;
    string symbol_;
};

// Tortoise interface
class Tortoise: public Contestant {
  public:
    Tortoise();
    void Move(int);
    void FastPlod();
    void SlowPlod();
    void Slip();
};

// Hare interface
class Hare: public Contestant {
  public:
    Hare();
    void Move(int);
    void Sleep();
    void BigHop();
    void BigSlip();
    void SmallHop();
    void SmallSlip();
};

#endif  // CONTESTANT_H