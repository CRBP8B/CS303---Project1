#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

class AssignTracker{

private:
	list<Assignment> assignedList;
	list<Assignment> completedList;
	void keepOrdered();

public:
	string printAssigned();
	string printCompleted();
	bool addAssignment(Assignment newAssign)
	{
		newAssign.getAssignedDate().check_valid();  //Check if date is valid

		if (assignedList.empty())    //if empty, just add it to the list, no frills
		{
			assignedList.push_front(newAssign);
			return true;
		}

		list<Assignment>::iterator it = assignedList.begin();

		while (it->getAssignedDate() < newAssign.getAssignedDate() && (it != assignedList.end()))
		{
			++it;
		}
		assignedList.insert(it,newAssign);
		return true;
	}
	bool completeAssignment(Assignment toBeComp);
	bool editAssignment(Date filter);
	bool readIn(istream& file);
	int countLate();

};