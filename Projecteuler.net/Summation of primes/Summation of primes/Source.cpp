/*Summation of primes
Problem 10 
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.*/

#include<iostream>
using namespace std;
bool IsPrimes(int);
int main()
{
	long long sum = 0;
	for(int i = 2; i < 2000000; i++)
	{ 
		if (IsPrimes(i) == true)
		{
			//cout << i << " + ";
			sum += i;
		}
	}
	cout << "sum of all the primes below two million = " << sum;

	system("pause");
	return 0;
}

bool IsPrimes(int x)
{
	if (x < 2) return false;
	if (x > 2)
	{
		if (x % 2 == 0) return false;
		for(int i = 3; i <= sqrt((double)x); i += 2)
		{ 
			if (x % i == 0) return false;
		}
	}
	return true;
}