// - Задание 2: Пользователь вводит прибыль фирмы в каждом месяце за год (12 месяцев) с начала года.
// Затем пользователь вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).
// Необходимо определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с учетом выбранного диапазона.
//

#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

void PrintMaximumAndMinimumValuesInRange(int *ptrArray, char months[][4], int sizeArray, int startMonths, int endMonths); // выводит в консоль месяца с максимальным и минимальным значениями прибыли за период [startMonths:endMonths]
int *FindMaxElement(int *ptrArray, int sizeArray, int start, int end); // поиск указателя на максимальный элемент в диапазоне [start:end] элементов массива
int *FindMinElement(int *ptrArray, int sizeArray, int start, int end); // поиск указателя на минимальный элемент в диапазоне [start:end] элементов массива
int *FillArray(int sizeArray, int minValue, int maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
void ShowArray(int *ptrArray, char months[][4], int sizeArray); // выводим содержимое массива в консоль

int main() {
	srand(time(NULL));

	char months[12][4] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	const int sizeArray = 12, // год 12 месяцев
		minValue = 500, // минимальное значение прибыли
		maxValue = 1000; // максимальное значение прибыли
	int *ptrArray;
	
	ptrArray = FillArray(sizeArray, minValue, maxValue); // заполняем массив размером sizeArray случайными числами от minValue до maxValue
	ShowArray(ptrArray, months, sizeArray); // выводим содержимое массива в консоль
	cout << endl;

	int startMonths = 3, // начало периода
		endMonths = 9; // конец периода
	PrintMaximumAndMinimumValuesInRange(ptrArray, months, sizeArray, startMonths, endMonths); // выводит в консоль месяца с максимальным и минимальным значениями прибыли за период [startMonths:endMonths]

	delete[] ptrArray;

	return 0;
}

void PrintMaximumAndMinimumValuesInRange(int *ptrArray, char months[][4], int sizeArray, int startMonths, int endMonths) { // выводит в консоль месяца с максимальным и минимальным значениями прибыли за период [startMonths:endMonths]
	if (startMonths > endMonths) {
		int temp = startMonths;
		startMonths = endMonths;
		endMonths = temp;
	}
	int start = startMonths - 1,
		end = endMonths;
	
	cout << "For the period from " << (*(months + (startMonths - 1)) + 0) << " to " << (*(months + (endMonths - 1)) + 0) << " :" << endl;

	int indexMinElement = (FindMinElement(ptrArray, sizeArray, start, end) - ptrArray); // поиск указателя на минимальный элемент в массиве
	//cout << "minimum profit per month " << indexMinElement << " was = " << ptrArray[indexMinElement] << endl;
	cout << " minimum profit: " << (*(months + indexMinElement) + 0) << " - " << ptrArray[indexMinElement] << ".00$" << endl;

	int indexMaxElement = (FindMaxElement(ptrArray, sizeArray, start, end) - ptrArray); // поиск указателя на максимальный элемент в массиве
	//cout << "maximum profit per month " << indexMaxElement << " was = " << ptrArray[indexMaxElement] << endl;
	cout << " maximum profit: " << (*(months + indexMaxElement) + 0) << " - " << ptrArray[indexMaxElement] << ".00$" << endl;
			
	cout << endl;
}

int *FindMaxElement(int *ptrArray, int sizeArray, int start, int end) { // поиск указателя на максимальный элемент в диапазоне [start:end] элементов массива
	int *ptrTemp = (ptrArray + start);
	int *indexMaxElement = (ptrArray + start);
	ptrTemp++;
	for (int i = (start + 1); i < end; i++) {
		if (*ptrTemp > *indexMaxElement)
			indexMaxElement = ptrTemp;
		ptrTemp++;
	}

	return indexMaxElement;
}

int *FindMinElement(int *ptrArray, int sizeArray, int start, int end) { // поиск указателя на минимальный элемент в диапазоне [start:end] элементов массива
	int *ptrTemp = (ptrArray + start);
	int *indexMinElement = (ptrArray + start);
	ptrTemp++;
	for (int i = (start + 1); i < end; i++) {
		if (*ptrTemp < *indexMinElement)
			indexMinElement = ptrTemp;
		ptrTemp++;
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

void ShowArray(int *ptrArray, char months[][4], int sizeArray) { // выводим содержимое массива в консоль
	for (int i = 0; i < sizeArray; i++) {
		cout << (*(months + i) + 0) << ".{" << ptrArray[i] << ".00$} ";
		if ((i + 1) % 6 == 0) // выводим по 6 значений в строку
			cout << endl;
	}
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
