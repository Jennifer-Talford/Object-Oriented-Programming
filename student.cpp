#include <iostream> // allows input and output of messages such as cout/cin
#include <string> // allows the use of getline
#include "student.h" // include student.h so we can access class public and private initilization for student
using namespace std;

// default constructor. This is necessary since we define an array 
// of students in the class Roster
Student::Student()
{
	id = "";
	name = "";
	score[CATEGORY_NUM] = 0;
	total = 0;
	letterGrade = 'F';
}

// copy constructor
Student::Student(const Student& s)
{
	id = s.id;
	name = s.name;
	score[CATEGORY_NUM] = s.score[CATEGORY_NUM];
	total = s.total;
	letterGrade = s.letterGrade;
}

//Accessor of id 
string Student::getID() const
{
	return id;
}

// Mutator of id 
void Student::setID(string ID)
{
	id = ID;
}

// Mutator of total (score)
void Student::ComputeTotal()
{
	// loop through all students "score" and add them together for "total"
	for (int i = 0; i < CATEGORY_NUM; ++i) 
	{
		total += score[i];
	}
}

// Accessor of total (score)
int Student::GetTotal() const
{
	return total;
}

// Mutator of letter grade
void Student::ComputeGrade()
{
	// check value of total to set "letterGrade"
	if (total >= 90)
	{
		letterGrade = 'A';
	}
	if (total >= 80 && total < 90)
	{
		letterGrade = 'B';
	}
	if (total >= 70 && total < 80)
	{
		letterGrade = 'C';
	}
	if (total >= 60 && total < 70)
	{
		letterGrade = 'D';
	}
	if (total < 60)
	{
		letterGrade = 'F';
	}
}

// Accessor of letter grade
char Student::GetGrade() const
{
	return letterGrade;
}

//ScoreType indicates which score you want to access
//Mutator of m_score
void Student::changeScore(ScoreType scoreName, int scoreValue)
{
	//uses array type - enum ScoreType { CLA, OLA, QUIZ, HOMEWORK, EXAM, BONUS } - to store values
	score[scoreName] = scoreValue;
}

//Accessor of m_score
int Student::getScore(ScoreType scoreName) const
{
	return score[scoreName];
}

//Accessor of name 
string Student::getName() const
{
	return name;
}

//Mutator of name 
void Student::setName(string Name)
{
	name = Name;
}

// This function displays information of one student, one value per row 
// label for each value is included
// total score and letter grade are also included
void Student::DisplayInfo() const
{
	// cout values for single student specified by user input student ID
	cout << "Information for student with ID " << id << endl;
	cout << "Here is the information for student with ID: " << id << endl;
	cout << "------------------------------------" << endl;
	cout << "Name : " << name << endl;
	// find the enum type CLA value and output it
	cout << "CLA : " << score[CLA] << endl;
	// find the enum type OLA value and output it
	cout << "OLA : " << score[OLA] << endl;
	// find the enum type QUIZ value and output it
	cout << "Quiz : " << score[QUIZ] << endl;
	// find the enum type HOMEWORK value and output it
	cout << "Homework : " << score[HOMEWORK] << endl;
	// find the enum type EXAM value and output it
	cout << "Exam : " << score[EXAM] << endl;
	// find the enum type BONUS value and output it
	cout << "Bonus : " << score[BONUS] << endl;
	cout << "------------------------------------" << endl;
	// cout values for total
	cout << "Total Score : " << total << endl;
	// cout values for letterGrade
	cout << "Final Grade : " << letterGrade << endl;
}