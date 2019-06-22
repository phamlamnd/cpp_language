using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Self_power_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger result = 0;
            for(int i = 1; i <= 1000; i++)
            {
                result += BigInteger.Pow(i, i);
            }
            Console.Write(result);
            Console.ReadKey();
        }
    }
}
