import java.util.Scanner;
import static java.lang.Math.*;
import java.util.ArrayList;
import java.util.List;

public class Main_1 {
    static boolean isPrime(int digit) { // проверка числа на простоту
        if (digit == 1 || digit % 2 == 0) {
            return false;
        }
        else if (digit <= 3) {
            return true;
        }
        else {
            for (int i = 5; i <= sqrt(digit); i += 2) { // проходимя по делителям до корня из числа
                if (digit % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    static int modPow(int base, int exponent, int module) { // возведение в степень по модулю 1 способ
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

    static boolean Fermat(int base, int module) { // проверка теоремы Ферма
        return modPow(base, module - 1, module) == 1;
    }

    static int digit2(int exponent) { // перевод числа в двоичную степень
        int dig = 1, result = 0; // dig - разряд числа
        while (exponent > 0) {
            result += (exponent % 2) * dig;
            exponent /= 2;
            dig *= 10;
        }
        return result;
    }

    static int modPowLog(int base, int exponent, int module) { // возведение в степень по модулю 2 способ (через логарифм)
        int t = (int) floor(log(exponent) / log(2.0)); // логарифм по основанию 2
        List<Integer> a = new ArrayList<>();
        int result = 1;
        for (int i = 1; i <= pow(2, t); i *= 2) {
            a.add(modPow(base, i, module)); // ищем ряд а, заполняем контейнер
        }
        int exp2 = digit2(exponent); // двоичная запись степени
        for (int i = 0; i < a.size(); i++) {
            result = result * modPow(a.get(i), exp2 % 10, module);
            exp2 /= 10;
        }
        return result % module;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите модуль р: ");
        int p = in.nextInt();
        if (isPrime(p)) { // проверка модуля на простоту
            System.out.print("Введите число а: ");
            int a = in.nextInt();
            if (Fermat(a, p)) { // проверка числа а на теорему Ферма
                System.out.print("Введите степень числа а: ");
                int expa = in.nextInt();
                System.out.print("Введите число b: ");
                int b = in.nextInt();
                if (Fermat(b, p)) { // проверка числа b на теорему Ферма
                    System.out.print("Введите степень числа b: ");
                    int expb = in.nextInt();
                    System.out.print("Сравнение первым способом: ");
                    if (modPow(a, expa, p) == modPow(b, expb, p)) { // сравнение по модулю через 1 способ
                        System.out.println(a + "^" + expa + " mod " + p + " = " + b + "^" + expb + " mod " + p);
                    }
                    else {
                        System.out.println(a + "^" + expa + " mod " + p + " != " + b + "^" + expb + " mod " + p);
                    }
                    System.out.print("Сравнение вторым способом (через логарифм): ");
                    if (modPowLog(a, expa, p) == modPowLog(b, expb, p)) { // сравнение по модулю через 2 способ (логарифм)
                        System.out.println(a + "^" + expa + " mod " + p + " = " + b + "^" + expb + " mod " + p);
                    }
                    else {
                        System.out.println(a + "^" + expa + " mod " + p + " != " + b + "^" + expb + " mod " + p);
                    }
                }
                else {
                    System.out.print("Теорема Ферма не выполняется для числа b.");
                }
            }
            else {
                System.out.print("Теорема Ферма не выполняется для числа а.");
            }
        }
        else {
            System.out.print("Введённый модуль р не является простым.");
        }
    }
}
