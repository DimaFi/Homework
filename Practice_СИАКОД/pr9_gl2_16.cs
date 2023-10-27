using System;
using System.IO;

class Program
{
    static void Main()
    {
        string inputFile = "input.txt";
        string outputFile = "output.txt";

        string[] lines = File.ReadAllLines(inputFile);
        double[] numbers = new double[lines.Length];


        for (int i = 0; i < lines.Length; i++)
        {
            numbers[i] = double.Parse(lines[i]);
        }

        using (StreamWriter writer = new StreamWriter(outputFile))
        {
            for (int i = 0; i < numbers.Length - 1; i += 2)
            {
                double average = (numbers[i] + numbers[i + 1]) / 2;
                writer.WriteLine(average);
            }
        }
    }
}

/*
10
15
20
5
30
25
*/
