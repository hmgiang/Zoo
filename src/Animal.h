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
using namespace std;

class Animal{
public:
	Animal(char sex, int speed, int power, int lifetime);
	virtual ~Animal();

	void seBattre(Animal &a);
	virtual string getClass() = 0;

public:
	char sex;
	int speed;
	int power;
	int lifetime;
};

#endif


