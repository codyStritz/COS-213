#include <iostream>
#include "alarm_clock.h"
using namespace std;

int main() {
  cout << "Alarm Clock Demo\n-----------" << endl;
  cout << "Using default constructor..." << endl;
  AlarmClock clock1;
  cout << "Clock initilized to: " << endl;
  clock1.ShowTime();
  clock1.SetAlarm(12,0,15,1);
  clock1.ShowAlarmTime();
  cout << "Press any key to run demo...";
  cin.get();
  clock1.Run();

  cout << "Press any key to continue..." << endl;
  cin.get();

  cout << "Using custom constructor..." << endl;
  AlarmClock clock2(11, 58, 55, 1);
  cout << "Clock initialized to:" << endl;
  clock2.ShowTime();
  clock2.SetAlarm(12, 0, 30, -1);
  clock2.ShowAlarmTime();
  cout << "Press any key to run demo...";
  cin.get();
  clock2.Run();

  cout << "Press any key to continue...";
  cin.get();
  return 0;
}