
using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Diagnostics;
using System.Data;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Intrinsics.X86;
//using System.Diagnostics.MetricS;
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
        int[,] x = { { 1, 2 } , { 3, 4 } };
        // Создание объектов Matric
        Matric a = new Matric(x);
        Console.WriteLine(a);
        //Matric b = new Matric();
        a--;
        Console.WriteLine(a);
        a++;
        Console.WriteLine(a);

        int sum = a.SumOfColumns(0); // Вычисление суммы элементов первого столбца матрицы a
        Console.WriteLine(sum);

        if (a)
        {
            Console.WriteLine("Square");
        }
        else
        {
            Console.WriteLine("NonSquare");
        }

        Console.WriteLine();
        Console.WriteLine(a);

        a[0, 0] = -1;

        Console.WriteLine();
        a[0, 9] = 999;
        Console.WriteLine(a);
        Console.WriteLine();
        int[,] z = a;
        Matric t = new Matric();
        t = z;


        Console.WriteLine(t.QuantitiOfZeroElements);
        Console.WriteLine(z.Length);

        Matric b = new Matric();

        b = Matric.EnteringElements(cin);
        b++;
        Console.WriteLine(b);
        b--;
        Console.WriteLine(b);







        //a = Matric.EnteringElements(cin);

        //if (a) // Проверка на квардрат
        //{
        //    Console.WriteLine("Square"); 
        //}

        //a--;
        //Console.WriteLine();
        //Console.WriteLine(a);

        //b = a++;
        //a[0, 0] = -1;

        //int sum = a.SumOfColumns(0); // Вычисление суммы элементов первого столбца матрицы a

        //Console.WriteLine();
        //a[0, 9] = 999;
        //Console.WriteLine(a);
        //Console.WriteLine();
        //Console.WriteLine(b);
        //int[,] z = a;
        //Matric t = new Matric();
        //t = z;

        //Console.WriteLine(t.QuantitiOfZeroElements);
        //Console.WriteLine(z.Length);
    }
}
