/*Largest palindrome product
Problem 4 
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.*/

#include<iostream>
using namespace std;
bool IsPalindromicNumber(int);
int main()
{
	int LargestPalindrome = 0;
	for (int i = 999; i >= 100; i--)
	{
		for (int j = 999; j >= 100; j--)
		{
			if (IsPalindromicNumber(i * j) == true)
			{
				if (i * j > LargestPalindrome)
				{
					LargestPalindrome = i * j;
				}
			}
		}
	}
	cout << "Largest palindrome product = " << LargestPalindrome;
	system("pause");
	return 0;
}

bool IsPalindromicNumber(int x)
{
	int sum = 0, temp = x;
	while (temp != 0)
	{
		sum = sum * 10 + temp % 10;
		temp /= 10;
	}
	if (x == sum) return true;
	return false;
}