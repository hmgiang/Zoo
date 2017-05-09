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

Mouse::Mouse(pos p)
	:Animal(p, getNameMouse(), rand() % 10 + 10){
}


Mouse::Mouse(pos p, string name, int power, char sex, int age)
	:Animal(p, name, power, sex, age){
}

Mouse::~Mouse(){
//	cout << "Destructor Mouse" << endl;
}

string Mouse::getClass(){
	return "Mouse";
}
