#include "Keeper.h"
#include "Car.h"
#include "Moto.h"
#include "Bus.h"
#include "Menu.h"

int main() {

	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	Keeper<Moto> ob1;
	Keeper<Bus> ob2;
	Keeper<Car> ob3;

	int menu;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "What do you want to add?" << endl;
		cout << "1 -> Moto" << endl;
		cout << "2 -> Bus" << endl;
		cout << "3 -> Car" << endl;
		cout << "4 -> Exit" << endl;
		cout << "Enter number: ";
		cin >> menu;
		switch (menu) {
		case 1: Menu(ob1, "Moto.txt"); break;
		case 2: Menu(ob2, "Bus.txt"); break;
		case 3: Menu(ob3, "Car.txt"); break;
		case 4: flag = 0; break;
		default: cout << "Error" << endl; system("pause"); break;
		}
	}
}