using System;

class Program
{
    static void Main()
    {
        int n = 3;

        int[,] mat = new int[n, n];
        
        Random random = new Random();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i, j] = random.Next(1, 10);
            }
        }

        int a = 2, b = 6;

        int[] sums = new int[n];

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                int cur = mat[i, j];
                if (cur < a || cur > b)
                {
                    sum += cur;
                }
            }
            sums[i] = sum;
        }


        Console.WriteLine("Матрица:");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Console.Write(mat[i, j] + "\t");
            }
            Console.WriteLine();
        }

        Console.WriteLine("\nСуммы элементов, не попадающих в интервал ({0}-{1}):", a, b);

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine("Строка {0}: {1}", i + 1, sums[i]);
        }
    }
}
