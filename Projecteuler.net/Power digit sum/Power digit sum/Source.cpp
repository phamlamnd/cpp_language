/*Power digit sum
Problem 16 
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?*/

#include<iostream>
#include<string>
#define N 1000
using namespace std;

int main()
{
	string Number = "1";
	for (int i = 1; i <= N; i++)
	{
		int over = 0;
		for (int idx = 0; idx < Number.length(); idx++)
		{
			int temp = (Number[idx] - 48) * 2 + over;
			Number[idx] = temp % 10 + 48;
			over = temp / 10;
		}
		if (over != 0)
		{
			Number += over % 10 + 48;
			over /= 10;
		}
	}
	int len = Number.length();
	cout << "2^" << N << " = ";
	for (int i = len - 1; i >= 0; i--)
	{
		cout << Number[i];
	}

	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += Number[i] - 48;
	}
	cout << ", len = " << len;
	cout << ", sum of the digits = " << sum;
	system("pause");
	return 0;
}