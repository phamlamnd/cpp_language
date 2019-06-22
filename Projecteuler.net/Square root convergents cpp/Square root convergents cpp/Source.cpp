/*Square root convergents
Problem 57
It is possible to show that the square root of two can be expressed as an infinite continued fraction.
√ 2 = 1 + 1 / (2 + 1 / (2 + 1 / (2 + ...))) = 1.414213...
By expanding this for the first four iterations, we get :
1 + 1 / 2 = 3 / 2 = 1.5
1 + 1 / (2 + 1 / 2) = 7 / 5 = 1.4
1 + 1 / (2 + 1 / (2 + 1 / 2)) = 17 / 12 = 1.41666...
1 + 1 / (2 + 1 / (2 + 1 / (2 + 1 / 2))) = 41 / 29 = 1.41379...
The next three expansions are 99 / 70, 239 / 169, and 577 / 408, but the eighth expansion, 1393 / 985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
In the first one - thousand expansions, how many fractions contain a numerator with more digits than denominator ?*/
#include<iostream>
using namespace std;
int main()
{
	double a[1001];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < 1001; i++)
	{
		a[i] = 2 * a[i - 1] + a[i - 2];
	}
	for (int i = 0; i < 10; i++)
	{
		cout << (double)(a[i + 1] + a[i]) / a[i + 1] << endl;
	}
	system("pause");
	return 0;
}
