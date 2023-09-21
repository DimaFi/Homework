using System;

class Program
{
    static int CalculateCombinations(int n, int m)
    {
        // Базовый случай 1: C(n, 0) и C(n, n) всегда равны 1
        if (m == 0 || m == n)
            return 1;

        // Базовый случай 2: C(n, 1) всегда равно n
        if (m == 1)
            return n;

        // Рекурсивный случай: используем свойство C(n, m) = C(n-1, m) + C(n-1, m-1)
        return CalculateCombinations(n - 1, m) + CalculateCombinations(n - 1, m - 1);
    }

    static void Main()
    {
        int n = 5; // Замените на нужное значение n
        int m = 2; // Замените на нужное значение m

        int result = CalculateCombinations(n, m);
        Console.WriteLine($"C({n}, {m}) = {result}");
    }
}
