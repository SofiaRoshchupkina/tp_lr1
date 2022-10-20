#pragma once
#include "Keeper.h"
// базовый класс
class Garage {
protected:
	string stamp;
	string model;
public:
	Garage() { cout << "The class constructor volunteered Garage" << endl; }
	virtual ~Garage() { cout << "The class destructor was called Garage" << endl;}
};

