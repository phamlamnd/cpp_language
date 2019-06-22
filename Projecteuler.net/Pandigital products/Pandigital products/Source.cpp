/*Pandigital products
Problem 32 
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.*/

#include<iostream>
using namespace std;

int main()
{
	long long sum = 0;

	for (int i = 0; i <= 9876; i++)
	{
		int temp0 = i / 2;			
		for (int j = 1; j < temp0; j++)
		{
			if (i % j == 0)
			{
				temp0 = i / j;
				int check[10] = { 0 };
				int temp1 = i;
				while (temp1 != 0)
				{
					++check[temp1 % 10];
					temp1 /= 10;
				}
				int temp2 = j;
				while (temp2 != 0)
				{
					++check[temp2 % 10];
					temp2 /= 10;
				}
				int temp3 = i / j;
				while (temp3 != 0)
				{
					++check[temp3 % 10];
					temp3 /= 10;
				}
				if ((check[0] == 0) && (check[1] == 1) && (check[2] == 1) && (check[3]) == 1 && (check[4] == 1) && (check[5] == 1) && (check[6] == 1) && (check[7] == 1) && (check[8] == 1) && (check[9] == 1))  
				{
					cout << i << " = " << j << " * " << i / j << endl;
					sum += i;
					break;
				}
			}
		}	
	}
	cout << sum;
	system("pause");
	return 0;
}