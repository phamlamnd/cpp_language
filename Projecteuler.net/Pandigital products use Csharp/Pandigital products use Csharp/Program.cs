using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pandigital_products_use_Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int sum = 0;
            for(int i = 0; i <= 987654321; i++)
            {
                int temp0 = i;
                for(int j = 1; j < temp0; j++)
                {
                    if(i % j == 0)
                    {
                        temp0 = i / j;
                        int[] check = new int[10];
                        int temp1 = i;
                        while(temp1 != 0)
                        {
                            check[temp1 % 10]++;
                            temp1 /= 10;
                        }
                        int temp2 = j;
                        while(temp2 != 0)
                        {
                            check[temp2 % 10]++;
                            temp2 /= 10;
                        }
                        int temp3 = i / j;
                        while(temp3 != 0)
                        {
                            check[temp3 % 10]++;
                            temp3 /= 10;
                        }
                        if(check[0] == 0 && check[1] == 1 && check[2] == 1 && check[3] == 1 && check[4] == 1 && check[5] == 1 && check[6] == 1 && check[7] == 1 && check[8] == 1 && check[9] == 1)
                        {
                            sum += i;
                            Console.WriteLine("{0} = {1} * {2}", i, j, i / j);
                            break;
                        }
                    }
                }
            }
            Console.Write("sum = {0}", sum);
            Console.ReadKey();
        }
    }
}
