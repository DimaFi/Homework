
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

class Program
{
    static void Main()
    {
        StreamWriter cout = new StreamWriter(Console.OpenStandardOutput());
        StreamReader cin = new StreamReader(Console.OpenStandardInput());

        Console.SetOut(cout);
        cout.AutoFlush = true;
        Console.SetIn(cin);

        // Создание объектов Matric
        Matric a = new Matric();
        Matric b = new Matric();


        a = Matric.EnteringElements(cin);

        if (a) // Проверка на квардрат
        {
            Console.WriteLine("Square"); 
        }

        a--;
        Console.WriteLine();
        Console.WriteLine(a);

        b = a++;
        a[0, 0] = -1;

        int sum = a.SumOfColumns(0); // Вычисление суммы элементов первого столбца матрицы a

        Console.WriteLine();
        a[0, 9] = 999;
        Console.WriteLine(a);
        Console.WriteLine();
        Console.WriteLine(b);
        int[,] z = a;
        Matric t = new Matric();
        t = z;

        Console.WriteLine(t.QuantitiOfZeroElements);
        Console.WriteLine(z.Length);
    }
}
