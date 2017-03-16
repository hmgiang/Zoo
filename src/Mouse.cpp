/*
 * Mouse.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */
#include "Mouse.h"

Mouse::Mouse(char sex, string name, int power, int lifetime)
	:Animal(sex, name, power, lifetime){
//	cout << "Constructor Mouse" << endl;
}

Mouse::~Mouse(){
	cout << "Destructor Mouse" << endl;
}

string Mouse::getClass(){
	return "Mouse";
}
