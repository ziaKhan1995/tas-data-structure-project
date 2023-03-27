# TAs-data-structure-project


# Data Structures & Algorithms Lab 
TA Data Structures Problem 
## The Problem: 
 
Department of Computer Science students, although awesome, are major procrastinators!!!   You give them two weeks for an assignment, and, inevitably, they wait till two or three days before the due  date  to  actually  start  working  on  it, and  that’s  for  the  average  CS students. But then there are those that just really love punishment and wait until the actual due date to begin coding. Invariably, and as with all programming students (even those that start early), these students run into obstacles in their understanding of the assignment, the requirements, the way to code, the syntax, and they end up having a plethora of questions. 
 
So, what happens: the Department, has assigned some TA’s for DS lab and they sit in the TA’s Lab assigned for TA’s by the Department, several TAs have been sitting idle, checking email and Facebook for a week and a half, finally gets busy.  The Monday before due date, a lot of students show up. Tuesday comes, and the number of students wanting help more than doubles. Wednesday...?  Well, Wednesday is just stupid! SOOO many students come, wanting help, and unfortunately, not all receive the help they require because of the overwhelmingly large number of students. 
 
## The Problem:   
with such a congestion of students, the TAs have no way of knowing who was first, who should come next,  etc.    And to get help, you basically need  to  be  an extrovert, willing to  chase  down  one  of  the  TAs  and  drag  them  to  your  desk  for  help. What if you’re a shy student?  There’s a  good chance you may not receive help. 
 
## The solution to this problem is rather trivial:   
any student who has a question MUST stand in LINE to ask a question from the TA.   To be fair and to prevent one student from monopolizing a TA’s time,  if  a  student  has  several  questions,  they  can  only  ask  one question at a time.   After they ask their first question, if they have subsequent questions, they must go to the back of the line and again wait for their turn.  For the purposes of this assignment, we assume that each question takes exactly 5 minutes to answer, which we will refer to as one Q/A session between a student and TA. 
 
Additionally, for the purpose of streamlining the lab, facilitating the procurement of help, and eliminating extraneous problems related to different compilers, coding bugs and suspicious errors, etc., the UNIVERISTY TA Lab (aka the “the Cave”) comes equipped with a Laptop  Dispensing  Minion  (LDM). The students will issue the laptops from the LDM and will use them for their work until the closing hours when they will have to deposit them back to LDM. 
These state-of-the-art (well at  least  for  2020)  laptops  are  sporting  Microsoft  Windows 10, several software’s along with Microsoft Visual Studio 2019 and the current version of DEV-C++ and a fully functional and updated Kaspersky’s Antivirus. 
 
Before a student can stand in the TA line and get help from a TA, each student must first stand in  the    laptop  line  to  take/issue a  laptop  from  the  LDM.    When  a  student  has finished asking all of their questions, or when the TAs are no longer in the lab (because they have left for the day), the student must then enter the laptop line to return the laptop to the LDM, BEFORE they can exit the lab. 
 
We assume that  the process of issuing a laptop takes one minute, and the process  of returning  a  laptop  also  takes  one  minute.    We  also  assume  (and  rightly  so!)  that  all  UNIVERISTY, students are honest and would never, ever, ever take one of these rock-star laptops with them. Therefore, for the purpose of this simulation, all students who take a laptop do indeed return the laptops. 
 
Your Assignment is to write a simulation that models the aforementioned lab specifications for the three days (Monday, Tuesday, and Wednesday) before an assignment is due.  Your three-day simulation will run p times, where p is the number of programs in the semester. 
 
You will need to implement this as follows: 
 
## Students: 
You will need to make a student Class as follows: 
```
class DataStructuresStudent { 
string firstName; 
string lastName; 
int enterTime; 
int numQuestions; 
int unanswered; 
int laptopSerialNum; 
} student; 
 ````
•	firstName and lastName should be self-explanatory 
•	enterTime is the time, in minutes after 12:00 PM that a student enters the lab. For example, if the value here was 0, that means the student enters the lab when it opens, at 12:00 PM.  If the value here were 141, that means that this student enters the lab at 141 minutes after 12:00 PM, or 2:21 PM 
•	numQuestions is a single positive integer representing the number of questions that this student wants to ask 
•	numAnswered is the number of questions that were answered.  Depending on lab congestion, there is a chance that not all questions will get answered.  As such, we will track how many questions each student has had answered, and we will use this when printing individual exit detail as well as the overall lab statistics 
•	laptopSerialNum is the serial number of the laptop this student borrows while in the lab 
 
You will read the list of students attending office hours from a file.  These students will be stored in an  array  of  pointers,  where  each  pointer  points  to  an object DataStructuresStudent (aka Student) in memory.   So at some point of the simulation, if there are 140 students that are read into the file, you will make an array, 140 cells long, of pointers to  student.  Then, for each student you read in, you allocate space dynamically for a student and store their information into that object.   Students will be in chronological order in the file – i.e. the first student in the file will be first to enter the lab. More than one student can enter the lab at any given minute.  However, when this happens, the order they appear in the file is the order in which they will be added to the Laptop Line.
Laptop Waiting Line (Laptop Queue): 
As mentioned, as soon as a student enters the lab, they must stand in line to check out a laptop. You will implement this line as a  queue.   The choice is yours as to whether this will be an array based  queue  or  a  linked  list  based  queue.    Either way,   you   will   be   using   pointers   since   each  student  is  saved  in  a  array, which is referenced by way of a pointer. 
 
 
## Stacks of Laptops: 
The  LDM  stores  all  laptops  in  a  stack  and  identifies  them  by  their  serial number. Therefore, you will implement this as a  stack.   The choice of an arraybased stack or linked-list based stack is up to you.   The input file will have a list of laptops at the beginning which will be placed into the stack.  This is constant over the whole simulation – i.e.: no new laptops are added after the beginning.  However, the order in which they are stored in the stack will surely change, just as the order of trays in a cafeteria change. Some students will use the laptops longer than others, resulting in the laptops being placed back on the stack at variable times.  Note:  the laptop stack will NOT reset to its original state after each simulated day.  Rather, the order of the laptops, at the end of any given day, will be the order for the start of the next day. 
 
## TA Waiting Line (TA Queue): 
The TA  waiting  line  will  also  be  implemented  as  a  queue;  again,  the  choice  is yours as to whether this will be an array based queue or a linked list based queue.  If you choose the latter, in addition to the head/front pointer, which points to the front of the list, it does make sense to maintain a pointer to the end of the list, thereby allowing for constant time enqueue operation. Otherwise, all enqueues result in traversing the entire list.  This also applies to the Laptop waiting queue. 
 
The TAs: 
The TAs should be stored, alphabetically*, in an array, where each cell of the array represents one TA, whose information is stored in the following class: 
 
````diff
class teachingAssistant { 
string name;     // only use first names for the TAs 
int startTimes[3]; 
int endTimes[3]; 
student studentWithTA; 
int minute; 
} TA; 
 ````
 
•	name is just the first name of the given TA 
•	startTimes is  an  array  of  start  times  for  each  of  the  3  days  of  the simulation. The  start  times  are stored as a number of minutes after 12:00 noon. 
•	endTimes is  an  array  of  end  times  for  each  of  the  3  days  of  the simulation.    The  end  times  are guaranteed to be later than the start times for each day, unless they are both 0, indicating that this TA has no office  hours  on  a  given  day.    Note  that  the  start  time  may  be  0, indicating that their office hours start at noon, and the end time may be something else.  Only if both numbers are 0 does it mean that they have no hours that day. 
studentWithTA is a  pointer  of  class  DataStructuresstudent, showing which specific student the TA is helping.    When a student is dequeued from the TA waiting line, what we are dequeuing is simply a pointer (an address) of that student in memory. 
•	This pointer is then saved into this member of the appropriate  TA’s object, showing that the TA is working with this student. This allows us to maintain  the  integrity  of  the   “student”,  in   memory,  therefore allowing us to the enqueue that student back into the TA waiting queue (if  they  have  more  questions) or  into  the  Laptop  queue  if  they are finished with questions. 
•	Minute is an integer indicating the number of minutes a TA has spent with their current student.  This allows you to make sure that the student only spends 5 minutes with the TA 
 
*When any TA is done helping a student and it is past their quitting time, they should leave the lab.  At this point, a check should be done to see if there are any TAs still on duty.  If not, all students currently waiting in the laptop line to pick up a laptop will need to leave, and any students in the TA line will need to move into the laptop line to return their laptops, no matter how many questions they still had. The day’s simulation should continue until all laptops have been returned to the LDM. 
 
 
## More Details: 
For the purposes of the simulation, the lab will open at noon, and “close” no later than 8:00 PM. 
Thus, you do not need to distinguish between AM and PM, as all the hours will be PM. When time is displayed, it must be displayed in standard time formatting, e.g.: “12:23 PM”, “1:30 PM”, “6:59 PM”, etc. 
 
If at any point, there are no TAs on duty, you may assume that the lab hours for the day are over, and any students still waiting in line are out of luck.  TAs will remain on duty at least as long as their office hours for each day, and possibly up to 4 minutes longer, if they are helping a student. But once their office hours are over, they may not help any new students.   If they were the last TA on duty at that point, all remaining students should return their laptops, the lab should close immediately afterwards, and you should print out the appropriate information (see output). Students who didn’t get any help that day may or may not be in the line again the next day, but you don’t need to keep track of this.
 
The following chart will help you keep track of how to organize the students into the various lines.   The “outside” box refers to the array of students that you read in at the beginning.   You will refer to this array to see when students enter the lab, which of course,  equates  to  entering the  Laptop waiting queue.    The  Laptop Queue  contains students picking up or dropping off laptops.  The TA Queue contains students who have a laptop and are waiting for a TA, and the TAs section represents students who are currently being helped by TAs. 
![image](https://user-images.githubusercontent.com/77499979/227983738-5d6481fd-f8ca-4376-b424-6570cf3fc16e.png)

 
 	 
# And now the nuts and bolts: 
 
•	The lab does not open until the first TA arrives.   You can assume that students know the TAs’ schedule and do not arrive to the lab until the lab is open (the TA is present). 
 
•	If a student is in the outside line and the current time is equal to their arrival time, they should immediately be placed into the laptop queue. As already mentioned, multiple students CAN have the same arrival time.   But the order that you place them into the laptop queue is based on the order that they are in the file. 
 
 
•	Each minute, one person may interact with the LDM (Laptop Dispensing Minion), and either pick up or return a laptop.   (Assume that this takes a full minute, so nobody else can talk with the LDM until the next minute.) 
 
 
•	If a student enters the lab at 12:20 PM, for example, they will also get in the laptop line at 12:20 PM. The borrowing takes 1 minute, so at 12:21 PM, the borrowing transaction is complete, and the student can enter the TA line. 
 
•	At every minute interval, if a TA is not working with a student, they will take a student from the front of the TA line. 
 
•	Let’s say a student begins working with a TA at 3:19 PM.  So, at 3:24 PM, they will either be enqueued back into the TA line (if they have more questions), or they will be enqueued into the laptop line to return the laptop (if they don’t have more questions).   ALSO, at 3:24 PM, that TA can immediately begin working with the next student (if one is available). 
 
 
•	So, there should be no delay from when a TA finishes with one student and takes the next. 
 
 
•	If student A enters the lab at the same time that student B finishes his Q&A session and enters the laptop line (to return a laptop), student B will enter the             Laptop line
•	BEFORE student A enters the laptop line (this just makes the coding less messy). So, you can simply process the laptop line last. 
 
 
•	If  student  A  issues a  laptop  and  enters  the  TA  line  at  the  same  time  that student   B  finishes     a  Q&A  session  and  re-enters  the  TA  line  (for  another question),  student  A  should get in the TA line first, since they haven’t had the chance to even ask one question. 
 
 
•	If a  TA  is  forced  to  stay  a  bit  longer  than  their  hours  because  they  haven’t finished that specific 5-minute question/answer, this is allowed.  However, once a TA is  past  their  official  hours,  they  may  not  help  any  new  students.     For example, if the TA finishes at 4:00PM, a student can ask a question of this TA up through 3:59 PM.   So, for example, if a student asks this TA a question at 3:57 PM, that Q/A session will finish at 4:02 PM.  But once a TA is officially no longer on duty, they cannot help a new student. 
 
•	At 8PM, all students in the TA waiting line enter the Laptop line (in their same order) to return the laptops. 
 
 
•	When the lab closes, you must empty the Laptop Queue. There is a 
possibility that some of the students in the queue at this point have no laptops.  In real life, they would  just  leave,  as there is no reason to wait in a line.    However, that complicates the code.  So we will assume that students can only leave the line via dequeuing, which translates to them staying in line until they are at the front of the line.  However, to expedite this process, if a student does not have a laptop to return, we assume that this takes ZERO time, thus allowing you to immediately work on the first actual student that does have a laptop to return.   For example, the lab closed, and we are emptying the laptop line.  At time X, let’s say there are 10 people in line, with the first three not having a laptop (they were waiting for one before the lab closed).    At time X, those three students are dequeued. Additionally, the fourth student is dequeued and initiates the laptop return. 
 
 
•	You can assume t h a t there  will always be  enough laptops for  the  number  of students; meaning, this system will never experience deadlock.   The number of laptops is equal to or greater than the number of students that will enter  the lab on a given day.
 
# Input File Specification (input.txt) 
You will read in input from a file, "input.txt". The name MUST BE “input.txt”. Have this AUTOMATED. Do not ask the user to enter “input.txt”. You should read in this automatically. (This will expedite the grading process.) 
 
The input file has a single positive integer, n, on its first line, specifying the number of laptops to be placed  in the machine.    On the next line, there will be n serial numbers, indicating each of the laptops.  These are represented as positive numbers small enough to be stored in an int variable. They should be placed into the stack in the order the numbers appear.   Thus, the last laptop on the stack will be the first one removed by the first student who needs one. 
 
On the next line will be another positive integer, t, indicating the number of TAs that will be on duty during the course of the simulation.   On the following t lines, there will  be  a  set  of  data indicating each TA’s name, along with their office hours for each of the days of the week.  These will be given in the order start, end, start, end, etc. for each of the 3 days, starting with Monday. TAs may have overlapping hours on some days, and there may be many of them on duty at once. This TA information will remain fixed over all the simulations. 
 
The  next  line  will  be  a  single  positive  integer,  p,  representing  the  number  of programs for the semester,  which,  in  turn,  represents  the  number  of  times  we need  to  run  this three-day simulation. 
On  the  next  lines  will  be  p  sets  of  data  for  each  of  the  three-day  simulations. Note, that since each of the p simulations is really a simulation over three days, each of the following p sets of data will have three days worth of information. 
 
The first line of each simulation will contain a single positive integer, m, never exceeding 300, representing the number of students who get into line for that Monday, followed by m lines containing information about each student (see below). The next line will contain a single positive integer, t, never exceeding 300, representing the number of students who get into line for that Tuesday, followed by t  lines  containing  information  about  each  student.     Finally,  the  next  line  will contain a single positive integer, w, never exceeding 300, representing the number of students who get into line for that Wednesday, followed by w lines containing information about each student. 
 
Note:  for each of the three days, and for each simulation, the order that the students are found in the input file will be the order that they arrive in the lab. 
 
## Information on each student:   
he first piece of information on each of these lines will be a non- negative integer (less than or equal to 480) representing the number of minutes, after noon, the student arrives to get into line. This is followed by  the  first  and  last  name  of  the  student  (all upper or lower-case letters with a length of fewer than 20 characters each). After this will be a single positive integer indicating the number of questions the student needs to have answered. All pieces of information will be separated by a space on each line. 
 
  
# Output Specification 
***NOTE***: You should generate your output to a FILE that you will call 
“out.txt”.
For each of the semester programs (each resulting in a 3 day simulation), print out a header with the following format: 

********** Program X: 
********** 

Where X is the ith program of the semester.  Follow this with a blank line. For each day of the three-day simulation, print the following header: Day: where Day represents the day of the simulation (“Monday”, “Tuesday”, or “Wednesday”). 
 
Follow this with a blank line. 
 
The following lines will give information about a TA beginning or ending their lab hours, or a student either entering or leaving, picking up or returning a laptop, or starting or finishing their session with a TA. These lines should be printed in the order in which the actions occur.  The formatting for these lines is as follows: 
 
 ```diff
