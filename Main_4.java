import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main_4 {
    static List<Integer> digitsPrime() { // генерация простых чисел в диапазоне от 10 до 100
        List<Integer> prime_dig = new ArrayList<>();
        for (int i = 2; i <= 100; i++) {
            boolean is_prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                prime_dig.add(i);
            }
        }
        return prime_dig;
    }

    static int gcd(int a, int b) { // НОД
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static int inverseElement(int a, int m) { // нахождение обратного элемента
        int m0 = m;
        int y = 0, x = 1;

        if (m == 1)
            return 0;

        while (a > 1) {
            int q = a / m;
            int t = m;

            m = a % m;
            a = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0)
            x += m0;

        return x;
    }

    static int modPow(int base, int exponent, int module) { // возведение в степень по модулю
        int result = 1;
        base = base % module;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % module;
            }
            exponent = exponent >> 1;
            base = (base * base) % module;
        }
        return result;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        Scanner scanner = new Scanner(System.in);
        List<Integer> prime_dig = digitsPrime(); // вектор с простыми числами от 10 до 99
        int p = prime_dig.get(rand.nextInt(prime_dig.size())); // случайные простые числа p и q
        int q = prime_dig.get(rand.nextInt(prime_dig.size()));
        int n = p * q;
        int funEuler = (p - 1) * (q - 1); // функция Эйлера для n
        System.out.println("Функция Эйлера = " + funEuler);
        int e = 0;
        while (true) {
            e = prime_dig.get(rand.nextInt(prime_dig.size())); // случайное число е такое, что оно меньше функции Эйлера и взаимообратно с p и q
            if (gcd(e, funEuler) == 1) {
                break;
            }
        }
        System.out.println("Число е для публичного ключа = " + e);
        int d = inverseElement(e, funEuler); // обратное число d -> d^e = 1 mod funEuler
        System.out.println("Обратное число d для приватного ключа = " + d);
        String str = scanner.nextLine(); // вводим сообщение для шифрования
        List<Integer> ascii = new ArrayList<>(); // вектор для символов ascii и зашифрованного сообщения
        List<Integer> cypher = new ArrayList<>();
        System.out.print("ASCII: ");
        for (int i = 0; i < str.length(); i++) {
            ascii.add((int) str.charAt(i)); // переводим символы в значения таблицы ascii
            System.out.print(ascii.get(i) + " ");
        }
        System.out.print("\nЗашифрованное сообщение: ");
        for (int i = 0; i < ascii.size(); i++) {
            cypher.add(modPow(ascii.get(i), e, n)); // шифруем значения: cypher = ascii^e mod n
            System.out.print(cypher.get(i) + " ");
        }
        System.out.print("\nРасшифрованное сообщение: ");
        for (int i = 0; i < cypher.size(); i++) {
            int m = modPow(cypher.get(i), d, n); // расшифровываем: ascii = cypher^d mod n
            System.out.print((char) m);
        }
    }
}
