/*
Digit cancelling fractions
Problem 33
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
#include<iostream>
#include<ctime>
using namespace std;
int ucln(int num, int den);
int main()
{
	clock_t t = clock();
	int num = 1, den = 1;
	for (int t = 1; t <= 9; t++)
	{
		for (int m = 1; m <= 9; m++)
		{
			for (int c = 1; c <= 9; c++)
			{
				if ((double)(t * 10 + c) / (c * 10 + m) == (double)t / m && t != m)
				{
					cout << t * 10 + c << "/" << c * 10 + m << endl;
					num *= t;
					den *= m;
				}
			}
		}
	}
	cout << den / ucln(num, den);
	cout << " done in " << (double)1000*(clock() - t) / CLOCKS_PER_SEC << "ms";
	system("pause");
	return 0;
}

int ucln(int num, int den)
{
	while (true)
	{
		if (num > den)
		{
			num -= den;
		}
		else if (den > num)
		{
			den -= num;
		}
		else
		{
			return num;
		}
	}
}