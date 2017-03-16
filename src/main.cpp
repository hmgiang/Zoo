//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Zoo.h"
#include <list>


using namespace std;


int main() {
	cout << "!!! START !!!" << endl; // prints !!!Hello World!!!

	int i = 10;
	string s = "hllo";
	Zoo z;
	z.createZoo(2, 5);
	z.advanceZoo();


	cout << "!!! END !!!" << endl; // prints !!!Hello World!!!
	return 0;
}
