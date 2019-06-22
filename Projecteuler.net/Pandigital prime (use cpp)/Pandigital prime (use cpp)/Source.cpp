/*Pandigital prime
Problem 41 
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool IsPrime(int);
int main()
{
	int num = 987654321;
	int max = 0;
	int n = 8;
	while (n > 1)
	{
		string s = to_string(num);
		do
		{
			if (IsPrime(stoi(s)) == true)
			{
				max = stoi(s);
				goto end;
			}
		} while (prev_permutation(s.begin(), s.end()));
		num %= (int)pow(10, n--);
	}
	end:
	cout << max;
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
		for (int i = 3; i <= (int)sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}