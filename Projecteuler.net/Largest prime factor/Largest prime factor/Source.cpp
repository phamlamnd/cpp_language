/*Largest prime factor
Problem 3 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include<iostream>
using namespace std;
bool IsPrimeNumber(long long);
int main()
{
	long long number = 6008514751431;
	long long i = 2;
	while(i <= number)
	{
		if (IsPrimeNumber(i) == true && number % i == 0)
		{
			if (number / i == 1)
			{
				cout << i;
				break;
			}
			number /= i;
			i = 2;
		}
		else
		{
			i++;
		}
	}
	system("pause");
	return 0;
}
bool IsPrimeNumber(long long x)
{
	if (x < 2) return false;
	else if(x > 2)
	{
		if (x % 2 == 0) return false;
		for (long long i = 3; i <= sqrt((long double)x); i += 2)
		{
			if (x % i == 0) return false;
		}
	}
	return true;
}