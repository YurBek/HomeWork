﻿// Пользователь вводит с клавиатуры целое шестизначное число.
// Написать программу, которая определяет, является ли введенное число – счастливым.
// Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр.
// Если пользователь ввел не шестизначное число – сообщение об ошибке.
//
// Тестовые значения:
// - 123456 - "не счастливое" число
// - 213132 - "счастливое" число

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int num, D1, D2, D3, D4, D5, D6;
	bool flag;

    cout << "Enter a six-digit number: ";
	cin >> num;
	cout << endl;

	if (num >= 100000 && num <= 999999) // проверяем на шестизначность
	{
		// используем линейный алгоритм для выделения цифр
		// выделяем шестую справа цифру
		//D6 = (num / 100000) % 10;
		D6 = num / 100000;

		// выделяем пятую справа цифру
		//D5 = (num / 10000) % 10;
		D5 = num / 10000 - D6 * 10;

		// выделяем четвертую справа цифру
		//D4 = (num / 1000) % 10;
		D4 = num / 1000 - D6 * 100 - D5 * 10;

		// выделяем третью справа цифру
		//D3 = (num / 100) % 10;
		D3 = num / 100 - D6 * 1000 - D5 * 100 - D4 * 10;

		// выделяем вторую справа цифру
		//D2 = (num / 10) % 10;
		D2 = num / 10 - D6 * 10000 - D5 * 1000 - D4 * 100 - D3 * 10;

		// выделяем первую слева цифру
		//D1 = num % 10;
		D1 = num - D6 * 100000 - D5 * 10000 - D4 * 1000 - D3 * 100 - D2 * 10;
										
		// проверяем, является ли число – счастливым 
		(D6 + D5 + D4) == (D3 + D2 + D1) ? flag = true : flag = false;
		
		// выводим красивое сообщение
		cout << D6 << " + "	<< D5 << " + " << D4;

		flag == true ? cout << " == " : cout << " != ";

		cout << D3 << " + " << D2 << " + " << D1;

		flag == true ? cout << "\n\rGreat! Your number is lucky! ;-)" : cout << "\n\rOops! You have a bad number... :-(";

		cout << endl;
	}
	else
	{
		cout << "Error: Your number is LESS or MORE than 6 digits!"
			<< endl;
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