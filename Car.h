#pragma once
#include "Garage.h"

class Car : public Garage {
protected:
	int engine_capacity; //в инт
	string colour;
	string CIO; //кпп
public:
	Car();
	Car(const Car& obj);
	~Car();

	Car& operator= (const Car& other);

	friend ostream& operator<<(ostream&, Car&); // поток вывода на экран
	friend istream& operator>>(istream&, Car&); // ввод с клавиатуры
	friend ofstream& operator<<(ofstream&, Car&); // вывод из файла
	friend ifstream& operator>>(ifstream&, Car&); //ввод в файл
};