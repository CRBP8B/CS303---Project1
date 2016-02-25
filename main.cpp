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
	
	//menu containing our assignment tracker is created
	Menu menu;
	string inputFile = ""; //input and output file name variables created
	string outputFile = "";
	int answer;

	string dueDate;
	string description;
	string assignDate;
	string status;
	string completeDate;
	bool loop = true;
	

	cout << "Which file should the assignments be read from?" << endl; //before we enter the menu, check to what the file is called. Read it in.
	cin >> inputFile;
	menu.readFileIn(inputFile);

	while (loop)
	{
		//output menu to screen, ask for answer
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
		case 0: //0: break from loop
		{
			loop = false;
			break;
		}
		case 1: //1: print all assignments
		{
			cout << menu.printAll() << endl;
			break;
		}
		case 2: //2: Create new assignment. Get the attributes from user.
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
		case 3: //3: Edit the due date of an assignment in the list
		{
			cout << "Enter the assigned date of the assignment you would like to edit, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the new due date, MM/DD/YYYY format" << endl;
			cin >> dueDate;

			menu.editDueDate(assignDate, dueDate);
			break;
		}
		case 4: //4: Edit the the description of an assignment
		{
			cout << "Enter the assigned date of the assignment you would like to edit, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the new description" << endl;
			cin.ignore();
			getline(cin, description);

			menu.editDescription(assignDate, description);
			break;
		}
		case 5: //5: Completed an assignment on the assigned list
		{
			cout << "Enter the assigned date of the assignment you would like to complete, MM/DD/YYYY format" << endl;
			cin >> assignDate;
			cout << "Enter the date it was completed, MM/DD/YYYY format" << endl;
			cin >> completeDate;
		
			menu.completeAssignment(assignDate, completeDate);

			break;
		}
		case 6: //6: Print out the number of late assignments
		{
			cout << menu.printNumberLate() << endl;
			break;
		}
		case 7: // 7: Change the name of the outputfile
		{
			cout << "Enter the file name that you would like to save to, including extension" << endl;
			cin >> outputFile;
			break;
		}
		case 8: //8: Save to file
		{
			if (outputFile == "") //if there isn't a filename that has been input, ask for the filename
			{
				cout << "Enter the file name that you would like to save to, including extension" << endl;
				cin >> outputFile;
			}
			menu.saveToFile(outputFile);
			break;
		}

		}

		
	}

	
	
	


	
}