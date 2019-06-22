#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long sum = 0;
	long long d[10] = { 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (d[3] == 0 || d[3] == 2 || d[3] == 4 || d[3] == 6 || d[3] == 8)
		{
			if ((d[2] + d[3] + d[4]) % 3 == 0)
			{
				if (d[5] == 0 || d[5] == 5)
				{
					if ((d[4] * 100 + d[5] * 10 + d[6]) % 7 == 0)
					{
						if ((d[5] * 100 + d[6] * 10 + d[7]) % 11 == 0)
						{
							if ((d[6] * 100 + d[7] * 10 + d[8]) % 13 == 0)
							{
								if ((d[7] * 100 + d[8] * 10 + d[9]) % 17 == 0)
								{
									cout << d[0] << d[1] << d[2] << d[3] << d[4] << d[5] << d[6] << d[7] << d[8] << d[9] << endl;
									sum += d[0]*pow(10, 9) + d[1]*pow(10, 8) + d[2]*pow(10, 7) + d[3]*pow(10, 6) + d[4]*pow(10, 5) + d[5]*pow(10, 4) + d[6] * pow(10, 3) + d[7] * pow(10, 2) +  d[8] * pow(10, 1) + d[9];
								}
							}
						}
					}
				}
			}
		}
	} while (next_permutation(d, d + 10));
	cout << sum;
	system("pause");
	return 0;
}