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
	list<Assignment> assignedList; //Keeps two lists, one ASSIGNED list, and one COMPLETED list. Late assignments go into the completed list
	list<Assignment> completedList;
	void addCompleted(Assignment assign) //This is a private function that adds an assignment directly to the COMPLETED list
	{
		assign.getAssignedDate().check_valid();//Check if dates are valid
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

		for (it = completedList.begin(); it != completedList.end(); ++it) //iterate through the list
		{
			if (assign.getDueDate() < it->getDueDate()) //if our new assignment has found its place, break
			{
				break;
			}
		}
		completedList.insert(it, assign); //insert it using the built it inset function
		return;

	}

public:
	string printAssigned() //this returns a STRING of all assigned assignments in the list
	{
		ostringstream output;
		for (list<Assignment>::iterator it = assignedList.begin(); it != assignedList.end(); ++it) //iterate through the list
		{
			output << it->toString(); //send it into the ostringstream using the built in toString() function
		}

		return output.str();
	}

	string printCompleted() //this returns a STRING of all completed assignments in the list
	{
		ostringstream output;
		for (list<Assignment>::iterator it = completedList.begin(); it != completedList.end(); ++it)
		{
			output << it->toString();
		}

		return output.str();
	}

	bool addAssignment(Assignment newAssign) //this adds an assignment to either list, depending on the status
	{
		newAssign.getAssignedDate().check_valid();  //Check if date is valid
		newAssign.getDueDate().check_valid();
		
		if (newAssign.getDueDate() < newAssign.getAssignedDate()) //if it
		{
			return false;
		}
			
		if (newAssign.statusString() == "late" || newAssign.statusString() == "completed") //if it's completed in any way, use the private addCompleted function
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

		for (it = assignedList.begin(); it != assignedList.end(); ++it) //iterate through the list, find the correct position
		{
			if (newAssign.getDueDate() < it->getDueDate())
			{
				break;
			}
		}
		assignedList.insert(it,newAssign); //insert it at that position
		return true;
	}

	bool completeAssignment(Date assigned, Date completed)
	{
		assigned.check_valid(); //check to make sure the dates are valid
		completed.check_valid();

		if (assignedList.empty()) //if the list is empty, it's obvious the assignment does not exist
		{
			return false;
		}
		list<Assignment>::iterator itr;

		for (itr = assignedList.begin(); itr != assignedList.end(); ++itr) //iterate through the list and find the assignment
		{
			if (itr->getAssignedDate() == assigned)
				break;
		}

		if (itr == assignedList.end()) //if it's the end, we didn't find it
			return false;

		Assignment toBeComp = *itr;

		if (completed > toBeComp.getDueDate()) //set the correct status
			toBeComp.setStatus("late");
		else
			toBeComp.setStatus("completed");

		addCompleted(toBeComp); //add to completedList
		assignedList.erase(itr); //remove from assigned


		return true;

	}

	bool editAssignment(Date assigned, Date newDue = Date(), string newDesc = "") //takes in the assigned date, can take in newDueDate or newDescription or both. changes either or. returns true if nothing went wrong
	{
		assigned.check_valid(); //checks to see if the assignedDate and possibly DueDate are valid
		if (newDue != Date())
		{
			newDue.check_valid();
		}
		

		if (assignedList.empty())
		{
			return false;
		}

		list<Assignment>::iterator itr;

		for (itr = assignedList.begin(); itr != assignedList.end(); ++itr) //find the assignment
		{
			if (itr->getAssignedDate() == assigned)
				break;
		}

		if (itr == assignedList.end()) //if we didn't find it, return false
			return false;


		if (newDue != Date()) //set the duedate, if necessary
		{
			itr->setDueDate(newDue);
		}

		if (newDesc != "")
		{
			itr->setDescription(newDesc); //set the desc, if necessary
		}

		return true;

	}
	bool readIn(string file) //reads the file with the name "file"  and reads the input into the correct list.
	{
		ifstream ifs; //start the ifstream with the "file" as the name
		ifs.open(file);

		string line;
		string dueInput, assignedInput;
		string newStat, newDesc;
		

		while (ifs.good()) //while there is more file to read
		{
			getline(ifs, line, '\n'); //read the next line in
			String_Tokenizer st(line, ","); //create a string tokenizer 

			while (st.has_more_tokens()) //while loop to check if the tokenizer actually has tokens
			{
				dueInput = st.next_token(); //reaad in duedate
				
				newDesc = st.next_token(); //read in the desc, and trim off the leading space
				newDesc = newDesc.substr(1);

				assignedInput = st.next_token(); //read in the assignedDate, and trim off leading space
				assignedInput = assignedInput.substr(1);

				newStat = st.next_token();//read in the status, and trim off leading space
				newStat = newStat.substr(1);

				Assignment temp(Date(dueInput), newDesc, Date(assignedInput), newStat); //create the assignment with the proper arguments
				if (newStat == "late" || newStat == "completed") //add it to the appropiate list
					this->addCompleted(temp);
				else
					this->addAssignment(temp);
			}
		}
		ifs.close();
		return true;
	}

	int countLate() //counts the amount of late assignments in line, and returns the amount. No variable is kept
	{
		int lateCount = 0;
		list<Assignment>::iterator it;

		for (it = completedList.begin(); it != completedList.end(); ++it) //iterate through the completed list, if it's late, increment the temp variable
		{
			if (it->statusString() == "late")
			{
				++lateCount;
			}
		}

		return lateCount; //return the value
	}
};
#endif