  static int[,] Remove(int[,] arr)
    {
        int i1 = arr.GetLength(0);
        int j1 = arr.GetLength(1);

        int[,] newArray = new int[i1, j1];
        int newRow = 0;

        for (int i = 0; i < i1; i++)
        {
            bool hasEven = false;
            for (int j = 0; j < j1; j++)
            {
                if (arr[i, j] % 2 == 0)
                {
                    hasEven = true;
                    break;
                }
            }

            if (hasEven)
            {
                for (int j = 0; j < j1; j++)
                {
                    newArray[newRow, j] = arr[i, j];
                }
                newRow++;
            }
        }

        int[,] resultArray = new int[newRow, j1];
        for (int i = 0; i < newRow; i++)
        {
            for (int j = 0; j < j1; j++)
            {
                resultArray[i, j] = newArray[i, j];
            }
        }

        return resultArray;
    }
