/*
 * Mouse.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */
#include "Mouse.h"
#include <cstdlib>
#include <sstream>

static string getNameMouse(){
	ostringstream ss;
	ss << "mickey"<< rand();
	return ss.str();
}

Mouse::Mouse()
	:Animal(getNameMouse(), rand() % 10 + 10){
}


Mouse::Mouse(string name, int power, char sex, int age)
	:Animal(name, power, sex, age){
}

Mouse::~Mouse(){
//	cout << "Destructor Mouse" << endl;
}

string Mouse::getClass(){
	return "Mouse";
}
