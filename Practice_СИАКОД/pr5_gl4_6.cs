using System;

class Program
{
    static void PrintDigits(int number)
    {
        if (number > 0)
        {
            PrintDigits(number / 10); // Рекурсивно вызываем для оставшихся разрядов числа
            int digit = number % 10; // Получаем последнюю цифру числа
            Console.Write(digit + " "); // Выводим цифру на экран
        }
    }

    static void Main()
    {
        int A = 123; // Начальное значение A
        int B = 135; // Конечное значение B

        for (int i = A; i <= B; i++)
        {
            Console.Write($"Цифры числа {i} в прямом порядке: ");
            PrintDigits(i);
            Console.WriteLine(); // Переход на новую строку для следующего числа
        }
    }
}
