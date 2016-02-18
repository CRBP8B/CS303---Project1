#ifndef ASSIGNTRACKER_H
#define ASSIGNTRACKER_H

#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "Ordered_List.h"
#include <iostream>
#include <fstream>
#include <sstream>



using namespace std;

class AssignTracker{

private:
	Ordered_List<Assignment> assignedList;
	Ordered_List<Assignment> completedList;
	void keepOrdered();

public:
	string displayAssignments()
	{
		ostringstream output;

		output << "Assigned: \n";
		output << this->printAssigned();

		output << "\n\n Completed: \n";
		output << this->printCompleted();

		return output.str();
	}
	string printAssigned()
	{
	
		for (Ordered_List<Assignment>::const_iterator ptr = assignedList.begin(); ptr != assignedList.end(); ++ptr)
			ptr->toString();

	}
	string printCompleted()
	{

		for (Ordered_List<Assignment>::const_iterator ptr = completedList.begin(); ptr != completedList.end(); ++ptr)
			ptr->toString();

	}
	bool addAssignment(Assignment newAssign) 
	{
		Date duedate = newAssign.getDueDate();
		Date assigneddate = newAssign.getAssignedDate();
		duedate.check_valid();
		assigneddate.check_valid();

		if (duedate <= assigneddate)
		{
			return false;
		}

		if (newAssign.getStatus() == 1)
		{
			for (Ordered_List<Assignment>::const_iterator ptr = assignedList.begin(); ptr != assignedList.end(); ++ptr)
			{
				if (newAssign.getAssignedDate() == ptr->getAssignedDate())
					return false;
			}

			assignedList.insert(newAssign);
			return true;
		}
	}
	bool completeAssignment(Assignment toBeComp);
	bool editAssignment(Date filter);
	bool readIn(istream& file);
	int countLate();

};
#endif