/*Pandigital multiples
Problem 38 
Take the number 192 and multiply it by each of 1, 2, and 3:
192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pandigital_multiples
{
    class Program
    {
        static void Main(string[] args)
        {
            int maxnum = 0;
            int max = 0;
            int nn = 0;
            for(int num = 1; num <= 9999; num++)
            {
                string sprod = "";
                int n = 1;
                int[] check = new int[10];
                while(true)
                {
                    int prod = num * n;
                    sprod += Convert.ToString(prod);
                    bool checkdigit = false;
                    while(prod != 0)
                    {
                        check[prod % 10]++;
                        prod /= 10;
                        if (check[0] > 0 || check[1] > 1 || check[2] > 1 || check[3] > 1 || check[4] > 1 || check[5] > 1 || check[6] > 1 || check[7] > 1 || check[8] > 1 || check[9] > 1)
                        {
                            checkdigit = true;
                            break;
                        }
                    }
                    if(checkdigit == true)
                    {
                        break;
                    }
                    if(check[0] == 0 && check[1] == 1 && check[2] == 1 && check[3] == 1 && check[4] == 1 && check[5] == 1 && check[6] == 1 && check[7] == 1 && check[8] == 1 && check[9] == 1)
                    {
                        int temp = Convert.ToInt32(sprod);
                        if(temp > max)
                        {
                            maxnum = num;
                            max = temp;
                            nn = n;
                        }
                        Console.WriteLine("{0}, {1}, {2}", temp, num, n);
                        break;
                    }
                    n++;
                }
            }
            Console.WriteLine("max = {0}, num = {1}, nn = {2}", max, maxnum, nn);
            Console.ReadKey();
        }
    }
}
