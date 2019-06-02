// - Задание 2: Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.
//

#include "pch.h"
#include <iostream>

void FillArray(int array[], int sizeArray, int minValue, int maxValue); // заполняем int массив размером sizeArray случайными числами от minValue до maxValue
void ShowArray(int array[], int sizeArray, int valuesPerLine); // выводим содержимое массива в консоль

int main() {

	const int sizeArray = 10, // все массивы одного размера
		minValue = -10, // минимальное minValue и максимальное maxValue значения
		maxValue = 10,
		valuesPerLine = 10; // количество значений в строке вывода

	int array1[sizeArray],
		array2[sizeArray],
		array3[sizeArray];

	std::cout << "array1:" << std::endl;
	FillArray(array1, sizeArray, minValue, maxValue); // заполняем массив array1 случайными числами от minValue до maxValue
	ShowArray(array1, sizeArray, valuesPerLine); // выводим содержимое массива array1 в консоль
	std::cout << std::endl;

	std::cout << "array2:" << std::endl;
	FillArray(array2, sizeArray, minValue, maxValue); // заполняем массив array2 случайными числами от minValue до maxValue
	ShowArray(array2, sizeArray, valuesPerLine); // выводим содержимое массива array2 в консоль
	std::cout << std::endl;

	for (int i = 0; i < sizeArray; i++)
		array3[i] = array1[i] + array2[i]; // сумму элементов массивов array1 и array2 сохраняем в - array3

	std::cout << "array3:" << std::endl;
	ShowArray(array3, sizeArray, valuesPerLine); // выводим содержимое массива array3 в консоль
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
