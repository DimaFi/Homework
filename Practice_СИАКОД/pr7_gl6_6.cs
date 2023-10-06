using System;

class Program
{

    static bool DelRow(ref int[] Array)
    {
        for (int i = 0; i < Array.Length; i++)
        {
                if (Array[i] % 2 == 0)
                {
                    return true;
                }
        }
        return false;
    }
    static void Main()
    {

        int n = 4;
        int[][] Array = new int[][]
        {
            new int[] { 1, 3, 5, 7 },
            new int[] { 2, 4, 6, 8 },
            new int[] { 11, 13, 15, 17 },
            new int[] { 11, 13, 15, 17 },
        };

        int RowCount = 0;

        for (int i = 0; i + RowCount < n; i++)
        {
            if (DelRow(ref Array[i + RowCount]) == false)
            {
                RowCount++;
                if (RowCount + i != n)
                {
                    Array[i] = Array[i + RowCount];
                }
                i--;
            }
            else
            {
                Array[i] = Array[i + RowCount];
            }
        }

        if (RowCount != n)
        {
            for (int i = 0; i < n - RowCount; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write($"{Array[i][j]} ");
                }
                Console.WriteLine();
            }
        }
        else
        {
            Console.WriteLine("Wasted");
        }

    }
}
