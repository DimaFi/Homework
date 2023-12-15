using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Data;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
using System.Diagnostics.Metrics;
using System.Reflection;
using System.Net.Http.Headers;
using System.ComponentModel.DataAnnotations;


class Matric
{
    private int[,] intArray;
    private int quantitiOfStrings, quantitiOfZeroElements, quantitiOfColumns;
    public int scal = 0;
    public Matric()
    {
        this.intArray = new int[0, 0];
        this.quantitiOfStrings = 0;
        this.quantitiOfZeroElements = 0;

    }
    public Matric(int[,] inputArray)
    {
        this.quantitiOfStrings = inputArray.Length;
        this.quantitiOfZeroElements = 0;
        int[,] temp = inputArray.Clone() as int[,];
        this.intArray = temp;
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            for (int j = 0; j < this.quantitiOfColumns; j++)
            {
                if (this.intArray[i, j] > 0)
                {
                    this.quantitiOfZeroElements++;
                }
            }
        }

    }
    public Matric(Matric x)
    {
        this.intArray = new int[x.quantitiOfStrings, ];
        int[,] temp = x.intArray.Clone() as int[,];
        this.intArray = temp;
        this.quantitiOfZeroElements = (int)x.quantitiOfZeroElements;
        this.quantitiOfStrings = (int)x.quantitiOfStrings;
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            for (int j = 0; j < this.quantitiOfColumns; j++)
            {
                if (this.intArray[i, j] > 0)
                {
                    this.quantitiOfZeroElements++;
                }
            }
        }
    }

    public static Matric EnteringElements(StreamReader Cin)
    {
        int n = Convert.ToInt32(Cin.ReadLine());
        int m = Convert.ToInt32(Cin.ReadLine());
        string[] temp;
        int[,] tempIntArray = new int[n, m];
        int counterOfStrings = n;
        while (counterOfStrings > 0)
        {
            temp = Cin.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            counterOfStrings--;
            int[] tempArray = new int[temp.Length];
            for (int i = 0; i < temp.Length; i++)
            {
                tempArray[i] = Convert.ToInt32(temp[i]);
            }
            for (int i = 0; i < m; i++)
            {
                tempIntArray[n - counterOfStrings - 1, i] = tempArray[i];
            }
        }
        return new Matric(tempIntArray);
    }

    public override string ToString()
    {
        string outString = "";
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            for (int j = 0; j < this.intArray[i, j]; j++)
            {
                outString += this.intArray[i, j].ToString() + " ";
            }
            outString += '\n';
        }
        return outString;
    }

    public static Matric operator --(Matric x)
    {
        Matric temp = new Matric(x);
        int[,] tempArray = new int[temp.quantitiOfStrings, temp.quantitiOfColumns];
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            for (int j = 0; j < temp.quantitiOfColumns; j++)
            {
                tempArray[i, j] = -1 + temp.intArray[i, j];
            }
        }
        temp.intArray = tempArray;
        return temp;
    }

    public static Matric operator ++(Matric x)
    {
        Matric temp = new Matric(x);
        int[,] tempArray = new int[temp.quantitiOfStrings, temp.quantitiOfColumns];
        for (int i = 0; i < x.quantitiOfStrings; i++)
        {
            for (int j = 0; j < temp.quantitiOfColumns; j++)
            {
                tempArray[i, j] = 1 + temp.intArray[i, j];
            }
        }
        temp.intArray = tempArray;
        return temp;
    }

    public static bool operator true(Matric x)
    {
        if (x.quantitiOfStrings == x.quantitiOfColumns)
        {
            return true;
        }
        return false;
    }

    public static bool operator false(Matric x)
    {
        if (x.quantitiOfStrings == x.quantitiOfColumns)
        {
            return true;
        }
        return false;
    }

    public static implicit operator int[,](Matric x)
    {
        int[,] temp = x.intArray.Clone() as int[,];
        return temp;
    }

    public static implicit operator Matric(int[,] x)
    {
        Matric temp = new Matric(x);
        return temp;
    }

    public int SumOfColumns(int m)
    {
        int sum = 0;
        for (int i = 0; i < this.quantitiOfStrings; i++)
        {
            sum += this.intArray[i, m];
        }
        return sum;
    }

    public int QuantitiOfZeroElements

    {
        get
        {
            return this.quantitiOfZeroElements;
        }
    }
    public int SetDiag

    {
        set
        {
            for (int i = 0; i < this.quantitiOfStrings; i++)
            {
                this.intArray[i, i] = scal;
            }
        }
    }

    public int this[int i, int j]
    {
        get
        {
            if (Math.Abs(i) >= this.quantitiOfStrings)
            {
                Console.WriteLine("Wrong Index");
                return 0;
            }
            else
            {
                if (i < 0)//Отрицательный индекс строки
                {
                    i = this.quantitiOfZeroElements + i;
                }
                if (Math.Abs(j) >= this.quantitiOfColumns)
                {
                    Console.WriteLine("Wrong Index");
                    return 0;
                }
                else
                {
                    if (j < 0)
                    {
                        j = this.quantitiOfColumns + j;

                    }
                    return this.intArray[i, j];
                }
            }
        }
        set
        {
            if (Math.Abs(i) >= this.quantitiOfStrings)
            {
                Console.WriteLine("Wrong Index");
            }
            else
            {
                if (i < 0)//Отрицательный индекс строки
                {
                    i = this.quantitiOfZeroElements + i;
                }
                if (Math.Abs(j) >= this.quantitiOfColumns)
                {
                    Console.WriteLine("Wrong Index");
                }
                else
                {
                    if (j < 0)
                    {
                        j = this.quantitiOfColumns + j;

                    }
                    this.intArray[i, j] = value;
                }
            }
        }


    }

}
