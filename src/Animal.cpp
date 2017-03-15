/*
 * Animal.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#include "Animal.h"
Animal::Animal(char sex, string name, int power, int lifetime) : sex(sex), name(name), power(power), lifetime(lifetime){
	cout << "Constructor Animal" << endl;
}

Animal::~Animal(){
	cout << "Destructor Animal" << endl;
}
