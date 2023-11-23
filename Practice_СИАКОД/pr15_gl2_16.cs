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

        var olderAccounts =
            from account in accounts
            where account.OpeningYear < currentYear
            orderby account.OpeningYear
            group account by account.OpeningYear;

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

/*
2024
John Smith Johnson 12345 1000 2021
Jane Doe Turner 23456 1500 2022
Michael Johnson White 34567 2000 2021
Alex Turner Turner 45678 1200 2020
Emily White White 56789 1800 2022
Andrew Anderson Anderson 67890 1600 2021
Artem Sokolov Sokolov 78901 1300 2020
Kirill Kozlov Kozlov 89012 2200 2022
Dmitry Lebedev Lebedev 90123 1700 2021
Egor Yegorov Yegorov 11223 1100 2020
Timur Titov Titov 22334 1900 2021
Boris Belyakov Belyakov 33445 1400 2022
Gregory Grigoriev Grigoriev 44556 2000 2020
Dmitriy Dmitriev Dmitriev 55667 1600 2021
Constantin Komarov Komarov 66778 1200 2022
Fedor Fedorov Fedorov 77889 1700 2020
Alexey Zhukov Zhukov 88990 1500 2021
Maxim Makarov Makarov 99001 1800 2022
Roman Romanov Romanov 10012 1300 2020
Semen Semenov Semenov 11123 1900 2021
*/

