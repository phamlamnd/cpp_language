/*Cubic permutations
Problem 62
The cube, 41063625 (345^3), can be permuted to produce two other cubes : 56623104 (384^3) and 66430125 (405^3).In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
Find the smallest cube for which exactly five permutations of its digits are cube.*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool IsCube(unsigned long long x)
{
	return cbrt(x) == (int)cbrt(x);
} 
int main()
{
	for (unsigned long long n = 41063625;;n++)
	{
		int count = 1;
		if (IsCube(n))
		{
			string s = to_string(n);
			sort(s.begin(), s.end());
			int cube = (int)cbrt(n);
			for (int i = cube + 1; i < (int)pow(10, (int)log10(cube) + 1); i++)
			{
				unsigned long long p = i * i * i;
				if (p > (unsigned long long)pow(10, (int)log10(n)+ 1))
				{
					break;
				}
				string s1 = to_string(p);
				sort(s1.begin(), s1.end());
				if (s == s1)
				{
					count++;
				}
			}
	
		}
		if (count == 4)
		{
			cout << n;
			break;
		}
	}
	system("pause");
	return 0;
}