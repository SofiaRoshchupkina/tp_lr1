#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
// массив наших объектов
using namespace std;
template <class T>
class Keeper {

	T* ptr_mas;
	int size;
public:
	Keeper() { size = 0; ptr_mas = nullptr; cout << "Object  Keeper created" << endl; };
	~Keeper() { delete[] ptr_mas; cout << "Object Keeper deleted" << endl; };

	void save(string); // запись в файл
	void read(string); //чтение из файла
	void add(); //добавить в массив наш объект
	void del(int index); //удалить из массива 
	void print(); //вывод на экран все элементы
	//void redact(int index);
};

template<class T>
void Keeper<T>::save(string s) {
	ofstream fout(s, ios::out);

	try {
		if (size == 0)
			throw exception("No data to save");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "File Successfully save" << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	fout.close();
}

template<class T>
void Keeper<T>::read(string s) {
	ifstream fin(s, ios::in);

	fin >> size;

	if (ptr_mas != nullptr)
		delete[] ptr_mas;

	ptr_mas = new T[size];

	for (int i = 0; i < size; i++) {
		fin >> ptr_mas[i];
	}

	cout << "File Successfully read" << endl;
	fin.close();
}

//template<class T>
//void Keeper<T>::redact(int index) {
//	if (size == 0)
//		cout << "Nothing delete." << endl;
//	else {
//
//		try {
//
//			if (index > size - 1 || index < 0)
//				throw exception("It is not possible to delete by the specified index..");
//		}
//		catch (exception& ex) {
//			while (index < 0 || index > size - 1) {
//				cout << ex.what() << endl;
//				cout << "Enter the index again(start 0):" << endl;
//				cin >> index;
//			}
//		}
//
//		T* tmp = new T[index];
//		int j = 0;
//		for (int i = 0; i < size; i++) {
//			if (i != index)
//				tmp[j++] = ptr_mas[i];
//		}
//		delete[] ptr_mas;
//		ptr_mas = tmp;
//		size--;
//		cout << "The object was successfully deleted." << endl;
//	}
//}

template<class T>
void Keeper<T>::add() {
	T* tmp = new T[size + 1]; //увеличение списка на один
	for (int i = 0; i < size; i++) {
		tmp[i] = ptr_mas[i]; //перезапись тех, что было
	}
	delete[] ptr_mas;
	cin >> tmp[size];
	ptr_mas = tmp;
	size++;
}

template<class T>
void Keeper<T>::del(int index) {
	if (size == 0)
		cout << "Nothing delete." << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("It is not possible to delete by the specified index.");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Enter the index again(start 0):" << endl;
				cin >> index;
			}
		}

		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}

		T* tmp = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas;
		ptr_mas = tmp;
		size--;
		cout << "The object was successfully deleted." << endl;	
	}
}

template<class T>
void Keeper<T>::print() {

	if (size == 0)
		cout << "There is nothing to output" << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << ptr_mas[i] << endl;
		}
}
