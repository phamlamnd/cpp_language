using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Digit_factorials
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 3;
            while(true)
            {
                int temp = n;
                double sum = 0;
                while(temp != 0)
                {
                    sum += Factorial(temp % 10);
                    temp /= 10;
                }
                if(sum == n)
                {
                    Console.WriteLine(n);
                }
                n++;
            }
            //Console.ReadKey();
        }
        static double Factorial(int x)
        {
            int fac = 1;
            for (int i = 1; i <= x; i++)
            {
                fac *= i;
            }
            return fac;
        }
    }  
}
