// Cody Stritz
// Final - Part 2
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream>
#include "alarm_clock.h"
using namespace std;

int main() {
  cout << "Alarm Clock Demo\n-----------" << endl;
  cout << "Using default constructor..." << endl;
  AlarmClock clock1;  // default constructor -> 12:00:00 AM
  cout << "Clock initilized to: " << endl;
  clock1.ShowTime();
  clock1.SetAlarm(12,0,15,1); // alarm set for 12:00:15 AM
  clock1.ShowAlarmTime();
  cout << "Press any key to run demo...";
  cin.get();
  clock1.Run(); // run clock until alarm

  cout << "Press any key to continue..." << endl;
  cin.get();

  cout << "Using custom constructor..." << endl;
  AlarmClock clock2(11, 58, 55, 1);    // set clock to 11:58:55 AM
  cout << "Clock initialized to:" << endl;
  clock2.ShowTime();
  clock2.SetAlarm(12, 0, 30, -1);   // set alarm to 12:00:30: PM
  clock2.ShowAlarmTime();
  cout << "Press any key to run demo...";
  cin.get();
  clock2.Run(); // run clock until alarm

  cout << "Press any key to continue...";
  cin.get();
  return 0;
}