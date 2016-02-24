#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "Menu.h"
#include "AssignTracker.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

void main(){
	
	Menu menu;
	string inputFile;
	string outputFile = inputFile;
	int answer;

	string dueDate;
	string description;
	char desc[20];
	string assignDate;
	string status;
	string completeDate;
	bool loop = true;
	

	cout << "Which file should the assignments be read from?" << endl;
	cin >> inputFile;
	menu.readFileIn(inputFile);

	while (loop)
	{
		cout << "What would you like to do?" << endl << endl <<
			"1. Display loaded assignments" << endl <<
			"2. Add an assignment" << endl <<
			"3. Edit a due date" << endl <<
			"4. Edit a description" << endl <<
			"5. Complete an assignment" << endl <<
			"6. Retrieve number of late assignments" << endl << endl <<
			"7. Change output file" << endl <<
			"8. Save to chosen file" << endl <<
			"0. Exit" << endl;
		cin >> answer;

		switch(answer)
		{
		case 0:
		{
			loop = false;
			break;
		}
		case 1:
		{
			cout << menu.printAll() << endl;
			break;
		}
		case 2:
		{
			cout << "Enter the due date, in the MM/DD/YYYY format" << endl;
			cin >> dueDate;
			cout << "Enter the description of the assignment" << endl;
			cin >> description;
			cout << "Enter the assigned date, in the MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the status of the assignment" << endl;
			cin >> status;

			menu.addAssignment(Assignment(Date(dueDate), description, Date(assignDate), status));
			break;
		}
		case 3:
		{
			cout << "Enter the assigned date of the assignment you would like to edit, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the new due date, MM/DD/YYYY format" << endl;
			cin >> dueDate;

			menu.editDueDate(assignDate, dueDate);
			break;
		}
		case 4:
		{
			cout << "Enter the assigned date of the assignment you would like to edit, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the new description" << endl;
			cin.ignore();
			getline(cin, description);

			menu.editDescription(assignDate, description);
			break;
		}
		case 5:
		{
			cout << "Enter the assigned date of the assignment you would like to complete, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the date it was completed, MM/DD/YYYY format" << endl;
			cin >> completeDate;
		
			menu.completeAssignment(assignDate, completeDate);

			break;
		}
		case 6:
		{
			cout << menu.printNumberLate() << endl;
			break;
		}
		case 7:
		{
			cout << "Enter the file name that you would like to save to, including extension" << endl;
			cin >> outputFile;
			break;
		}
		case 8:
		{
			menu.saveToFile(outputFile);
			break;
		}

		}

		
	}

	
	
	


	
}