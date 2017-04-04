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

static char getRandomSex() {
	if (rand() % 2 == 0)
		return 'F';
	else
		return 'M';
}

template<typename T>
static string NumberToString(T Number) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}

Zoo::Zoo() {
	srand((unsigned) time(0));
}

list<Animal *>::iterator Zoo::getRandomIterator() {
	int r = rand() % list_a.size();
	cout <<"random number = " << r << endl;
	list<Animal *>::iterator it = list_a.begin();
	for(int i = 0; i < r; i++){
		it++;
	}
	return it;
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
		string name;
		if (a->power > b->power) {
			name = b->name;
			delete b;
			list_a.remove(b);
		} else if (a->power < b->power) {
			name = a->name;
			delete a;
			list_a.remove(a);
		}
		if (name.size()>0) cout << "Animal " << name << " is dead" << endl;

	} else // they are in the same class, they create a new children
	{
		if (a->sex != b->sex) {
			cout << "they creat a new children between " << a->name << " and " << b->name << endl;
			if (a->getClass() == "Mouse")
				list_a.push_back(new Mouse('M', "mickey2", 3, 10));
			else if (a->getClass() == "Cat")
				list_a.push_back(new Mouse('M', "tom2", 10, 10));
			else
				cout << "Don't find the class - bad context" << endl;
		}
	}
}

int Zoo::getSizeZoo(){
	return list_a.size();
}

void Zoo::advanceZoo() {
	if (list_a.size() < 2 ){
		cout << "Zoo is too small"<< endl;
		return ;
	}

	list<Animal *>::iterator it1 = getRandomIterator();
	list<Animal *>::iterator it2 = getRandomIterator();

	if ( (*it1==*it2) && (*it1==*(--list_a.end())) ) {
		it2 = it1--;
	}
	else if ( (*it1==*it2) ){
		it2 = it1++;
	}
	getMeeting(*it1, *it2);
	cout << "size list_a = " << list_a.size() << endl;
}
