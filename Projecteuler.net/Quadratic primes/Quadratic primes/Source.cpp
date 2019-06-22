/*Quadratic primes
Problem 27 
Euler discovered the remarkable quadratic formula:

n2+n+41n2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤390≤n≤39. However, when n=40,402+40+41=40(40+1)+41n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41n=41,412+41+41 is clearly divisible by 41.

The incredible formula n2−79n+1601n2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤790≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n2+an+bn2+an+b, where |a|<1000|a|<1000 and |b|≤1000|b|≤1000

where |n||n| is the modulus/absolute value of nn
e.g. |11|=11|11|=11 and |−4|=4|−4|=4
Find the product of the coefficients, aa and bb, for the quadratic expression that produces the maximum number of primes for consecutive values of nn, starting with n=0n=0.*/

#include<iostream>
using namespace std;

bool IsPrimes(int n)
{
	if (n < 2)
	{
		return false;
	}
	if (n >= 4)
	{
		if (n % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i <= sqrt(n); i += 2)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int max = 0;
	int a, b;
	for (int i = -999; i < 1000; i++)
	{
		for (int j = -1000; j <= 1000; j++)
		{
			if (IsPrimes(j) == true)
			{
				int dem = 1;
				int n = 1;
				while (true)
				{
					if (IsPrimes((int)pow(n, 2) + i * n + j) == true)
					{
						dem++;
						n++;
					}
					else
					{
						break;
					}
				}
				cout << "max = " << max << ", dem = " << dem << ", a = " << i << ", b = " << j << endl;
				if (dem > max)
				{
					max = dem;
					a = i;
					b = j;
				}
			}
		}
	}
	cout << "max = " << max << endl;
	cout << a << endl;
	cout << b << endl;
	cout << a * b;
	system("pause");
	return 0;
}