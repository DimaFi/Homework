using System;

class Program
{
    static void Main()
    {
        int n = 3;

        int[,] array = new int[n, n];

        Random random = new Random();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i, j] = random.Next(1, 10);
            }
        }

        // Выводим исходный массив
        Console.WriteLine("Исходный массив:");
        PrintArray(array);

        array = RemoveRowsWithoutEvenElements(array);

        Console.WriteLine("\nМассив после удаления строк без четных элементов:");
        PrintArray(array);
    }

    static int[,] RemoveRowsWithoutEvenElements(int[,] inputArray)
    {
        int rows = inputArray.GetLength(0);
        int cols = inputArray.GetLength(1);

        int[,] newArray = new int[rows, cols];
        int newRow = 0;

        for (int i = 0; i < rows; i++)
        {
            bool hasEven = false;
            for (int j = 0; j < cols; j++)
            {
                if (inputArray[i, j] % 2 == 0)
                {
                    hasEven = true;
                    break;
                }
            }

            if (hasEven)
            {
                for (int j = 0; j < cols; j++)
                {
                    newArray[newRow, j] = inputArray[i, j];
                }
                newRow++;
            }
        }

        int[,] resultArray = new int[newRow, cols];
        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                resultArray[i, j] = newArray[i, j];
            }
        }

        return resultArray;
    }

    static void PrintArray(int[,] array)
    {
        int rows = array.GetLength(0);
        int cols = array.GetLength(1);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Console.Write(array[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
