using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Collections;

namespace Odd_period_square_roots_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable map = new Hashtable();
            map.Add("one", "Mot");
            map.Add("two", "Hai");
            map.Add("three", "Ba");
            foreach(DictionaryEntry element in map)
            {
                string key = (string)element.Key;
                string value = (string)element.Value;
                Console.WriteLine("{0} -> {1}", key, value);
            }
            BigInteger a;
            int dem = 0;
            for(int i = 1; i <= 10000; i++)
            {
                if(period_square_roots(i) % 2 != 0)
                {
                    dem++;
                }
            }
            Console.Write(dem);
            Console.ReadKey();
        }

        static bool check_square_number(int X)
        {
            return Math.Sqrt(X) == (int)Math.Sqrt(X);
        }

        static int period_square_roots(int X)
        {
            if (check_square_number(X) == true) return 0;
            int count = 0;
            int b = (int)Math.Sqrt(X);
            int c = 1;
            do
            {
                c = (X - (int)Math.Pow(b, 2)) / c;
                b = c * (((int)Math.Sqrt(X) + b) / c) - b;
                count++;
            } while (c != 1 || b != (int)Math.Sqrt(X));
            return count;
        }
    }
}
