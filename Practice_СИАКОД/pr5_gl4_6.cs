using System;

class Program
{
    static void PrintDigits(int number)
    {
        if (number > 0)
        {
            PrintDigits(number / 10);
            int digit = number % 10;
            Console.Write(digit + " ");
        }
    }

    static void Main()
    {
        int A = 123;
        int B = 135;

        for (int i = A; i <= B; i++)
        {
            Console.Write($"Цифры числа {i} в прямом порядке: ");
            PrintDigits(i);
            Console.WriteLine();
        }
    }
}