TIME: TA_NAME has begun lab hours. 
TIME: TA_NAME has finished lab hours. 
TIME: There are no TAs on duty.  Arslan is now closed. 
TIME: STUDENT_NAME has arrived in Arslan. 
TIME: STUDENT_NAME has borrowed laptop SERIAL and moved to the TA line. 
TIME: STUDENT_NAME is getting help from TA_NAME. 
TIME: STUDENT_NAME has had one question answered and gotten back in line. 
TIME: STUDENT_NAME has no more questions and will now return the laptop. 
TIME: STUDENT_NAME has returned laptop SERIAL and went home HAPPY. 
TIME: STUDENT_NAME has returned laptop SERIAL and went home FRUSTRATED. TIME: STUDENT_NAME never even got a laptop and went home FRUSTRATED. TIME:  STUDENT_NAME has had one question answered, but must now return the laptop and exit the lab. 
 ```
where TIME is the time the Student checked in, STUDENT_NAME is the name of the student (first name followed by a space and then followed by the last name), TA_NAME is the name of the TA, and SERIAL is the serial number of a laptop. 
 
A student  is  “happy” if  all of their questions were answered, and is “frustrated” otherwise. Students only go home happy if they had at least 75% of their questions answered.   Otherwise, they go home frustrated.   So, if a student had 10 questions, but only 7 were answered, they would go home frustrated.  But if that student had 8 questions answered, they would go home happy. 
 
The time should be printed out in the following format: (H)H:MM PM
 
The first one (or possibly two) digits represent the hour.   The hour must not be printed as 0 if it is between noon and 1:00, so you’ll need to check for this.  This is followed  by a  colon  and then the next two digits represent the minute.   If the minute value is less than 10, you’ll need to add a leading 0, so that it prints as 3:05, not 3:5.   (It probably makes sense to have a function that takes in as input the number of minutes after noon and in turn prints out the corresponding time in this format.) 
 
 
# Explanation of Output: 
Most of the output is straightforward.  The following explanation covers the few cases that may not be completely clear 
 
TIME: STUDENT_NAME is getting help from TA_NAME. 
-	This output should occur AS SOON AS the student begins working with the TA. 
 
TIME: STUDENT_NAME never even got a laptop and went home FRUSTRATED. 
-	This output should occur if a student is in line, to GET a laptop (they came REALLY late to the lab) and the lab closes before they even get a laptop. 
 
TIME: STUDENT_NAME has had one question answered, but must now return the laptop and exit the lab. 
-	This output occurs when a student is working with a TA, whose hours have finished AND who is the last TA on duty (meaning the lab is now closed).  So when that student finishes with the TA, if they have had at least 75% of their questions answered, they go home happy.  Otherwise, you need the above output. 
 
TIME: There are no TAs on duty.  Arslan is now closed. 
-	This message should only print AFTER the last TA has finished their hours AND AFTER their respective “TA_NAME has finished lab hours.” message has printed. 
 
  
# Output Day Summary: 
Follow each day’s output with one blank line.   Then you will print that day’s lab summary as follows: 
 
# Day’s Lab Summary: 
The TA Lab was open for H hours M minutes. 
Y students visited the lab.  Out of those students, only Z left happy. The remaining left frustrated. 
 
Lesson Learned: do not procrastinate!  Start programs early! 
 
where  “Day’s”  represents  that  day  of  the  simulation  (Monday’s,  Tuesday’s,  or Wednesday’s). The lab is open from when the first TA arrives until the last student leaves the lab (by returning their laptop.  So, if the last TA finishes their office hours at 6:30 PM, works an extra 4 minutes with a student till, 6:34 PM, and if it then takes all the students till 6:42 PM to exit the lab, you would say that the lab is open for 6 hours and 42 minutes. 
 
Follow each day’s summary with a TWO blank lines. 
 
# ***Helpful Suggestions*** 
•	As stated, you can use either array based or linked-list based stacks and queues. 
•	Considering that the array of student pointers is in chronological order based on the time that they enter the lab, it does make sense to view this array as a queue. How is that helpful?   You are already implementing two queues (laptop and TA line), and as such, you will already be using the various array or linked-list based queue operations. Therefore, we can “peek” at the enter time of the student at the front of the queue.  If it is their time to enter, we can simple perform a dequeue operation.  Of course, you continue to dequeue for all students whose enter time as at this specific minute, as multiple students can enter at the same time. 
•	The interfaces shown in this PDF contain the minimum number of fields you need. • Feel free to add any members as you feel appropriate. 
 
  
# Implementation Restrictions 
Name the file you create and turn in Semester_Assig-Enrollement#.cpp.   You must use at least two queues and one stack (for the laptops).   You must write functions that operate on these classes  analogous  to  the stack and queue functions shown in class. Look closely at the sample input and output files provided with the assignment and make sure you follow the formatting exactly. 
 
## Grading Details Your program will be graded upon the following criteria: 
 
1)	Correctness. 
2)	Your use of functions. Even if your output is correct, you won't receive full credit if your program doesn't make appropriate use of functions. 
3)	Use of different Data structures. Since the purpose of this assignment is to teach you to use diffrernt data structures we have studied, you will not receive credit if you don't use them. 
4)	Your programming style, comments, and use of white space. 


Solution to TA Data Structures and Algorithms Problem

"Semester Assignment_068.cpp" is the file containing the driver program
```diff
User Defined Classes:
•	Node
•	Queue
•	Stack
•	Time
•	DataStrucresStudent
•	teachingAssistant
```
# Method to read from "input.txt"
•	Global function used to push values onto Laptop Stack
•	Member functions used to insert values in DataStrucresStudent and teachingAssistant accordingly

Method to keep track of Time
Time class made with several operators overloaded to write the main code easily. It stores time in 24hrs format but when required to display its values on Console Application or write data on file "output.txt", it writes in AM and PM format. Since our time range stays in PM, the TIME class ignored any condition to write AM.

Approach:
As the small diagram was displayed in Assignment.pdf, the same sequence was followed starting from LDM to Tas themselves.

```diff
### Input.txt file format

