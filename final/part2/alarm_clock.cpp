#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "alarm_clock.h"
using namespace std;

// Default Constructor
AlarmClock::AlarmClock() {
  this->hour_ = 12;
  this->min_ = 0;
  this->sec_ = 0;
  this->am_pm_ = 1;
}

// Custom Constructor
AlarmClock::AlarmClock(int hr, int min, int sec, int am_pm) {
  this->hour_ = hr > 0 && hr < 13 ? hr : 12;
  this->min_ = min >= 0 && min < 60 ? min : 0;
  this->sec_ = sec >= 0 && sec < 60 ? sec : 0;
  this->am_pm_ = am_pm == -1 ? am_pm : 1;
}

void AlarmClock::SetTime(int hr, int min, int sec, int am_pm) {
  bool valid_hr = hr > 0 && hr < 13;
  bool valid_min = min >= 0 && min < 60;
  bool valid_sec = sec >= 0 && sec < 60;
  bool valid_am_pm = am_pm == -1 || am_pm == 1;
  if (valid_hr && valid_min && valid_sec && valid_am_pm) {
    this->hour_ = hr;
    this->min_ = min;
    this->sec_ = sec;
    this->am_pm_ = am_pm;
  } 
  else {
    cout << "Invalid:" << endl;
    if (!valid_hr) cout << "hour" << endl;
    if (!valid_min) cout << "minutes" << endl;
    if (!valid_sec) cout << "seconds" << endl;
    if (!valid_am_pm) cout << "am/pm" << endl;
  }
}

void AlarmClock::SetAlarm(int hr, int min, int sec, int am_pm) {
  bool valid_hr = hr > 0 && hr < 13;
  bool valid_min = min >= 0 && min < 60;
  bool valid_sec = sec >= 0 && sec < 60;
  bool valid_am_pm = am_pm == -1 || am_pm == 1;
  if (valid_hr && valid_min && valid_sec && valid_am_pm) {
    this->al_hour_ = hr;
    this->al_min_ = min;
    this->al_sec_ = sec;
    this->al_am_pm_ = am_pm;
    this->al_set_ = true;
  }
  else {
    cout << "Invalid:" << endl;
    if (!valid_hr) cout << "hour" << endl;
    if (!valid_min) cout << "minutes" << endl;
    if (!valid_sec) cout << "seconds" << endl;
    if (!valid_am_pm) cout << "am/pm" << endl;
  }
}

bool AlarmClock::IsAlarmTriggered() {
  bool same_hour = hour_ == al_hour_;
  bool same_min = min_ == al_min_;
  bool same_sec = sec_ == al_sec_;
  return same_hour && same_min && same_sec;
}

void AlarmClock::DismissAlarm() {
  this->al_set_ = false;
}

void AlarmClock::Tick() {
  if (sec_ < 59) sec_++;
  else {
    sec_ = 0;
    if (min_ < 59) min_++;
    else {
      min_ = 0;
      if (hour_ < 12)  {
        hour_++;
        if (hour_ == 12) am_pm_ *= -1;
      }
      else {
        hour_ = 0;
      }
    }
  }
}

void AlarmClock::ShowTime() {
  cout << setfill('0') << setw(2) << hour_;
  cout << ":" << setfill('0') << setw(2) << min_;
  cout << ":" << setfill('0') << setw(2) << sec_;
  if (am_pm_ == 1) cout << " AM" << endl;
  else if (am_pm_ == -1) cout << " PM" << endl;
}

void AlarmClock::ShowAlarmTime() {
  if (!al_set_) cout << "No Alarm Set" << endl;
  else {
    cout << "Alarm set for: " << endl;
    cout << setfill('0') << setw(2) << al_hour_;
    cout << ":" << setfill('0') << setw(2) << al_min_;
    cout << ":" << setfill('0') << setw(2) << al_sec_;
    if (al_am_pm_ == 1) cout << " AM" << endl;
    else if (al_am_pm_ == -1) cout << " PM" << endl;
  }
}

void AlarmClock::Run() {
  while(true) {
    if (IsAlarmTriggered()) {
      cout << "WAKE UP" << endl;
      break;
    } 
    else {
      ShowTime();
      this_thread::sleep_for(chrono::seconds(1));
      Tick();
    }
  }
}