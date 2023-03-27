#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time{
    int hour; int minute;
    public:
    Time(){hour=minute=0;}
    Time(int hour, int minute);
    void setHour(int hour);
    void setMinute(int minute);
    int getHour();
    int getMinute();
    //to add minutes into current time
    Time operator-(Time t);
    Time operator+(int minute);
    void operator+=(int minute);
    Time operator++();
    //display on console, file
    friend ostream& operator<<(ostream&,Time);
    friend ofstream& operator<<(ofstream&, Time);
    //compare time
    bool operator!=(Time t);
    bool operator==(Time t);
    bool operator<(Time t);
    bool operator>(Time t);
    bool operator<=(Time t);
    bool operator>=(Time t);
    //assignment operator
    Time operator=(int a){
        hour=minute=0; return *this;
    }
};