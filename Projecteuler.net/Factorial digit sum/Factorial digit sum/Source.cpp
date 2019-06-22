/*Factorial digit sum
Problem 20 
n! means n × (n − 1) × ... × 3 × 2 × 1
For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
Find the sum of the digits in the number 100!*/

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
	while(over != 0)
	{
		char c = over % 10 + 48;
		over /= 10;
		strsum += c;
	}
	return strsum;
}

string producttwonumber(string number1, string number2)
{
	string strpro = "0";
	int len1 = number1.length();
	int len2 = number2.length();
	int lenmin = len1 < len2 ? len1 : len2;
	int lenmax = len1 > len2 ? len1 : len2;
	string numberlong = len1 >= len2 ? number1 : number2;
	string numbershort = len1 < len2 ? number1 : number2;

	for (int i = 0; i < lenmin; i++)
	{
		int overpro = 0;
		string strtemp = "";
		strtemp.insert(0, i, '0');
		for (int j = 0; j < lenmax; j++)
		{
			int d = ((numbershort[i] - 48) * (numberlong[j] - 48)) + overpro;
			overpro = d / 10;
			char c = d % 10 + 48;
			strtemp += c;
		}
		while (overpro != 0)
		{
			char c = overpro % 10 + 48;
			overpro /= 10;
			strtemp += c;
		}
		strpro = sumtwonumber(strtemp, strpro);
	}
	return strpro;
}

string Factorial(int n)
{
	string strf = "1";
	for (int i = 1; i <= n; i++)
	{
		string strn = "";
		int temp = i;
		while (temp != 0)
		{
			char c = temp % 10 + 48;
			temp /= 10;
			strn += c;
		}
		strf = producttwonumber(strf, strn);
	}
	_strrev((char *)strf.c_str());
	return strf;
}

int Factorialdigitsum(string s)
{
	int len = s.length();
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += s[i] - 48;
	}
	return sum;
}


int main()
{
	cout << Factorial(100) << endl;
	cout << Factorialdigitsum(Factorial(100));
	system("pause");
	return 0;
}