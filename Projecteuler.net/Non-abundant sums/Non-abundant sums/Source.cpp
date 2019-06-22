/*Non-abundant sums
Problem 23 
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/

#include<iostream>
using namespace std;

int IsAbundantNumber(int x)
{
	int sum = 0;
	for (int i = 1; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			if (i != x / i)
			{
				sum += i + x / i;
			}
			else
			{
				sum += i;
			}
		}
	}
	sum -= x;
	if (sum == x)  //perfect number 
	{
		return 0;
	}
	if (sum > x) //abundant number
	{
		return 1;
	}
	if (sum < x)
	{
		return -1; //Non-abundant
	}
}

int main()
{
	int count = 0;
	long long sum = 0;
	for (int i = 1; i <= 28123; i++)
	{
		int check = 0;
		for (int j = 1; j <= i; j++)
		{
			if (IsAbundantNumber(j) == 1)
			{
				if (IsAbundantNumber(i - j) == 1)
				{
					check = 1;
					break;
				}
			}
		}
		if (check == 0)
		{
			//cout << i << endl;
			sum += i;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}