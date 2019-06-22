#include <iostream>

int min = 0;
int sum = 0;
int current;
void DFS(int matrix[5][5], int i, int j)
{
	while (true)
	{
		current = matrix[i][j];
		sum += current;
		
		if (i == 5 && j < 5)
		{
			DFS(matrix, i, j + 1);
		}
		else if (i < 5 && j == 5)
		{
			DFS(matrix, i + 1, j);
		}
		else if (i < 5 && j < 5)
		{
			DFS(matrix, i, j + 1);
			DFS(matrix, i + 1, j);
		}
		else if ()
		if (sum < min)
		{
			min = sum;
		}
	}
}


int main()
{
	int matrix[5][5] = {
		{ 131, 673, 234, 103, 18 },
		{ 201, 96, 342, 965, 150 },
		{ 630, 803, 746, 422, 111},
		{ 537, 699, 497, 121, 956},
		{ 805, 732, 524, 37, 331}
	};


	system("pause");
	return 0;
}