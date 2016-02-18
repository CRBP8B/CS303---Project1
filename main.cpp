#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include "AssignTracker.h"
#include "Ordered_List.h"
#include <iostream>
#include <fstream>

using namespace std;

void main(){

	AssignTracker assigns;
	Assignment assignment1(Assignment(Date("1/2/16", US), "poop", Date("1/1/16", US), "assigned"));
	Assignment assignment2(Assignment(Date("1/8/16", US), "poop", Date("1/7/16", US), "assigned"));
	//Assignment assignment3(Assignment(Date("1/1/16", US), "poop", Date("1/2/16", US), "assigned"));
	//Assignment assignment4(Assignment(Date("1/1/16", US), "poop", Date("1/7/16", US), "assigned"));

	system("pause");
	
	
	


	
}