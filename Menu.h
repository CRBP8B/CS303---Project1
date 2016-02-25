#include <string>
#include "AssignTracker.h"
#include "Assignment.h"

#ifndef MENU_H
#define MENU_H
class Menu
{

private:
	AssignTracker tracker;
public:
	string printAll()
	{
		return (tracker.printAssigned() + tracker.printCompleted()); //calls the tracker's built in printAssigned and printCompleted functions, returns a STRING
	}
	
	bool addAssignment(Assignment assign) //takes in an assignment, and uses the tracker's built in addAssignment() function
	{
		return tracker.addAssignment(assign);
	}

	bool editDueDate(string assignDate, string newDueDate) //Takes in the assignDate and a newDueDate. Uses the tracker's editAssignment.
	{
		return tracker.editAssignment(Date(assignDate), Date(newDueDate));
	}

	bool editDescription(string assignDate, string newDescription) //takes in the assignDate and the new Description. Uses the take editAssignment function, and uses a Date() as a placeholder
	{
		return tracker.editAssignment(Date(assignDate), Date() , newDescription);
	}

	bool completeAssignment(string assignDate, string completeDate) //takes in the assigndate for locating the assignment. Completes the assignment on the completeDate using the completeAssignment function of the tracker
	{
		return tracker.completeAssignment(Date(assignDate), Date(completeDate));
	}

	int numberOfLateAssignments() //returns the int value of how many late assignments there are.
	{
		return tracker.countLate();
	}

	string printNumberLate() //uses the above function to output a string that states how many functions were late.
	{
		return ("There are " + to_string(numberOfLateAssignments()) + " late assignments\n");
	}

	void saveToFile(string outputFile = "output.txt") //Uses an output file (default = output.txt) to write to, using the printfunctions.
	{
		ofstream fout(outputFile);
		fout << tracker.printAssigned() << tracker.printCompleted();
		fout.close();
	}

	bool readFileIn(string inputFile) //uses the readIn function to read in assignments from a inputFile.
	{
		return tracker.readIn(inputFile);
	}
};

#endif