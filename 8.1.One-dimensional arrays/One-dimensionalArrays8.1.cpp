// - Задание 1: В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

int *FindMaxElement(int *ptrArray, int sizeArray); // поиск указателя на максимальный элемент в массиве
int *FindMinElement(int *ptrArray, int sizeArray); // поиск указателя на минимальный элемент в массиве
int *FillArray(int sizeArray, int minValue, int maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
void ShowArray(int *ptrArray, int sizeArray); // выводим содержимое массива в консоль

int main() {
	srand(time(NULL));
	const int sizeArray = 10,
		minValue = -100,
		maxValue = 100;
	int *ptrArray;

	ptrArray = FillArray(sizeArray, minValue, maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
	ShowArray(ptrArray, sizeArray); // выводим содержимое массива в консоль
	cout << endl;

	int indexMaxElement = (FindMaxElement(ptrArray, sizeArray) - ptrArray); // поиск указателя на максимальный элемент в массиве
	cout << "The element with index [" << (indexMaxElement + 1) << "] is maximum. Its value = " << ptrArray[indexMaxElement] << endl;
	cout << endl;

	int indexMinElement = (FindMinElement(ptrArray, sizeArray) - ptrArray); // поиск указателя на минимальный элемент в массиве
	cout << "The element with index [" << (indexMinElement + 1) << "] is minimum. Its value = " << ptrArray[indexMinElement] << endl;
	cout << endl;

	delete[] ptrArray;

	return 0;
}

int *FindMaxElement(int *ptrArray, int sizeArray) { // поиск указателя на максимальный элемент в массиве
	int *indexMaxElement = ptrArray;
	ptrArray++;
	for (int i = 1; i < sizeArray; i++, ptrArray++) {
		if (*ptrArray > *indexMaxElement)
			indexMaxElement = ptrArray;
	}

	return indexMaxElement;
}

int *FindMinElement(int *ptrArray, int sizeArray) { // поиск указателя на минимальный элемент в массиве
	int *indexMinElement = ptrArray;
	ptrArray++;
	for (int i = 1; i < sizeArray; i++, ptrArray++) {
		if (*ptrArray < *indexMinElement)
			indexMinElement = ptrArray;
	}

	return indexMinElement;
}

int *FillArray(int sizeArray, int minValue, int maxValue) { // заполняем массив размером sizeArray случайными числами от minValue до maxValue
	int *ptrArray = new int[sizeArray];
	int rangeOfValues;
	if (minValue == maxValue)
		rangeOfValues = 1; // что бы не возникало деления на 0
	else if (minValue > maxValue) { // если случайно поменяли местами
		rangeOfValues = minValue - maxValue;
		minValue = maxValue;
	}
	else
		rangeOfValues = maxValue - minValue;

	for (int i = 0; i < sizeArray; i++)
		ptrArray[i] = minValue + rand() % rangeOfValues;

	return ptrArray;
}

void ShowArray(int *ptrArray, int sizeArray) { // выводим содержимое массива в консоль
	for (int i = 0; i < sizeArray; i++) {
		cout << i + 1 << ".{" << ptrArray[i] << "} ";
		if ((i + 1) % 10 == 0) // выводим по 10 значений в строку
			cout << endl;
	}
	cout << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
