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
	cout << "!!! START !!!" << endl;

	Zoo z(10, 20);
	z.viewZoo();
//	z.createZoo(1, 5);
//	for(int i = 0;  i < 50; i++){
//		cout << i << " = ";
//		z.advanceZoo();
//	}
//	cout << "Size of Zoo = " << z.getSize() << endl;
	cout << "!!! END !!!" << endl; // prints !!!Hello World!!!
	return 0;
}

