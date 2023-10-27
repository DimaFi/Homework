using System;
using System.IO;

class Program
{
    static void Main()
    {
        StreamReader inputFile = new StreamReader("input.txt");

        string[] lines = inputFile.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);

        double[] numbers = new double[lines.Length];

        for (int i = 0; i < lines.Length; i++)
        {
            numbers[i] = double.Parse(lines[i]);
        }

        inputFile.Close();

        StreamWriter outputFile = new StreamWriter("output.txt");

        for (int i = 0; i < numbers.Length - 1; i += 2)
        {
            double average = (numbers[i] + numbers[i + 1]) / 2;
            outputFile.WriteLine(average);
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
