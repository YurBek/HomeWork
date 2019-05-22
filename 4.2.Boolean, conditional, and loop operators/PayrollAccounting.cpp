// Зарплата менеджера составляет 200$ + процент от продаж,
// продажи до 500$ - 3 % , от 500 до 1000 – 5 % , 1000 и выше – 8 % .
// Пользователь вводит с клавиатуры уровень продаж для трех менеджеров.
// Определить их зарплату, определить лучшего менеджера, начислить ему премию 200$.
// Выведите итоги на экран.
//
// Тестовые значения:
// - Sales level: 100, 500, 1000
// - Salary: 203, 225, 280
// - Bonus: - , - , 200
// - TOTAL: 203, 225, 480
//
// - Sales level: 500, 1000, 100
// - Salary: 225, 280, 203
// - Bonus: - , 200 , -
// - TOTAL: 225, 480, 203
//
// - Sales level: 1000, 100, 500
// - Salary: 280, 203, 225
// - Bonus: 200 , - , -
// - TOTAL: 480, 203, 225

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	const double salesLevel1 = 500, // уровень продаж 500 долл.
				 salesLevel2 = 1000, // уровень продаж 1000 долл.

				 percentageOfSales1 = 3.0 / 100, // 3% - процент от продаж
				 percentageOfSales2 = 5.0 / 100, // 5% - процент от продаж
				 percentageOfSales3 = 8.0 / 100, // 8% - процент от продаж

				 baseSalary = 200,// базовая зарплата менеджера

				 bonus = 200; // премия менеджера

	double currentSales1, currentSales2, currentSales3; // текущие продажи
	double managerSalary1, managerSalary2, managerSalary3; // зарплата менеджеров с учетом процентов и бонусов

	// вводим текущие уровни продаж для каждого менеджера
	cout << "Enter current sales 1-st manager: ";
	cin >> currentSales1;
	cout << "Enter current sales 2-nd manager: ";
	cin >> currentSales2;
	cout << "Enter current sales 3-rd manager: ";
	cin >> currentSales3;
	cout << endl;

	// выводим в таблицу текущие уровни продаж для каждого менеджера
	cout << "\t\tManager 1\tManager 2\tManager 3"
		<< "\r\n\Sales level:"
		<< "\r\t\t" << currentSales1 << "\t\t" << currentSales2 << "\t\t" << currentSales3;

	// расчитываем размер процентной надбавки в зависимости от уровня продаж для каждого менеджера
	currentSales1 >= salesLevel2 ? managerSalary1 = baseSalary + currentSales1 * percentageOfSales3 :
		(currentSales1 >= salesLevel1 && currentSales1 < salesLevel2)? managerSalary1 = baseSalary + currentSales1 * percentageOfSales2 :
			managerSalary1 = baseSalary + currentSales1 * percentageOfSales1;
	currentSales2 >= salesLevel2 ? managerSalary2 = baseSalary + currentSales2 * percentageOfSales3 :
		(currentSales2 >= salesLevel1 && currentSales2 < salesLevel2) ? managerSalary2 = baseSalary + currentSales2 * percentageOfSales2 :
			managerSalary2 = baseSalary + currentSales2 * percentageOfSales1;
	currentSales3 >= salesLevel2 ? managerSalary3 = baseSalary + currentSales3 * percentageOfSales3 :
		(currentSales3 >= salesLevel1 && currentSales3 < salesLevel2) ? managerSalary3 = baseSalary + currentSales3 * percentageOfSales2 :
			managerSalary3 = baseSalary + currentSales3 * percentageOfSales1;

	// выводим в таблицу зарплату для каждого менеджера
	cout << "\r\n\Salary:"
		<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;

	// необходимо определить кто получит премию
	cout << "\r\n\Bonus:";
	if (managerSalary1 == managerSalary2 && managerSalary2 == managerSalary3) {
		// если все три менеджа сработали одинаково - премию делим на троих
		double bonus3 = bonus / 3.0;
		managerSalary1 = managerSalary1 + bonus3;
		managerSalary2 = managerSalary2 + bonus3;
		managerSalary3 = managerSalary3 + bonus3;

		// выводим в таблицу итоговую зарплату с учетом бонуса для каждого менеджера
		cout << "\r\t\t" << bonus3 << "\t\t" << bonus3 << "\t\t" << bonus3
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary1 == managerSalary2 && managerSalary1 > managerSalary3) {
		// если только менеджеры 1-ый и 2-ой сработали одинаково хорошо - премию делим на двоих
		double bonus2 = bonus / 2.0;
		managerSalary1 = managerSalary1 + bonus2;
		managerSalary2 = managerSalary2 + bonus2;
		
		// выводим в таблицу итоговую зарплату с учетом бонуса для менеджеров 1-го и 2-го
		cout << "\r\t\t" << bonus2 << "\t\t" << bonus2 << "\t\t" << " - "
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary1 == managerSalary3 && managerSalary1 > managerSalary2) {
		// если только менеджеры 1-ый и 3-ий сработали одинаково хорошо - премию делим на двоих
		double bonus2 = bonus / 2.0;
		managerSalary1 = managerSalary1 + bonus2;
		managerSalary3 = managerSalary3 + bonus2;

		// выводим в таблицу итоговую зарплату с учетом бонуса для менеджеров 1-го и 3-го
		cout << "\r\t\t" << bonus2 << "\t\t" << " - " << "\t\t" << bonus2
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary2 == managerSalary3 && managerSalary2 > managerSalary1) {
		// если только менеджеры 2-ой и 3-ий сработали одинаково хорошо - премию делим на двоих
		double bonus2 = bonus / 2.0;
		managerSalary2 = managerSalary2 + bonus2;
		managerSalary3 = managerSalary3 + bonus2;

		// выводим в таблицу итоговую зарплату с учетом бонуса для менеджеров 2-го и 3-го
		cout << "\r\t\t" << " - " << "\t\t" << bonus2 << "\t\t" << bonus2
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary1 > managerSalary2 && managerSalary1 > managerSalary3) {
		// если только 1-й менеджер сработал хорошо - премию одному
		managerSalary1 = managerSalary1 + bonus;
		
		// выводим в таблицу итоговую зарплату с учетом бонуса для 1-го менеджера
		cout << "\r\t\t" << bonus << "\t\t" << " - " << "\t\t" << " - "
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary2 > managerSalary1 && managerSalary2 > managerSalary3) {
		// если только 2-й менеджер сработал хорошо - премию одному
		managerSalary2 = managerSalary2 + bonus;

		// выводим в таблицу итоговую зарплату с учетом бонуса для 2-го менеджера
		cout << "\r\t\t" << " - " << "\t\t" << bonus << "\t\t" << " - "
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	if (managerSalary3 > managerSalary1 && managerSalary3 > managerSalary2) {
		// если только 3-й менеджер сработал хорошо - премию одному
		managerSalary3 = managerSalary3 + bonus;

		// выводим в таблицу итоговую зарплату с учетом бонуса для 3-го менеджера
		cout << "\r\t\t" << " - " << "\t\t" << " - " << "\t\t" << bonus
			<< "\r\n\TOTAL:"
			<< "\r\t\t" << managerSalary1 << "\t\t" << managerSalary2 << "\t\t" << managerSalary3;
	}

	cout << endl;

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