20
91457419
91160324
49976149
67237465
24124626
88812998
14759708
89594006
71281199
16994365
47235759
35073907
24350204
42320451
45594438
68428759
28698737
46933604
70571329
23662766
2
Charles 0 180   0 120 120 240
Max     0   0 120 240   0 180
2
9  
0 Sooraya Qadir 5
11 Alisa Tager 6
17 Selene Gallio 4
49 Rita Wayword 6
106 Cecilia Reyes 6
109 Sean Cassidy 6
114 Alexander Summers 4
154 Neal Shaara 2
179 Nicholas Gleason 3
17  
49 Xi'an Manh 6
52 Jean-Paul Beaubier 5
72 Danielle Moonstar 3
83 Tandy Bowen 5
96 Samuel Guthrie 3
97 Santo Vaccarro 6
101 James Bradley 6
105 Paige Guthrie 5
106 James Proudstar 4
118 Christy Nord 1
129 Julian Keller 4
132 Amara Aquilla 2
146 Laura Kinney 2
147 Nathaniel Grey 2
148 John Proudstar 5
154 Hisako Ichiki 1
231 David Alleyne 2
25  
2 Wade Wilson 6
9 Shiro Yoshida 5
9 Kevin Sydney 4
19 Cain Marko 4
25 Eric Gitter 1
29 Nezhno Abidemi 5
37 Carl Denti 4
48 Anna Marie 4
48 Jonothon Starsmore 3
48 Jubilation Lee 2
52 Matsu'o Tsurayaba 2
62 Cassandra Nova 2
65 Alison Crestmere 1
84 Hope Summers 2
90 Davis Cameron 4
96 Thomas Cassidy 6
106 Ororo T'Challa 3
110 Arkady Rossovich 3
124 Elizabeth Braddock 6
132 James Howlett 4
160 Emma Frost 5
169 Sarah Rushman 1
172 Madison Jeffries 2
189 Amahl Farouk 2
190 Kenuichio Harada 5
9  
5 Cessily Kincaid 1
13 Raven Darkholme 6
21 Douglas Ramsey 6
75 Paris Bennett 5
82 Remy LeBeau 3
88 Karima Shapandar 6
95 Alison Blaire 4
138 Robert Kelly 5
176 Rachel Summers 6
16  
8 Victor Borkowski 5
39 Kevin MacTaggert 4
40 Scott Summers 1
47 Namor McKenzie 6
59 Robert Drake 5
69 Miranda Leevald 1
117 Megan Gwynn 5
135 Bolivar Trask 5
136 Calvin Rankin 2
143 David Haller 1
174 Lucas Bishop 6
177 Heather Cameron 3
202 Tabitha Smith 6
203 Jean Grey 2
207 Kurt Wagner 6
232 Warren Worthington 2
26  
6 Jason Wyngarde 3
9 Shen Xorn 2
10 Henry McCoy 5
14 Jeanne-Marie Beaubier 5
17 Illyana Rasputina 3
24 Gabriel Summers 5
25 Nathan Summers 6
32 Suzanne Chan 6
52 Lorna Dane 1
62 Karl Lykos 3
73 Yuriko Oyama 6
88 Roberto Da_Costa 1
105 Madelyne Pryor 5
105 Armando Munoz 4
107 Victor Creed 3
108 Noriko Ashida 2
115 Kitty Pryde 5
128 Nathaniel Essex 2
154 Cameron Hodge 2
162 Regan Wyngarde 1
179 Joshua Foley 1
181 William Stryker 6
189 Piotr Rasputin 2
205 Neena Thurman 3
230 Ruth Aldine 5
230 Tyrone Johnson 3
```


### Output.txt file generated after running the code
This is the filed created after running the code.
************
Program 1:
************

```diff
Day: Monday

12:00 PM: Charles has begun Lab Hours
12:00 PM: Sooraya Qadir has arrived in Arsalan
12:02 PM: Sooraya Qadir has borrowed Laptop 23662766 and moved to the TA Line
12:02 PM: Sooraya Qadir is getting help from Charles
12:07 PM: Sooraya Qadir has had one question answered and gotten back in line.
12:07 PM: Sooraya Qadir is getting help from Charles
12:11 PM: Alisa Tager has arrived in Arsalan
12:12 PM: Sooraya Qadir has had one question answered and gotten back in line.
12:12 PM: Sooraya Qadir is getting help from Charles
12:13 PM: Alisa Tager has borrowed Laptop 70571329 and moved to the TA Line
12:17 PM: Selene Gallio has arrived in Arsalan
12:17 PM: Sooraya Qadir has had one question answered and gotten back in line.
12:17 PM: Alisa Tager is getting help from Charles
12:19 PM: Selene Gallio has borrowed Laptop 46933604 and moved to the TA Line
12:22 PM: Alisa Tager has had one question answered and gotten back in line.
12:22 PM: Sooraya Qadir is getting help from Charles
12:27 PM: Sooraya Qadir has had one question answered and gotten back in line.
12:27 PM: Selene Gallio is getting help from Charles
12:32 PM: Selene Gallio has had one question answered and gotten back in line.
12:32 PM: Alisa Tager is getting help from Charles
12:37 PM: Alisa Tager has had one question answered and gotten back in line.
12:37 PM: Sooraya Qadir is getting help from Charles
12:42 PM: Sooraya Qadir has no more questions and will now return the laptop
12:42 PM: Selene Gallio is getting help from Charles
12:44 PM: Sooraya Qadir has returned laptop 23662766 and went home HAPPY.
12:47 PM: Selene Gallio has had one question answered and gotten back in line.
12:47 PM: Alisa Tager is getting help from Charles
12:49 PM: Rita Wayword has arrived in Arsalan
12:51 PM: Rita Wayword has borrowed Laptop 23662766 and moved to the TA Line
12:52 PM: Alisa Tager has had one question answered and gotten back in line.
12:52 PM: Selene Gallio is getting help from Charles
12:57 PM: Selene Gallio has had one question answered and gotten back in line.
12:57 PM: Rita Wayword is getting help from Charles
01:02 PM: Rita Wayword has had one question answered and gotten back in line.
01:02 PM: Alisa Tager is getting help from Charles
01:07 PM: Alisa Tager has had one question answered and gotten back in line.
01:07 PM: Selene Gallio is getting help from Charles
01:12 PM: Selene Gallio has no more questions and will now return the laptop
01:12 PM: Rita Wayword is getting help from Charles
01:14 PM: Selene Gallio has returned laptop 46933604 and went home HAPPY.
01:17 PM: Rita Wayword has had one question answered and gotten back in line.
01:17 PM: Alisa Tager is getting help from Charles
01:22 PM: Alisa Tager has had one question answered and gotten back in line.
01:22 PM: Rita Wayword is getting help from Charles
01:27 PM: Rita Wayword has had one question answered and gotten back in line.
01:27 PM: Alisa Tager is getting help from Charles
01:32 PM: Alisa Tager has no more questions and will now return the laptop
01:32 PM: Rita Wayword is getting help from Charles
01:34 PM: Alisa Tager has returned laptop 70571329 and went home HAPPY.
01:37 PM: Rita Wayword has had one question answered and gotten back in line.
01:37 PM: Rita Wayword is getting help from Charles
01:42 PM: Rita Wayword has had one question answered and gotten back in line.
01:42 PM: Rita Wayword is getting help from Charles
01:46 PM: Cecilia Reyes has arrived in Arsalan
01:47 PM: Rita Wayword has no more questions and will now return the laptop
01:48 PM: Cecilia Reyes has borrowed Laptop 70571329 and moved to the TA Line
01:48 PM: Cecilia Reyes is getting help from Charles
01:49 PM: Sean Cassidy has arrived in Arsalan
01:49 PM: Rita Wayword has returned laptop 23662766 and went home HAPPY.
01:51 PM: Sean Cassidy has borrowed Laptop 23662766 and moved to the TA Line
01:53 PM: Cecilia Reyes has had one question answered and gotten back in line.
01:53 PM: Sean Cassidy is getting help from Charles
01:54 PM: Alexander Summers has arrived in Arsalan
01:56 PM: Alexander Summers has borrowed Laptop 46933604 and moved to the TA Line
01:58 PM: Sean Cassidy has had one question answered and gotten back in line.
01:58 PM: Cecilia Reyes is getting help from Charles
02:03 PM: Cecilia Reyes has had one question answered and gotten back in line.
02:03 PM: Alexander Summers is getting help from Charles
02:08 PM: Alexander Summers has had one question answered and gotten back in line.
02:08 PM: Sean Cassidy is getting help from Charles
02:13 PM: Sean Cassidy has had one question answered and gotten back in line.
02:13 PM: Cecilia Reyes is getting help from Charles
02:18 PM: Cecilia Reyes has had one question answered and gotten back in line.
02:18 PM: Alexander Summers is getting help from Charles
02:23 PM: Alexander Summers has had one question answered and gotten back in line.
02:23 PM: Sean Cassidy is getting help from Charles
02:28 PM: Sean Cassidy has had one question answered and gotten back in line.
02:28 PM: Cecilia Reyes is getting help from Charles
02:33 PM: Cecilia Reyes has had one question answered and gotten back in line.
02:33 PM: Alexander Summers is getting help from Charles
02:34 PM: Neal Shaara has arrived in Arsalan
02:36 PM: Neal Shaara has borrowed Laptop 28698737 and moved to the TA Line
02:38 PM: Alexander Summers has had one question answered and gotten back in line.
02:38 PM: Sean Cassidy is getting help from Charles
02:43 PM: Sean Cassidy has had one question answered and gotten back in line.
02:43 PM: Cecilia Reyes is getting help from Charles
02:48 PM: Cecilia Reyes has had one question answered and gotten back in line.
02:48 PM: Neal Shaara is getting help from Charles
02:53 PM: Neal Shaara has had one question answered and gotten back in line.
02:53 PM: Alexander Summers is getting help from Charles
02:58 PM: Alexander Summers has no more questions and will now return the laptop
02:58 PM: Sean Cassidy is getting help from Charles
02:59 PM: Nicholas Gleason has arrived in Arsalan
02:59 PM: Alexander Summers has returned laptop 46933604 and went home HAPPY.
03:00 PM: Charles has finished Lab Hours
03:00 PM: There are no TAs on duty. Arsalan is now closed.
03:01 PM: Nicholas Gleason never even got a laptop and went home FRUSTRATED.
03:01 PM: Cecilia Reyes has returned laptop 70571329 and went home HAPPY.
03:02 PM: Neal Shaara has returned laptop 28698737 and went home FRUSTRATED.
03:03 PM: Sean Cassidy has had one question answered but must return the laptop now and exit the lab.
03:05 PM: Sean Cassidy has returned laptop 23662766 and went home HAPPY.

Monday's Lab Summary:
The TA Lab was open for 3 hours and 5 minutes. 9 students visited the lab.
Out of those students, only 7 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!

Day: Tuesday

