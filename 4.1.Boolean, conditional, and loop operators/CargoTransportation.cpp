// Задание 4: Грузовой самолет должен пролететь с грузом из пункта А в пункт С через пункт В. Емкость бака для топлива у самолета – 300 литров.
// Потребление топлива на 1 км в зависимости от веса груза у самолета следующее: 
// - до 500 кг  : 1 л / км
// - до 1000 кг : 4 л / км
// - до 1500 кг : 7 л / км
// - до 2000 кг : 9 л / км.
// - более 2000 кг – самолет не поднимает.
// Пользователь вводит расстояние между пунктами А и В, и расстояние между пунктами В и С, а также вес груза.
// Программа должна рассчитать какое минимальное количество топлива необходимо для дозаправки самолету в пункте В, чтобы долететь из пункта А в пункт С.
// В случае невозможности преодолеть любое из расстояний – программа должна вывести сообщение о невозможности полета по введенному маршруту.

#include "pch.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// сравнивает double числа и возвращает 0 если x == y, 1 если x > yили -1 если x < y
int compare(double x, double y);

int main()
{
	// сообщения в консоль
	char message1[] = "Enter the distance from city A to city B: ",
		 message2[] = "Enter the distance from city B to city C: ",
		 message3[] = "Enter the weight of the load: ",
		 message4[] = "Refueling is not required. ",
		 message51[] = "To fly to city C, in city B enough to fill up ",
		 message52[] = " liters of fuel.",
		 warning1[] = "WARNING!!! Underloading.",
		 warning2[] = "WARNING!!! The distance to city B is too long!!! We can't make the flight.",
		 warning3[] = "WARNING!!! The distance to city C is too long!!! We can only fly to city B.",
		 warning4[] = "WARNING!!! Overload.";

	// емкость топливного бака
	const double tankCapacity = 300;

	// варианты загрузки
	const double loadMin = 0,
				 loadUpTo500 = 500,
				 loadUpTo1000 = 1000,
				 loadUpTo1500 = 1500,
				 loadMax = 2000;

	// FCP (fuel consumption per) - расход топлива в зависимости от загрузки
	const double FCPUpTo500 = 1, // одного бака хватает на 300 км
				 FCPUpTo1000 = 4, // одного бака хватает на 75 км
				 FCPUpTo1500 = 7, // одного бака хватает на ~42,85 км
				 FCPUpTo2000 = 9; // одного бака хватает на ~33,33 км

	double distFromAtoB, // расстояние между А и В
		   distFromBtoC, // расстояние между В и С
		   cargoWeight; // вес груза

	cout << message1;
	cin >> distFromAtoB;
	cout << distFromAtoB << endl;
	
	cout << message2;
	cin >> distFromBtoC;
	cout << distFromBtoC << endl;

	cout << message3;
	cin >> cargoWeight;
	cout << cargoWeight << endl;

	if (compare(cargoWeight, loadMin) < 0) // если вес груза меньше или равен минимальной загрузки
		cout << warning1 << endl;
	else if (compare(cargoWeight, loadUpTo500) < 0) { // если вес груза до 500 кг
		if (compare((tankCapacity / FCPUpTo500), distFromAtoB) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от А до В
			cout << warning2 << endl;
		else if (compare((tankCapacity / FCPUpTo500), distFromAtoB) >= 0) { // если расстояние пролетаемое на одном баке больше или равно дистанции от А до В
			if (compare((tankCapacity / FCPUpTo500), distFromBtoC) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от B до С
				cout << warning3 << endl;
			else if (compare(((tankCapacity - (distFromAtoB * FCPUpTo500)) * FCPUpTo500), distFromBtoC) >= 0) // если на одном баке можно пролететь обе дистанции и АВ, и ВС
				cout << message4 << endl;
			else // вычисляем сколько надо долить топлива чтобы долететь от В до С
				cout << message51 << ((distFromBtoC * FCPUpTo500) - (tankCapacity - (distFromAtoB * FCPUpTo500))) << message52 << endl;
		}
	}
	else if (compare(cargoWeight, loadUpTo1000) < 0) { // если вес груза до 1000 кг
		if (compare((tankCapacity / FCPUpTo1000), distFromAtoB) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от А до В
			cout << warning2 << endl;
		else if (compare((tankCapacity / FCPUpTo1000), distFromAtoB) >= 0) { // если расстояние пролетаемое на одном баке больше или равно дистанции от А до В
			if (compare((tankCapacity / FCPUpTo1000), distFromBtoC) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от B до С
				cout << warning3 << endl;
			else if (compare(((tankCapacity - (distFromAtoB * FCPUpTo1000)) * FCPUpTo1000), distFromBtoC) >= 0) // если на одном баке можно пролететь обе дистанции и АВ, и ВС
				cout << message4 << endl;
			else // вычисляем сколько надо долить топлива чтобы долететь от В до С
				cout << message51 << ((distFromBtoC * FCPUpTo1000) - (tankCapacity - (distFromAtoB * FCPUpTo1000))) << message52 << endl;
		}
	}
	else if (compare(cargoWeight, loadUpTo1500) < 0) { // если вес груза до 1500 кг
		if (compare((tankCapacity / FCPUpTo1500), distFromAtoB) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от А до В
			cout << warning2 << endl;
		else if (compare((tankCapacity / FCPUpTo1500), distFromAtoB) >= 0) { // если расстояние пролетаемое на одном баке больше или равно дистанции от А до В
			if (compare((tankCapacity / FCPUpTo1500), distFromBtoC) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от B до С
				cout << warning3 << endl;
			else if (compare(((tankCapacity - (distFromAtoB * FCPUpTo1500)) * FCPUpTo1500), distFromBtoC) >= 0) // если на одном баке можно пролететь обе дистанции и АВ, и ВС
				cout << message4 << endl;
			else // вычисляем сколько надо долить топлива чтобы долететь от В до С
				cout << message51 << ((distFromBtoC * FCPUpTo1500) - (tankCapacity - (distFromAtoB * FCPUpTo1500))) << message52 << endl;
		}
	}
	else if (compare(cargoWeight, loadMax) < 0) { // если вес груза до 2000 кг
		if (compare((tankCapacity / FCPUpTo2000), distFromAtoB) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от А до В
			cout << warning2 << endl;
		else if (compare((tankCapacity / FCPUpTo2000), distFromAtoB) >= 0) { // если расстояние пролетаемое на одном баке больше или равно дистанции от А до В
			if (compare((tankCapacity / FCPUpTo2000), distFromBtoC) < 0) // если расстояние пролетаемое на одном баке меньше дистанции от B до С
				cout << warning3 << endl;
			else if (compare(((tankCapacity - (distFromAtoB * FCPUpTo2000)) * FCPUpTo2000), distFromBtoC) >= 0) // если на одном баке можно пролететь обе дистанции и АВ, и ВС
				cout << message4 << endl;
			else // вычисляем сколько надо долить топлива чтобы долететь от В до С
				cout << message51 << ((distFromBtoC * FCPUpTo2000) - (tankCapacity - (distFromAtoB * FCPUpTo2000))) << message52 << endl;
		}
	}
	else if (compare(cargoWeight, loadMax) >= 0) // если вес груза равен или больше 2000 кг
		cout << warning4 << endl;
	
	return 0;
}

// сравнивает double числа и возвращает 0 если x == y, 1 если x > yили -1 если x < y
int compare(double x, double y) {
	double delta = x - y;
	if (fabs(delta) < numeric_limits<double>::epsilon())
		// numeric_limits<double>::epsilon() - это наименьшее положительное double число 2.22045E-016
		return 0;
	return delta > 0 ? 1 : -1;
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
