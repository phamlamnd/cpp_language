/*Truncatable primes
Problem 37 
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Truncatable_primes
{
    class Program
    {
        static void Main(string[] args)
        {
            int sum = 0;
            for(int i = 10, count =  0;; i++)
            {
                if(IsTruncatablePrimes(i))
                {
                    Console.WriteLine(i);
                    count++;
                    sum += i;
                    if(count == 11)
                    {
                        break;
                    }
                }
            }
            Console.Write("sum = " + sum);
            Console.ReadKey();
        }

        static bool IsTruncatablePrimes(int x)
        {
            int temp = x;
            while(temp != 0)
            {
                if(IsPrimes(temp) == false)
                {
                    return false;
                }
                temp /= 10;
            }
            int n = DigitCount(x) - 1;
            temp = x;
            while(n != 0)
            {
                temp %= (int)Math.Pow((double)10, n);
                if (IsPrimes(temp) == false)
                {
                    return false;
                }
                n--;
            }
            return true;
        }

        static int DigitCount(int x)
        {
            if(x >= 0 && x <= 9)
            {
                return 1;
            }
            int count = 0;
            while(x != 0)
            {
                x /= 10;
                count++;
            }
            return count;
        }

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
                for(int i = 3; i <= (int)Math.Sqrt((double)x); i += 2)
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
