/*Lexicographic permutations
Problem 24 
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?*/

#include<iostream>
using namespace std;

int main()
{
	int dem = 0;
	long long k = 123456789;
	for (long long i = 123456789; i <= 9876543210; i += 9)
	{
		long long arr[10] = { 0 };
		long long temp = i;
		int idx = 0;
		while (temp != 0)
		{
			arr[idx++] = temp % 10;
			temp /= 10;
		}
		bool check = false;
		for (int j = 0; j < 9; j++)
		{
			for (int k = j + 1; k < 10; k++)
			{
				if (arr[j] == arr[k])
				{
					check = true;
					break;
				}
			}
		}

		if (check == false)
		{
			dem++;
			if (dem <= 1000000)
			{
				//cout << i - k << endl;
				cout << i << endl;
				//break;
			}
			//k = i;
		}	
	}
	system("pause");
	return 0;
}