12:00 PM: Charles has begun Lab Hours
12:49 PM: Xi'an Manh has arrived in Arsalan
12:51 PM: Xi'an Manh has borrowed Laptop 23662766 and moved to the TA Line
12:51 PM: Xi'an Manh is getting help from Charles
12:52 PM: Jean-Paul Beaubier has arrived in Arsalan
12:54 PM: Jean-Paul Beaubier has borrowed Laptop 28698737 and moved to the TA Line
12:56 PM: Xi'an Manh has had one question answered and gotten back in line.
12:56 PM: Jean-Paul Beaubier is getting help from Charles
01:01 PM: Jean-Paul Beaubier has had one question answered and gotten back in line.
01:01 PM: Xi'an Manh is getting help from Charles
01:06 PM: Xi'an Manh has had one question answered and gotten back in line.
01:06 PM: Jean-Paul Beaubier is getting help from Charles
01:11 PM: Jean-Paul Beaubier has had one question answered and gotten back in line.
01:11 PM: Xi'an Manh is getting help from Charles
01:12 PM: Danielle Moonstar has arrived in Arsalan
01:14 PM: Danielle Moonstar has borrowed Laptop 70571329 and moved to the TA Line
01:16 PM: Xi'an Manh has had one question answered and gotten back in line.
01:16 PM: Jean-Paul Beaubier is getting help from Charles
01:21 PM: Jean-Paul Beaubier has had one question answered and gotten back in line.
01:21 PM: Danielle Moonstar is getting help from Charles
01:23 PM: Tandy Bowen has arrived in Arsalan
01:25 PM: Tandy Bowen has borrowed Laptop 46933604 and moved to the TA Line
01:26 PM: Danielle Moonstar has had one question answered and gotten back in line.
01:26 PM: Xi'an Manh is getting help from Charles
01:31 PM: Xi'an Manh has had one question answered and gotten back in line.
01:31 PM: Jean-Paul Beaubier is getting help from Charles
01:36 PM: Samuel Guthrie has arrived in Arsalan
01:36 PM: Jean-Paul Beaubier has had one question answered and gotten back in line.
01:36 PM: Tandy Bowen is getting help from Charles
01:37 PM: Santo Vaccarro has arrived in Arsalan
01:38 PM: Samuel Guthrie has borrowed Laptop 68428759 and moved to the TA Line
01:39 PM: Santo Vaccarro has borrowed Laptop 45594438 and moved to the TA Line
01:41 PM: James Bradley has arrived in Arsalan
01:41 PM: Tandy Bowen has had one question answered and gotten back in line.
01:41 PM: Danielle Moonstar is getting help from Charles
01:43 PM: James Bradley has borrowed Laptop 42320451 and moved to the TA Line
01:45 PM: Paige Guthrie has arrived in Arsalan
01:46 PM: James Proudstar has arrived in Arsalan
01:46 PM: Danielle Moonstar has had one question answered and gotten back in line.
01:46 PM: Xi'an Manh is getting help from Charles
01:47 PM: Paige Guthrie has borrowed Laptop 24350204 and moved to the TA Line
01:48 PM: James Proudstar has borrowed Laptop 35073907 and moved to the TA Line
01:51 PM: Xi'an Manh has had one question answered and gotten back in line.
01:51 PM: Jean-Paul Beaubier is getting help from Charles
01:56 PM: Jean-Paul Beaubier has no more questions and will now return the laptop
01:56 PM: Samuel Guthrie is getting help from Charles
01:58 PM: Christy Nord has arrived in Arsalan
01:58 PM: Jean-Paul Beaubier has returned laptop 28698737 and went home HAPPY.
02:00 PM: Max has begun Lab Hours
02:00 PM: Christy Nord has borrowed Laptop 28698737 and moved to the TA Line
02:00 PM: Charles has finished Lab Hours
02:00 PM: Santo Vaccarro is getting help from Max
02:01 PM: Samuel Guthrie has had one question answered and gotten back in line.
02:05 PM: Santo Vaccarro has had one question answered and gotten back in line.
02:05 PM: Tandy Bowen is getting help from Max
02:09 PM: Julian Keller has arrived in Arsalan
02:10 PM: Tandy Bowen has had one question answered and gotten back in line.
02:10 PM: James Bradley is getting help from Max
02:11 PM: Julian Keller has borrowed Laptop 47235759 and moved to the TA Line
02:12 PM: Amara Aquilla has arrived in Arsalan
02:14 PM: Amara Aquilla has borrowed Laptop 16994365 and moved to the TA Line
02:15 PM: James Bradley has had one question answered and gotten back in line.
02:15 PM: Danielle Moonstar is getting help from Max
02:20 PM: Danielle Moonstar has no more questions and will now return the laptop
02:20 PM: Paige Guthrie is getting help from Max
02:22 PM: Danielle Moonstar has returned laptop 70571329 and went home HAPPY.
02:25 PM: Paige Guthrie has had one question answered and gotten back in line.
02:25 PM: James Proudstar is getting help from Max
02:26 PM: Laura Kinney has arrived in Arsalan
02:27 PM: Nathaniel Grey has arrived in Arsalan
02:28 PM: John Proudstar has arrived in Arsalan
02:28 PM: Laura Kinney has borrowed Laptop 70571329 and moved to the TA Line
02:29 PM: Nathaniel Grey has borrowed Laptop 71281199 and moved to the TA Line
02:30 PM: John Proudstar has borrowed Laptop 89594006 and moved to the TA Line
02:30 PM: James Proudstar has had one question answered and gotten back in line.
02:30 PM: Xi'an Manh is getting help from Max
02:34 PM: Hisako Ichiki has arrived in Arsalan
02:35 PM: Xi'an Manh has no more questions and will now return the laptop
02:35 PM: Christy Nord is getting help from Max
02:36 PM: Hisako Ichiki has borrowed Laptop 14759708 and moved to the TA Line
02:37 PM: Xi'an Manh has returned laptop 23662766 and went home HAPPY.
02:40 PM: Christy Nord has no more questions and will now return the laptop
02:40 PM: Samuel Guthrie is getting help from Max
02:41 PM: Christy Nord has returned laptop 28698737 and went home HAPPY.
02:45 PM: Samuel Guthrie has had one question answered and gotten back in line.
02:45 PM: Santo Vaccarro is getting help from Max
02:50 PM: Santo Vaccarro has had one question answered and gotten back in line.
02:50 PM: Tandy Bowen is getting help from Max
02:55 PM: Tandy Bowen has had one question answered and gotten back in line.
02:55 PM: Julian Keller is getting help from Max
03:00 PM: Julian Keller has had one question answered and gotten back in line.
03:00 PM: Amara Aquilla is getting help from Max
03:05 PM: Amara Aquilla has had one question answered and gotten back in line.
03:05 PM: James Bradley is getting help from Max
03:10 PM: James Bradley has had one question answered and gotten back in line.
03:10 PM: Paige Guthrie is getting help from Max
03:15 PM: Paige Guthrie has had one question answered and gotten back in line.
03:15 PM: Laura Kinney is getting help from Max
03:20 PM: Laura Kinney has had one question answered and gotten back in line.
03:20 PM: Nathaniel Grey is getting help from Max
03:25 PM: Nathaniel Grey has had one question answered and gotten back in line.
03:25 PM: John Proudstar is getting help from Max
03:30 PM: John Proudstar has had one question answered and gotten back in line.
03:30 PM: James Proudstar is getting help from Max
03:35 PM: James Proudstar has had one question answered and gotten back in line.
03:35 PM: Hisako Ichiki is getting help from Max
03:40 PM: Hisako Ichiki has no more questions and will now return the laptop
03:40 PM: Samuel Guthrie is getting help from Max
03:42 PM: Hisako Ichiki has returned laptop 14759708 and went home HAPPY.
03:45 PM: Samuel Guthrie has no more questions and will now return the laptop
03:45 PM: Santo Vaccarro is getting help from Max
03:47 PM: Samuel Guthrie has returned laptop 68428759 and went home HAPPY.
03:50 PM: Santo Vaccarro has had one question answered and gotten back in line.
03:50 PM: Tandy Bowen is getting help from Max
03:51 PM: David Alleyne has arrived in Arsalan
03:53 PM: David Alleyne has borrowed Laptop 68428759 and moved to the TA Line
03:55 PM: Tandy Bowen has had one question answered and gotten back in line.
03:55 PM: Julian Keller is getting help from Max
04:00 PM: Max has finished Lab Hours
04:00 PM: There are no TAs on duty. Arsalan is now closed.
04:00 PM: Julian Keller has had one question answered but must return the laptop now and exit the lab.
04:01 PM: Amara Aquilla has returned laptop 16994365 and went home FRUSTRATED.
04:02 PM: James Bradley has returned laptop 42320451 and went home FRUSTRATED.
04:03 PM: Paige Guthrie has returned laptop 24350204 and went home FRUSTRATED.
04:04 PM: Laura Kinney has returned laptop 70571329 and went home FRUSTRATED.
04:05 PM: Nathaniel Grey has returned laptop 71281199 and went home FRUSTRATED.
04:06 PM: John Proudstar has returned laptop 89594006 and went home FRUSTRATED.
04:07 PM: James Proudstar has returned laptop 35073907 and went home FRUSTRATED.
04:08 PM: Santo Vaccarro has returned laptop 45594438 and went home FRUSTRATED.
04:09 PM: David Alleyne has returned laptop 68428759 and went home FRUSTRATED.
04:10 PM: Tandy Bowen has returned laptop 46933604 and went home HAPPY.
04:11 PM: Julian Keller has returned laptop 47235759 and went home FRUSTRATED.

Tuesday's' Lab Summary:
The TA Lab was open for 4 hours and 11 minutes. 17 students visited the lab.
Out of those students, only 7 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!

Day: Wednesday

