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

Zoo::Zoo() {
	srand((unsigned) time(0));
}

int Zoo::getSize(){
	return list_a.size();
}

list<Animal *>::iterator Zoo::getRandomIterator() {
	int r = rand() % list_a.size();
	list<Animal *>::iterator it = list_a.begin();
	advance(it, r);
	return it;
}

Animal* Zoo::newAnimal(string str){
	if (str=="Mouse"){
		ostringstream ss;
		ss << "mickey"<< rand();
		return new Mouse(getRandomSex(), ss.str(), (rand() % 10), 10);
	}
	else if (str=="Cat"){
		ostringstream ss;
		ss << "tom"<< rand();
		return new Cat(getRandomSex(), ss.str(), (rand() % 10 + 10), 10);
	}
	return NULL;
}

void Zoo::createZoo(int nb_cat, int nb_mouse) {
	for (int i = 0; i < nb_mouse; i++) {
		ostringstream ss;
		ss << "mickey"<< rand();
		list_a.push_back(new Mouse(getRandomSex(), ss.str(), rand() % 10, 10));
	}
	for (int i = 0; i < nb_cat; i++) {
		ostringstream ss;
		ss << "tom"<< rand();
		list_a.push_back(new Cat(getRandomSex(), ss.str(), (rand() % 10 + 10), 10));
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
		if (name.size()>0) cout << name << " is dead" << endl;

	} else // they are in the same class, they create a new children
	{
		if (a->sex != b->sex) {
			cout << "A new children between " << a->name << " and " << b->name << endl;
			if (a->getClass() == "Mouse"){
				ostringstream ss;
				ss << "mickey"<< rand();
				list_a.push_back(new Mouse(getRandomSex(), ss.str(), rand() % 10, 10));
			}
			else if (a->getClass() == "Cat"){
				ostringstream ss;
				ss << "tom"<< rand();
				list_a.push_back(new Cat(getRandomSex(), ss.str(), (rand() % 10 + 10), 10));
			}
			else
				cout << "Don't find the class - bad context" << endl;
		}
	}
}

void Zoo::getGrowing(){
	for(list<Animal*>::iterator it = list_a.begin(); it!=list_a.end();){
		(*it)->lifetime = (*it)->lifetime + 1;
		cout << "hot fix 2" << endl;
		(*it)->age = (*it)->age + 1;

		if ((*it)->lifetime == Animal::age_dead){
			cout << (*it)->name << " is dead because of his age" << endl;
			delete(*it);
			it = list_a.erase(it);
			continue;
		}
		else if ((*it)->age == Animal::age_adulte){
			cout << (*it)->name << " will become a adult" << endl;
			if ((*it)->getClass() == "Mouse"){
				Mouse *m = new Mouse((*it)->sex, (*it)->name, (*it)->power, (*it)->lifetime, (*it)->age);
				Mouse *ptr_m = static_cast<Mouse*>(*it);
				(*it) = m;
				delete (ptr_m);
			}
			else if ((*it)->getClass() == "Cat"){
				Cat *c = new Cat((*it)->sex, (*it)->name, (*it)->power, (*it)->lifetime, (*it)->age);
				Cat *ptr_c = static_cast<Cat*>(*it);
				(*it) = c;
				delete (ptr_c);
			}
		}
		++it;
	}
}

// we choose randomly two animals for meeting in every round of game
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
	getGrowing();
}
