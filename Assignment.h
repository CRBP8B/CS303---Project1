#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Date.h"
#include <string>

using namespace std;

class Assignment{

	Date dueDate;
	string description;
	Date assignedDate;
	//enum status { Assigned, Completed, Late };
	//status stat;

public:

	Assignment(){
		dueDate = Date();
		description = "";
		assignedDate = Date();
		//stat = status::Assigned;
	}

	Assignment(Date initDueDate, string initDesc, Date initAssigned, status initStat)
	{
		dueDate = initDueDate;
		description = initDesc;
		assignedDate = initAssigned;
		//stat = initStat;
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
	/*
	status getStatus()
	{
		return stat;
	}

	void setStatus(status &newStat)
	{
		stat = newStat;
	}
	*/
};

#endif
