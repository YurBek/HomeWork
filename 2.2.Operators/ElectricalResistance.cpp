﻿#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	double R, R0, R1, R2, R3;

	cout << "Input R1: ";
	cin >> R1;
	cout << "Input R2: ";
	cin >> R2;
	cout << "Input R3: ";
	cin >> R3;

	R = 1.0 / R1 + 1.0 / R2 + 1.0 / R3;
	R0 = 1.0 / R;
	cout << "R0 = " << R0
		<< endl;
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
