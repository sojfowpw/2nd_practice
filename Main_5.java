import java.util.Scanner;

public class Main_5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Введите основание степени: ");
        int base = in.nextInt(); // ввод основания
        System.out.print("Введите 1 показатель степени: ");
        int exponent_1 = in.nextInt(); // ввод 1 показателя
        System.out.print("Введите 2 показатель степени: ");
        int exponent_2 = in.nextInt(); // ввод 2 показателя
        System.out.print("Последняя цифра: " + lastDigit(base, exponent_1, exponent_2)); // вывод результата
    }
    public static int lastDigit(int b, int ex_1, int ex_2) { // вычисление последней цифры
        int result = 1;
        for (int i = 1; i <= Math.pow(ex_1, ex_2); i++) { // вычисление степени числа
            result = result * b % 10; // умножение числа и нахождение последней цифры
        }
        return result;
    }
}
