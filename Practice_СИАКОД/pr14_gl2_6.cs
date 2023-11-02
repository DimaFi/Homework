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
        int minQuantity = 10; // Замените эту величину на вашу заданную минимальную величину

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

        List<Product> filteredInventory = new List<Product>();
        foreach (Product product in inventory)
        {
            if (product.quantity < minQuantity)
            {
                filteredInventory.Add(product);
            }
        }

        filteredInventory.Sort();

        StreamWriter outputFile = new StreamWriter("output.txt");
        foreach (Product product in filteredInventory)
        {
            outputFile.WriteLine($"{product.productType} {product.price} {product.variety} {product.quantity}");
        }
        outputFile.Close();
    }
}

Товар 1
10.5
Сорт А
15

Товар 2
8.2
Сорт B
5

Товар 3
20.0
Сорт C
8

Товар 4
12.3
Сорт A
2

