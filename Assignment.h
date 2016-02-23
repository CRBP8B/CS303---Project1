#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Date.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Assignment{

private:
	Date dueDate; //Due date of the assignment
	string description; //The description of the assignment
	Date assignedDate; //Date the assignment was assigned
	enum status { assigned, completed, late }; //The status of the assignment
	status stat;

public:


	Assignment(){ //Default constructor, setting variables to default values. Note: "assigned" is the default status
		dueDate = Date();
		description = "";
		assignedDate = Date();
		stat = status::assigned;
	}

	Assignment(Date initDueDate, string initDesc, Date initAssigned, string inputStat) // Regular constructor. Notice that the status is input as a STRING
	{
		dueDate = initDueDate;
		description = initDesc;
		assignedDate =initAssigned;

		int casevar; // turn the string into an int value
		if (inputStat == "assigned")
			casevar = 1;
		else if (inputStat == "completed")
			casevar = 2;
		else if (inputStat == "late")
			casevar = 3;
		else
		{
			throw("That is not a valid status"); //throw error if the string cannot be found
			return;
		}


		switch (casevar) //Set the correct enum value according to the casevar int
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

	/* Getters and setters for all variables*/
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
	
	status getStatus() // notice that it returns the status type
	{
		return stat;
	}

	string statusString()
	{
		if (stat == assigned)
			return "assigned";
		else if (stat == completed)
			return "completed";
		else if (stat == late)
			return "late";

		return "";
	}


	void setStatus(string inputStat)
	{
		int casevar; // turn the string into an int value
		if (inputStat == "assigned")
			casevar = 1;
		else if (inputStat == "completed")
			casevar = 2;
		else if (inputStat == "late")
			casevar = 3;
		else
		{
			throw("That is not a valid status"); //throw error if the string cannot be found
			return;
		}


		switch (casevar) //Set the correct enum value according to the casevar int
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

	string toString()
	{
				
		ostringstream output;

		string commaspace = ", ";
		string newline = "\n";

		output << dueDate.toString() << commaspace;
		output << description << commaspace;
		output << assignedDate.toString() << commaspace;
		output << (*this).statusString() << newline;

		return output.str();
		

	}
	
};

#endif
