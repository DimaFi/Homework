using System;

class Program
{
    // Метод для быстрого возведения числа x в степень n
    static long FastPower(long x, int n)
    {
        if (n == 0)
            return 1;
        else if (n % 2 == 0)
        {
            long halfPower = FastPower(x, n / 2);
            return halfPower * halfPower;
        }
        else
        {
            long halfPower = FastPower(x, (n - 1) / 2);
            return x * halfPower * halfPower;
        }
    }

    static void Main()
    {
        // a) Вывести значения x в n-ной степени для каждого x на отрезке [a, b] с шагом h

        int a = -1, b = 3, h = 1;
        for (int x = a; x <= b; x += h)
        {
            int n = (x - a) / h;
            long result = FastPower(x, n);
            Console.WriteLine($"{x} в степени {n} = {result}");
        }

        // b) Найти сумму всех чисел x^n

        long sum = 0;
        for (int x = a; x <= b; x += h)
        {
            int n = (x - a) / h;
            long result = FastPower(x, n);
            sum += result;
        }
        Console.WriteLine($"Сумма: {sum}");

        // c) Найти все тройки различных целых чисел x, y, z таких, что x^2 + y^2 = z^2

        int start = 2, end = 6;
        for (int x = start; x <= end; x++)
        {
            for (int y = x + 1; y <= end; y++)
            {
                double z = Math.Sqrt(x * x + y * y);
                if (z != (int)z)
                {
                    continue;
                }
                Console.WriteLine($"Тройка {x}, {y}, {(int)z}");
            }
        }

        // d) Найти такое число n, для которого выполняется неравенство 2^(n-1) ≤ a < 2^n

        long aValue = 10;
        int nValue = 0;
        while (Math.Pow(2, nValue - 1) <= aValue && aValue < Math.Pow(2, nValue))
        {
            nValue++;
        }
        Console.WriteLine($"Для a = {aValue}, n = {nValue}");
    }
}
