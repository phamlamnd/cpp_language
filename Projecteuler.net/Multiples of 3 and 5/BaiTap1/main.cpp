/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
Nếu chúng ta liệt kê tất cả các số tự nhiên dưới 10 là bội số của 3 hoặc 5, chúng ta có 3, 5, 6 và 9. Tổng của các bội số là 23.
Tìm tổng của tất cả các bội số của 3 hoặc 5 dưới 1000.*/

#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}