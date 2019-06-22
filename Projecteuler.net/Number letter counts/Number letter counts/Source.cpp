/*
Number letter counts
Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

1 one
2 two
3 three
4 four
5 five
6 six
7 seven
8 eight
9 nine
10 ten
11 eleven
12 twelve
13 thirteen
14 fourteen
15 fifteen
16 sixteen
17 seventeen
18 eighteen
19 nineteen
20 twenty
21
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string table1[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
	string table2[] = { "zero", "ten", "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
	int letter_count = 0;
	for (int i = 1; i <= 1000; i++)
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
		else if (i >= 100 && i <= 999)
		{
			if (i % 100 == 0)
			{
				s = table1[i / 100] + "hundred";
			}
			else
			{
				s = table1[i / 100] + "hundredand";
				int temp = i % 100;
				if (temp <= 19)
				{
					s += table1[temp];
				}
				if (temp >= 20 && temp <= 99)
				{
					int hangchuc = temp / 10;
					int hangdonvi = temp % 10;
					if (hangdonvi == 0)
					{
						s += table2[hangchuc];
					}
					else
					{
						s += table2[hangchuc] + table1[hangdonvi];
					}
				}
			}
		}
		else if (i == 1000)
		{
			s = "onethousand";
		}
		letter_count += s.length();
		cout << s << endl;
	}
	cout << "How many letters would be used? " << letter_count;
	system("pause");
	return 0;
}

