// - Задание 3: В одномерном массиве, состоящем из N целых чисел вычислить:
// • Сумму отрицательных элементов.
// • Произведение элементов, находящихся между min и max элементами.
// • Произведение элементов с четными индексами.
// • Сумму элементов, находящихся между первым и последним отрицательными элементами включительно.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

int SumElements_2(int *ptrArray, int sizeArray); // сумма элементов, находящихся между первым и последним отрицательными элементами включительно
long int ProductElements_2(int *ptrArray, int sizeArray); // произведение элементов с четными индексами
long int ProductElements(int *ptrArray, int sizeArray); // произведение элементов, находящихся между min и max элементами
int SumElements(int *ptrArray, int sizeArray); // сумма отрицательных элементов
int *FindMaxElement(int *ptrArray, int sizeArray); // поиск указателя на максимальный элемент в массиве
int *FindMinElement(int *ptrArray, int sizeArray); // поиск указателя на минимальный элемент в массиве
int *FillArray(int sizeArray, int minValue, int maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
void ShowArray(int *ptrArray, int sizeArray); // выводим содержимое массива в консоль

int main() {
	//srand(time(NULL));
	const int sizeArray = 10, // количество значений
		minValue = -100, // минимальное значение
		maxValue = 100; // максимальное значение
	int *ptrArray;

	ptrArray = FillArray(sizeArray, minValue, maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
	ShowArray(ptrArray, sizeArray); // выводим содержимое массива в консоль
	cout << endl;

	int sumElements = SumElements(ptrArray, sizeArray); // сумма отрицательных элементов
	cout << "The sum of negative elements = " << sumElements << endl;
	cout << endl;

	long int productElements = ProductElements(ptrArray, sizeArray); // произведение элементов, находящихся между min и max элементами
	cout << "Product of elements between MIN and MAX elements = " << productElements << endl;
	cout << endl;

	productElements = ProductElements_2(ptrArray, sizeArray); // произведение элементов с четными индексами
	cout << "Product of elements with even index = " << productElements << endl;
	cout << endl;

	sumElements = SumElements_2(ptrArray, sizeArray); // сумма элементов, находящихся между первым и последним отрицательными элементами включительно
	cout << "The sum of the elements between the first and last negative elements = " << sumElements << endl;
	cout << endl;

	delete[] ptrArray;

	return 0;
}

int SumElements_2(int *ptrArray, int sizeArray) { // сумма элементов, находящихся между первым и последним отрицательными элементами включительно
	int sumElements = 0,
		sumTemp = 0;
	for (int i = 0; i < sizeArray; i++, ptrArray++) {
		if (*ptrArray > 0 && sumTemp == 0) { // если число положительное, но отрицательное число еще не встречалось
			cout << i << ".{" << *ptrArray << "} " << "sumTemp " << sumTemp << " sumElements " << sumElements << endl;
			continue;
		}
		else if (*ptrArray < 0 && sumTemp == 0) // если отрицательное число встретилось первый раз
			sumTemp += *ptrArray;
		else if (*ptrArray > 0 && sumTemp != 0) // если число положительное, но отрицательное число уже встречалось
			sumTemp += *ptrArray;
		else if (*ptrArray < 0 && sumTemp != 0) { // если отрицательное число встретилось второй и более раз
			sumTemp += *ptrArray;
			sumElements = sumTemp;
		}
		cout << i << ".{" << *ptrArray << "} " << "sumTemp " << sumTemp << " sumElements " << sumElements << endl;
	}

	return sumElements;
}

long int ProductElements_2(int *ptrArray, int sizeArray) { // произведение элементов с четными индексами
	long int productElements = 1;
	for (int i = 0; i < sizeArray; i++, ptrArray++) {
		if (i % 2 == 0) { // проверка четности индекса. Число 0 является четным числом!
			cout << i << ".{" << *ptrArray << "} ";
			productElements *= *ptrArray;
		}			
	}
	cout << endl;

	return productElements;
}

long int ProductElements(int *ptrArray, int sizeArray) { // произведение элементов, находящихся между min и max элементами
	int *indexMinElement = FindMinElement(ptrArray, sizeArray); // поиск указателя на минимальный элемент в массиве
	cout << "The element with index [" << ((indexMinElement - ptrArray) + 1) << "] is minimum = " << *indexMinElement << endl;
	
	int *indexMaxElement = FindMaxElement(ptrArray, sizeArray); // поиск указателя на максимальный элемент в массиве	
	cout << "The element with index [" << ((indexMaxElement - ptrArray) + 1) << "] is maximum = " << *indexMaxElement << endl;
	
	if (indexMinElement > indexMaxElement) { // указатели располагаем так чтобы меньший был левее большего
		int *ptrTemp = indexMinElement;
		indexMinElement = indexMaxElement;
		indexMaxElement = ptrTemp;
	}

	long int productElements = 1;
	while (indexMinElement <= indexMaxElement) {
		productElements *= *indexMinElement;
		indexMinElement++;
	}

	return productElements;
}

int SumElements(int *ptrArray, int sizeArray) { // сумма отрицательных элементов
	int sumElements = 0;
	for (int i = 0; i < sizeArray; i++, ptrArray++) {
		if (*ptrArray < 0)
			sumElements += *ptrArray;
	}

	return sumElements;
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
