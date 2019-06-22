#include <iostream>
#include <vector>

bool isLucky(int n)
{
	std::vector<int> sumDigits;
	int tmp = n;
	while (tmp != 0)
	{
		if (sumDigits.size() > 0)
		{
			sumDigits.push_back(sumDigits[sumDigits.size() - 1] + (tmp % 10));
		}
		else
		{
			sumDigits.push_back(tmp % 10);
		}
		tmp /= 10;
	}
	int a = sumDigits[sumDigits.size() - 1];
	int b = (sumDigits[(sumDigits.size() / 2) - 1] / 2);
	return sumDigits[sumDigits.size() - 1] / 2 == (sumDigits[(sumDigits.size() / 2) - 1]);
}

int main()
{
	isLucky(1230);
	return 0;
}