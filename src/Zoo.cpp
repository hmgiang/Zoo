/*
 * Zoo.cpp
 *
 *  Created on: 15 mars 2017
 *      Author: mgiang
 */

#include "Zoo.h"

Zoo::Zoo(){

}
void Zoo::createZoo(){
	list_a.push_back(new Mouse('M', "mickey1", 10, 10));
	list_a.push_back(new Mouse('F', "mimi1", 10, 10));
	list_a.push_back(new Cat  ('F', "tom1", 20, 10));
}

void Zoo::getMeeting(Animal *a, Animal *b){
	if (a->getClass() != b->getClass() )
	{
		cout << "they can battle until dead between " << a->name << " and " << b->name << endl;
		if (a->power > b->power){
			delete b;
			list_a.remove(b);
		}
		else if (a->power < b->power){
			delete a;
			list_a.remove(a);
		}
	}
	else // they are in the same class, they create a new children
	{
		cout << "they can creat a new children between " << a->name << " and " << b->name << endl;
		if (a->sex != b->sex){
			if (a->getClass() == "Mouse")
				list_a.push_back(new Mouse('M', "mickey2", 3, 10));
			else if (a->getClass() == "Cat")
				list_a.push_back(new Mouse('M', "tom2", 10, 10));
			else
				cout << "Don't find the class - bad context" << endl;
		}
	}
}

void Zoo::advanceZoo(){
	list<Animal *>::iterator it2 = list_a.begin();
	list<Animal *>::iterator it1 = it2++;
	getMeeting(*it1, *it2);
	cout << "size list_a = " << list_a.size() << endl;
}