12:00 PM: Max has begun Lab Hours
12:02 PM: Wade Wilson has arrived in Arsalan
12:04 PM: Wade Wilson has borrowed Laptop 47235759 and moved to the TA Line
12:04 PM: Wade Wilson is getting help from Max
12:09 PM: Shiro Yoshida has arrived in Arsalan
12:09 PM: Kevin Sydney has arrived in Arsalan
12:09 PM: Wade Wilson has had one question answered and gotten back in line.
12:09 PM: Wade Wilson is getting help from Max
12:11 PM: Shiro Yoshida has borrowed Laptop 46933604 and moved to the TA Line
12:12 PM: Kevin Sydney has borrowed Laptop 68428759 and moved to the TA Line
12:14 PM: Wade Wilson has had one question answered and gotten back in line.
12:14 PM: Shiro Yoshida is getting help from Max
12:19 PM: Cain Marko has arrived in Arsalan
12:19 PM: Shiro Yoshida has had one question answered and gotten back in line.
12:19 PM: Kevin Sydney is getting help from Max
12:21 PM: Cain Marko has borrowed Laptop 45594438 and moved to the TA Line
12:24 PM: Kevin Sydney has had one question answered and gotten back in line.
12:24 PM: Wade Wilson is getting help from Max
12:25 PM: Eric Gitter has arrived in Arsalan
12:27 PM: Eric Gitter has borrowed Laptop 35073907 and moved to the TA Line
12:29 PM: Nezhno Abidemi has arrived in Arsalan
12:29 PM: Wade Wilson has had one question answered and gotten back in line.
12:29 PM: Shiro Yoshida is getting help from Max
12:31 PM: Nezhno Abidemi has borrowed Laptop 89594006 and moved to the TA Line
12:34 PM: Shiro Yoshida has had one question answered and gotten back in line.
12:34 PM: Cain Marko is getting help from Max
12:37 PM: Carl Denti has arrived in Arsalan
12:39 PM: Carl Denti has borrowed Laptop 71281199 and moved to the TA Line
12:39 PM: Cain Marko has had one question answered and gotten back in line.
12:39 PM: Kevin Sydney is getting help from Max
12:44 PM: Kevin Sydney has had one question answered and gotten back in line.
12:44 PM: Eric Gitter is getting help from Max
12:48 PM: Anna Marie has arrived in Arsalan
12:48 PM: Jonothon Starsmore has arrived in Arsalan
12:48 PM: Jubilation Lee has arrived in Arsalan
12:49 PM: Eric Gitter has no more questions and will now return the laptop
12:49 PM: Wade Wilson is getting help from Max
12:50 PM: Anna Marie has borrowed Laptop 70571329 and moved to the TA Line
12:51 PM: Jonothon Starsmore has borrowed Laptop 24350204 and moved to the TA Line
12:52 PM: Matsu'o Tsurayaba has arrived in Arsalan
12:52 PM: Jubilation Lee has borrowed Laptop 42320451 and moved to the TA Line
12:53 PM: Eric Gitter has returned laptop 35073907 and went home HAPPY.
12:54 PM: Wade Wilson has had one question answered and gotten back in line.
12:54 PM: Nezhno Abidemi is getting help from Max
12:55 PM: Matsu'o Tsurayaba has borrowed Laptop 35073907 and moved to the TA Line
12:59 PM: Nezhno Abidemi has had one question answered and gotten back in line.
12:59 PM: Shiro Yoshida is getting help from Max
01:02 PM: Cassandra Nova has arrived in Arsalan
01:04 PM: Cassandra Nova has borrowed Laptop 16994365 and moved to the TA Line
01:04 PM: Shiro Yoshida has had one question answered and gotten back in line.
01:04 PM: Carl Denti is getting help from Max
01:05 PM: Alison Crestmere has arrived in Arsalan
01:07 PM: Alison Crestmere has borrowed Laptop 14759708 and moved to the TA Line
01:09 PM: Carl Denti has had one question answered and gotten back in line.
01:09 PM: Cain Marko is getting help from Max
01:14 PM: Cain Marko has had one question answered and gotten back in line.
01:14 PM: Kevin Sydney is getting help from Max
01:19 PM: Kevin Sydney has had one question answered and gotten back in line.
01:19 PM: Anna Marie is getting help from Max
01:24 PM: Hope Summers has arrived in Arsalan
01:24 PM: Anna Marie has had one question answered and gotten back in line.
01:24 PM: Jonothon Starsmore is getting help from Max
01:26 PM: Hope Summers has borrowed Laptop 28698737 and moved to the TA Line
01:29 PM: Jonothon Starsmore has had one question answered and gotten back in line.
01:29 PM: Jubilation Lee is getting help from Max
01:30 PM: Davis Cameron has arrived in Arsalan
01:32 PM: Davis Cameron has borrowed Laptop 23662766 and moved to the TA Line
01:34 PM: Jubilation Lee has had one question answered and gotten back in line.
01:34 PM: Wade Wilson is getting help from Max
01:36 PM: Thomas Cassidy has arrived in Arsalan
01:38 PM: Thomas Cassidy has borrowed Laptop 88812998 and moved to the TA Line
01:39 PM: Wade Wilson has had one question answered and gotten back in line.
01:39 PM: Matsu'o Tsurayaba is getting help from Max
01:44 PM: Matsu'o Tsurayaba has had one question answered and gotten back in line.
01:44 PM: Nezhno Abidemi is getting help from Max
01:46 PM: Ororo T'Challa has arrived in Arsalan
01:48 PM: Ororo T'Challa has borrowed Laptop 24124626 and moved to the TA Line
01:49 PM: Nezhno Abidemi has had one question answered and gotten back in line.
01:49 PM: Cassandra Nova is getting help from Max
01:50 PM: Arkady Rossovich has arrived in Arsalan
01:52 PM: Arkady Rossovich has borrowed Laptop 67237465 and moved to the TA Line
01:54 PM: Cassandra Nova has had one question answered and gotten back in line.
01:54 PM: Shiro Yoshida is getting help from Max
01:59 PM: Shiro Yoshida has had one question answered and gotten back in line.
01:59 PM: Alison Crestmere is getting help from Max
02:00 PM: Charles has begun Lab Hours
02:00 PM: Carl Denti is getting help from Charles
02:04 PM: Elizabeth Braddock has arrived in Arsalan
02:04 PM: Alison Crestmere has no more questions and will now return the laptop
02:04 PM: Cain Marko is getting help from Max
02:05 PM: Carl Denti has had one question answered and gotten back in line.
02:05 PM: Kevin Sydney is getting help from Charles
02:06 PM: Elizabeth Braddock has borrowed Laptop 49976149 and moved to the TA Line
02:07 PM: Alison Crestmere has returned laptop 14759708 and went home HAPPY.
02:09 PM: Cain Marko has had one question answered and gotten back in line.
02:09 PM: Anna Marie is getting help from Max
02:10 PM: Kevin Sydney has no more questions and will now return the laptop
02:10 PM: Hope Summers is getting help from Charles
02:11 PM: Kevin Sydney has returned laptop 68428759 and went home HAPPY.
02:12 PM: James Howlett has arrived in Arsalan
02:14 PM: James Howlett has borrowed Laptop 68428759 and moved to the TA Line
02:14 PM: Anna Marie has had one question answered and gotten back in line.
02:14 PM: Jonothon Starsmore is getting help from Max
02:15 PM: Hope Summers has had one question answered and gotten back in line.
02:15 PM: Davis Cameron is getting help from Charles
02:19 PM: Jonothon Starsmore has had one question answered and gotten back in line.
02:19 PM: Jubilation Lee is getting help from Max
02:20 PM: Davis Cameron has had one question answered and gotten back in line.
02:20 PM: Thomas Cassidy is getting help from Charles
02:24 PM: Jubilation Lee has no more questions and will now return the laptop
02:24 PM: Wade Wilson is getting help from Max
02:25 PM: Thomas Cassidy has had one question answered and gotten back in line.
02:25 PM: Matsu'o Tsurayaba is getting help from Charles
02:26 PM: Jubilation Lee has returned laptop 42320451 and went home HAPPY.
02:29 PM: Wade Wilson has no more questions and will now return the laptop
02:29 PM: Ororo T'Challa is getting help from Max
02:30 PM: Matsu'o Tsurayaba has no more questions and will now return the laptop
02:30 PM: Nezhno Abidemi is getting help from Charles
02:31 PM: Wade Wilson has returned laptop 47235759 and went home HAPPY.
02:32 PM: Matsu'o Tsurayaba has returned laptop 35073907 and went home HAPPY.
02:34 PM: Ororo T'Challa has had one question answered and gotten back in line.
02:34 PM: Arkady Rossovich is getting help from Max
02:35 PM: Nezhno Abidemi has had one question answered and gotten back in line.
02:35 PM: Cassandra Nova is getting help from Charles
02:39 PM: Arkady Rossovich has had one question answered and gotten back in line.
02:39 PM: Shiro Yoshida is getting help from Max
02:40 PM: Emma Frost has arrived in Arsalan
02:40 PM: Cassandra Nova has no more questions and will now return the laptop
02:40 PM: Carl Denti is getting help from Charles
02:42 PM: Emma Frost has borrowed Laptop 35073907 and moved to the TA Line
02:43 PM: Cassandra Nova has returned laptop 16994365 and went home HAPPY.
02:44 PM: Shiro Yoshida has no more questions and will now return the laptop
02:44 PM: Elizabeth Braddock is getting help from Max
02:45 PM: Shiro Yoshida has returned laptop 46933604 and went home HAPPY.
02:45 PM: Carl Denti has had one question answered and gotten back in line.
02:45 PM: Cain Marko is getting help from Charles
02:49 PM: Sarah Rushman has arrived in Arsalan
02:49 PM: Elizabeth Braddock has had one question answered and gotten back in line.
02:49 PM: James Howlett is getting help from Max
02:50 PM: Cain Marko has no more questions and will now return the laptop
02:50 PM: Anna Marie is getting help from Charles
02:51 PM: Sarah Rushman has borrowed Laptop 46933604 and moved to the TA Line
02:52 PM: Madison Jeffries has arrived in Arsalan
02:52 PM: Cain Marko has returned laptop 45594438 and went home HAPPY.
02:54 PM: Madison Jeffries has borrowed Laptop 45594438 and moved to the TA Line
02:54 PM: James Howlett has had one question answered and gotten back in line.
02:54 PM: Hope Summers is getting help from Max
02:55 PM: Anna Marie has had one question answered and gotten back in line.
02:55 PM: Jonothon Starsmore is getting help from Charles
02:59 PM: Hope Summers has no more questions and will now return the laptop
02:59 PM: Davis Cameron is getting help from Max
03:00 PM: Hope Summers has returned laptop 28698737 and went home HAPPY.
03:00 PM: Jonothon Starsmore has no more questions and will now return the laptop
03:00 PM: Thomas Cassidy is getting help from Charles
03:00 PM: Max has finished Lab Hours
03:02 PM: Jonothon Starsmore has returned laptop 24350204 and went home HAPPY.
03:04 PM: Davis Cameron has had one question answered and gotten back in line.
03:05 PM: Thomas Cassidy has had one question answered and gotten back in line.
03:05 PM: Ororo T'Challa is getting help from Charles
03:09 PM: Amahl Farouk has arrived in Arsalan
03:10 PM: Kenuichio Harada has arrived in Arsalan
03:10 PM: Ororo T'Challa has had one question answered and gotten back in line.
03:10 PM: Nezhno Abidemi is getting help from Charles
03:11 PM: Amahl Farouk has borrowed Laptop 24350204 and moved to the TA Line
03:12 PM: Kenuichio Harada has borrowed Laptop 28698737 and moved to the TA Line
03:15 PM: Nezhno Abidemi has had one question answered and gotten back in line.
03:15 PM: Arkady Rossovich is getting help from Charles
03:20 PM: Arkady Rossovich has had one question answered and gotten back in line.
03:20 PM: Emma Frost is getting help from Charles
03:25 PM: Emma Frost has had one question answered and gotten back in line.
03:25 PM: Carl Denti is getting help from Charles
03:30 PM: Carl Denti has no more questions and will now return the laptop
03:30 PM: Elizabeth Braddock is getting help from Charles
03:32 PM: Carl Denti has returned laptop 71281199 and went home HAPPY.
03:35 PM: Elizabeth Braddock has had one question answered and gotten back in line.
03:35 PM: Sarah Rushman is getting help from Charles
03:40 PM: Sarah Rushman has no more questions and will now return the laptop
03:40 PM: Madison Jeffries is getting help from Charles
03:42 PM: Sarah Rushman has returned laptop 46933604 and went home HAPPY.
03:45 PM: Madison Jeffries has had one question answered and gotten back in line.
03:45 PM: James Howlett is getting help from Charles
03:50 PM: James Howlett has had one question answered and gotten back in line.
03:50 PM: Anna Marie is getting help from Charles
03:55 PM: Anna Marie has no more questions and will now return the laptop
03:55 PM: Davis Cameron is getting help from Charles
03:57 PM: Anna Marie has returned laptop 70571329 and went home HAPPY.
04:00 PM: Charles has finished Lab Hours
04:00 PM: There are no TAs on duty. Arsalan is now closed.
04:00 PM: Davis Cameron has had one question answered but must return the laptop now and exit the lab.
04:01 PM: Thomas Cassidy has returned laptop 88812998 and went home FRUSTRATED.
04:02 PM: Ororo T'Challa has returned laptop 24124626 and went home FRUSTRATED.
04:03 PM: Amahl Farouk has returned laptop 24350204 and went home FRUSTRATED.
04:04 PM: Kenuichio Harada has returned laptop 28698737 and went home FRUSTRATED.
04:05 PM: Nezhno Abidemi has returned laptop 89594006 and went home HAPPY.
04:06 PM: Arkady Rossovich has returned laptop 67237465 and went home FRUSTRATED.
04:07 PM: Emma Frost has returned laptop 35073907 and went home FRUSTRATED.
04:08 PM: Elizabeth Braddock has returned laptop 49976149 and went home FRUSTRATED.
04:09 PM: Madison Jeffries has returned laptop 45594438 and went home FRUSTRATED.
04:10 PM: James Howlett has returned laptop 68428759 and went home FRUSTRATED.
04:11 PM: Davis Cameron has returned laptop 23662766 and went home HAPPY.

