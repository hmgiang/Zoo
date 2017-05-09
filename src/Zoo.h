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
	Zoo(int row, int col);
	void createZoo(int nb_cat, int nb_mouse);
	void advanceZoo();
	int getSize();
	void viewZoo();
	~Zoo();

private:
	void getMeeting(Animal *a, Animal *b);
	list<Animal *>::iterator getRandomItAnimal();
	void getGrowing();
	pos getRandomPos();
	Zoo & operator==(Zoo &z1);

	list<Animal *> list_a;
	int row;
	int col;
	char **tab;
};



#endif /* ZOO_H_ */
