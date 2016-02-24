#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;
#ifndef ASSIGNTRACKER_H
#define ASSIGNTRACKER_H

class AssignTracker{

private:
	list<Assignment> assignedList;
	list<Assignment> completedList;
	void keepOrdered();
	void addCompleted(Assignment assign)
	{
		assign.getAssignedDate().check_valid();//Check if date is valid
		assign.getDueDate().check_valid();

		if (assign.getDueDate() < assign.getAssignedDate())
		{
			return;
		}

		if (completedList.empty())    //if empty, just add it to the list, no frills
		{
			completedList.push_front(assign);
			return;
		}

		list<Assignment>::iterator it;

		for (it = completedList.begin(); it != completedList.end(); ++it)
		{
			if (assign.getDueDate() < it->getDueDate())
			{
				break;
			}
		}
		completedList.insert(it, assign);
		return;

	}

public:
	string printAssigned()
	{
		ostringstream output;
		for (list<Assignment>::iterator it = assignedList.begin(); it != assignedList.end(); ++it)
		{
			output << it->toString();
		}

		return output.str();
	}

	string printCompleted()
	{
		ostringstream output;
		for (list<Assignment>::iterator it = completedList.begin(); it != completedList.end(); ++it)
		{
			output << it->toString();
		}

		return output.str();
	}

	bool addAssignment(Assignment newAssign)
	{
		newAssign.getAssignedDate().check_valid();  //Check if date is valid
		newAssign.getDueDate().check_valid();
		
		if (newAssign.getDueDate() < newAssign.getAssignedDate())
		{
			return false;
		}
			
		if (newAssign.statusString() == "late" || newAssign.statusString() == "completed")
		{
			this->addCompleted(newAssign);
			return true;
		}

		if (assignedList.empty())    //if empty, just add it to the list, no frills
		{
			assignedList.push_front(newAssign);
			return true;
		}

		
		list<Assignment>::iterator it;

		for (it = assignedList.begin(); it != assignedList.end(); ++it)
		{
			if (newAssign.getDueDate() < it->getDueDate())
			{
				break;
			}
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
			return false;
		}
		list<Assignment>::iterator itr;

		for (itr = assignedList.begin(); itr != assignedList.end(); ++itr)
		{
			if (itr->getAssignedDate() == assigned)
				break;
		}

		if (itr == assignedList.end())
			return false;

		Assignment toBeComp = *itr;

		if (completed > toBeComp.getDueDate())
			toBeComp.setStatus("late");
		else
			toBeComp.setStatus("completed");

		addCompleted(toBeComp);
		assignedList.erase(itr);


		return true;

	}

	bool editAssignment(Date assigned, Date newDue = Date(), string newDesc = "")
	{
		assigned.check_valid();
		if (newDue != Date())
		{
			newDue.check_valid();
		}
		

		if (assignedList.empty())
		{
			return false;
		}

		list<Assignment>::iterator itr;

		for (itr = assignedList.begin(); itr != assignedList.end(); ++itr)
		{
			if (itr->getAssignedDate() == assigned)
				break;
		}

		if (itr == assignedList.end())
			return false;


		if (newDue != Date())
		{
			itr->setDueDate(newDue);
		}

		if (newDesc != "")
		{
			itr->setDescription(newDesc);
		}

		return true;

	}
	bool readIn(string file)
	{
		ifstream ifs;
		ifs.open(file);

		string line;
		string dueInput, assignedInput;
		string newStat, newDesc;
		

		while (ifs.good())
		{
			getline(ifs, line, '\n');
			String_Tokenizer st(line, ",");

			while (st.has_more_tokens())
			{
				dueInput = st.next_token();
				newDesc = st.next_token();


				newDesc = newDesc.substr(1);
				


				assignedInput = st.next_token();
				assignedInput = assignedInput.substr(1);
				newStat = st.next_token();
				newStat = newStat.substr(1);

				Assignment temp(Date(dueInput), newDesc, Date(assignedInput), newStat);
				if (newStat == "late" || newStat == "completed")
					this->addCompleted(temp);
				else
					this->addAssignment(temp);
			}
		}
		ifs.close();
		return true;
	}

	int countLate()
	{
		int lateCount = 0;
		list<Assignment>::iterator it;

		for (it = completedList.begin(); it != completedList.end(); ++it)
		{
			if (it->statusString() == "late")
			{
				++lateCount;
			}
		}

		return lateCount;
	}
};
#endif