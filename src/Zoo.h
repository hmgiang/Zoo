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
using namespace std;

class Zoo{
public:
	Zoo(int x, int y);
	void createZoo(int nb_cat, int nb_mouse);
	void advanceZoo();
	int getSize();
	void viewZoo();

private:
	void getMeeting(Animal *a, Animal *b);
	list<Animal *>::iterator getRandomItAnimal();
	void getGrowing();

	list<Animal *> list_a;
	int size_x;
	int size_y;
};


#endif /* ZOO_H_ */
