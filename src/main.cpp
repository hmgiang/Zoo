//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Mouse.h"
#include "Cat.h"
#include <list>

using namespace std;


int main() {
	cout << "!!! START !!!" << endl; // prints !!!Hello World!!!

	Mouse *m1 = new Mouse('M', 10, 10, 10);
	Cat *c1 = new Cat('F', 10, 20, 10);
	list<Animal *> list_a;
	list_a.push_back(m1);
	list_a.push_back(c1);
	for(list<Animal *>::iterator it = list_a.begin(); it!=list_a.end(); ++it){
		cout << "getClass = " <<(*it)->getClass() << endl;
	}
//	c1->seBattre(m1);

	cout << list_a.size() << endl;

	std::list<Animal *>::iterator it1;
	it1 = list_a.begin();


	for(list<Animal *>::iterator it = list_a.begin(); it!=list_a.end(); it++){
		if (*it)
		{
			cout << "delete " << (*it)->getClass() << endl;
			delete *it;
		}
		else
		{
			cout << "nothing to delete" << endl;
		}
	}

	list_a.erase(it1);
	list_a.erase(it1);

	return 0;
}
