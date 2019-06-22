/*Prime permutations
Problem 49
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
What 12-digit number do you form by concatenating the three terms in this sequence?*/
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#define MIN 100000000001
#define MAX 999999999999
using namespace std;
bool IsPrime(long long);
int main()
{
	for (long long n = MIN; n <= MAX; n += 2)
	{
		if (IsPrime(n))
		{
			/*for (long long val = 2; val <= MAX; val += 2)*/
			{
				long long n1 = n + 3330;
				if (IsPrime(n1))
				{
					string s = to_string(n);
					string s1 = to_string(n1);
					sort(s.begin(), s.end());
					sort(s1.begin(), s1.end());
					if (s == s1)
					{
						long long n2 = n1 + 3330;
						if (IsPrime(n2))
						{
							string s2 = to_string(n2);
							sort(s2.begin(), s2.end());
							if (s == s2)
							{
								cout << n << "," << n1 << "," << n2 << endl;
								//cout << val << endl;
								//goto fini;
							}
						}
					}
				}
			}
		}
	}
fini:
	system("pause");
	return 0;
}

bool IsPrime(long long x)
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
		for (long long i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}