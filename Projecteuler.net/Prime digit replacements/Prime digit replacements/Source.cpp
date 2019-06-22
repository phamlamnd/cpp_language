/*Prime digit replacements
Problem 51 
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
bool IsPrime(int x);
int main()
{
	clock_t t = clock();
	int th = 8;
	int num = 1;
	while (true)
	{
		num += 2;
		int x;
		if (IsPrime(num))
		{
			x = num / 10;
			int arr[3] = { 0 };
			while (x != 0)
			{
				int digit = x % 10;
				if (digit <= 2)
				{
					arr[digit]++;
				}
				x /= 10;
			}
			x = num / 10;

			if (arr[0] > 0)
			{

				int dem = 0;
				int next = 0;
				while (x != 0)
				{
					dem++;
					int digit = x % 10;
					if (digit == 0)
					{
						next += (int)pow(10, dem);
					}
					x /= 10;
				}
				int count = 0;
				for (int i = num; i <= num + (next * 9); i += next)
				{
					//cout << i << endl;
					if (IsPrime(i))
					{
						count++;
					}
					//cout << count << endl;
					if (count == th)
					{
						cout << num;
						goto fini;
					}
				}
			}

			x = num / 10;
			if (arr[1] > 0)
			{
				int dem = 0;
				int next = 0;
				while (x != 0)
				{
					dem++;
					int digit = x % 10;
					if (digit == 1)
					{
						next += (int)pow(10, dem);
					}
					x /= 10;
				}
				int count = 0;
				for (int i = num; i <= num + (next * 8); i += next)
				{
					//cout << i << endl;
					if (IsPrime(i))
					{
						count++;
					}
					//cout << count << endl;
					if (count == th)
					{
						cout << num;
						goto fini;
					}
				}
			}

			x = num / 10;
			if (arr[2] > 0)
			{
				int dem = 0;
				int next = 0;
				while (x != 0)
				{
					dem++;
					int digit = x % 10;
					if (digit == 2)
					{
						next += (int)pow(10, dem);
					}
					x /= 10;
				}
				int count = 0;
				for (int i = num; i <= num + (next * 7); i += next)
				{
					//cout << i << endl;
					if (IsPrime(i))
					{
						count++;
					}
					//cout << count << endl;
					if (count == th)
					{
						cout << num;
						goto fini;
					}
				}
			}
		}
	}
fini:
	cout << " done in " << (double)(clock() - t) / CLOCKS_PER_SEC << "s" << endl;
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
		for(int i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}