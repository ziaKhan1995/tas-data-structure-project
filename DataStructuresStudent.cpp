#include "DataStructuresStudent.h"
#include "Time.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

DataStructuresStudent::DataStructuresStudent(){
    enterTime = 0;
numQuestions=numAwnsered=laptopSerialNum=0;
    firstName=lastName=" ";
}
void DataStructuresStudent::setTime(int minute)
{enterTime=Time(12,00)+((minute>=0)?minute:0);}
void DataStructuresStudent::setQuestions(int n)
{numQuestions=(n>=0)?n:0;}
void DataStructuresStudent::setAwnsered(int n)
{numAwnsered=(n>=0)?n:0;}
void DataStructuresStudent::setSerialNum(int serial)
{laptopSerialNum=(serial>=0)?serial:0;}
void DataStructuresStudent::setFirst(string first)
{firstName=(first.length()<=20)?first:"";}
void DataStructuresStudent::setLast(string last)
{lastName=(last.length()<=20)?last:"";}
Time DataStructuresStudent::getTime()
{return enterTime;}
int DataStructuresStudent::getQuestions()
{return numQuestions;}
int DataStructuresStudent::getAwnsered()
{return numAwnsered;}
int DataStructuresStudent::getSerialNum()
{return laptopSerialNum;}
string DataStructuresStudent::getFirst()
{return firstName;}
string DataStructuresStudent::getLast()
{return lastName;}
string DataStructuresStudent::getName()
{return firstName+" "+lastName;}
bool DataStructuresStudent::isSatisfy()
{return numAwnsered==numQuestions;}
float DataStructuresStudent::perc(){
       return ((float)numAwnsered/(float)numQuestions);
}
bool DataStructuresStudent::operator==(DataStructuresStudent& d){
    return(getName()==d.getName())&&(d.laptopSerialNum==laptopSerialNum)&&(numAwnsered==d.numAwnsered)&&(numQuestions==d.numQuestions)&&(enterTime==d.enterTime);
}
ostream& operator<<(ostream& a, DataStructuresStudent s){
    cout<<s.enterTime<<" "<<s.getName()<<" "<<s.numQuestions;
    return a;
}
ifstream& operator>>(ifstream& f, DataStructuresStudent& s) {
    int a;
    f >> a; s.setTime(a);
    f >> s.firstName >> s.lastName;
    f >> a; s.setQuestions(a);
    return f;
}