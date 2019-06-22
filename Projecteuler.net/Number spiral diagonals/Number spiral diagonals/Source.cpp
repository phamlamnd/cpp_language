/*
Number spiral diagonals
Problem 28
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include<iostream>
#define N 1001
using namespace std;

int main()
{
	//long long sum;
	//for (long long s = 1, x = 1, i = 2; i < 1001; i += 2)
	//	for (int n = 0; n < 4; n++)
	//		s += x += i, sum = s;
	//cout << sum;
	
	int **map;
	map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		*(map + i) = new int[N];
	}

	map[N/2][N/2] = 1;
	int dem = 1;
	int i = N / 2, j = N / 2;
	for (int k = 1; k <= N / 2; k++)
	{
		for (j++; i <= N / 2 + k; i++)
		{
			map[i][j] = ++dem;
		}
		for (i--, j--; j >= N / 2 - k; j--)
		{
			map[i][j] = ++dem;
		}
		for (j++, i--; i >= N / 2 - k; i--)
		{
			map[i][j] = ++dem;
		}
		for (i++, j++; j <= N / 2 + k; j++)
		{
			map[i][j] = ++dem;
		}
		j--;
	}

	long long sum = 0;
	for (int i = 0, j = 0; i < N, j < N; i++, j++)
	{
		sum += map[i][j];
	}
	for (int i = N - 1, j = 0; i >= 0, j < N; i--, j++)
	{
		sum += map[i][j];
	}
	cout << sum - map[N / 2][N / 2];

	for (int i = 0; i < N; i++)
	{
		delete[] * (map + i);
	}
	delete[] map;
	system("pause");
	return 0;
}