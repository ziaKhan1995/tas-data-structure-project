#pragma once
#include "Time.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DataStructuresStudent
{
    string firstName;
    string lastName;
    Time enterTime;
    int numQuestions;
    int numAwnsered;
    int laptopSerialNum;
  public:
    DataStructuresStudent();
    void setTime(int minute);
    void setQuestions(int n);
    void setAwnsered(int n);
    void setSerialNum(int serial);
    void setFirst(string first);
    void setLast(string last);
    Time getTime();
    int getQuestions();
    int getAwnsered();
    int getSerialNum();
    string getFirst();
    string getLast();
    string getName();
    float perc(); //gives percentage of awnsers
    bool isSatisfy();
    bool operator==(DataStructuresStudent&);
    int inc(){return ++numAwnsered;}
    friend ostream& operator<<(ostream& a, DataStructuresStudent s);
    friend ifstream& operator>>(ifstream&, DataStructuresStudent&);
};