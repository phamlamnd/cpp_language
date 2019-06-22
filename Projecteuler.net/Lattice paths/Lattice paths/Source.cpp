/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/
#include<iostream>
#define N 20
using namespace std;

unsigned long long LatticePaths(int x, int y)
{
	static unsigned long long table[N + 1][N + 1] = { 0 };
	if (x < N && y < N)
	{
		if (table[x][y] == 0)
		{
			table[x][y] = LatticePaths(x + 1, y) + LatticePaths(x, y + 1);
		}
		return table[x][y];
	}
	if (x == N || y == N)
	{
		table[x][y] = 1;
		return 1;
	}
	return table[0][0];
}

int main()
{
	cout << LatticePaths(0, 0) << endl;
	unsigned long long table[N + 1][N +1] = { 0 };
	for (int i = 0; i < N + 1; i++)
	{
		table[i][N] = 1;
		table[N][i] = 1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			table[i][j] = table[i + 1][j] + table[i][j + 1];
		}
	}
	cout << table[0][0];
	system("pause");
	return 0;
}