/*
 * Animal.h
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Animal{
public:
	Animal(char sex, string name, int power, int lifetime);
	virtual ~Animal();

	virtual string getClass() = 0;

public:
	char sex;
	string name;
	int power;
	int lifetime;
};

#endif


