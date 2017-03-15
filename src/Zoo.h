/*
 * Zoo.h
 *
 *  Created on: 15 mars 2017
 *      Author: mgiang
 */

#ifndef ZOO_H_
#define ZOO_H_

#include <iostream>
#include "Mouse.h"
#include "Cat.h"
#include <list>

class Zoo{
public:
	Zoo();
	void createZoo();
	void advanceZoo();

private:
	void getMeeting(Animal *a, Animal *b);

	list<Animal *> list_a;
};


#endif /* ZOO_H_ */
