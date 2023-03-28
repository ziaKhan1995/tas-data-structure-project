#include "Time.h"

#include <iostream>

#include <fstream>

#include <string>

using namespace std;

Time::Time(int hour, int minute) {
  setHour(hour);
  setMinute(minute);
}

void Time::setHour(int hour) {
  this -> hour = (hour >= 0 && hour <= 24) ? hour : 0;
}
void Time::setMinute(int minute) {
  this -> minute = (minute < 60 && minute >= 0) ? minute : 0;
}
int Time::getHour() {
  return hour;
}
int Time::getMinute() {
  return minute;
}
Time Time::operator++() {
  * this = * this + 1;
  return ( * this);
}
void Time::operator += (int minute) {
  * this = * this + minute;
}
Time Time::operator - (Time t) {
  Time result;
  result.hour = hour - t.hour;
  result.minute = minute - t.minute;
  if (minute - t.minute < 0) {
    result.minute += 60;
    result.hour--;
  }
  return result;
}
Time Time::operator + (int minute) {
  Time result = * this;
  if (minute >= 0) {
    while (minute + result.minute >= 60) {
      if (result.hour >= 24) {
        result.hour -= 24;
        result.hour++;
      } else result.hour++;
      minute -= 60;
    }
    result.minute += minute;
    return result;
  } else return Time(0, 0);
}
bool Time::operator != (Time t) {
  return (t.hour != hour && t.minute != minute);
}
bool Time::operator == (Time t) {
  return (t.hour == hour && t.minute == minute);
}
bool Time::operator < (Time t) {
  return (hour < t.hour || (hour == t.hour && minute < t.minute));
}
bool Time::operator > (Time t) {
  return (hour > t.hour || (hour == t.hour && minute > t.minute));
}
bool Time::operator <= (Time t) {
  return (hour < t.hour || (hour == t.hour && minute <= t.minute));
}
bool Time::operator >= (Time t) {
  return (hour > t.hour || (hour == t.hour && minute >= t.minute));
}
ostream & operator << (ostream & s, Time t) {
  if (t.hour > 12) {
    if (t.hour - 12 < 10) {
      if (t.minute < 10)
        cout << "0" << t.hour - 12 << ":" << "0" << t.minute << " PM";
      else
        cout << "0" << t.hour - 12 << ":" << t.minute << " PM";
    } else {
      if (t.minute < 10)
        cout << t.hour - 12 << ":" << "0" << t.minute << " PM";
      else
        cout << t.hour - 12 << ":" << t.minute << " PM";
    }
  } else {
    if (t.hour < 10) {
      if (t.minute < 10)
        cout << "0" << t.hour << ":" << "0" << t.minute << " PM";
      else
        cout << "0" << t.hour << ":" << t.minute << " PM";
    } else {
      if (t.minute < 10)
        cout << t.hour << ":" << "0" << t.minute << " PM";
      else
        cout << t.hour << ":" << t.minute << " PM";
    }
  }
  return s;
}
ofstream & operator << (ofstream & f, Time t) {
  if (t.hour > 12) {
    if (t.hour - 12 < 10) {
      if (t.minute < 10)
        f << "0" << t.hour - 12 << ":" << "0" << t.minute << " PM";
      else
        f << "0" << t.hour - 12 << ":" << t.minute << " PM";
    } else {
      if (t.minute < 10)
        f << t.hour - 12 << ":" << "0" << t.minute << " PM";
      else
        f << t.hour - 12 << ":" << t.minute << " PM";
    }
  } else {
    if (t.hour < 10) {
      if (t.minute < 10)
        f << "0" << t.hour << ":" << "0" << t.minute << " PM";
      else
        f << "0" << t.hour << ":" << t.minute << " PM";
    } else {
      if (t.minute < 10)
        f << t.hour << ":" << "0" << t.minute << " PM";
      else
        f << t.hour << ":" << t.minute << " PM";
    }
  }
  return f;
}
