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
		return (tracker.printAssigned() + tracker.printCompleted());
	}

	bool addAssignment(Assignment assign)
	{
		return tracker.addAssignment(assign);
	}

	bool editDueDate(string assignDate, string newDueDate)
	{
		return tracker.editAssignment(Date(assignDate), Date(newDueDate));
	}

	bool editDescription(string assignDate, string newDescription)
	{
		return tracker.editAssignment(Date(assignDate), Date() , newDescription);
	}

	bool completeAssignment(string assignDate, string completeDate)
	{
		return tracker.completeAssignment(Date(assignDate), Date(completeDate));
	}

	int numberOfLateAssignments()
	{
		return tracker.countLate();
	}

	string printNumberLate()
	{
		return ("There are " + to_string(numberOfLateAssignments()) + " late assignments\n");
	}

	void saveToFile(string outputFile = "output.txt")
	{
		ofstream fout(outputFile);
		fout << tracker.printAssigned() << tracker.printCompleted();
		fout.close();
	}

	bool readFileIn(string inputFile)
	{
		return tracker.readIn(inputFile);
	}
};

#endif