Wednesday's Lab Summary:
The TA Lab was open for 4 hours and 11 minutes. 25 students visited the lab.
Out of those students, only 16 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!

************
Program 2:
************

Day: Monday

12:00 PM: Charles has begun Lab Hours
12:05 PM: Cessily Kincaid has arrived in Arsalan
12:07 PM: Cessily Kincaid has borrowed Laptop 23662766 and moved to the TA Line
12:07 PM: Cessily Kincaid is getting help from Charles
12:12 PM: Cessily Kincaid has no more questions and will now return the laptop
12:13 PM: Raven Darkholme has arrived in Arsalan
12:14 PM: Cessily Kincaid has returned laptop 23662766 and went home HAPPY.
12:16 PM: Raven Darkholme has borrowed Laptop 23662766 and moved to the TA Line
12:16 PM: Raven Darkholme is getting help from Charles
12:21 PM: Douglas Ramsey has arrived in Arsalan
12:21 PM: Raven Darkholme has had one question answered and gotten back in line.
12:21 PM: Raven Darkholme is getting help from Charles
12:23 PM: Douglas Ramsey has borrowed Laptop 68428759 and moved to the TA Line
12:26 PM: Raven Darkholme has had one question answered and gotten back in line.
12:26 PM: Douglas Ramsey is getting help from Charles
12:31 PM: Douglas Ramsey has had one question answered and gotten back in line.
12:31 PM: Raven Darkholme is getting help from Charles
12:36 PM: Raven Darkholme has had one question answered and gotten back in line.
12:36 PM: Douglas Ramsey is getting help from Charles
12:41 PM: Douglas Ramsey has had one question answered and gotten back in line.
12:41 PM: Raven Darkholme is getting help from Charles
12:46 PM: Raven Darkholme has had one question answered and gotten back in line.
12:46 PM: Douglas Ramsey is getting help from Charles
12:51 PM: Douglas Ramsey has had one question answered and gotten back in line.
12:51 PM: Raven Darkholme is getting help from Charles
12:56 PM: Raven Darkholme has had one question answered and gotten back in line.
12:56 PM: Douglas Ramsey is getting help from Charles
01:01 PM: Douglas Ramsey has had one question answered and gotten back in line.
01:01 PM: Raven Darkholme is getting help from Charles
01:06 PM: Raven Darkholme has no more questions and will now return the laptop
01:06 PM: Douglas Ramsey is getting help from Charles
01:08 PM: Raven Darkholme has returned laptop 23662766 and went home HAPPY.
01:11 PM: Douglas Ramsey has had one question answered and gotten back in line.
01:11 PM: Douglas Ramsey is getting help from Charles
01:15 PM: Paris Bennett has arrived in Arsalan
01:16 PM: Douglas Ramsey has no more questions and will now return the laptop
01:17 PM: Paris Bennett has borrowed Laptop 23662766 and moved to the TA Line
01:17 PM: Paris Bennett is getting help from Charles
01:18 PM: Douglas Ramsey has returned laptop 68428759 and went home HAPPY.
01:22 PM: Remy LeBeau has arrived in Arsalan
01:22 PM: Paris Bennett has had one question answered and gotten back in line.
01:22 PM: Paris Bennett is getting help from Charles
01:24 PM: Remy LeBeau has borrowed Laptop 68428759 and moved to the TA Line
01:27 PM: Paris Bennett has had one question answered and gotten back in line.
01:27 PM: Remy LeBeau is getting help from Charles
01:28 PM: Karima Shapandar has arrived in Arsalan
01:30 PM: Karima Shapandar has borrowed Laptop 45594438 and moved to the TA Line
01:32 PM: Remy LeBeau has had one question answered and gotten back in line.
01:32 PM: Paris Bennett is getting help from Charles
01:35 PM: Alison Blaire has arrived in Arsalan
01:37 PM: Alison Blaire has borrowed Laptop 49976149 and moved to the TA Line
01:37 PM: Paris Bennett has had one question answered and gotten back in line.
01:37 PM: Karima Shapandar is getting help from Charles
01:42 PM: Karima Shapandar has had one question answered and gotten back in line.
01:42 PM: Remy LeBeau is getting help from Charles
01:47 PM: Remy LeBeau has had one question answered and gotten back in line.
01:47 PM: Alison Blaire is getting help from Charles
01:52 PM: Alison Blaire has had one question answered and gotten back in line.
01:52 PM: Paris Bennett is getting help from Charles
01:57 PM: Paris Bennett has had one question answered and gotten back in line.
01:57 PM: Karima Shapandar is getting help from Charles
02:02 PM: Karima Shapandar has had one question answered and gotten back in line.
02:02 PM: Remy LeBeau is getting help from Charles
02:07 PM: Remy LeBeau has no more questions and will now return the laptop
02:07 PM: Alison Blaire is getting help from Charles
02:08 PM: Remy LeBeau has returned laptop 68428759 and went home HAPPY.
02:12 PM: Alison Blaire has had one question answered and gotten back in line.
02:12 PM: Paris Bennett is getting help from Charles
02:17 PM: Paris Bennett has no more questions and will now return the laptop
02:17 PM: Karima Shapandar is getting help from Charles
02:18 PM: Robert Kelly has arrived in Arsalan
02:19 PM: Paris Bennett has returned laptop 23662766 and went home HAPPY.
02:21 PM: Robert Kelly has borrowed Laptop 23662766 and moved to the TA Line
02:22 PM: Karima Shapandar has had one question answered and gotten back in line.
02:22 PM: Alison Blaire is getting help from Charles
02:27 PM: Alison Blaire has had one question answered and gotten back in line.
02:27 PM: Robert Kelly is getting help from Charles
02:32 PM: Robert Kelly has had one question answered and gotten back in line.
02:32 PM: Karima Shapandar is getting help from Charles
02:37 PM: Karima Shapandar has had one question answered and gotten back in line.
02:37 PM: Alison Blaire is getting help from Charles
02:42 PM: Alison Blaire has no more questions and will now return the laptop
02:42 PM: Robert Kelly is getting help from Charles
02:44 PM: Alison Blaire has returned laptop 49976149 and went home HAPPY.
02:47 PM: Robert Kelly has had one question answered and gotten back in line.
02:47 PM: Karima Shapandar is getting help from Charles
02:52 PM: Karima Shapandar has had one question answered and gotten back in line.
02:52 PM: Robert Kelly is getting help from Charles
02:56 PM: Rachel Summers has arrived in Arsalan
02:57 PM: Robert Kelly has had one question answered and gotten back in line.
02:57 PM: Karima Shapandar is getting help from Charles
02:58 PM: Rachel Summers has borrowed Laptop 49976149 and moved to the TA Line
03:00 PM: Charles has finished Lab Hours
03:00 PM: There are no TAs on duty. Arsalan is now closed.
03:01 PM: Robert Kelly has returned laptop 23662766 and went home FRUSTRATED.
03:02 PM: Rachel Summers has returned laptop 49976149 and went home FRUSTRATED.
03:02 PM: Karima Shapandar has no more questions and will now return the laptop
03:04 PM: Karima Shapandar has returned laptop 45594438 and went home HAPPY.

Monday's Lab Summary:
The TA Lab was open for 3 hours and 4 minutes. 9 students visited the lab.
Out of those students, only 7 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!

Day: Tuesday

