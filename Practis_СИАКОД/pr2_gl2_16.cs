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

        string result = (discriminant > 0) ? "два корня" : (discriminant == 0) ? "один корень" : "нет корней";
        Console.WriteLine(result);
    }
}
