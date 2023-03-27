#pragma once
#include "Time.h"
#include "DataStructuresStudent.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class teachingAssistant
{
    string name; // only use first names for the TAs
    Time startTimes[3];
    Time endTimes[3];
    DataStructuresStudent *studentWithTA;
    int minute;
  public:
      teachingAssistant();
      void setName(string name);
      void setStart(int i, int val);
      void setEnd(int i, int val);
      void setStudent(DataStructuresStudent *std);
      void setMinute(int minute);
      string getName();
      //returns start,end by passing day num 'int'
      Time getEnd(int);
      Time getStart(int);
      DataStructuresStudent* getStudent();
      int getMinute();
      //chuti pe ya nhi on "int" day
      bool isChuti(int&);
      //us time TIME aur us din INT
      bool isAvailable(int,Time);
      //operators to assign value to minute
      int operator+(int time);
      void operator+=(int time);
      int operator++();
      void operator=(int time);
      friend ostream& operator<<(ostream& a, teachingAssistant t);
      friend ifstream& operator>>(ifstream&, teachingAssistant &);
};