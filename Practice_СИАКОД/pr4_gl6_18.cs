using System;


class Program
{
    static void Main()
    {
        Console.Write("a= ");
        double a = Convert.ToDouble(Console.ReadLine());

        Console.Write("b= ");
        double b = Convert.ToDouble(Console.ReadLine());

        int c1 = 0, c2 = 0;

        while (a != 0)
        {
            if (a % 10 == 0)
            {
                c1++;
            }
            a = a / 10;
        }

        while (b != 0)
        {
            if (b % 10 == 0)
            {
                c2++;
            }
            b = b / 10;
        }


        string result = (c1 > c2) ? "в А больше" : "в B больше";
        Console.WriteLine(result);

        //Console.ReadKey();
    }
}
