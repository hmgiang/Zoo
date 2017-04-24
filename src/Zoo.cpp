/*
 * Zoo.cpp
 *
 *  Created on: 15 mars 2017
 *      Author: mgiang
 */

#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include "Zoo.h"


Zoo::Zoo(int x, int y) {
	srand((unsigned) time(0));
	size_x = x;
	size_y = y;
}

int Zoo::getSize(){
	return list_a.size();
}

list<Animal *>::iterator Zoo::getRandomItAnimal() {
	int r = rand() % list_a.size();
	list<Animal *>::iterator it = list_a.begin();
	advance(it, r);
	return it;
}

void Zoo::createZoo(int nb_cat, int nb_mouse) {
	for (int i = 0; i < nb_mouse; i++) {
		list_a.push_back(new Mouse());
	}
	for (int i = 0; i < nb_cat; i++) {
		list_a.push_back(new Cat());
	}
}

void Zoo::getMeeting(Animal *a, Animal *b) {
	if (a->getClass() != b->getClass())
	{
		string name_animal_dead;
		if (a->power > b->power) {
			name_animal_dead = b->name;
			delete b;
			list_a.remove(b);
		} else if (a->power < b->power) {
			name_animal_dead = a->name;
			delete a;
			list_a.remove(a);
		}
		if (name_animal_dead.size()>0) cout << name_animal_dead << " is dead" << endl;
	}
	else // they are in the same class, they create a new children
	{
		if (a->sex != b->sex) {
			cout << "A new children between " << a->name << " and " << b->name << endl;
			if (a->getClass() == "Mouse"){
				list_a.push_back(new Mouse());
			}
			else if (a->getClass() == "Cat"){
				list_a.push_back(new Cat());
			}
			else{
				cout << "Don't find the class - bad context" << endl;
			}
		}
	}
}

void Zoo::getGrowing(){
	for(list<Animal*>::iterator it = list_a.begin(); it!=list_a.end();){
		(*it)->age = (*it)->age + 1;

		if ((*it)->age == Animal::age_dead){
			cout << (*it)->name << " is dead because of his age" << endl;
			delete(*it);
			it = list_a.erase(it);
			continue;
		}
		else if ((*it)->age == Animal::age_adulte){
			cout << (*it)->name << " will become a adult" << endl;
			if ((*it)->getClass() == "Mouse"){
				Mouse *m = new Mouse((*it)->name, (*it)->power, (*it)->sex, (*it)->age);
				Mouse *ptr_m = static_cast<Mouse*>(*it);
				(*it) = m;
				delete (ptr_m);
			}
			else if ((*it)->getClass() == "Cat"){
				Cat *c = new Cat((*it)->name, (*it)->power, (*it)->sex, (*it)->age);
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

	list<Animal *>::iterator it1 = getRandomItAnimal();
	list<Animal *>::iterator it2 = getRandomItAnimal();

	if ( (*it1==*it2) && (*it1==*(--list_a.end())) ) {
		it2 = it1--;
	}
	else if ( (*it1==*it2) ){
		it2 = it1++;
	}
	getMeeting(*it1, *it2);
	getGrowing();
}


void Zoo::viewZoo(){
	for(int i = 0; i < size_x; i++){
		for(int j = 0; j <size_y; j++){
			cout << "x" ;
		}
		cout << endl;
	}
	cout << endl;
}
