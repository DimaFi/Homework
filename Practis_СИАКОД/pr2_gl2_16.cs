using System;

class Program
{
    static void Main()
    {
        Console.Write("a= ");
        double a = Convert.ToDouble(Console.ReadLine());

        Console.Write("b= ");
        double b = Convert.ToDouble(Console.ReadLine());

        Console.Write("c= ");
        double c = Convert.ToDouble(Console.ReadLine());

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0)
        {
            Console.WriteLine("два корня.");
        }
        else if (discriminant == 0)
        {
            Console.WriteLine("один корень.");
        }
        else
        {
            Console.WriteLine("нет корней.");
        }
    }
}
