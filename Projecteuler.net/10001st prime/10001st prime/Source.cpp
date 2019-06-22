/*10001st prime
Problem 7 
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?*/
#include<iostream>
using namespace std;
bool IsPrimeNumber(long long);
int main()
{
	int n = 0, i = 0;
	while (true)
	{
		if(IsPrimeNumber(n) == true)
		{
			i++;
		}
		if (i == 10001)
		{
			cout << n;
			break;
		}
		n++;
	}
	system("pause");
	return 0;
}
bool IsPrimeNumber(long long x)
{
	if (x < 2) return false;
	else if (x > 3)
	{
		if (x % 2 == 0) return false;
		for (long long i = 3; i <= sqrt((long double)x); i += 2)
		{
			if (x % i == 0) return false;
		}
	}
	return true;
}