/*Consecutive prime sum
Problem 50 
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes?*/
#include<iostream>
#include<ctime>
using namespace std;
bool IsPrime(int);
int main()
{
	clock_t t = clock();
	int *arr = new int[500000];
	int n = 0;
	int count = 0;
	int max = 0;
	int num;
	while(n < 1000000)
	{
		if (IsPrime(n))
		{
			arr[count++] = n;
		}
		n++;
	}
	for (int idx = count - 1; idx >= 0; idx--)
	{
		int sum = arr[0];
		int i = 0;
		int j = 0;
		while (true)
		{
			if (sum < arr[idx])
			{
				j++;
				if (j >= idx)
				{
					break;
				}
				sum += arr[j];
			}
			else if (sum > arr[idx])
			{
				sum -= arr[i];
				i++;
			}
			if (sum == arr[idx])
			{
				if (j - i > max)
				{
					max = j - i;
					num = sum;
				}
				break;
			}

		}
	}
	cout << num;
	delete[] arr;
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