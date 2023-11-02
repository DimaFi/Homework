using System;
using System.IO;

class Program
{
    static void Main()
    {
        StreamReader inputFile = new StreamReader("input.txt");

        List<double> numbers = new List<double>();

        while (!inputFile.EndOfStream)
        {
            string[] numberStrings = inputFile.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);

            foreach (string numberStr in numberStrings)
            {
                if (double.TryParse(numberStr, out double number))
                {
                    numbers.Add(number);
                }
            }
        }

        inputFile.Close();

        StreamWriter outputFile = new StreamWriter("output.txt");

        for (int i = 0; i < numbers.Count - 1; i += 2)
        {
            double average = (numbers[i] + numbers[i + 1]) / 2;
            outputFile.WriteLine(average);
        }

        outputFile.Close();
    }
}

/*
10 15
20
5
30
25
*/
