using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

namespace Square_root_convergents_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();
            BigInteger[] a = new BigInteger[1001];
            a[0] = 1;
            a[1] = 2;
            for (int i = 2; i < 1001; i++)
            {
                a[i] = 2 * a[i - 1] + a[i - 2];
            }
            int dem = 0;
            for (int i = 0; i < 1000; i++)
            {
                if (GetDigit(a[i + 1] + a[i]) > GetDigit(a[i + 1]))
                {
                    //Console.WriteLine("{0}/{1}", a[i + 1] + a[i], a[i + 1]);
                    dem++;
                }
            }
            Console.WriteLine(dem);
            sw.Stop();
            Console.WriteLine("done in " + sw.ElapsedMilliseconds + "ms");
            Console.ReadKey();
        }
        static int GetDigit(BigInteger x)
        {
            if (x < 10) return 1;
            int dem = 0;
            while (x != 0)
            {
                x /= 10;
                dem++;
            }
            return dem;
        }
    }
}
