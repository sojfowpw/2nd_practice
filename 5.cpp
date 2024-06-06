#include <iostream>
#include <cmath>

using namespace std;

int lastDigit(int b, int ex_1, int ex_2) { // вычисление последней цифры
    int result = 1;
    for (int i = 1; i <= pow(ex_1,  ex_2); i++) { // вычисление степени числа
        result = result * b % 10; // умножение числа и нахождение последней цифры
    }
    return result; // возврат результата (последней цифры)
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите основание степени: ";
    int base;
    cin >> base;
    cout << "Введите 1 показатель степени: ";
    int exponent_1;
    cin >> exponent_1;
    cout << "Введите 2 показатель степени: ";
    int exponent_2;
    cin >> exponent_2;
    cout << "Последняя цифра: " << lastDigit(base, exponent_1, exponent_2); // вывод результата
    return 0;
}
