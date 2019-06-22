#include<iostream>
#include<fstream>
using namespace std;
template <class phamlamnd>
bool IsTalkingPrime(phamlamnd a, phamlamnd b)
{
	int na = log10(a) + 1;
	int nb = log10(b) + 1;
	if (IsPrime(a) && IsPrime(b) && IsPrime(a * (int)pow(10, nb) + b) && IsPrime(b * (int)pow(10, na) + a))
	{
		return true;
	}
	return false;
}
template <class phamlamnd>
bool IsPrime(phamlamnd x)
{
	if (x < 2)
	{
		return false;
	}
	if (x > 3)
	{
		if (x % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	ofstream FileOut;
	FileOut.open("OUTPUT.txt", ios_base::app);
	int i = 31;
	FileOut << i << ": ";
	for (int j = 1; j < 5000; j++)
	{
		if (IsTalkingPrime(i, j))
		{
			FileOut << j << ",";
		}
	}
	FileOut << endl;
	system("pause");
}

