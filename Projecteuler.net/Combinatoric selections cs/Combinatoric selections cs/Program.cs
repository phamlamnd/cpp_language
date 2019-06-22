using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace Combinatoric_selections_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int dem = 0;
            for(int i = 1; i <= 100; i++)
            {
                for(int j = 1; j <= i; j++)
                {
                    if(Fact(i) / (Fact(j) * Fact(i - j)) > 1000000)
                    {
                        dem++;
                    }
                }
            }
            Console.Write(dem);
            Console.ReadKey();
        }
        static BigInteger Fact(int x)
        {
            if(x > 0)
            {
                return x * Fact(x - 1);
            }
            return 1;
        }
    }
}
