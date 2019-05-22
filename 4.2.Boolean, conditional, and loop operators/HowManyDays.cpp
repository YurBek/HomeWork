// Пользователь вводит две даты (день, месяц, год в виде целых чисел).
// Необходимо определить и вывести количество дней МЕЖДУ этими двумя датами.
// Для расчетов учитывать високосные года, а также корректное число дней в месяцах
// (март – 31, сентябрь – 30, февраль не високосного года – 28 и т.д.).
//
// Тестовые данные:
// 1. любые две одинаковые даты:
// - 12.06.2019 - 12.06.2019 -> sumOfDays = 0
//
// 2. любые две даты в пределах одного месяца:
// - 05.04.2019 - 25.04.2019 - sumOfDays = 19
// - 06.12.1978 - 12.12.1978 - sumOfDays = 5
//
// 3. любые две даты в пределах одного года
// - 05.01.2019 - 25.12.2019 - sumOfDays = 353 (год 2019 невисокосный)
// - 05.01.1968 - 25.12.1968 - sumOfDays = 354 (год 1968 високосный)
//
// 3. любые две произвольные даты
// - 05.01.2009 - 25.12.2019 - sumOfDays = 4 005 (года 2012 и 2016 високосные)
// - 12.02.1908 - 06.03.1968 - sumOfDays = 21 937 (года 1908,1912, 1916, 1920, 1924, 1928, 1932, 1936, 1940, 1944, 1948, 1952, 1956, 1960, 1964 и 1968 високосные)
// - 01.01.0001 - 03.05.2019 - sumOfDays = 737 180
//

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	enum { January = 1, February, March, April, May, June, July, August, September, October, November, December };

	const int dayPerYear = 365,
			  dayPerMonth31 = 31, // Янв Мар Май Июл Авг Окт Дек
			  dayPerMonth30 = 30, // Апр Июн Сен Ноя
			  dayPerMonth28 = 28; // Фев

	int day1, month1, year1,
		day2, month2, year2,
		tmp = 0, sumOfDays = 0;

	cout << "Enter the first date:\r\n";
	cout << "day (dd) ";
	cin >> day1;
	cout << "month (mm) ";
	cin >> month1;
	cout << "year (yyyy) ";
	cin >> year1;
			
	cout << "\r\nEnter the second date:\r\n";
	cout << "day (dd) ";
	cin >> day2;
	cout << "month (mm) ";
	cin >> month2;
	cout << "year (yyyy) ";
	cin >> year2;
	cout << endl;

	// хотим чтобы дата day1.month1.year1 была меньше даты day2.month2.year2
	if (year1 > year2) {
		//cout << "year1 > year2" << endl;
		tmp = year1;
		year1 = year2;
		year2 = tmp;

		tmp = month1;
		month1 = month2;
		month2 = tmp;

		tmp = day1;
		day1 = day2;
		day2 = tmp;
	}
	else if (year1 == year2) {
		//cout << "year1 == year2" << endl;
		if (month1 > month2) {
			//cout << "month1 > month2" << endl;
			tmp = month1;
			month1 = month2;
			month2 = tmp;

			tmp = day1;
			day1 = day2;
			day2 = tmp;
		}
		else if (month1 == month2) {
			//cout << "month1 == month2" << endl;
			if (day1 > day2) {
				//cout << "day1 > day2" << endl;
				tmp = day1;
				day1 = day2;
				day2 = tmp;
			}
		}
	}

	cout << "You entered the following two dates: ";
	cout << setfill('0') << setw(2) << day1 << "."
						 << setw(2) << month1 << "."
						 << setw(4) << year1 << " and "
						 << setw(2) << day2 << "."
						 << setw(2) << month2 << "."
						 << setw(4) << year2 << endl;

	if (year1 == year2) { // если year1 == year2

		if (month1 == month2) { // если month1 == month2
			
			if (day1 == day2) {
				sumOfDays = 0;
				//cout << sumOfDays << " days." << endl; // если day1 == day2, то количество дней между ними = 0
			}				
			else{
				sumOfDays = sumOfDays + day2 - day1 - 1; // количество дней между day2 и day1
				//cout << sumOfDays << " days." << endl;
			}

		}
		else{ // если month1 != month2
			// количество дней с day1 и до конца month1
			if (month1 == February) {
				if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
					sumOfDays = sumOfDays + dayPerMonth28 + 1 - day1;
				else // если год НЕвисокосный
					sumOfDays = sumOfDays + dayPerMonth28 - day1;
			}
			else if (month1 == April || month1 == June || month1 == September || month1 == November) // если месяц Апр или Июн или Сен или Ноя
				sumOfDays = sumOfDays + dayPerMonth30 - day1;
			else // если месяц Янв или Мар или Май или Июл или Авг или Окт или Дек
				sumOfDays = sumOfDays + dayPerMonth31 - day1;			
			//cout << sumOfDays << " days." << endl;

			// количество дней суммарно в месяцах между month1 и month2
			for (int month = month1 + 1; month < month2; month++) {
				if (month == February) {
					if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
						sumOfDays = sumOfDays + dayPerMonth28 + 1;
					else // если год НЕвисокосный
						sumOfDays = sumOfDays + dayPerMonth28;
				}
				else if (month == April || month == June || month == September || month == November) // если месяц Апр или Июн или Сен или Ноя
					sumOfDays = sumOfDays + dayPerMonth30;
				else // если месяц Янв или Мар или Май или Июл или Авг или Окт или Дек
					sumOfDays = sumOfDays + dayPerMonth31;
			}
			//cout << sumOfDays << " days." << endl;

			// количество дней с начала month2 и до day2
			sumOfDays = sumOfDays + day2 - 1;
			//cout << sumOfDays << " days." << endl;
		}
	}	 
	else { // если year1 != year2
		// количество дней с day1 и до конца month1
		if (month1 == February) {
			if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
				sumOfDays = sumOfDays + dayPerMonth28 + 1 - day1;
			else // если год НЕвисокосный
				sumOfDays = sumOfDays + dayPerMonth28 - day1;
		}
		else if (month1 == April || month1 == June || month1 == September || month1 == November) // если месяц Апр или Июн или Сен или Ноя
			sumOfDays = sumOfDays + dayPerMonth30 - day1;
		else // если месяц Янв или Мар или Май или Июл или Авг или Окт или Дек
			sumOfDays = sumOfDays + dayPerMonth31 - day1;
		//cout << sumOfDays << " days." << endl;

		// количество дней суммарно в месяцах между month1 и до конца year1
		for (int month = month1 + 1; month <= December; month++) {
			if (month == February) {
				if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
					sumOfDays = sumOfDays + dayPerMonth28 + 1;
				else // если год НЕвисокосный
					sumOfDays = sumOfDays + dayPerMonth28;
			}
			else if (month == April || month == June || month == September || month == November) // если месяц Апр или Июн или Сен или Ноя
				sumOfDays = sumOfDays + dayPerMonth30;
			else // если месяц Янв или Мар или Май или Июл или Авг или Окт или Дек
				sumOfDays = sumOfDays + dayPerMonth31;
		}
		//cout << sumOfDays << " days." << endl;

		// количество дней суммарно в годах между year1 и year2
		for (int year = year1 + 1; year < year2; year++) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
				sumOfDays = sumOfDays + dayPerYear + 1;
			else // если год НЕвисокосный
				sumOfDays = sumOfDays + dayPerYear;
		}
		//cout << sumOfDays << " days." << endl;

		// количество дней суммарно в месяцах с начала year2 и до month2
		for (int month = January; month < month2; month++) { // количество дней в месяцах между month1 и month2
			if (month == February) {
				if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) // если год високосный (год кратен 4, но не кратен 100 или кратен 400)
					sumOfDays = sumOfDays + dayPerMonth28 + 1;
				else // если год НЕвисокосный
					sumOfDays = sumOfDays + dayPerMonth28;
			}
			else if (month == April || month == June || month == September || month == November) // если месяц Апр или Июн или Сен или Ноя
				sumOfDays = sumOfDays + dayPerMonth30;
			else // если месяц Янв или Мар или Май или Июл или Авг или Окт или Дек
				sumOfDays = sumOfDays + dayPerMonth31;
		}
		//cout << sumOfDays << " days." << endl;

		// количество дней с начала month2 и до day2
		sumOfDays = sumOfDays + day2 - 1;
		//cout << sumOfDays << " days." << endl;
	}
	
	cout << "Between your dates: ";
	cout << setfill('0') << setw(2) << day1 << "."
						 << setw(2) << month1 << "."
						 << setw(4) << year1 << " and "
						 << setw(2) << day2 << "."
						 << setw(2) << month2 << "."
						 << setw(4) << year2 << " "
		 << sumOfDays << " days." << endl;
	
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
