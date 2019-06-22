/*
1000-digit Fibonacci number
Problem 25
The Fibonacci sequence is defined by the recurrence relation:
Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:
F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/
#include<iostream>
#include<string>
using namespace std;
string sumtwonumber(string number1, string number2)
{
	string strsum = "";
	int len1 = number1.length();
	int len2 = number2.length();
	int lenmin = len1 < len2 ? len1 : len2;
	int lenmax = len1 > len2 ? len1 : len2;
	string numberlong = len1 >= len2 ? number1 : number2;
	string numbershort = len1 < len2 ? number1 : number2;
	int over = 0;
	for (int i = 0; i < lenmin; i++)
	{
		int temp = numberlong[i] - 48 + numbershort[i] - 48 + over;
		over = temp / 10;
		char c = temp % 10 + 48;
		strsum += c;
	}
	for (int i = lenmin; i < lenmax; i++)
	{
		int temp = numberlong[i] - 48 + over;
		over = temp / 10;
		char c = temp % 10 + 48;
		strsum += c;
	}
	while (over != 0)
	{
		char c = over % 10 + 48;
		over /= 10;
		strsum += c;
	}
	return strsum;
}


int main()
{
	string F1 = "1";
	string F2 = "1";
	string Fn = "";
	int count = 2;
	while (true)
	{
		count++;
		Fn = sumtwonumber(F1, F2);
		F1 = F2;
		F2 = Fn;
		if (Fn.length() >= 1000)
		{
			break;
		}
	}
	cout << "F" << count << "th = " << _strrev((char*)Fn.c_str());
	system("pause");
	return 0;
}