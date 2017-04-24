/*
 * Cat.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#include "Cat.h"
#include <cstdlib>
#include <sstream>

static string getNameCat(){
	ostringstream ss;
	ss << "tom"<< rand();
	return ss.str();
}

Cat::Cat()
	:Animal(getNameCat(), rand() % 10 + 10)
{

}

Cat::Cat(string name, int power, char sex, int age)
	:Animal(name, power, sex, age){
}

Cat::~Cat(){
//	cout << "Destructor Cat" << endl;
}

string Cat::getClass(){
	return "Cat";
}
