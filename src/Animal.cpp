/*
 * Animal.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */
#include "Animal.h"
#include <cstdlib>

int Animal::age_dead = 20;
int Animal::age_adulte = 5;

static char getRandomSex() {
	if (rand() % 2 == 0)
		return 'F';
	else
		return 'M';
}


Animal::Animal(pos p, string name, int power):name(name), power(power){
	this->p.x = p.x;
	this->p.y = p.y;
	sex = getRandomSex();
	age = 0;
	cout << "new animal " << name << endl;
}

Animal::Animal(pos p, string name, int power, char sex, int age) : name(name), power(power), sex(sex), age(age){

}

Animal::~Animal(){

}
