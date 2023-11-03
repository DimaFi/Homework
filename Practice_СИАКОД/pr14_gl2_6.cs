using System;
using System.Collections.Generic;
using System.IO;

class Program
{
    struct Product : IComparable<Product>
    {
        public string productType;
        public double price;
        public string variety;
        public int quantity;

        public Product(string productType, double price, string variety, int quantity)
        {
            this.productType = productType;
            this.price = price;
            this.variety = variety;
            this.quantity = quantity;
        }

        public int CompareTo(Product other)
        {
            return this.quantity.CompareTo(other.quantity);
        }
    }

    static void Main()
    {
        StreamReader inputFile = new StreamReader("input.txt");
        List<Product> inventory = new List<Product>();
        int minQuantity = 10;

        while (!inputFile.EndOfStream)
        {
            string productType = inputFile.ReadLine();
            double price = double.Parse(inputFile.ReadLine());
            string variety = inputFile.ReadLine();
            int quantity = int.Parse(inputFile.ReadLine());

            Product product = new Product(productType, price, variety, quantity);
            inventory.Add(product);
        }
        inputFile.Close();

        List<Product> filter_Invent = new List<Product>();

        foreach (Product product in inventory)
        {
            if (product.quantity < minQuantity)
            {
                filter_Invent.Add(product);
            }
        }

        filter_Invent.Sort();

        StreamWriter outputFile = new StreamWriter("output.txt");

        foreach (Product product in filter_Invent)
        {
            outputFile.WriteLine($"{product.productType} {product.price} {product.variety} {product.quantity}");
        }
        outputFile.Close();
    }
}

Prod 1
10
Sort А
15
Prod 2
8
Sort B
5
Prod 3
20
Sort C
8
Prod 4
12
Sort A
2
Prod 5
12
Sort A
8
