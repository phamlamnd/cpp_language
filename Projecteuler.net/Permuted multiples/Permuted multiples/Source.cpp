/*Permuted multiples
Problem 52 
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.*/
#include<iostream>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	clock_t t = clock();
	long long x = 1;
	while (true)
	{
		string s = to_string(x);
		string s1 = to_string(2 * x);
		sort(s.begin(), s.end());
		sort(s1.begin(), s1.end());
		if (s == s1)
		{
			string s2 = to_string(3 * x);
			sort(s2.begin(), s2.end());
			if (s == s2)
			{
				string s3 = to_string(4 * x);
				sort(s3.begin(), s3.end());
				if (s == s3)
				{
					string s4 = to_string(5 * x);
					sort(s4.begin(), s4.end());
					if (s == s4)
					{
						string s5 = to_string(6 * x);
						sort(s5.begin(), s5.end());
						{
							if (s == s5)
							{
								cout << x << endl;
								cout << 2 * x << endl;
								cout << 3 * x << endl;
								cout << 4 * x << endl;
								cout << 5 * x << endl;
								cout << 6 * x;
								break;
							}
						}
					}
				}
			}
		}
		x++;
	}
	cout << " done in " << (double)1000 * (clock() - 1) / CLOCKS_PER_SEC << "ms";
	system("pause");
	return 0;
}