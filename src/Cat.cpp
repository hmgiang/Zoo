/*
 * Cat.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#include "Cat.h"

Cat::Cat(char sex, int speed, int power, int lifetime)
	:Animal(sex, speed, power, lifetime){
	cout << "Constructor Cat" << endl;
}

Cat::~Cat(){
	cout << "Destructor Cat" << endl;
}

string Cat::getClass(){
	return "Cat";
}