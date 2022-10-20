#pragma once
#include "Garage.h"

class Moto : public Garage {
protected:
	int engine_capacity; //в инт
	int engine_power; //в инт
	string terrain;
public:
	Moto();
	Moto(const Moto& obj);
	~Moto();

	Moto& operator= (const Moto& other);

	friend ostream& operator<<(ostream&, Moto&);
	friend istream& operator>>(istream&, Moto&);
	friend ofstream& operator<<(ofstream&, Moto&);
	friend ifstream& operator>>(ifstream&, Moto&);
};

