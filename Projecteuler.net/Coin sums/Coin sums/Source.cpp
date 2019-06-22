/*Coin sums
Problem 31
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:
1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	long long coin = 0;
	for (int i = 0; i <= 200 / 100; ++i)
	{
		for (int j = 0; j <= (200 - i * 100) / 50; ++j)
		{
			for (int k = 0; k <= (200 - i * 100 - j * 50) / 20; ++k)
			{
				for (int g = 0; g <= (200 - i * 100 - j * 50 - k * 20) / 10; ++g)
				{
					for (int h = 0; h <= (200 - i * 100 - j * 50 - k * 20 - g * 10) / 5; ++h)
					{
						for (int l = 0; l <= (200 - i * 100 - j * 50 - k * 20 - g * 10 - h * 5) / 2; ++l)
						{
							for (int m = 0; m <= (200 - i * 100 - j * 50 - k * 20 - g * 10 - h * 5 - l * 2); ++m)
							{
								if (i * 100 + j * 50 + k * 20 + g * 10 + h * 5 + l * 2 + m == 200)
								{
									//if(i == 1 && j == 1)
									//cout << "L2 = " << i << "*L1 + " << j << "*50p + " << k << "*20p + " << g << "*10p + " << h << "*5p + " << l << "*2p + " << m << "*1p" << endl;
									coin++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << coin + 1;
	system("pause");
	return 0;
}