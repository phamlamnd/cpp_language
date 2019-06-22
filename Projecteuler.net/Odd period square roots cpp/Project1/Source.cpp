#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

bool check_square_number(int X)
{
	return sqrt(X) == (int)sqrt(X);
}

int period_square_roots(int X)
{
	if (check_square_number(X) == true) return 0;
	int count = 0;
	int b = (int)sqrt(X); 
	int c = 1;
	do
	{	
		c = (X - (int)pow(b, 2)) / c;
		b = c * (((int)sqrt(X) + b) / c) - b;
		count++;
	} while (c != 1 || b != (int)sqrt(X));
	return count;
}

int main()
{
	clock_t t = clock();
	int dem = 0;
	for (int X = 1; X <= 10000; X++)
	{
		if (period_square_roots(X) % 2 != 0)
		{
			dem++;
		}
	}
	cout << dem;
	cout << " done in " << (double)(clock() - t) * 1000 / CLOCKS_PER_SEC << "ms";
	system("pause");
	return 0;
}