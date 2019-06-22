/*
Goldbach's other conjecture
Problem 46
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2
It turns out that the conjecture was false.
What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include<iostream>
#include<ctime>
using namespace std;
bool IsPrime(long);
bool IsNoGoldbach(long);
int main()
{
	clock_t t = clock();
	long n = 9;
	while (true)
	{
		if (IsNoGoldbach(n))
		{
			cout << n;
			break;
		}
		n++;
	}
	t = clock() - t;
	cout << " done in " << (double)t / CLOCKS_PER_SEC;
	system("pause");
	return 0;
}

bool IsPrime(long x)
{
	if (x < 2)
	{
		return false;
	}
	if (x > 3)
	{
		if (x % 2 == 0)
		{
			return false;
		}
		for (long i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool IsNoGoldbach(long n)
{
	if (n % 2 == 0 || IsPrime(n))
	{
		return false;
	}
	for (long i = n - 2; i >= 2; i--)
	{
		if (IsPrime(i))
		{
			if (sqrt((n - i) / 2) == (int)sqrt((n - i) / 2))
			{
				return false;
			}
		}
	}
	return true;
}