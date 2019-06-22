
//find all spral primes 
#include <iostream>
#include <cmath>

bool isprime(unsigned int x)
{
	if (!(x & 1)) return false;
	unsigned int lim = sqrt(x);
	for (unsigned int p{ 3 }; p <= lim; p += 2)
		if (!(x%p)) return false;

	return true;
}

int main()
{
	unsigned int count{ 0 };
	double target{ 0.100 };
	unsigned int diagonal{ 1 };
	unsigned int n;
	unsigned int temp;
	for (n = 3;; n += 2)
	{
		temp = n*n - n + 1;
		count += isprime(temp) + isprime(temp - n + 1) + isprime(temp - 2 * n + 2);
		diagonal += 4;
		if (count < diagonal*target) break;
	}

	std::cout << n << '\n';
	system("pause");
	return 0;
}