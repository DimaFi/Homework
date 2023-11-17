// Вывести на экран в порядке убывания все трехзначные числа, уменьшив их на 1.

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static void Main()
    {
        StreamReader input = new StreamReader("input.txt");
        List<int> num = new List<int>();

        while (!input.EndOfStream)
        {
            string[] temp = input.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);

            for (int i = 0; i < temp.Length; i++)
            {
                int number = Convert.ToInt32(temp[i]);
                num.Add(number);

            }
        }
        input.Close();

        var nums =
            from n in num
            where (Math.Abs(n) >= 100 && Math.Abs(n) <= 999)
            orderby n descending
            select n-1;

        StreamWriter output = new StreamWriter("output.txt");

        foreach (int n in nums)
        {
            output.WriteLine("{0}", n);
        }
        output.Close();
    }
}