12:00 PM: Charles has begun Lab Hours
12:08 PM: Victor Borkowski has arrived in Arsalan
12:10 PM: Victor Borkowski has borrowed Laptop 45594438 and moved to the TA Line
12:10 PM: Victor Borkowski is getting help from Charles
12:15 PM: Victor Borkowski has had one question answered and gotten back in line.
12:15 PM: Victor Borkowski is getting help from Charles
12:20 PM: Victor Borkowski has had one question answered and gotten back in line.
12:20 PM: Victor Borkowski is getting help from Charles
12:25 PM: Victor Borkowski has had one question answered and gotten back in line.
12:25 PM: Victor Borkowski is getting help from Charles
12:30 PM: Victor Borkowski has had one question answered and gotten back in line.
12:30 PM: Victor Borkowski is getting help from Charles
12:35 PM: Victor Borkowski has no more questions and will now return the laptop
12:37 PM: Victor Borkowski has returned laptop 45594438 and went home HAPPY.
12:39 PM: Kevin MacTaggert has arrived in Arsalan
12:40 PM: Scott Summers has arrived in Arsalan
12:41 PM: Kevin MacTaggert has borrowed Laptop 45594438 and moved to the TA Line
12:41 PM: Kevin MacTaggert is getting help from Charles
12:42 PM: Scott Summers has borrowed Laptop 49976149 and moved to the TA Line
12:46 PM: Kevin MacTaggert has had one question answered and gotten back in line.
12:46 PM: Scott Summers is getting help from Charles
12:47 PM: Namor McKenzie has arrived in Arsalan
12:49 PM: Namor McKenzie has borrowed Laptop 23662766 and moved to the TA Line
12:51 PM: Scott Summers has no more questions and will now return the laptop
12:51 PM: Kevin MacTaggert is getting help from Charles
12:53 PM: Scott Summers has returned laptop 49976149 and went home HAPPY.
12:56 PM: Kevin MacTaggert has had one question answered and gotten back in line.
12:56 PM: Namor McKenzie is getting help from Charles
12:59 PM: Robert Drake has arrived in Arsalan
01:01 PM: Robert Drake has borrowed Laptop 49976149 and moved to the TA Line
01:01 PM: Namor McKenzie has had one question answered and gotten back in line.
01:01 PM: Kevin MacTaggert is getting help from Charles
01:06 PM: Kevin MacTaggert has had one question answered and gotten back in line.
01:06 PM: Robert Drake is getting help from Charles
01:09 PM: Miranda Leevald has arrived in Arsalan
01:11 PM: Miranda Leevald has borrowed Laptop 68428759 and moved to the TA Line
01:11 PM: Robert Drake has had one question answered and gotten back in line.
01:11 PM: Namor McKenzie is getting help from Charles
01:16 PM: Namor McKenzie has had one question answered and gotten back in line.
01:16 PM: Kevin MacTaggert is getting help from Charles
01:21 PM: Kevin MacTaggert has no more questions and will now return the laptop
01:21 PM: Miranda Leevald is getting help from Charles
01:23 PM: Kevin MacTaggert has returned laptop 45594438 and went home HAPPY.
01:26 PM: Miranda Leevald has no more questions and will now return the laptop
01:26 PM: Robert Drake is getting help from Charles
01:28 PM: Miranda Leevald has returned laptop 68428759 and went home HAPPY.
01:31 PM: Robert Drake has had one question answered and gotten back in line.
01:31 PM: Namor McKenzie is getting help from Charles
01:36 PM: Namor McKenzie has had one question answered and gotten back in line.
01:36 PM: Robert Drake is getting help from Charles
01:41 PM: Robert Drake has had one question answered and gotten back in line.
01:41 PM: Namor McKenzie is getting help from Charles
01:46 PM: Namor McKenzie has had one question answered and gotten back in line.
01:46 PM: Robert Drake is getting help from Charles
01:51 PM: Robert Drake has had one question answered and gotten back in line.
01:51 PM: Namor McKenzie is getting help from Charles
01:56 PM: Namor McKenzie has had one question answered and gotten back in line.
01:56 PM: Robert Drake is getting help from Charles
01:57 PM: Megan Gwynn has arrived in Arsalan
01:59 PM: Megan Gwynn has borrowed Laptop 68428759 and moved to the TA Line
02:00 PM: Max has begun Lab Hours
02:00 PM: Charles has finished Lab Hours
02:00 PM: Namor McKenzie is getting help from Max
02:01 PM: Robert Drake has no more questions and will now return the laptop
02:03 PM: Robert Drake has returned laptop 49976149 and went home HAPPY.
02:05 PM: Namor McKenzie has no more questions and will now return the laptop
02:05 PM: Megan Gwynn is getting help from Max
02:07 PM: Namor McKenzie has returned laptop 23662766 and went home HAPPY.
02:10 PM: Megan Gwynn has had one question answered and gotten back in line.
02:10 PM: Megan Gwynn is getting help from Max
02:15 PM: Bolivar Trask has arrived in Arsalan
02:15 PM: Megan Gwynn has had one question answered and gotten back in line.
02:15 PM: Megan Gwynn is getting help from Max
02:16 PM: Calvin Rankin has arrived in Arsalan
02:17 PM: Bolivar Trask has borrowed Laptop 23662766 and moved to the TA Line
02:18 PM: Calvin Rankin has borrowed Laptop 49976149 and moved to the TA Line
02:20 PM: Megan Gwynn has had one question answered and gotten back in line.
02:20 PM: Bolivar Trask is getting help from Max
02:23 PM: David Haller has arrived in Arsalan
02:25 PM: David Haller has borrowed Laptop 45594438 and moved to the TA Line
02:25 PM: Bolivar Trask has had one question answered and gotten back in line.
02:25 PM: Calvin Rankin is getting help from Max
02:30 PM: Calvin Rankin has had one question answered and gotten back in line.
02:30 PM: Megan Gwynn is getting help from Max
02:35 PM: Megan Gwynn has had one question answered and gotten back in line.
02:35 PM: David Haller is getting help from Max
02:40 PM: David Haller has no more questions and will now return the laptop
02:40 PM: Bolivar Trask is getting help from Max
02:42 PM: David Haller has returned laptop 45594438 and went home HAPPY.
02:45 PM: Bolivar Trask has had one question answered and gotten back in line.
02:45 PM: Calvin Rankin is getting help from Max
02:50 PM: Calvin Rankin has no more questions and will now return the laptop
02:50 PM: Megan Gwynn is getting help from Max
02:52 PM: Calvin Rankin has returned laptop 49976149 and went home HAPPY.
02:54 PM: Lucas Bishop has arrived in Arsalan
02:55 PM: Megan Gwynn has no more questions and will now return the laptop
02:55 PM: Bolivar Trask is getting help from Max
02:56 PM: Lucas Bishop has borrowed Laptop 49976149 and moved to the TA Line
02:57 PM: Heather Cameron has arrived in Arsalan
02:57 PM: Megan Gwynn has returned laptop 68428759 and went home HAPPY.
02:59 PM: Heather Cameron has borrowed Laptop 68428759 and moved to the TA Line
03:00 PM: Bolivar Trask has had one question answered and gotten back in line.
03:00 PM: Lucas Bishop is getting help from Max
03:05 PM: Lucas Bishop has had one question answered and gotten back in line.
03:05 PM: Heather Cameron is getting help from Max
03:10 PM: Heather Cameron has had one question answered and gotten back in line.
03:10 PM: Bolivar Trask is getting help from Max
03:15 PM: Bolivar Trask has had one question answered and gotten back in line.
03:15 PM: Lucas Bishop is getting help from Max
03:20 PM: Lucas Bishop has had one question answered and gotten back in line.
03:20 PM: Heather Cameron is getting help from Max
03:22 PM: Tabitha Smith has arrived in Arsalan
03:23 PM: Jean Grey has arrived in Arsalan
03:24 PM: Tabitha Smith has borrowed Laptop 45594438 and moved to the TA Line
03:25 PM: Jean Grey has borrowed Laptop 35073907 and moved to the TA Line
03:25 PM: Heather Cameron has had one question answered and gotten back in line.
03:25 PM: Bolivar Trask is getting help from Max
03:27 PM: Kurt Wagner has arrived in Arsalan
03:29 PM: Kurt Wagner has borrowed Laptop 67237465 and moved to the TA Line
03:30 PM: Bolivar Trask has no more questions and will now return the laptop
03:30 PM: Lucas Bishop is getting help from Max
03:31 PM: Bolivar Trask has returned laptop 23662766 and went home HAPPY.
03:35 PM: Lucas Bishop has had one question answered and gotten back in line.
03:35 PM: Tabitha Smith is getting help from Max
03:40 PM: Tabitha Smith has had one question answered and gotten back in line.
03:40 PM: Jean Grey is getting help from Max
03:45 PM: Jean Grey has had one question answered and gotten back in line.
03:45 PM: Heather Cameron is getting help from Max
03:50 PM: Heather Cameron has no more questions and will now return the laptop
03:50 PM: Kurt Wagner is getting help from Max
03:52 PM: Warren Worthington has arrived in Arsalan
03:52 PM: Heather Cameron has returned laptop 68428759 and went home HAPPY.
03:54 PM: Warren Worthington has borrowed Laptop 68428759 and moved to the TA Line
03:55 PM: Kurt Wagner has had one question answered and gotten back in line.
03:55 PM: Lucas Bishop is getting help from Max
04:00 PM: Max has finished Lab Hours
04:00 PM: There are no TAs on duty. Arsalan is now closed.
04:00 PM: Lucas Bishop has had one question answered but must return the laptop now and exit the lab.
04:01 PM: Tabitha Smith has returned laptop 45594438 and went home FRUSTRATED.
04:02 PM: Jean Grey has returned laptop 35073907 and went home FRUSTRATED.
04:03 PM: Warren Worthington has returned laptop 68428759 and went home FRUSTRATED.
04:04 PM: Kurt Wagner has returned laptop 67237465 and went home FRUSTRATED.
04:05 PM: Lucas Bishop has returned laptop 49976149 and went home FRUSTRATED.

Tuesday's' Lab Summary:
The TA Lab was open for 4 hours and 5 minutes. 16 students visited the lab.
Out of those students, only 11 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!

Day: Wednesday

