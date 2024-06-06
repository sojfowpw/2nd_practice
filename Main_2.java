import java.util.Scanner;

public class Main_2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите число с: ");
        int c = in.nextInt();
        System.out.print("Введите модуль m: ");
        int m = in.nextInt();
        int d = inverseElement(c, m);
        if (gcd(c, m) == 1) { // если НОД = 1, то числа взаимно простые, а значит существует обратный элемент d
            System.out.println("d = " + d);
            System.out.print(c + " * " + d + " mod " + m + " = 1"); // проверка уравнения
        }
    }

    public static int gcd(int dig_1, int dig_2) { // НОД чисел c и m с реализацией алгоритма Евклида
        if (dig_2 == 0) { // если второе число = 0, то первое = НОД
            return dig_1;
        }
        else {
            return gcd(dig_2, dig_1 % dig_2); // вызов gcd, делитель становится делимым, а остаток - делителем
        }
    }

    public static int inverseElement(int a, int b) { // нахождение обратного элемента d
        System.out.println("|  r  |  x  |  y  |  q  |");
        int x1 = 1, y1 = 0; // x и y при r = a, значения в предпредыдущей строке
        int x2 = 0, y2 = 1; // x и y при r = b, значения в предыдущей строке
        int r = a, q, x, y; // r - остаток от деления, q - частное, x и y - значения в текущей строке
        int mdl = b; // значение модуля
        while (r > 0) {
            r = a % b;
            q = a / b;
            x = x1 - q * x2;
            y = y1 - q * y2;
            System.out.printf("|%5d|%5d|%5d|%5d|\n", r, x, y, q); // вывод таблицы
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
}
