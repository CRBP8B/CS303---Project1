#include <string>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment.h"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

void main(){

	Assignment assignment(Date("1/2/16", US), "buttsex", Date("1/1/16", US), "assigned");
	string example = assignment.toString();
	cout << example;
	system("pause");
	
	
	


	
}