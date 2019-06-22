/*
Number letter counts
Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include<iostream>
#include<string>
using namespace std;
string table1[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string table2[] = { "zero", "ten", "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
string readlower99(int i)
{
	string s = "";
	if (i <= 19)
	{
		s = table1[i];
	}
	else if (i >= 20 && i <= 99)
	{
		int hangchuc = i / 10;
		int hangdonvi = i % 10;
		if (hangdonvi == 0)
		{
			s = table2[hangchuc];
		}
		else
		{
			s = table2[hangchuc] + table1[hangdonvi];
		}
	}
	return s;
}

string readlower999(int i)
{
	string s = "";
	if (i % 100 == 0)
	{
		s = table1[i / 100] + "hundred";
	}
	else
	{
		s = table1[i / 100] + "hundredand" + readlower99(i % 100);
	}
	return s;
}

int main()
{
	int letter_count = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (i <= 99)
		{
			letter_count += readlower99(i).length();
		}
		else if (i >= 100 && i <= 999)
		{
			letter_count += readlower999(i).length();
		}
		else if (i == 1000)
		{
			letter_count += 11;
		}
	}
	cout << letter_count;
	system("pause");
	return 0;
}

