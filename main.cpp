#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "AssignTracker.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

void main(){

	AssignTracker at;

	at.readIn("input.txt");

	at.completeAssignment(Date("4/13/2015"), Date("4/16/15"));
	cout << "The assigned:" << endl;
	cout << at.printAssigned();
	cout << endl << "The completed:"<< endl;
	cout << at.printCompleted();
	system("pause");
	
	
	


	
}