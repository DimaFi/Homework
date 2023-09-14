using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {

            for (int i = 1; i < 10; i++)
            {
                for (int j = Math.Max(0,i-2); j <= Math.Min(9,i+2); j++)
                {
                    Console.Write($"{i}{j} \n");

                }
            }
        }
    }
}
