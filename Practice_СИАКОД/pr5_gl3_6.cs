using System;

class Program
{
    static int CalculateCombinations(int n, int m)
    {
        if (m == 0 || m == n)
            return 1;
        
        if (m == 1)
            return n;

        return CalculateCombinations(n - 1, m) + CalculateCombinations(n - 1, m - 1);
    }

    static void Main()
    {
        int n = 5;
        int m = 2;

        int result = CalculateCombinations(n, m);
        Console.WriteLine($"C({n}, {m}) = {result}");
    }
}
