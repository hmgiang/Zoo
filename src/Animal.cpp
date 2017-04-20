/*
 * Animal.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */
#include "Animal.h"

int Animal::age_dead = 20;
int Animal::age_adulte = 1;


Animal::Animal(char sex, string name, int power, int lifetime, int age) : sex(sex), name(name), power(power), lifetime(lifetime), age(age){

}

Animal::~Animal(){

}
