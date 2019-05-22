﻿// Пользователь вводит с клавиатуры целое шестизначное число.
// Написать программу, которая определяет, является ли введенное число – счастливым.
// Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр.
// Если пользователь ввел не шестизначное число – сообщение об ошибке.
//
// Тестовые значения:
// - 123456 - "не счастливое" число
// - 213132 - "счастливое" число
// - 003030 - "счастливое" число

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string numS; // для шестизначного числа используем переменную string
	int sumL = 0, sumR = 0, numLen = 0;

	// Вводим число, желательно шестизначное
	cout << "Enter a six-digit number: ";
	getline(cin, numS);
	//cout << numS << endl;

	numLen = numS.length();
	if (numLen == 6) { // проверяем число на шестизначность
		cout << "Ok, Your number is six-digit number." << endl;

		// используем цикл for для выделения цифр
		for (int i = 0; i < numLen; i++) {
			// находим сначала сумму правой части числа, а затем - левой
			if (i < 3) {
				sumL = sumL + atoi(numS.substr(i, 1).c_str());
				cout << "sumL = " << sumL << " sumR = " << sumR << " " << numS.substr(0, (i + 1)) << endl;
			}
			else {
				sumR = sumR + atoi(numS.substr(i, 1).c_str());
				cout << "sumL = " << sumL << " sumR = " << sumR << " " << numS.substr(3, (i + 1 - 3)) << endl;
			}
		}
		cout << endl;

		// проверяем, является ли число счастливым и сообщаем об этом
		sumL == sumR ? cout << "sumL == sumR" << endl << "Great! Your number is lucky! ;-)" << endl :
						cout << "sumL != sumR" << endl << "Oops! You have a bad number... :-(" << endl;
	}
	else {
		cout << "Error: Your number is LESS or MORE than 6 digits!" << endl;
	}

	return 0;
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
