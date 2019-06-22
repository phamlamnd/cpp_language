/*
Distinct primes factors
Problem 47
The first two consecutive numbers to have two distinct prime factors are:
14 = 2 × 7
15 = 3 × 5
The first three consecutive numbers to have three distinct prime factors are:
644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.
Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool IsPrime(long);
int main()
{
	set<long> s, s1, s2, s3;
	long n = 0;
	while (true)
	{
		if (!IsPrime(n))
		{
			s.clear();
			s1.clear();
			s2.clear();
			s3.clear();
			long tem = n;
			for (long i = 2; i <= tem; i++)
			{
				if (tem % i == 0 && IsPrime(i))
				{
					s.insert(i);
					tem /= i;
					i = 1;
				}
			}

			tem = n + 1;
			for (long i = 2; i <= tem; i++)
			{
				if (tem % i == 0 && IsPrime(i))
				{
					s1.insert(i);
					tem /= i;
					i = 1;
				}
			}

			tem = n + 2;
			for (long i = 2; i <= tem; i++)
			{
				if (tem % i == 0 && IsPrime(i))
				{
					s2.insert(i);
					tem /= i;
					i = 1;
				}
			}
			
			tem = n + 3;
			for (long i = 2; i <= tem; i++)
			{
				if (tem % i == 0 && IsPrime(i))
				{
					s3.insert(i);
					tem /= i;
					i = 1;
				}
			}
			if (s.size() == 4 && s1.size() == 4 && s2.size() == 4 && s3.size() == 4)
			{
				cout << n << endl;
				while(!s3.empty())
				{
					cout << *s3.begin() << " ";
					s3.erase(s3.begin());
				}
				break;
			}
		}
		n++;
	}
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