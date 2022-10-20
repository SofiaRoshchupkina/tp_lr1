#include "Bus.h"

Bus::Bus() {
	cout << " The default constructor of the class was called Bus" << endl;
	stamp = "No data available";
	model = "No data available";
	number_seats = 0;
	number_of_passenger_seats = 0;
	destination = "No data available";
}


Bus::Bus(const Bus& obj) {
	*this = obj;
}

Bus::~Bus() {
	cout << "The class destructor was called Bus" << endl;
}

Bus& Bus::operator=(const Bus& other) {
	this->stamp = other.stamp;
	this->number_seats = other.number_seats;
	this->number_of_passenger_seats = other.number_of_passenger_seats;
	this->model = other.model;
	this->destination = other.destination;

	return *this;
}

istream& operator>>(istream& in, Bus& obj) {
	cout << "Input bus brand: ";
	getchar();
	getline(in, obj.stamp);

	cout << "Input information about model: ";
	in >> obj.model;

	cout << "Input information number seats: ";
	while (!(in >> obj.number_seats))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information about number of passenger seats: ";
	while (!(in >> obj.number_of_passenger_seats))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information about destination: ";
	in >> obj.destination;

	return in;
}

ostream& operator<<(ostream& out, Bus& obj) {
	out << "Bus brand: " << obj.stamp << endl;
	out << "Model of Bus: " << obj.model << endl;
	out << "Information about number seats : " << obj.number_seats << endl;
	out << "Information about number of passenger seats: " << obj.number_of_passenger_seats << endl;
	out << "Information about destination: " << obj.destination << endl;
	
	return out;
}

ofstream& operator<<(ofstream& fout, Bus& obj)
{
	fout << obj.stamp << endl;
	fout << obj.model << endl;

	fout << obj.number_seats << endl;
	fout << obj.number_of_passenger_seats << endl;
	fout << obj.destination << endl;
	
	return fout;
}

ifstream& operator>>(ifstream& fin, Bus& obj)
{
	fin >> obj.stamp;
	fin >> obj.model;
	fin >> obj.number_seats;
	fin >> obj.number_of_passenger_seats;
	fin >> obj.destination;
	return fin;
}
