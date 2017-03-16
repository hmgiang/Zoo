/*
 * Zoo.cpp
 *
 *  Created on: 15 mars 2017
 *      Author: mgiang
 */

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include "Zoo.h"

Zoo::Zoo() {
	srand((unsigned) time(0));
}

static char getRandomSex() {
	if (rand() % 2 == 0)
		return 'F';
	else
		return 'M';
}

template<typename T>
string NumberToString(T Number) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}

void Zoo::createZoo(int nb_cat, int nb_mouse) {

	for (int i = 0; i < nb_cat; i++) {
		stringstream ss;
		string num = NumberToString(i);
		ss << "tom"<< num;
		list_a.push_back(new Cat(getRandomSex(), ss.str(), (rand() % 10 + 10), 10));
	}

	for (int i = 0; i < nb_mouse; i++) {
		stringstream ss;
		string num = NumberToString(i);
		ss << "mickey"<< num;
		list_a.push_back(new Mouse(getRandomSex(), ss.str(), rand() % 10, 10));
		ss.clear();
	}
}

void Zoo::getMeeting(Animal *a, Animal *b) {
	if (a->getClass() != b->getClass()) {
		cout << "they can battle until dead between " << a->name << " and "
				<< b->name << endl;
		if (a->power > b->power) {
			delete b;
			list_a.remove(b);
		} else if (a->power < b->power) {
			delete a;
			list_a.remove(a);
		}
	} else // they are in the same class, they create a new children
	{
		cout << "they can creat a new children between " << a->name << " and " << b->name << endl;
		if (a->sex != b->sex) {
			if (a->getClass() == "Mouse")
				list_a.push_back(new Mouse('M', "mickey2", 3, 10));
			else if (a->getClass() == "Cat")
				list_a.push_back(new Mouse('M', "tom2", 10, 10));
			else
				cout << "Don't find the class - bad context" << endl;
		}
	}
}

void Zoo::advanceZoo() {
	list<Animal *>::iterator it2 = list_a.begin();
	list<Animal *>::iterator it1 = it2++;
	getMeeting(*it1, *it2);
	cout << "size list_a = " << list_a.size() << endl;
}
