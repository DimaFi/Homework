// https://docs.google.com/document/d/1eClW9Qc8pg3gqsWZn20ARrnUUR8wQZA-sHPUAL_v-RE/edit?usp=sharing

using System;
using System.Diagnostics;
using System.Text;

class Program
{
    static void Main()
    {
        string sourceString = GenerateRandomString(100000000);
        Console.WriteLine("Исходная строка:");
        //Console.WriteLine(sourceString);

        string searchString = GenerateRandomString(6);
        Console.WriteLine("\nИскомая подстрока:");
        //Console.WriteLine(searchString);

        Stopwatch naiveStopwatch = Stopwatch.StartNew();
        int naiveIndex = NaiveSearch(sourceString, searchString);
        naiveStopwatch.Stop();

        int rabinKarpIndex = RabinKarpSearch(sourceString, searchString);


        Console.WriteLine($"Прямой поиск: {naiveIndex}, Время выполнения: {naiveStopwatch.ElapsedMilliseconds} мс");
        // Console.WriteLine($"Алгоритм Карпа-Рабина: {rabinKarpIndex}, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
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

    public static int RabinKarpSearch(string s, string t)
    {
        const long P = 37;
        double string_len = s.Length;
        int t_len = t.Length;
        long[] pwp = new long[s.Length];//вычисляем массив степеней P
        pwp[0] = 1;
        long[] h = new long[s.Length];//вычисляем массив хэш-значение для всех префиксов строки
        long h_s = 0;//для хранения хеш значения podstr


        //вычисляем массив степеней P
        for (int i = 1; i < string_len; i++)
        {
            pwp[i] = pwp[i - 1] * P;
        }
        //вычисляем массив хэш-значение для всех префиксов строки T         
        for (int i = 0; i < string_len; i++)
        {
            h[i] = (s[i] - 'a' + 1) * pwp[i]; //1
            if (i > 0)
                h[i] += h[i - 1];
        }
        // вычисляем хэш-значение для подстроки S

        for (int i = 0; i < t_len; i++)
        {
            h_s += (t[i] - 'a' + 1) * pwp[i];
        }
        //проводим поиск по хеш-значениям
        Stopwatch rabinKarpStopwatch = Stopwatch.StartNew(); //создаем экземпляр класса Stopwatch
        for (int i = 1; i + t_len - 1 < string_len; i++)
        {
            // находим хэш-значение подстроки начиная с позиции i длиною s.Length
            long cur_h = h[i + t_len - 1];
            if (i > 0)
            {
                cur_h -= h[i - 1];
            }
            //приводим хэш-значения двух подстрок к одной степени
            if (cur_h == h_s * pwp[i]) // если хеш-значения равны, то и подстроки равны
            {
                
                rabinKarpStopwatch.Stop();
                Console.WriteLine($"Алгоритм Карпа-Рабина: {i}, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
                return i; // выводим позицию i, с которой начинается повторение
            }
        }
        rabinKarpStopwatch.Stop();
        Console.WriteLine($"Алгоритм Карпа-Рабина: -1, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
        return -1;
    }

}













// НИЖЕ СТАРЫЙ КОД, Алгоритм Карпа-рабина не работает





/*



// https://docs.google.com/document/d/1eClW9Qc8pg3gqsWZn20ARrnUUR8wQZA-sHPUAL_v-RE/edit?usp=sharing

using System;
using System.Diagnostics;
using System.Text;

class Program
{
    static void Main()
    {
        string sourceString = GenerateRandomString(100000000);
        Console.WriteLine("Исходная строка:");
        //Console.WriteLine(sourceString);

        string searchString = GenerateRandomString(1);
        Console.WriteLine("\nИскомая подстрока:");
        //Console.WriteLine(searchString);

        Stopwatch naiveStopwatch = Stopwatch.StartNew();
        int naiveIndex = NaiveSearch(sourceString, searchString);
        naiveStopwatch.Stop();

        int rabinKarpIndex = RabinKarpSearch(sourceString, searchString);


        Console.WriteLine($"Прямой поиск: {naiveIndex}, Время выполнения: {naiveStopwatch.ElapsedMilliseconds} мс");
        // Console.WriteLine($"Алгоритм Карпа-Рабина: {rabinKarpIndex}, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
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

    public static int RabinKarpSearch(string s, string t)
    {

        const long P = 37;
        //вычисляем массив степеней P
        long[] pwp = new long[s.Length];
        pwp[0] = 1;
        for (int i = 1; i < s.Length; i++)
        {
            pwp[i] = pwp[i - 1] * P;
        }
        //вычисляем массив хэш-значение для всех префиксов строки T
        long[] h = new long[t.Length];
        for (int i = 0; i < t.Length; i++)
        {
            h[i] = (t[i] - 'a' + 1) * pwp[i]; //1
            if (i > 0)
                h[i] += h[i - 1];
        }
        // вычисляем хэш-значение для подстроки S
        long h_s = 0;
        for (int i = 0; i < s.Length; i++)
        {
            h_s += (s[i] - 'a' + 1) * pwp[i];
        }
        //проводим поиск по хеш-значениям
        Stopwatch rabinKarpStopwatch = Stopwatch.StartNew();
        for (int i = 0; i + s.Length - 1 < t.Length; i++)
        {
            // находим хэш-значение подстроки T начиная с позиции i длиною s.Length
            long cur_h = h[i + s.Length - 1];
            if (i > 0)
            {
                cur_h -= h[i - 1];
            }
            //приводим хэш-значения двух подстрок к одной степени
            if (cur_h == h_s * pwp[i]) // если хеш-значения равны, то и подстроки равны
            {
                return i; // выводим позицию i, с которой начинается повторение
                rabinKarpStopwatch.Stop();
                Console.WriteLine($"Алгоритм Карпа-Рабина: {i}, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
            }
        }
        rabinKarpStopwatch.Stop();
        Console.WriteLine($"Алгоритм Карпа-Рабина: -1, Время выполнения: {rabinKarpStopwatch.ElapsedMilliseconds} мс");
        return -1;
    }

    /*
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

*/

    */
}
