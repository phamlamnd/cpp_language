#include<iostream>
#include<ctime>
using namespace std;
bool IsPrime(int);
bool Isfouristinctprimefactors(int);
int main()
{
	clock_t t = clock();
	int n = 4;
	while (true)
	{
		if (Isfouristinctprimefactors(n))
			if (Isfouristinctprimefactors(n + 1))
				if (Isfouristinctprimefactors(n + 2))
					if (Isfouristinctprimefactors(n + 3))
					{
						cout << n << endl;
						break;
					}
		n++;
	}
	t = clock() - t;
	cout << " done in" << (double)t / CLOCKS_PER_SEC << " s";
	system("pause");
	return 0;
}

bool IsPrime(int x)
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
		for (int i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Isfouristinctprimefactors(int x)
{
	if (IsPrime(x))
	{
		return false;
	}
	int a[4];
	int n = 0;
	if (x % 2 == 0)
	{
		n = 1;
		a[0] = 2;
		while (x % 2 == 0)
		{
			x /= 2;
		}
	}
	for (int i = 3; i <= x; i += 2)
	{
		if(IsPrime(i) == true && x % i == 0)
		{
			n++;
			if (n > 4)
			{
				return false;
			}
			a[n - 1] = i;
			while (x % i == 0)
			{
				x /= i;	
			}
		}
	}
	if (n == 4)
	{
		return true;
	}
	return false;
}