#include<iostream>
#define N 10000000000
using namespace std;
int main()
{
	long long result = 0;
	for (int x = 1; x <= 1000; x++)
	{
		long long tem = 1;
		for (int y = 1; y <= x; y++)
		{
			tem = (tem % N)*(x % N);
		}
		result += tem % N;
	}
	cout << result % N;
	system("pause");
	return 0;
}