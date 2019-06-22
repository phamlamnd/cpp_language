/*Digit fifth powers
Problem 30
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.*/

#include<iostream>
#include<set>
#include<fstream>
using namespace std;

int main()
{
	long long i = 1;
	while (i++)
	{
		long long temp = i;
		double sum = 0;
		while (temp != 0)
		{
			sum += pow(temp % 10, 5);
			temp /= 10;
		}
		if (sum == (double)i)
		{
			cout << i << endl;
		}
	}

	//set<char> a;
	//ifstream FileIn;
	//FileIn.open("Largesum.txt", ios_base::in);
	//if (!FileIn)
	//{
	//	cout << "Can not open";
	//	system("pause");
	//	return 0;
	//}
	//while (!FileIn.eof())
	//{
	//	char c;
	//	FileIn >> c;
	//	a.insert(c);
	//}
	////cout << a.size();
	//for (set<char>::iterator it = a.begin(); it != a.end(); it++)
	//{
	//	cout << " " << *it;
	//}
	system("pause");
	return 0;
}