12:00 PM: Max has begun Lab Hours
12:06 PM: Jason Wyngarde has arrived in Arsalan
12:08 PM: Jason Wyngarde has borrowed Laptop 49976149 and moved to the TA Line
12:08 PM: Jason Wyngarde is getting help from Max
12:09 PM: Shen Xorn has arrived in Arsalan
12:10 PM: Henry McCoy has arrived in Arsalan
12:11 PM: Shen Xorn has borrowed Laptop 67237465 and moved to the TA Line
12:12 PM: Henry McCoy has borrowed Laptop 68428759 and moved to the TA Line
12:13 PM: Jason Wyngarde has had one question answered and gotten back in line.
12:13 PM: Shen Xorn is getting help from Max
12:14 PM: Jeanne-Marie Beaubier has arrived in Arsalan
12:16 PM: Jeanne-Marie Beaubier has borrowed Laptop 35073907 and moved to the TA Line
12:17 PM: Illyana Rasputina has arrived in Arsalan
12:18 PM: Shen Xorn has had one question answered and gotten back in line.
12:18 PM: Henry McCoy is getting help from Max
12:19 PM: Illyana Rasputina has borrowed Laptop 45594438 and moved to the TA Line
12:23 PM: Henry McCoy has had one question answered and gotten back in line.
12:23 PM: Jason Wyngarde is getting help from Max
12:24 PM: Gabriel Summers has arrived in Arsalan
12:25 PM: Nathan Summers has arrived in Arsalan
12:26 PM: Gabriel Summers has borrowed Laptop 23662766 and moved to the TA Line
12:27 PM: Nathan Summers has borrowed Laptop 89594006 and moved to the TA Line
12:28 PM: Jason Wyngarde has had one question answered and gotten back in line.
12:28 PM: Jeanne-Marie Beaubier is getting help from Max
12:32 PM: Suzanne Chan has arrived in Arsalan
12:33 PM: Jeanne-Marie Beaubier has had one question answered and gotten back in line.
12:33 PM: Shen Xorn is getting help from Max
12:34 PM: Suzanne Chan has borrowed Laptop 28698737 and moved to the TA Line
12:38 PM: Shen Xorn has no more questions and will now return the laptop
12:38 PM: Illyana Rasputina is getting help from Max
12:40 PM: Shen Xorn has returned laptop 67237465 and went home HAPPY.
12:43 PM: Illyana Rasputina has had one question answered and gotten back in line.
12:43 PM: Henry McCoy is getting help from Max
12:48 PM: Henry McCoy has had one question answered and gotten back in line.
12:48 PM: Gabriel Summers is getting help from Max
12:52 PM: Lorna Dane has arrived in Arsalan
12:53 PM: Gabriel Summers has had one question answered and gotten back in line.
12:53 PM: Nathan Summers is getting help from Max
12:54 PM: Lorna Dane has borrowed Laptop 67237465 and moved to the TA Line
12:58 PM: Nathan Summers has had one question answered and gotten back in line.
12:58 PM: Jason Wyngarde is getting help from Max
01:02 PM: Karl Lykos has arrived in Arsalan
01:03 PM: Jason Wyngarde has no more questions and will now return the laptop
01:03 PM: Jeanne-Marie Beaubier is getting help from Max
01:04 PM: Karl Lykos has borrowed Laptop 24350204 and moved to the TA Line
01:05 PM: Jason Wyngarde has returned laptop 49976149 and went home HAPPY.
01:08 PM: Jeanne-Marie Beaubier has had one question answered and gotten back in line.
01:08 PM: Suzanne Chan is getting help from Max
01:13 PM: Yuriko Oyama has arrived in Arsalan
01:13 PM: Suzanne Chan has had one question answered and gotten back in line.
01:13 PM: Illyana Rasputina is getting help from Max
01:15 PM: Yuriko Oyama has borrowed Laptop 49976149 and moved to the TA Line
01:18 PM: Illyana Rasputina has had one question answered and gotten back in line.
01:18 PM: Henry McCoy is getting help from Max
01:23 PM: Henry McCoy has had one question answered and gotten back in line.
01:23 PM: Gabriel Summers is getting help from Max
01:28 PM: Roberto Da_Costa has arrived in Arsalan
01:28 PM: Gabriel Summers has had one question answered and gotten back in line.
01:28 PM: Lorna Dane is getting help from Max
01:30 PM: Roberto Da_Costa has borrowed Laptop 24124626 and moved to the TA Line
01:33 PM: Lorna Dane has no more questions and will now return the laptop
01:33 PM: Nathan Summers is getting help from Max
01:34 PM: Lorna Dane has returned laptop 67237465 and went home HAPPY.
01:38 PM: Nathan Summers has had one question answered and gotten back in line.
01:38 PM: Karl Lykos is getting help from Max
01:43 PM: Karl Lykos has had one question answered and gotten back in line.
01:43 PM: Jeanne-Marie Beaubier is getting help from Max
01:45 PM: Madelyne Pryor has arrived in Arsalan
01:45 PM: Armando Munoz has arrived in Arsalan
01:47 PM: Victor Creed has arrived in Arsalan
01:47 PM: Madelyne Pryor has borrowed Laptop 67237465 and moved to the TA Line
01:48 PM: Noriko Ashida has arrived in Arsalan
01:48 PM: Armando Munoz has borrowed Laptop 88812998 and moved to the TA Line
01:48 PM: Jeanne-Marie Beaubier has had one question answered and gotten back in line.
01:48 PM: Suzanne Chan is getting help from Max
01:49 PM: Victor Creed has borrowed Laptop 70571329 and moved to the TA Line
01:50 PM: Noriko Ashida has borrowed Laptop 46933604 and moved to the TA Line
01:53 PM: Suzanne Chan has had one question answered and gotten back in line.
01:53 PM: Yuriko Oyama is getting help from Max
01:55 PM: Kitty Pryde has arrived in Arsalan
01:57 PM: Kitty Pryde has borrowed Laptop 71281199 and moved to the TA Line
01:58 PM: Yuriko Oyama has had one question answered and gotten back in line.
01:58 PM: Illyana Rasputina is getting help from Max
02:00 PM: Charles has begun Lab Hours
02:00 PM: Henry McCoy is getting help from Charles
02:03 PM: Illyana Rasputina has no more questions and will now return the laptop
02:03 PM: Gabriel Summers is getting help from Max
02:05 PM: Illyana Rasputina has returned laptop 45594438 and went home HAPPY.
02:05 PM: Henry McCoy has had one question answered and gotten back in line.
02:05 PM: Roberto Da_Costa is getting help from Charles
02:08 PM: Nathaniel Essex has arrived in Arsalan
02:08 PM: Gabriel Summers has had one question answered and gotten back in line.
02:08 PM: Nathan Summers is getting help from Max
02:10 PM: Nathaniel Essex has borrowed Laptop 45594438 and moved to the TA Line
02:10 PM: Roberto Da_Costa has no more questions and will now return the laptop
02:10 PM: Karl Lykos is getting help from Charles
02:12 PM: Roberto Da_Costa has returned laptop 24124626 and went home HAPPY.
02:13 PM: Nathan Summers has had one question answered and gotten back in line.
02:13 PM: Madelyne Pryor is getting help from Max
02:15 PM: Karl Lykos has had one question answered and gotten back in line.
02:15 PM: Armando Munoz is getting help from Charles
02:18 PM: Madelyne Pryor has had one question answered and gotten back in line.
02:18 PM: Jeanne-Marie Beaubier is getting help from Max
02:20 PM: Armando Munoz has had one question answered and gotten back in line.
02:20 PM: Victor Creed is getting help from Charles
02:23 PM: Jeanne-Marie Beaubier has had one question answered and gotten back in line.
02:23 PM: Noriko Ashida is getting help from Max
02:25 PM: Victor Creed has had one question answered and gotten back in line.
02:25 PM: Suzanne Chan is getting help from Charles
02:28 PM: Noriko Ashida has had one question answered and gotten back in line.
02:28 PM: Kitty Pryde is getting help from Max
02:30 PM: Suzanne Chan has had one question answered and gotten back in line.
02:30 PM: Yuriko Oyama is getting help from Charles
02:33 PM: Kitty Pryde has had one question answered and gotten back in line.
02:33 PM: Henry McCoy is getting help from Max
02:34 PM: Cameron Hodge has arrived in Arsalan
02:35 PM: Yuriko Oyama has had one question answered and gotten back in line.
02:35 PM: Gabriel Summers is getting help from Charles
02:36 PM: Cameron Hodge has borrowed Laptop 24124626 and moved to the TA Line
02:38 PM: Henry McCoy has no more questions and will now return the laptop
02:38 PM: Nathaniel Essex is getting help from Max
02:40 PM: Henry McCoy has returned laptop 68428759 and went home HAPPY.
02:40 PM: Gabriel Summers has had one question answered and gotten back in line.
02:40 PM: Nathan Summers is getting help from Charles
02:42 PM: Regan Wyngarde has arrived in Arsalan
02:43 PM: Nathaniel Essex has had one question answered and gotten back in line.
02:43 PM: Karl Lykos is getting help from Max
02:44 PM: Regan Wyngarde has borrowed Laptop 68428759 and moved to the TA Line
02:45 PM: Nathan Summers has had one question answered and gotten back in line.
02:45 PM: Madelyne Pryor is getting help from Charles
02:48 PM: Karl Lykos has no more questions and will now return the laptop
02:48 PM: Armando Munoz is getting help from Max
02:50 PM: Karl Lykos has returned laptop 24350204 and went home HAPPY.
02:50 PM: Madelyne Pryor has had one question answered and gotten back in line.
02:50 PM: Jeanne-Marie Beaubier is getting help from Charles
02:53 PM: Armando Munoz has had one question answered and gotten back in line.
02:53 PM: Victor Creed is getting help from Max
02:55 PM: Jeanne-Marie Beaubier has no more questions and will now return the laptop
02:55 PM: Noriko Ashida is getting help from Charles
02:57 PM: Jeanne-Marie Beaubier has returned laptop 35073907 and went home HAPPY.
02:58 PM: Victor Creed has had one question answered and gotten back in line.
02:58 PM: Suzanne Chan is getting help from Max
02:59 PM: Joshua Foley has arrived in Arsalan
03:00 PM: Noriko Ashida has no more questions and will now return the laptop
03:00 PM: Kitty Pryde is getting help from Charles
03:00 PM: Max has finished Lab Hours
03:01 PM: William Stryker has arrived in Arsalan
03:01 PM: Joshua Foley has borrowed Laptop 35073907 and moved to the TA Line
03:02 PM: Noriko Ashida has returned laptop 46933604 and went home HAPPY.
03:03 PM: Suzanne Chan has had one question answered and gotten back in line.
03:04 PM: William Stryker has borrowed Laptop 46933604 and moved to the TA Line
03:05 PM: Kitty Pryde has had one question answered and gotten back in line.
03:05 PM: Yuriko Oyama is getting help from Charles
03:09 PM: Piotr Rasputin has arrived in Arsalan
03:10 PM: Yuriko Oyama has had one question answered and gotten back in line.
03:10 PM: Cameron Hodge is getting help from Charles
03:11 PM: Piotr Rasputin has borrowed Laptop 24350204 and moved to the TA Line
03:15 PM: Cameron Hodge has had one question answered and gotten back in line.
03:15 PM: Gabriel Summers is getting help from Charles
03:20 PM: Gabriel Summers has no more questions and will now return the laptop
03:20 PM: Nathaniel Essex is getting help from Charles
03:21 PM: Gabriel Summers has returned laptop 23662766 and went home HAPPY.
03:25 PM: Neena Thurman has arrived in Arsalan
03:25 PM: Nathaniel Essex has no more questions and will now return the laptop
03:25 PM: Regan Wyngarde is getting help from Charles
03:27 PM: Neena Thurman has borrowed Laptop 23662766 and moved to the TA Line
03:28 PM: Nathaniel Essex has returned laptop 45594438 and went home HAPPY.
03:30 PM: Regan Wyngarde has no more questions and will now return the laptop
03:30 PM: Nathan Summers is getting help from Charles
03:31 PM: Regan Wyngarde has returned laptop 68428759 and went home HAPPY.
03:35 PM: Nathan Summers has had one question answered and gotten back in line.
03:35 PM: Madelyne Pryor is getting help from Charles
03:40 PM: Madelyne Pryor has had one question answered and gotten back in line.
03:40 PM: Armando Munoz is getting help from Charles
03:45 PM: Armando Munoz has had one question answered and gotten back in line.
03:45 PM: Victor Creed is getting help from Charles
03:50 PM: Ruth Aldine has arrived in Arsalan
03:50 PM: Tyrone Johnson has arrived in Arsalan
03:50 PM: Victor Creed has no more questions and will now return the laptop
03:50 PM: Joshua Foley is getting help from Charles
03:52 PM: Ruth Aldine has borrowed Laptop 68428759 and moved to the TA Line
03:53 PM: Tyrone Johnson has borrowed Laptop 45594438 and moved to the TA Line
03:54 PM: Victor Creed has returned laptop 70571329 and went home HAPPY.
03:55 PM: Joshua Foley has no more questions and will now return the laptop
03:55 PM: Suzanne Chan is getting help from Charles
03:56 PM: Joshua Foley has returned laptop 35073907 and went home HAPPY.
04:00 PM: Charles has finished Lab Hours
04:00 PM: There are no TAs on duty. Arsalan is now closed.
04:00 PM: Suzanne Chan has had one question answered but must return the laptop now and exit the lab.
04:01 PM: William Stryker has returned laptop 46933604 and went home FRUSTRATED.
04:02 PM: Kitty Pryde has returned laptop 71281199 and went home FRUSTRATED.
04:03 PM: Yuriko Oyama has returned laptop 49976149 and went home FRUSTRATED.
04:04 PM: Piotr Rasputin has returned laptop 24350204 and went home FRUSTRATED.
04:05 PM: Cameron Hodge has returned laptop 24124626 and went home FRUSTRATED.
04:06 PM: Neena Thurman has returned laptop 23662766 and went home FRUSTRATED.
04:07 PM: Nathan Summers has returned laptop 89594006 and went home HAPPY.
04:08 PM: Madelyne Pryor has returned laptop 67237465 and went home FRUSTRATED.
04:09 PM: Armando Munoz has returned laptop 88812998 and went home HAPPY.
04:10 PM: Ruth Aldine has returned laptop 68428759 and went home FRUSTRATED.
04:11 PM: Tyrone Johnson has returned laptop 45594438 and went home FRUSTRATED.
04:12 PM: Suzanne Chan has returned laptop 28698737 and went home HAPPY.
```

*Wednesday's Lab Summary*
The TA Lab was open for 4 hours and 12 minutes. 26 students visited the lab.
Out of those students, only 17 left happy.
remaining left frustrated.

Lesson Learned:  Do not procrastinate!  Start programs early!


