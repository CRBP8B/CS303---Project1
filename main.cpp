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

	Assignment assignment(Date("1/2/16", US), "hello", Date("1/1/16", US), "assigned");
	AssignTracker at;
	at.addAssignment(assignment);


	system("pause");
	
	
	


	
}