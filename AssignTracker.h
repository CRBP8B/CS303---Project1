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
	void addCompleted(Assignment assign)
	{
		assign.getAssignedDate().check_valid();//Check if date is valid
		assign.getDueDate().check_valid();

		if (completedList.empty())    //if empty, just add it to the list, no frills
		{
			completedList.push_front(assign);
			return;
		}

		list<Assignment>::iterator it = completedList.begin();

		while ((it->getAssignedDate() < assign.getAssignedDate()) && (it != completedList.end()))
		{
			++it;
		}
		completedList.insert(it, assign);
		return;

	}

public:
	string printAssigned();
	string printCompleted();
	bool addAssignment(Assignment newAssign)
	{
		newAssign.getAssignedDate().check_valid();  //Check if date is valid
		newAssign.getDueDate().check_valid();

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
/*	bool completeAssignment(Date assigned, Date completed)
	{
		list<Assignment>::iterator it = assignedList.begin();
		
		if (assignedList.empty()) //if the list is empty, return false
			throw("The list is empty.");

		
		while (it->getAssignedDate() != assigned && it != assignedList.end())   //iterate through list, find the assignment, if possible
		{
			it++;   //Error <--------- const
		}
		

		if (it == assignedList.end())  //if it cannot find the item, throw error
			throw("Cannot find item");
		Assignment toBeComp = *it;

		if (completed > toBeComp.getDueDate())
		{
			toBeComp.setStatus("late");
		}
		else
			toBeComp.setStatus("completed");

		
		addCompleted(toBeComp);      //add to completed list, and remove from the assigned list
		assignedList.erase(it);
		return true;

	}*/
	bool completeAssignment(Date assigned, Date completed)
	{
		assigned.check_valid();
		completed.check_valid();

		if (assignedList.empty())
		{
			throw invalid_argument("list is empty");
		}
		list<Assignment>::iterator itr;

		for (itr = assignedList.begin(); itr != assignedList.end(); ++itr)
		{
			if (itr->getAssignedDate() == assigned)
				break;
		}

		if (itr == assignedList.end())
			throw invalid_argument("Not in list");

		Assignment toBeComp = *itr;

		if (completed > toBeComp.getDueDate())
			toBeComp.setStatus("late");
		else
			toBeComp.setStatus("completed");

		addCompleted(toBeComp);
		assignedList.erase(itr);


		return true;

	}

	bool editAssignment(Date filter);
	bool readIn(istream& file);
	int countLate();
};