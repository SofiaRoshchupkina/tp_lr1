#include "Moto.h"

Moto::Moto() {
	cout << " The default constructor of the class was called Moto" << endl;
	stamp = "No data available";
	model = "No data available";
	engine_capacity = 0;
	engine_power = 0;
	terrain = "No data available";

}



Moto::Moto(const Moto& obj) {
	*this = obj;
}

Moto::~Moto() {
	cout << "The class destructor was called Moto" << endl;
}

Moto& Moto::operator=(const Moto& other) {
	this->stamp = other.stamp;
	this->model = other.model;
	this->engine_power = other.engine_power;
	this->engine_capacity = other.engine_capacity;
	this->terrain = other.terrain;


	return *this;
}

ostream& operator<<(ostream& out, Moto& obj) {
	out << "Moto brand: " << obj.model << endl;
	out << "Model of Moto: " << obj.stamp << endl;
	out << "Information about engine capacity: " << obj.engine_capacity << endl;
	out << "Information about engine power: " << obj.engine_power << endl;
	out << "Information about terrain: " << obj.terrain << endl;
	return out;
}

istream& operator>>(istream& in, Moto& obj) {
	cout << "Input information about moto brand: ";
	getchar();
	getline(in, obj.stamp);

	cout << "Input  model: ";
	in >> obj.model;

	cout << "Input information about engine capacity: ";
	while (!(in >> obj.engine_capacity))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information about engine power: ";
	while (!(in >> obj.engine_power))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information about terrain: ";
	in >> obj.terrain;
	return in;
}

ofstream& operator<<(ofstream& fout, Moto& obj)
{
	fout << obj.stamp << endl;
	fout << obj.model << endl;
	fout << obj.engine_capacity << endl;
	fout << obj.engine_power << endl;
	fout << obj.terrain << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Moto& obj)
{
	fin >> obj.stamp;
	fin >> obj.model;
	fin >> obj.engine_capacity;
	fin >> obj.engine_power;
	fin >> obj.terrain;

	return fin;
}


