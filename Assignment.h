#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Date.h"
#include <string>

using namespace std;

class Assignment{

private:
	Date dueDate;
	string description;
	Date assignedDate;
	enum status { assigned, completed, late };
	status stat;

public:

	Assignment(){
		dueDate = Date();
		description = "";
		assignedDate = Date();
		stat = status::assigned;
	}

	Assignment(Date initDueDate, string initDesc, Date initAssigned, string inputStat) //add status parameter.
	{
		dueDate = initDueDate;
		description = initDesc;
		assignedDate =initAssigned;

		int casevar;
		if (inputStat == "assigned")
			casevar = 1;
		else if (inputStat == "completed")
			casevar = 2;
		else if (inputStat == "late")
			casevar = 3;
		else
		{
			throw("That is not a valid status");
			return;
		}


		switch (casevar)
		{
		case 1:
			stat = assigned;
			break;
		case 2:
			stat = completed;
			break;
		case 3:
			stat = late;
			break;
		}


	}

	Date getDueDate()
	{
		return dueDate;
	}

	void setDueDate(Date newDate)
	{
		dueDate = newDate;
	}

	string getDescription()
	{
		return description;
	}

	void setDescription(string newDesc)
	{
		description = newDesc;
	}

	Date getAssignedDate()
	{
		return assignedDate;
	}

	void setAssignedDate(Date newDate)
	{
		assignedDate = newDate;
	}
	
	status getStatus()
	{
		return stat;
	}

	void setStatus(status &newStat)
	{
		stat = newStat;
	}
	
};

#endif
