#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

vector<int> digitsPrime() { // генерация простых чисел в диапазоне от 10 до 100
    vector<int> prime_dig; // вектор для простых чисел
    for (int i = 10; i <= 100; i++) {
        if (i % 2 == 1) {
            bool is_prime = true;
            for (int j = 3; j <= sqrt(i); j += 2) { // проходимя по делителям от 3 до корня из делимого
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                prime_dig.push_back(i); // заполняем вектор простыми числами
            }
        }
    }
    return prime_dig;
}

int gcd(int dig_1, int dig_2) { // НОД 
    if (dig_1 % dig_2 == 0) { // если остаток = 0, то НОД = делитель
        return dig_2; // возвращаем НОД
    }
    else {
        gcd(dig_2, dig_1 % dig_2); // вызов gcd, делитель становится делимым, а остаток - делителем
    }
}

int inverseElement(int a, int b) { // нахождение обратного элемента d
    int x1 = 1, y1 = 0; // x и y при r = a, значения в предпредыдущей строке
    int x2 = 0, y2 = 1; // x и y при r = b, значения в предыдущей строке
    int r = a, q, x, y; // r - остаток от деления, q - частное, x и y - значения в текущей строке
    int mdl = b; // значение модуля
    while (r > 0) {
        r = a % b;
        q = a / b;
        x = x1 - q * x2;
        y = y1 - q * y2;
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

int modPow(int base, int exponent, int module) { // возведение в степень по модулю
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

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> prime_dig = digitsPrime(); // вектор с простыми числами от 100 до 999
    int p = prime_dig[rand() % (prime_dig.size() + 1)]; // случайные простые числа p и q
    int q = prime_dig[rand() % (prime_dig.size() + 1)];
    int n = p * q;
    int funEuler = (p - 1) * (q - 1); // функция Эйлера для n
    cout << "Функция Эйлера = " << funEuler << endl;
    int e = 0;
    while (true) {
        e = rand() % (funEuler - 10 + 1); // случайное число е такое, что оно меньше функции Эйлера и взаимообратно с p и q
        if (gcd(p, e) == 1 && gcd(q, e) == 1) {
            break;
        }
    }
    cout << "Число е для публичного ключа = " << e << endl;
    int d = inverseElement(e, funEuler); // обратное число d -> d^e = 1 mod funEuler
    cout << "Обратное число d для приватного ключа = " << d << endl;
    string str;
    getline(cin, str); // вводим сообщение для шифрования
    vector<int> ascii, cypher; // вектор для символов ascii и зашифрованного сообщения
    cout << "ASCII: ";
    for (int i = 0; i < str.size(); i++) {
        ascii.push_back((int)(unsigned char)str[i]); // переводим символы в значения таблицы ascii
        cout << ascii[i] << " ";
    }
    cout << endl << "Зашифрованное сообщение: ";
    for (int i = 0; i < ascii.size(); i++) {
        cypher.push_back(modPow(ascii[i], e, n)); // шифруем значения: cypher = ascii^e mod n
        cout << cypher[i] << " ";
    }
    cout << endl << "Расшифрованное сообщение: ";
    for (int i = 0; i < cypher.size(); i++) {
        cout << static_cast<unsigned char>(modPow(cypher[i], d, n)); // расшифровываем: ascii = cypher^d mod n
    }
    cout << endl;
    return 0;
}
