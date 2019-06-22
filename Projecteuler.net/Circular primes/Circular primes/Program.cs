/*Circular primes
Problem 35 
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Circular_primes
{
    class Program
    {
        static void Main(string[] args)
        {
            int count = 0;
            for(int n = 1; n <= 1000000; n++)
            {
                if(IsCircularPrimes(n))
                {
                    //Console.WriteLine(n);
                    count++;
                }
            }
            Console.WriteLine(count);
            Console.ReadKey();
        }

        //check circular primes number function
        static bool IsCircularPrimes(int x)
        {
            if(IsPrimes(x) == false)
            {
                return false;
            }

            int ndigit = DigitCount(x);
            for(int i = 1; i <= ndigit; i++)
            {
                x = x / 10 + (x % 10) * (int)Math.Pow((double)10, (double)(ndigit - 1));
                if(IsPrimes(x) == false)
                {
                    return false;
                }
            }
            return true;
        }

        //count digit function
        static int DigitCount(int x)
        {
            if(x >= 0 && x <= 9)
            {
                return 1;
            }
            int count = 0;
            while(x != 0)
            {
                count++;
                x /= 10;
            }
            return count;
        }

        //check primes number function
        static bool IsPrimes(int x)
        {
            if(x < 2)
            {
                return false;
            }
            if(x > 3)
            {
                if(x % 2 == 0)
                {
                    return false;
                }
                int cmp = (int)Math.Sqrt((double)x);
                for (int i = 3; i <= cmp; i += 2)
                {
                    if(x % i == 0)
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}