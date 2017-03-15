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

	Zoo z;
	z.createZoo();
	z.advanceZoo();

	cout << "!!! END !!!" << endl; // prints !!!Hello World!!!
	return 0;
}
