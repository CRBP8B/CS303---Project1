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
	bool addAssignment(Assignment newAssign);
	bool completeAssignment(Assignment toBeComp);
	bool editAssignment(Date filter);
	bool readIn(istream& file);
	int countLate();

};