#include<iostream>
#define N 1000000
using namespace std;
bool IsCheckCollatz[N] = { 0 };
int main()
{
	long long LonggestCollatz = 1;
	long long max = 0;
	for (int i = 1; i < N; i++)
	{
		if (IsCheckCollatz[i - 1] == 1)
		{
			continue;
		}
		int count = 1;
		long long val = i;
		while (val != 1)
		{
			val = val % 2 ? val * 3 + 1 : val / 2;
			if (val < i) IsCheckCollatz[val - 1] = 1;
			count++;
		}
		if (count > max) max = count, LonggestCollatz = i;
	}
	cout << max << endl;
	cout << LonggestCollatz;
	system("pause");
	return 0;
}
