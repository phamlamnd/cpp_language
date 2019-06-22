/*Powerful digit counts
Problem 63 
The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
How many n-digit positive integers exist which are also an nth power?*/
#include<iostream>
#include<iomanip>

using namespace std;
int CountDigit(long long x)
{
	if (x == 0)
	{
		return 1;
	}
	int count = 0;
	while (x != 0)
	{
		x /= 10;
		count++;
	}
	return count;
}
int main()
{
	/*unsigned long long n = 1;
	while (n++)
	{
		if ((unsigned long long)pow(n % 10, (unsigned long long)log10(n) + 1) == n)
		{
			cout << n << " = " << n % 10 << "^" << (int)log10(n) + 1 << endl;
		}
	}*/
	cout << setprecision(50);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			cout << i << "^" << j << " = " << pow(i, j);
			if (i == (long long)pow(i, j) % 10 && j == CountDigit((long long)pow(i, j)))
			{
				cout << " \t\t-> OK";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}