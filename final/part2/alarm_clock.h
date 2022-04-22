#ifndef ALARM_CLOCK_H   // include guards
#define ALARM_CLOCK_H


// Alarm clock interface
class AlarmClock {
  public:
    AlarmClock();
    AlarmClock(int, int, int, int);
    void SetTime(int, int, int, int);
    void SetAlarm(int, int, int, int);
    bool IsAlarmTriggered();
    void DismissAlarm();
    void Tick();
    void ShowTime();
    void ShowAlarmTime();
    void Run();

  private:
    int hour_;
    int min_;
    int sec_;
    int am_pm_;
    int al_hour_;
    int al_min_;
    int al_sec_;
    int al_am_pm_;
    bool al_set_ = false;
};


#endif ALARM_CLOCK_H