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

typedef struct pos{
	int x;
	int y;
}pos;

class Animal{
public:
	Animal(pos p, string name, int power);
	Animal(pos p, string name, int power, char sex, int age = 0);
	virtual ~Animal();

	virtual string getClass() = 0;

public:
	string name;
	int power;
	char sex;
	int age;
	pos p;

	static int age_dead;
	static int age_adulte;
};

#endif


