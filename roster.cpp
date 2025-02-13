#include <cassert> // allows you to assert file has been opened
#include <fstream> // allows you open and read/write local files
#include <iomanip> // allows for output manipulations such as setw
#include <iostream> // allows input and output of messages such as cout/cin
#include <string> // allows the use of getline
#include "roster.h" // include roster.h so we can access class public and private initilization for student
using namespace std;

// a value constructor, the parameter is the course name
// Create an empty roster, i.e. studentNum = 0 for
// a specific course
Roster::Roster(string courseName)
{
	courseName = courseName;
}

// This function reads student information from a file
// The parameter is a file name
// post-condition: 
//		students contains student information read from the file
//		studentNum is the number of students read from the file	
void Roster::readStudentRecord(string filename)
{
	// initialize values
	const int fileEnd = 18;
	string line;
	string tempID, tempName, tempCLA, tempOLA, tempQuiz, tempHomework, tempExam, tempBonus;

	// open file
	ifstream studentFile(filename);
	// assert that file is open
	assert(studentFile);
	// if file doesnt open cout message
	if (!studentFile.is_open())
	{
		cout << "Error opening grades.dat file" << endl;
		return;
	}
	// use getline to start reading string values found in file
	getline(studentFile, line);
	// use getline twice to remove second line in file as it contains unneeded info
	getline(studentFile, line);

	// loop through file until end and store all info within student class array
	for (int i = 1; i < fileEnd; i++)
	{
		// read in all lines from file
		studentFile >> tempID >> tempName >> tempCLA >> tempOLA >> tempQuiz >> tempHomework >> tempExam >> tempBonus;

		// Call class Student functions to set values contained within file to correct value.
		// set up call is like: students[i] = student/roster (in main) --- see next line
		// then setID(value) = isValid(studentID) (also in main) <-- not the same value obv but set up is the same
		students[i].setID(tempID);
		students[i].setName(tempName);
		students[i].changeScore(students[i].CLA, stoi(tempCLA));
		students[i].changeScore(students[i].OLA, stoi(tempOLA));
		students[i].changeScore(students[i].QUIZ, stoi(tempQuiz));
		students[i].changeScore(students[i].HOMEWORK, stoi(tempHomework));
		students[i].changeScore(students[i].EXAM, stoi(tempExam));
		students[i].changeScore(students[i].BONUS, stoi(tempBonus));
		// SET ALL VALUES WITHIN THIS SECTION AS THIS IS WERE WE LOAD ALL VALUES INTO ARRAY
		students[i].ComputeTotal(); 
		students[i].ComputeGrade();
	}

	// Display information for all students
	cout << "Here is the information for the 17 students in Class CSCI3110" << endl;
	// lists out header above student info
	cout << left << setw(10) << "ClassID" << setw(15) << "Name" << setw(5) << "CLA"
		<< setw(5) << "OLA" << setw(5) << "Quiz" << setw(10) << "Homework"
		<< setw(5) << "Exam" << setw(5) << "Bonus" << endl << endl;
	for (int i = 1; i < fileEnd; ++i)
	{
		cout << left << setw(10) << students[i].getID() << setw(15) << students[i].getName()
			<< setw(5) << students[i].getScore(students[i].CLA) << setw(5) << students[i].getScore(students[i].OLA)
			<< setw(5) << students[i].getScore(students[i].QUIZ) << setw(10) << students[i].getScore(students[i].HOMEWORK)
			<< setw(5) << students[i].getScore(students[i].EXAM) << setw(5) << students[i].getScore(students[i].BONUS) << endl;
	}
	studentFile.close();

}

// This function returns the number of students in the class roster  
// post-condition: the studentNum value is returned
int Roster::GetStudentCount() const
{
	// get the count of students in the roster
	int count = 0;
	while (count < MAX_NUM && !students[count].getID().empty()) 
	{
		++count;
	}
	// return studentNum value to main
	return count;
}

// This function determines whether there is a student with "id" in the class roster
// post-condition: if there is a student in class with this "id", true is returned
//                 Otherwise, false is returned
bool Roster::isValid(string id) const
{
	// loops through all student classID's.
	for (int i = 0; i < MAX_NUM; ++i)
	{
		// verify if user input classID is valid
		if(students[i].getID() == id)
		{
			//  if true value is sent back to main function
			return true;
		}
	}
	// if false sent back to main requiring new user input
	return false;
}

// This function displays all the information of one student, one value per line
// This function also displays the total score and letter grade of the student with the id given
// pre-condition: a valid user id is provided
// post-condition: All information of the student with the given id is displayed, 
//                 one value per line with label
void Roster::ShowOneStudent(string id) const
{
	// loop through all students contained within array
	for (int i = 0; i < MAX_NUM; ++i) 
	{
		// find user input student classID
		if (students[i].getID() == id)
		{
			// send that student placement within array to "DisplayInfo" function
			students[i].DisplayInfo();
			return;
		}
	}
}