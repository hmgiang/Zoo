//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Mouse.h"
#include "Cat.h"


int main() {
	cout << "!!! START !!!" << endl; // prints !!!Hello World!!!

	Mouse m1('M', 10, 10, 10);
	Cat c1('F', 10, 10, 10);
	m1.seBattre(c1);

	return 0;
}
