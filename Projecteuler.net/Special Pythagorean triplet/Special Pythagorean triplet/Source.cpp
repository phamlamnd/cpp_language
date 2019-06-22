/*Special Pythagorean triplet
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 52.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	for (int a = 1; a <= 1000 / 3; a++)
	{
		for (int b = a + 1; b <= (1000 - a) / 2; b++)
		{
			int c = 1000 - a - b;
			if (a * a + b * b == c * c)
			{
				std::cout << "a = " << a << std::endl;
				std::cout << "b = " << b << std::endl;
				std::cout << "c = " << c << std::endl;
				cout << "Product abc = " << a * b * c;
				break;
			}

		}
	}
	system("pause");
	return 0;
}