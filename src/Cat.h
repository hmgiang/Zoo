/*
 * Cat.h
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#ifndef CAT_H_
#define CAT_H_
#include <iostream>
#include "Animal.h"
using namespace std;

class Cat:public Animal{
public:
	Cat();
	Cat(string name, int power, char sex, int age);
	virtual ~Cat();
	virtual string getClass();
};




#endif /* CAT_H_ */
