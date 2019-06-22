#include<iostream>
#define LIMIT 1000000
using namespace std;

unsigned long long next(unsigned long long n) { return n % 2 ? n * 3 + 1 : n / 2; }
long len(unsigned long long n)
{
	static unsigned long long table[LIMIT] = { 0, 1 };
	if (n < LIMIT)
	{
		if (table[n] == 0)
		{
			table[n] = len(next(n)) + 1;
		}
		return table[n];
	}
	return len(next(n)) + 1;
}

int main()
{
	unsigned long long max = 1;
	for (unsigned long long n = 2; n < LIMIT; n++)
	{
		if (len(max) < len(n)) 
		{
			max = n;
		}
		cout << "n = " << n << ", len = " << len(n) << endl;
	}
	cout << max;
	system("pause");
	return 0;
}