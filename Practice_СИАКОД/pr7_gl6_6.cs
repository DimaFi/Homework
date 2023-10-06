using System;

class Program
{
    static void Main()
    {
        int[][] Array = new int[][]
        {
            new int[] { 1, 3, 5, 7 },
            new int[] { 2, 4, 6, 8 },
            new int[] { 11, 13, 15, 17 },
            new int[] { 10, 20, 30, 40 },
        };


        int[][] NewArray = new int[Array.Length][];
        int RowCount = 0;

        for (int i = 0; i < Array.Length; i++)
        {
            bool hasEven = false;

            foreach (int element in Array[i])
            {
                if (element % 2 == 0)
                {
                    hasEven = true;
                    break;
                }
            }

            if (hasEven)
            {
                NewArray[RowCount] = Array[i];
                RowCount++;
            }
        }

        Console.WriteLine("Result:");
        for (int i = 0; i < RowCount;  i++)
        {
            Console.WriteLine(string.Join(", ", NewArray[i]));
        }
    }
}
