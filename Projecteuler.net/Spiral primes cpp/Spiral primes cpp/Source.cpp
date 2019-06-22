/*Spiral primes
Problem 58
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49
It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8 / 13 ≈ 62 % .
If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10 % ?*/
#include<iostream>
#include<ctime>
using namespace std;
bool IsPrime(int x);
int main()
{
	clock_t t = clock();
	int next = 0;
	int n = 1;
	int count = 0;
	while(true)
	{
		next += 2;
		for (int i = 1; i <= 4; i++)
		{
			n += next;
			if (IsPrime(n) == true)
			{
				count++;
			}
		}
		if ((double)count / (next * 2 + 1) < 0.1)
		{
			cout << count << endl;
			cout << next * 2 + 1 << endl;
			cout << next + 1;
			break;
		}
	}
	cout << " done in " << (double)(clock() - t) / CLOCKS_PER_SEC << "s";
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