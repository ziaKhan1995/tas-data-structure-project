#include "teachingAssistant.h"
#include "Time.h"
#include "DataStructuresStudent.h"


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

teachingAssistant::teachingAssistant(){
    name="";
    minute=0;
    for(int i=0;i<3;i++){
        startTimes[i]=endTimes[i]=0;
    }
    studentWithTA=NULL;
}
void teachingAssistant::setName(string name)
{this->name=name;}
//sets time, minutes 'val' after 12:00 
void teachingAssistant::setStart(int i, int val)
{startTimes[i]=Time(12,00)+((val>=0)?val:0);}
void teachingAssistant::setEnd(int i, int val)
{endTimes[i]=Time(12,00)+((val>=0)?val:0);}
void teachingAssistant::setStudent(DataStructuresStudent *std)
{studentWithTA=std;}
void teachingAssistant::setMinute(int minute)
{this->minute=(minute<=5)?minute:0;}
string teachingAssistant::getName()
{return name;}
 Time teachingAssistant::getEnd(int b)
 {return endTimes[b-1];}
 Time teachingAssistant::getStart(int b)
 {return startTimes[b-1];}
 DataStructuresStudent* teachingAssistant::getStudent()
 {return studentWithTA;}
 int teachingAssistant::getMinute()
 {return minute;}
 bool teachingAssistant::isChuti(int &day)
 {return startTimes[day-1]==endTimes[day-1];}

bool teachingAssistant:: isAvailable(int day,Time t)
{return (!isChuti(day)&&t<getEnd(day)&&t>=getStart(day));}
int teachingAssistant:: operator+(int time){
    return (minute+time);
}
void teachingAssistant:: operator+=(int time){
    setMinute(minute+time);
}
int teachingAssistant:: operator++(){
    operator+=(1);
    return minute;
}
void teachingAssistant:: operator=(int time){
    setMinute(time);
}
ostream& operator<<(ostream& a, teachingAssistant t){
     cout<<t.name<<" "<<t.startTimes[0]<<" "<<t.endTimes[0]<<" "<<t.startTimes[1]<<" "<<t.endTimes[1]<<" "<<t.startTimes[2]<<" "<<t.endTimes[2];
     return a;
}
ifstream& operator>>(ifstream& f, teachingAssistant& t) {
    f >> t.name;
    int start, end;
    for (int i = 0; i < 3; i++) {
        f >> start >> end;
        t.setStart(i, start);
        t.setEnd(i, end);
    }
    return f;
}