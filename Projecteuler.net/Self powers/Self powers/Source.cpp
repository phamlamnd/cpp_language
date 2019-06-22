/*Self powers
Problem 48 
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;
string BigPow(int x, int y);
string operator*(string s1, string s2);
string AddNum(string s1, string s2);
int main()
{
	long long a(0);
	cout << a;
	string sum = "0";
	for (int i = 1; i <= 1000; i++)
	{
		sum = AddNum(sum, BigPow(i, i));
	}
	cout << _strrev((char*)sum.c_str());
	//cout << BigPow(78, 23);
	system("pause");
	return 0;
}

string BigPow(int x, int y) //return x^y
{
	string pro = "1";
	string s = _strrev((char*)to_string(x).c_str());
	for (int i = 1; i <= y; i++)
	{
		pro = pro * s;
	}
	return pro;
}

string operator*(string s1, string s2)
{
	string result = "0";
	string lo = s1.length() >= s2.length() ? s1 : s2;
	string sh = s1.length() < s2.length() ? s1 : s2;
	int lenlo = lo.length();
	int lensh = sh.length();
	for (int i = 0; i < lensh; i++)
	{
		string tem = "";
		int carry = 0;
		for (int j = 0; j < lenlo; j++)
		{
			tem += ((sh[i] - 48) * (lo[j] - 48) + carry) % 10 + 48;
			carry = ((sh[i] - 48) * (lo[j] - 48) + carry) / 10;
		}
		if (carry > 0)
		{
			tem += carry + 48;
		}
		tem.insert(0, i, '0');
		//cout << tem << endl;
		result = AddNum(result, tem);
	}
	return result;
}

string AddNum(string s1, string s2)
{
	string result = "";
	string lo = s1.length() >= s2.length() ? s1 : s2;
	string sh = s1.length() < s2.length() ? s1 : s2;
	int lenlo = lo.length();
	int lensh = sh.length();
	int carry = 0;
	for (int i = 0; i < lensh; i++)
	{
		result += ((sh[i] - 48 + lo[i] - 48 + carry) % 10) + 48;
		carry = (sh[i] - 48 + lo[i] - 48 + carry) / 10;
	}
	for (int i = lensh; i < lenlo; i++)
	{
		result += ((lo[i] - 48 + carry) % 10) + 48;
		carry = (lo[i] - 48 + carry) / 10;
	}
	if (carry > 0)
	{
		result += carry + 48;
	}
	return result;
}