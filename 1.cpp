#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int digit) { // проверка числа на простоту
	if (digit == 1 || digit % 2 == 0) {
		return false;
	}
	else if (digit <= 3) {
		return true;
	}
	else {
		for (int i = 5; i <= sqrt(digit); i += 2) { // проходимся по делителям до корня из числа
			if (digit % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int modPow(int base, int exponent, int module) { // возведение в степень по модулю 1 способ
	int result = 1;
	base %= module;
	while (exponent > 0) {
		if (exponent % 2 == 1) { // если степень нечётная, уменьшаем её на единицу, сохраняем результат
			result = result * base % module;
			exponent--;
		}
		exponent /= 2;
		base = base * base % module; // если степень чётная, предыдущее значение возводим в квадрат
	}
	return result;
}

bool Fermat(int base, int module) { // проверка теоремы Ферма
	return modPow(base, module - 1, module) == 1;
}

int digit2(int exponent) { // перевод числа в двоичную степень
	int dig = 1, result = 0; // dig - разряд числа
	while (exponent) {
		result += (exponent % 2) * dig;
		exponent /= 2;
		dig *= 10;
	}
	return result;
}

int modPowLog(int base, int exponent, int module) { // возведение в степень по модулю 2 способ (через логарифм)
	int t = log2(exponent); // логарифм степени по основанию 2
	vector<int> a;
	int result = 1;
	for (int i = 1; i <= pow(2, t); i *= 2) {
		a.push_back(modPow(base, i, module)); // ищем ряд а, заполняем вектор
	}
	int exp2 = digit2(exponent); // двоичная запись степени
	for (int i = 0; i < a.size(); i++) {
		result = result * modPow(a[i], exp2 % 10, module);
		exp2 /= 10;
	};
	return result % module;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите модуль p: ";
	int p;
	cin >> p;
	if (isPrime(p)) { // проверка модуля на простоту
		cout << "Введите число a: ";
		int a;
		cin >> a;
		if (Fermat(a, p)) { // проверка числа а на теорему Ферма
			cout << "Введите степень числа а: ";
			int expa;
			cin >> expa;
			cout << "Введите число b: ";
			int b;
			cin >> b;
			if (Fermat(b, p)) { // проверка числа b на теорему Ферма
				cout << "Введите степень числа b: ";
				int expb;
				cin >> expb;
				cout << "Сравнение первым способом: ";
				if (modPow(a, expa, p) == modPow(b, expb, p)) { // сравнение по модулю через 1 способ
					cout << a << "^" << expa << " mod " << p << " = " << b << "^" << expb << " mod " << p;
				}
				else {
					cout << a << "^" << expa << " mod " << p << " != " << b << "^" << expb << " mod " << p;
				}
				cout << endl << "Сравнение вторым способом (через логарифм): ";
				if (modPowLog(a, expa, p) == modPowLog(b, expb, p)) { // сравнение по модулю через 2 способ (логарифм)
					cout << a << "^" << expa << " mod " << p << " = " << b << "^" << expb << " mod " << p;
				}
				else {
					cout << a << "^" << expa << " mod " << p << " != " << b << "^" << expb << " mod " << p;
				}
			}
			else {
				cout << "Теорема Ферма не выполняется для числа b.";
			}
		}
		else {
			cout << "Теорема Ферма не выполняется для числа а.";
		}
	}
	else {
		cout << "Введённый модуль р не является простым.";
	}
	return 0;
}
