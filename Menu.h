#pragma once
#include "Keeper.h"

template <typename T>
void Menu(T& obj, string s) {

	int menu;
	int index;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 -> Add a transport" << endl;
		cout << "2 -> Delete transport" << endl;
		cout << "3 -> Read from the file" << endl;
		cout << "4 -> Save in file" << endl;
		cout << "5 -> Print all info" << endl;
		cout << "6 -> Exit" << endl;
		//cout << "7 --------------------------- Redact info --------------------------------" << endl;

		cout << "Input num: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;

		case 2: obj.print(); cout << "Input smth: "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: flag = 0; break;
		//case 7: obj.redact(index); system("pause"); break;
		default: cout << "Error" << endl; system("pause"); break;
		}
	}
}
