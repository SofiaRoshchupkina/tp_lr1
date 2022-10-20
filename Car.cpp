#include "Car.h"

Car::Car() {
	cout << "The default constructor of the class was called Car" << endl;
	stamp = "No data available";
	model = "No data available";
	engine_capacity = 0; 
	colour = "No data available";
	CIO = "No data available";

}


Car::Car(const Car& obj) {
	*this = obj;
}

Car::~Car() {
	cout << "The class destructor was called Car" << endl;
}

Car& Car::operator=(const Car& other) {
	this->stamp = other.stamp;
	this->model = other.model;
	this->colour = other.colour;
	this->engine_capacity = other.engine_capacity;
	this->CIO = other.CIO;
	return *this;
}

ostream& operator<<(ostream& out, Car& obj) {
	out << "Car brand: " << obj.stamp << endl;
	out << "Model of Car: " << obj.model << endl;
	out << "Information about engine capacity: " << obj.engine_capacity << endl;
	out << "Information about colour: " << obj.colour << endl;
	out << "Information about CIO: " << obj.CIO << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj) {
	cout << "Input car brand: ";
	getchar();
	getline(in, obj.stamp);

	cout << "Input model of Car: ";
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

	cout << "Input information about colour: ";
	getchar();
	getline(in, obj.colour);

	cout << "Input CIO: ";
	//getchar();
	getline(in, obj.CIO);

	return in;
}

ofstream& operator<<(ofstream& fout, Car& obj) {
	fout << obj.stamp << endl;
	fout << obj.model << endl;
	fout << obj.engine_capacity << endl;
	fout << obj.colour << endl;
	fout << obj.CIO << endl;

	return fout;
}

ifstream& operator>>(ifstream& fin, Car& obj) {
	fin >> obj.stamp;
	fin >> obj.model;
	fin >> obj.engine_capacity;
	fin >> obj.colour;
	fin >> obj.CIO;
	return fin;
}
