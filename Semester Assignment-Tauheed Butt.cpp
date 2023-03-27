#include "Time.h"
#include "Queue.h"
#include "Stack.h"
#include "DataStructuresStudent.h"
#include "teachingAssistant.h"

//have to do this cuz mobile dont support project mode
/*
#include "Stack.cpp"
#include "Time.cpp"
#include "DataStructuresStudent.cpp"
#include "teachingAssistant.cpp"
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


//push elements onto stack from file
Stack readLaptop(ifstream& f);
//sort TAs alphabetically
void sort(teachingAssistant*, int);
//msg writing functions
void writeProg(ofstream&, int&);
void writeDay(ofstream&, int&);
void TAstarted(ofstream&, teachingAssistant&, Time&, int&);
void TAended(ofstream&, teachingAssistant&, Time&, Time, int&);
void Review(ofstream&, Time, int, int, int);
void getHelp(ofstream&, teachingAssistant&, Time&);
//tells when LAB starts and ENDs according to TA timing
Time closing(teachingAssistant*, int, int);
Time starting(teachingAssistant*, int, int);

int main() {
	//read Laptop serial nums and add them in Laptop stack
	ifstream in("input.txt");
	ofstream out("output.txt", ios::trunc);
	Stack Laptop;
	Laptop = readLaptop(in);
	//read TAs and create a dynamic array
	int t; in >> t;
	teachingAssistant* TAs = new teachingAssistant[t];
	for (int i = 0; i < t; i++) { in >> TAs[i]; }
	sort(TAs, t);
	//read number of programs        
	int programs; in >> programs;
	for (int i = 1; i <= programs; i++) {
		writeProg(out, i);
		for (int day = 1; day <= 3; day++) {
			writeDay(out, day);
			Time waqt(12, 00);
			//num of std happy in a day
			int happy = 0;
			int track = 0, track2 = 0;
			int TAtoLDM = 0;
			//dont take students in ta after closing time
			bool noMore = false;
			//read students and add them in Door queue
			int numOfStds; in >> numOfStds;
			Queue Door;
			Queue LDM;
			Queue TA;
			bool stds = true;
			if (numOfStds > 300)
			{
				cout << "Too Many!/n"; stds = false;
			}
			else {
				for (int k = 0; k < numOfStds; k++) {
					DataStructuresStudent* temp = new DataStructuresStudent;
					in >> *temp;
					if (stds) Door.enqueue(temp);
				}
			}
			//check if lab is open
			//2 conditions. either no TA available,
			Time close = closing(TAs, t, day);
			Time start = starting(TAs, t, day);
			//or time is not 12
			//if lab open, start waqt looo
			if (waqt <= close) {
				//if open, enque in LDM queue,time same only change.  
				for (; waqt <= Time(20, 00) && waqt <= close; ++waqt) {
					for (int x = 0; x < t; x++)
					{
						TAstarted(out, TAs[x], waqt, day);
					}
					if (!noMore) {
						while (!Door.isEmpty() && waqt == Door.peek()->getTime())
						{
							out << waqt << ": " << Door.peek()->getName() << " has arrived in Arsalan\n";
							LDM.enqueue(Door.dequeue());
						}
					}
					//if student satisfy
					 //push laptop, dequeue them out
				 //if student unsatisfy
					 //pop laptop, deque them to TA queue
					if (noMore) {
						DataStructuresStudent* temp;
						while (!TA.isEmpty())
						{
							LDM.enqueue(TA.dequeue());
						}
						if (!LDM.isEmpty()) {
							if (LDM.peek()->getSerialNum() == 0) {
								temp = LDM.dequeue();
								out << waqt << ": " << temp->getName() << " never even got a laptop and went home FRUSTRATED.\n";
							}
							temp = LDM.dequeue();
							Laptop.push(temp->getSerialNum());
							temp->setSerialNum(0);
							if (temp->perc() >= 0.75) {
								out << waqt << ": " << temp->getName() << " has returned laptop " << Laptop.Top() << " and went home HAPPY.\n";
								happy++;
							}
							else {
								out << waqt << ": " << temp->getName() << " has returned laptop " << Laptop.Top() << " and went home FRUSTRATED.\n";
							}
						}//ldm empty check
					}//if ta not taking anymore students
					else if (!LDM.isEmpty()) {
						DataStructuresStudent* temp;
						if (LDM.peek()->isSatisfy()) {
							if (track2 == 1) {
								temp = LDM.dequeue();
								Laptop.push(temp->getSerialNum());
								temp->setSerialNum(0);
								if (temp->isSatisfy()) {
									out << waqt << ": " << temp->getName() << " has returned laptop " << Laptop.Top() << " and went home HAPPY.\n";
									happy++;
								}
								if (TAtoLDM >= 1)
								{
									track2 = 1; TAtoLDM--;
								}
								else track2 = 0;
								if (!LDM.isEmpty()) { track = 1; }
								else track = 0;
							}
							else track2++;
						}
						else {
							if (!Laptop.isEmpty()) {
								if (track == 2) {
									if (LDM.count() > 1)track = 2;
									else 
										track = 0;
									temp = LDM.dequeue();
									temp->setSerialNum(Laptop.pop());
									out << waqt << ": " << temp->getName() << " has borrowed Laptop "
										<< temp->getSerialNum() << " and moved to the TA Line\n";
									TA.enqueue(temp);
								}
								else track++;
							}//check for empty Laptop
						}
					}//check for empty LDM
					//handling students with TA
					for (int m = 0; m < t; m++) {
						//if ta available at that time and day
						if (TAs[m].isAvailable(day, waqt)) {
							//give student if he is free
							if (TAs[m].getStudent() == NULL) {
								if (!TA.isEmpty()) {
									TAs[m].setStudent(TA.dequeue());
								ta1:
									getHelp(out, TAs[m], waqt);
									TAs[m] = 0;
								}
							}
							//take student from him minute>5
							else if (TAs[m].getMinute() == 4) {
								TAs[m].getStudent()->inc();
								TAs[m] = 0;
								//std happy? send to ldm
								if (TAs[m].getStudent()->isSatisfy()) {
									out << waqt << ": " << TAs[m].getStudent()->getName() << " has no more questions and will now return the laptop\n";
									LDM.enqueue(TAs[m].getStudent());
									if (LDM.count() > 1) {
										track2 = 1;
										TAtoLDM++;
									}
									TAs[m].setStudent(NULL);
									//dont waste time, ta handle student
									if (!TA.isEmpty()) {
										TAs[m].setStudent(TA.dequeue());
										getHelp(out, TAs[m], waqt);
									}
								}//is satisfy end
								else {
									//std not happy? send to TA queu
									out << waqt << ": " << TAs[m].getStudent()->getName() << " has had one question answered and gotten back in line.\n";
									if (TA.isEmpty()) { goto ta1; }
									else {
										//dont waste time, ta handle student
										TA.enqueue(TAs[m].getStudent());
										TAs[m].setStudent(TA.dequeue());
										getHelp(out, TAs[m], waqt);
										TAs[m] = 0;
									}
								}//not satisfy end                        
							}

							else { ++TAs[m]; }
						}//Ta available or nah
						else {//TA leaving,take student from him
							// if closing time equal to leaving time dont take anymore studnt in lab. bool noMore is used here
							// display TA leaving
							TAended(out, TAs[m], waqt, closing(TAs, t, day), day);
							if (waqt == close) {
								noMore = true;
								if (TAs[m].getStudent() != NULL) {
									track = 0;
									if (TAs[m].getMinute() == 4) {
										TAs[m].getStudent()->inc();
										if (TAs[m].getStudent()->isSatisfy())
										{
											out << waqt << ": " << TAs[m].getStudent()->getName() << " has no more questions and will now return the laptop\n";
											LDM.enqueue(TAs[m].getStudent());
											TAs[m].setStudent(NULL);
										}
										else {
											out << waqt << ": " << TAs[m].getStudent()->getName() << " has had one question answered but must return the laptop now and exit the lab.\n";
											TA.enqueue(TAs[m].getStudent());
											TAs[m].setStudent(NULL);
										}
										TAs[m] = 0;
										break;
									}
									else {
										++TAs[m];
										++close;
									}
								}//if he has student
							}//if leave time same as closing time
							else {
								//if ta leave before closing time
								if (TAs[m].getStudent() != NULL) {
									if (TAs[m].getMinute() == 4) {
										TAs[m].getStudent()->inc();
										if (TAs[m].getStudent()->isSatisfy())
										{
											out << waqt << ": " << TAs[m].getStudent()->getName() << " has no more questions and will now return the laptop\n";
											LDM.enqueue(TAs[m].getStudent());
											TAs[m].setStudent(NULL);
										}
										else {
											out << waqt << ": " << TAs[m].getStudent()->getName() << " has had one question answered and gotten back in line.\n";
											TA.enqueue(TAs[m].getStudent());
											TAs[m].setStudent(NULL);
										}
										TAs[m] = 0;
									}
									else {
										++TAs[m];
									}
								}//if he got student
							}//if ta leave before closing time

						}//ta leaving ends
					}//TAs loop ends
				}//waqt ends

				//empty the lab
				while (!TA.isEmpty())
					LDM.enqueue(TA.dequeue());
				bool flag = true;
				if (LDM.count() == 1) { ++waqt; flag = false; }
				while (!LDM.isEmpty()) {
					DataStructuresStudent* temp = LDM.dequeue();
					if (temp->getSerialNum() != 0)
					{
						Laptop.push(temp->getSerialNum());
						temp->setSerialNum(0);
						if (temp->perc() >= 0.75) {
							out << waqt << ": " << temp->getName() << " has returned laptop " << Laptop.Top() << " and went home HAPPY.\n";
							happy++;
						}
						else {
							out << waqt << ": " << temp->getName() << " has returned laptop " << Laptop.Top() << " and went home FRUSTRATED.\n";
						}
					}
					if (flag && !LDM.isEmpty()) ++waqt;
				}
				//lab empty now
				cout << waqt << endl;
			}//lab check finish
			else {
				//else display close msg
				cout << "Lab Band\n";
			}
			//summary 
			Review(out, waqt - start, happy, numOfStds, day);
		}//days finish
	}// programs finish
	out.close(); in.close();
	delete[] TAs;
}//int main ends

//global functions

Stack readLaptop(ifstream& f) {
	Stack result;
	int size; 
	f >> size;
	for (int i = 0, a; i < size; i++) {
		f >> a;
		result.push(a);
	}
	return result;
}
void sort(teachingAssistant* ta, int size) {
	teachingAssistant temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ta[i].getName() < ta[j].getName()) {
				temp = ta[i];
				ta[i] = ta[j];
				ta[j] = temp;
			}
		}
	}
}
void writeProg(ofstream& f, int& prog) {
	f << "************\n";
	f << "Program " << prog << ":\n";
	f << "************\n\n";
}
void writeDay(ofstream& f, int& day) {
	f << "Day: ";
	if (day == 1) f << "Monday\n\n";
	else if (day == 2) f << "Tuesday\n\n";
	else if (day == 3) f << "Wednesday\n\n";
}
void TAstarted(ofstream& f, teachingAssistant& TA, Time& t, int& day)
{
	if (TA.isAvailable(day, t)) {
		if (t == TA.getStart(day))
			f << t << ": " << TA.getName() << " has begun Lab Hours\n";
	}
}
void TAended(ofstream& f, teachingAssistant& TA, Time& t, Time close, int& day) {
	if (!TA.isChuti(day)) {
		if (t == TA.getEnd(day)) {
			f << t << ": " << TA.getName() << " has finished Lab Hours\n";
			if (t == close)
				f << t << ": There are no TAs on duty. Arsalan is now closed.\n";
		}
	}
}
void getHelp(ofstream& f, teachingAssistant& TA, Time& t) {
	f << t << ": " << TA.getStudent()->getName() << " is getting help from " 
		<< TA.getName() << endl;
}
Time closing(teachingAssistant* TAs, int t, int day) {
	Time* temp = new Time[t];
	for (int i = 0; i < t; i++) {
		temp[i] = TAs[i].getEnd(day);
	}
	Time max = temp[0];
	for (int i = 0; i < t; i++) {
		if (temp[i] > max)
			max = temp[i];
	}
	delete[] temp;
	return max;
}
Time starting(teachingAssistant* TAs, int t, int day) {
	Time* temp = new Time[t];
	for (int i = 0; i < t; i++) {
		temp[i] = TAs[i].getStart(day);
	}
	Time min = temp[0];
	for (int i = 0; i < t; i++) {
		if (temp[i] < min)
			min = temp[i];
	}
	delete[] temp;
	return min;
}

void Review(ofstream& f, Time t, int happy, int stds, int day) {
	f << "\n";
	if (day == 1)
		f << "MONDAY's Lab Summary:\n";
	else if (day == 2)
		f << "TUESDAY's' Lab Summary:\n";
	else if (day == 3)
		f << "WednesDAY's Lab Summary:\n";
	f << "The TA Lab was open for " << t.getHour() << " hours and " << t.getMinute() << " minutes. ";
	f << stds << " students visited the lab.\n";
	f << "Out of those students, only " << happy << " left happy.\nremaining left frustrated.\n\nLesson Learned:  Do not procrastinate!  Start programs early!\n\n";

}
