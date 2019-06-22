using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Powerful_digit_sum_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger max = 0;
            for(int i = 1; i < 100; i++)
            {
                for(int j = 1; j <= 100; j++)
                {
                    BigInteger p = BigInteger.Pow(i, j);
                    BigInteger sum = 0;
                    while(p != 0)
                    {
                        BigInteger temp = p % 10;
                        p /= 10;
                        sum += temp;     
                    }
                    if(sum > max)
                    {
                        max = sum;
                    }
                }
            }
            Console.Write(max);
            Console.ReadKey();
        }
    }
}
