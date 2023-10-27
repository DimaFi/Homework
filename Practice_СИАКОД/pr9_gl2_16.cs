using System;
using System.IO;

class Program
{
    static void Main()
    {
        string inputFile = "input.txt";
        string outputFile = "output.txt";

        if (!File.Exists(inputFile))
        {
            Console.WriteLine("Исходный файл не найден.");
            return;
        }


        string[] lines = File.ReadAllLines(inputFile);
        double[] numbers = new double[lines.Length];

        for (int i = 0; i < lines.Length; i++)
        {
            if (double.TryParse(lines[i], out double number))
            {
                numbers[i] = number;
            }
            else
            {
                Console.WriteLine($"Ошибка чтения числа в строке {i + 1}: {lines[i]}");
                return;
            }
        }

        // Создаем новый файл и вычисляем средние арифметические
        using (StreamWriter writer = new StreamWriter(outputFile))
        {
            for (int i = 0; i < numbers.Length - 1; i += 2)
            {
                double average = (numbers[i] + numbers[i + 1]) / 2;
                writer.WriteLine(average);
            }
        }

        Console.WriteLine("Средние арифметические записаны в файл: " + outputFile);
    }
}
