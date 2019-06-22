#include<iostream>
#define N 28123
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
	bool checkarr[N];
	for (int i = 1; i <= N; i++)
	{
		if (IsAbundantNumber(i) == 1)
		{
			checkarr[i - 1] = true;
		}
		else
		{
			checkarr[i - 1] = false;
		}
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		bool check = 0;
		for (int j = 12; j < i; j++)
		{
			if (checkarr[j - 1] == true)
			{
				if (checkarr[i - j - 1] == true)
				{
					check = 1;
					break;
				}
			}
		}
		if (check == 0)
		{
			sum += i;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}
