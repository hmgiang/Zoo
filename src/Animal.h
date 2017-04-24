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

typedef struct point{
	int x;
	int y;
}point;

class Animal{
public:
	Animal(string name, int power);
	Animal(string name, int power, char sex, int age = 0);
	virtual ~Animal();

	virtual string getClass() = 0;

public:
	string name;
	int power;
	char sex;
	int age;
	point p;

	static int age_dead;
	static int age_adulte;
};

#endif


