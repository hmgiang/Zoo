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
	ss << "tom"<< rand()%1000;
	return ss.str();
}

Cat::Cat(pos p)
	:Animal(p, getNameCat(), rand() % 10 + 10)
{

}

Cat::Cat(pos p, string name, int power, char sex, int age)
	:Animal(p, name, power, sex, age){
}

Cat::~Cat(){
//	cout << "Destructor Cat" << endl;
}

string Cat::getClass(){
	return "Cat";
}
