#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	int num = 0;
	int max = 0;
	for (int p = 3; p <= 1000; p++)
	{
		int count = 0;
		for (int a = 1; a <= p / 3; a++)
		{
			for (int b = a + 1; b < p / 2; b++)
			{
				int c = p - a - b;
				if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				{
					//cout << p << ": " << a << "," << b << "," << c << endl;
					count++;
				}
			}
		}
		if (count > max)
		{
			max = count;
			num = p;
		}
	}
	cout << num;
	system("pause");
	return 0;
}