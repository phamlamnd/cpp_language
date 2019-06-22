/*Counting Sundays
Problem 19 
You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/

#include<iostream>
using namespace std;

struct NGAY
{
	int day;
	int month;
	int year;
	int dayofweek;
};

void nextday(NGAY &d)
{
	d.dayofweek++;
	if (d.dayofweek == 8)
	{ 
		d.dayofweek = 1;
	}
	d.day++;
	if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
	{
		if (d.day == 32)
		{
			d.day = 1;
			d.month++;
			if (d.month == 13)
			{
				d.month = 1;
				d.year++;
			}
		}
	}
	else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
	{
		if (d.day == 31)
		{
			d.day = 1;
			d.month++;
		}
	}
	else if (d.month == 2)
	{
		if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
		{
			if (d.day == 30)
			{
				d.day = 1;
				d.month++;
			}
		}
		else
		{
			if (d.day == 29)
			{
				d.day = 1;
				d.month++;
			}
		}
	}
}

int main()
{
	NGAY d;
	d.day = 1;
	d.month = 1;
	d.year = 1900;
	d.dayofweek = 2;

	int count = 0;
	while (true)
	{
		nextday(d);
		if (d.year >= 1901 && d.year <= 2000)
		{
			if(d.day == 1 && d.dayofweek == 1)
			{ 
				count++;
			}
		}
		if (d.year > 2000)
		{
			break;
		}
	}
	cout << count;

	system("pause");
	return 0;
}