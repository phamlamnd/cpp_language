/*
Double-base palindromes
Problem 36
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include<iostream>
#include<string>
using namespace std;
string IntToStringBase10(int );
string IntToStringBase2(int);
int main()
{
	int sum = 0;
	for (int i = 1; i < 1000000; i++)
	{
		if (IntToStringBase10(i) == _strrev((char*)IntToStringBase10(i).c_str()) && IntToStringBase2(i) == _strrev((char*)IntToStringBase2(i).c_str()))
		{
			cout << i << endl;
			sum += i;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}

string IntToStringBase10(int x)
{
	string str = "";
	while (x != 0)
	{
		char c = x % 10 + 48;
		x /= 10;
		str += c;
	}
	return str;
}

string IntToStringBase2(int x)
{
	string str = "";
	while (x != 0)
	{
		char c = x % 2 + 48;
		x /= 2;
		str += c;
	}
	return str;
}