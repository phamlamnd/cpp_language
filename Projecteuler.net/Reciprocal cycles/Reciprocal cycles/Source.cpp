/*Reciprocal cycles
Problem 26
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.*/

#include<iostream>
#include<ctime>
using namespace std;
int ReciprocalCycles(int);
int main()
{
	clock_t t = clock();
	int max = 0;
	int num;
	for (int d = 2; d < 1000; d++)
	{
		int r = ReciprocalCycles(d);
		if (r > max)
		{
			max = r;
			num = d;
		}
	}
	cout << num;
	t = clock() - t;
	cout << " done in " << (double)t * 1000 / CLOCKS_PER_SEC << "ms";
	system("pause");
	return 0;
}

int ReciprocalCycles(int d)
{
	static int a[1000];
	int idx = 0;
	int carry = 1;
	while (true)
	{
		carry = (carry * 10) % d;
		if (carry == 0) //nếu phần dư chia hết cho nó thì không xét nữa
		{
			return 0;
		}
		else
		{
			a[idx] = carry; //nếu khác 0 thì lưu số dư hiện tại vào mảng
			int check = 0;
			for (int i = 0; i < idx; i++) //kiểm tra số dư hiện tại với trước đó đã lưu trong mảng
			{
				if (a[i] == carry) //nếu xuất hiện lặp lại số dư thì thoát
				{
					return idx - i;
				}
			}
			idx++;
		}
	}
}
