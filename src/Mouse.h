/*
 * Mouse.h
 *
 *  Created on: 14 mars 2017
 *      Author: mgiang
 */

#ifndef MOUSE_H_
#define MOUSE_H_
#include <iostream>
#include "Animal.h"
using namespace std;

class Mouse : public Animal {
public:
	Mouse(char sex, int speed, int power, int lifetime);
	virtual ~Mouse();
	virtual string getClass();
};



#endif /* MOUSE_H_ */
