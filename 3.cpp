#include <iostream>
#include <iomanip>

using namespace std;

int gcd(int dig_1, int dig_2) { // НОД чисел c и m с реализацией алгоритма Евклида
	if (dig_1 % dig_2 == 0) { // если остаток = 0, то НОД = делитель
		return dig_2; // возвращаем НОД
	}
	else {
		gcd(dig_2, dig_1 % dig_2); // вызов gcd, делитель становится делимым, а остаток - делителем
	}
}

int inverseElement(int a, int b) { // нахождение обратного элемента d
	cout << "|" << setw(3) << "r" << setw(3) << "|" << setw(3) << "x" << setw(3) << "|" << setw(3) << "y" << setw(3) << "|" << setw(3) << "q" << setw(3) << "|" << endl;
	int x1 = 1, y1 = 0; // x и y при r = a, значения в предпредыдущей строке
	int x2 = 0, y2 = 1; // x и y при r = b, значения в предыдущей строке
	int r = a, q, x, y; // r - остаток от деления, q - частное, x и y - значения в текущей строке
	int mdl = b; // значение модуля
	while (r > 0) {
		r = a % b;
		q = a / b;
		x = x1 - q * x2;
		y = y1 - q * y2;
		cout << "|" << setw(3) << r << setw(3) << "|" << setw(3) << x << setw(3) << "|" << setw(3) << y << setw(3) << "|" << setw(3) << q << setw(3) << "|" << endl; // вывод таблицы
		a = b; // делитель b становится делимым a
		b = r; // остаток r становится делителем b
		x1 = x2; // значения предыдущей строки присваиваются предпредыдущей
		x2 = x; // значения текущей строки присваиваются предыдущей
		y1 = y2; // значения предыдущей строки присваиваются предпредыдущей
		y2 = y; // значения текущей строки присваиваются предыдущей
	}
	if (x1 < 0) { // если d отрицательное, прибавляем значение модуля
		x1 += mdl;
	}
	return x1; // возвращаем d
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите число c: ";
	int c;
	cin >> c;
	cout << "Введите модуль m: ";
	int m;
	cin >> m;
	int d = inverseElement(c, m);
	if (gcd(c, m) == 1) { // если НОД = 1, то числа взаимно простые, а значит существует обратный элемент d
		cout << c << "^-1 mod " << m << " = " << d << endl;
		cout << c << " * " << d << " mod " << m << " = 1"; // проверка уравнения
	}
	return 0;
}
