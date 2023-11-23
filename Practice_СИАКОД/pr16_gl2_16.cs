/*
На основе данных входного файла составить список вкладчиков банка,
включив следующие данные: ФИО, № счета, сумма, год открытия счета. Вывести в новый
файл информацию о тех вкладчиках, которые открыли вклад ранее текущего года,
сгруппировав их по год открытия счета. 
*/

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    struct Account
    {
        public string FirstName, SurName,   SecondName, AccountNumber;
        public int Amount, OpeningYear;

        public Account(string firstName, string surname, string secondName, string accountNumber, int amount, int openingYear)
        {
            this.FirstName = firstName;
            this.SurName = surname;
            this.SecondName = secondName;
            this.AccountNumber = accountNumber;
            this.Amount = amount;
            this.OpeningYear = openingYear;
        }

        public string ToString()
        {
            string s = this.FirstName + ' ' + this.SurName + ' ' + this.SecondName + ' ' + this.AccountNumber + ' ' + this.Amount + ' ' + this.OpeningYear;
            return s;
        }
    }

    static void Main()
    {
        StreamReader input = new StreamReader("input.txt");
        List<Account> accounts = new List<Account>();

        int currentYear = Convert.ToInt32(input.ReadLine());

        while (!input.EndOfStream)
        {
            string[] temp = input.ReadLine().Split(new char[] { ' ', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            Account tempAccount = new Account(temp[1], temp[0], temp[2], temp[3], Convert.ToInt32(temp[4]), Convert.ToInt32(temp[5]));
            accounts.Add(tempAccount);
        }

        input.Close();

        var olderAccounts = accounts.Where(account => account.OpeningYear < currentYear).GroupBy(account => account.OpeningYear);
        /*
        var olderAccounts =
            from account in accounts
            where account.OpeningYear < currentYear
            orderby account.OpeningYear
            group account by account.OpeningYear;
        */

        StreamWriter output = new StreamWriter("output.txt");

        foreach (var group in olderAccounts)
        {
            output.WriteLine($"=== {group.Key} ===");

            foreach (var account in group)
            {
                output.WriteLine(account.ToString());
            }

            output.WriteLine();
        }

        output.Close();
    }
}
