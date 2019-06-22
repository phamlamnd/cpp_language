using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

namespace Lychrel_numbers_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            int dem = 0;
            for(int i = 0; i < 10000; i++)
            {
                if(IsLychrelNumber(i))
                {
                    dem++;
                }
            }
            Console.Write(dem);
            sw.Stop();
            Console.WriteLine("done in " + sw.ElapsedMilliseconds + "ms");
            Console.ReadKey();
        }

        static BigInteger Reversed(BigInteger x)
        {
            BigInteger p = 0;
            while (x != 0)
            {
                p = p * 10 + x % 10;
                x /= 10;
            }
            return p;
        }

        static bool IsPalindromic(BigInteger x)
        {
            if (x == Reversed(x))
                return true;
            return false;
        }

        static bool IsLychrelNumber(BigInteger x)
        {
            for (int i = 1; i <= 50; i++)
            {
                x += Reversed(x);
                if (IsPalindromic(x))
                {
                    return false;
                }
            }
            return true;
        }
    }
}
