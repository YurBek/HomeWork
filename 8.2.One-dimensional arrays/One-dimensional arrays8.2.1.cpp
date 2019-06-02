// - Задание 1: Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.
//

#include "pch.h"
#include <iostream>

void FillArray(int array[], int sizeArray, int minValue, int maxValue); // заполняем int массив размером sizeArray случайными числами от minValue до maxValue
void ShowArray(int array[], int sizeArray, int valuesPerLine); // выводим содержимое массива в консоль

int main() {
	
	const int sizeArray10 = 10, // размеры массивов
		sizeArray51 = 5,
		sizeArray52 = 5,
		minValue = -10, // минимальное minValue и максимальное maxValue значения
		maxValue = 10,
		valuesPerLine = 10; // количество значений в строке вывода
		
	int array10[sizeArray10],
		array51[sizeArray51],
		array52[sizeArray52];

	std::cout << "array10:" << std::endl;
	FillArray(array10, sizeArray10, minValue, maxValue); // заполняем массив array10 случайными числами от minValue до maxValue
	ShowArray(array10, sizeArray10, valuesPerLine); // выводим содержимое массива array10 в консоль
	std::cout << std::endl;

	for (int i = 0; i < sizeArray10; i++) { // копируем элементы из массива array10
		if (i < sizeArray51)
			array51[i] = array10[i]; // в массив array51
		else
			array52[i - sizeArray52] = array10[i]; // и в массив array52
	}

	std::cout << "array51:" << std::endl;
	ShowArray(array51, sizeArray51, valuesPerLine); // выводим содержимое массива array51 в консоль
	std::cout << std::endl;

	std::cout << "array52:" << std::endl;
	ShowArray(array52, sizeArray52, valuesPerLine); // выводим содержимое массива array52 в консоль
	std::cout << std::endl;

	return 0;
}

void FillArray(int array[], int sizeArray, int minValue, int maxValue) { // заполняем int массив размером sizeArray случайными числами от minValue до maxValue
	
	int rangeOfValues;
	if (minValue == maxValue)
		rangeOfValues = 1; // что бы не возникало деления на 0
	else if (minValue > maxValue) { // если случайно поменяли местами
		rangeOfValues = minValue - maxValue;
		minValue = maxValue;
	}
	else
		rangeOfValues = maxValue - minValue; // диапазон значений

	int randomValue = 0;
	for (int i = 0; i < sizeArray; i++) {
		randomValue = rand() % rangeOfValues;
		array[i] = minValue + randomValue; // заполняем int массив размером sizeArray случайными числами от minValue до maxValue
	}
}

void ShowArray(int array[], int sizeArray, int valuesPerLine) { // выводим содержимое массива в консоль

	for (int i = 0; i < sizeArray; i++) {
		std::cout << i + 1 << ".{" << array[i] << "} ";
		if ((i + 1) % valuesPerLine == 0) // вывод несколько значений в строку
			std::cout << std::endl;
	}
	std::cout << std::endl;
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
