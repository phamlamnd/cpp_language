/*Smallest multiple
Problem 5 
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

#include<iostream>
using namespace std;

int main()
{
	int x = 1;
	bool check = false;
	while(true)
	{
		for (int i = 1; i <= 20; i++)
		{
			if (x % i != 0)
			{
				break;
			}
			if (i == 20)
			{
				check = true;
			}
		}
		if (check == true)
		{
			break;
		}
		x++;
	}
	cout << x;
	system("pause");
	return 0;
}