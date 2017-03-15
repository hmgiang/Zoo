/*
 * Animal.cpp
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#include "Animal.h"
Animal::Animal(char sex, int speed, int power, int lifetime):sex(sex), speed(speed), power(power), lifetime(lifetime){
	cout << "Constructor Animal" << endl;
}

Animal::~Animal(){
	cout << "Destructor Animal" << endl;
}

void Animal::seBattre(Animal *a){
	if (this->getClass() != a->getClass() ){
		if (this->power > a->power)
		{
			delete a;
		}
		else if (this->power < a->power)
		{
			delete this;
		}
	}
}
