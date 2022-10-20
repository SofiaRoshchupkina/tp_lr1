#pragma once
#include "Garage.h"

class Bus : public Garage {
protected:
	int number_seats; //int
	int number_of_passenger_seats; //int
	string destination;
public:
	Bus();
	Bus(const Bus& obj);
	~Bus();

	Bus& operator= (const Bus& other);

	friend ostream& operator<<(ostream&, Bus&);
	friend istream& operator>>(istream&, Bus&);
	friend ofstream& operator<<(ofstream&, Bus&);
	friend ifstream& operator>>(ifstream&, Bus&);
};