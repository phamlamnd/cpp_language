using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Integer_right_triangles
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 0;
            int max = 0;
            for(int p = 3; p <= 1000; p++)
            {
                int count = 0;
                for(int a = 1; a <= p / 3; a++)
                {
                    for(int b = a + 1; b < p / 2; b++)
                    {
                        int c = p - a - b;
                        if(Math.Pow(a, 2) + Math.Pow(b, 2) == Math.Pow(c, 2))
                        {
                            Console.WriteLine("{0}: {1},{2},{3}", p, a, b, c);
                            count++;
                        }
                    }
                }
                if(count > max)
                {
                    max = count;
                    num = p;
                }
            }
            Console.WriteLine(num);
            Console.ReadKey();
        }
    }
}
