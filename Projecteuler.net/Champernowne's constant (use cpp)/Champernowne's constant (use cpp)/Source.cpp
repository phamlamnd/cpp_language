/*Champernowne's constant
Problem 40 
An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the value of the following expression.
d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int DigitCount(int x)
{
	int count = 0;
	while (x != 0)
	{
		count++;
		x /= 10;
	}
	return count;
}
int main()
{
	clock_t start = clock();
	char *a = new char[1000000];
	int idx = 0;
	int num = 1;
	while (true)
	{
		int tem = num;
		int exp = DigitCount(tem) - 1;
		while (exp >= 0 && idx < 1000000)
		{
			a[idx++] = tem / (int)pow(10, exp) + 48;
			tem %= (int)pow(10, exp);
			exp--;
		}
		num++;
		if (idx == 1000000)
		{
			break;
		}
	}
	cout << a[0] << ", " << a[9] << ", " << a[99] << ", " << a[999] << ", " << a[9999] << ", " << a[99999] << ", " << a[999999];
	delete a;
	clock_t end = clock();
	cout << " done in " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	system("pause");
	return 0;
}