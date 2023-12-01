// https://docs.google.com/document/d/1eClW9Qc8pg3gqsWZn20ARrnUUR8wQZA-sHPUAL_v-RE/edit?usp=sharing

using System;
using System.Diagnostics;
using System.Text;

class Program
{
    static void Main()
    {
        string sourceString = GenerateRandomString(100000);
        Console.WriteLine("Исходная строка:");
        //Console.WriteLine(sourceString);

        string searchString = GenerateRandomString(3);
        Console.WriteLine("\nИскомая подстрока:");
        //Console.WriteLine(searchString);

        Stopwatch naiveStopwatch = Stopwatch.StartNew();
        int naiveIndex = NaiveSearch(sourceString, searchString);
        naiveStopwatch.Stop();

        Stopwatch rabinKarpStopwatch = Stopwatch.StartNew();
        int rabinKarpIndex = RabinKarpSearch(sourceString, searchString);
        rabinKarpStopwatch.Stop();


        Console.WriteLine("\nРезультаты поиска:");
        Console.WriteLine($"Прямой поиск: {naiveIndex}, Время выполнения: {naiveStopwatch.ElapsedMilliseconds} мс");
        Console.WriteLine($"Алгоритм Карпа-Рабина: {rabinKarpIndex}, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
    }

    // генерации случайной строки
    static string GenerateRandomString(int length)
    {
        Random random = new Random();
        const string alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
        StringBuilder result = new StringBuilder(length);

        for (int i = 0; i < length; i++)
        {
            result.Append(alphabet[random.Next(alphabet.Length)]);
        }

        return result.ToString();
    }



    // Прямой поиск
    public static int NaiveSearch(string haystack, string needle)
    {
        int n = haystack.Length;
        int m = needle.Length;

        for (int i = 0; i <= n - m; i++)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }

            if (j == m)
                return i;
        }

        return -1;
    }


    // Алгоритма Карпа-Рабина
    public static int RabinKarpSearch(string haystack, string needle)
    {
        int n = haystack.Length;
        int m = needle.Length;
        int needleHash = needle.GetHashCode();

        for (int i = 0; i <= n - m; i++)
        {
            string substring = haystack.Substring(i, m);
            int substringHash = substring.GetHashCode();

            if (substringHash == needleHash && substring == needle)
                return i;
        }

        return -1;
    }

}
