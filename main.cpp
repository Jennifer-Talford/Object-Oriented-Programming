#include <iostream> // allows input and output of messages such as cout/cin
#include "student.h" // include student.h so we can access class info for student
#include "roster.h" // include roster.h so we can access class info for roster
using namespace std;

int main()
{
	// Create/initialize a string type for user input student ID
	string studentID;
	// Create/initialize a Roster object
	Roster roster("CSCI 3110");
	// Create/initialize a Student object
	Student student;
	// Read student records from the "grades.dat" file
	roster.readStudentRecord("grades.dat");
	
	// ask for valid student ID
	cout << endl << "Enter a valid student ID: ";

	// while statement loops through until user inputs valid student ID
	while (true)
	{
		//get user input and set studentID value
		cin >> studentID;
		// call idValid function
		if (roster.isValid(studentID))
		{
			// once classID info found breaks out of while loop
			break;
		}
		// if user inputs invalid classID# repeat while loop
		else
		{
			// continue loop until user inputs valid student ID
			cout << endl << "Enter a valid student ID: ";
		}
	}

	// Display information for user specified student
	roster.ShowOneStudent(studentID);

	return 0;
}

