#include<iostream>
#include<math.h>
using namespace std;
bool IsPrime(int);
int main()
{
	int a = 2, b = 2;
	int max = 0;
	int maxa, maxb;
	for (int i = 0; i <= 9000000; i++)
	{
		if (IsPrime(i))
		{
			a = b;
			b = i;
			if (b - a > max)
			{
				max = b - a;
				cout << max << endl;
				maxa = a;
				maxb = b;
			}
		}
	}
	cout << max << endl;
	cout << maxa << endl;
	cout << maxb;
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