#include<iostream>
using namespace std;

unsigned Faculty(unsigned n)
{
	return n ? n*Faculty(n - 1) : 1;
}

char* PermN(unsigned target)
{
	const char cdigits[] = "0123456789 ";
	const char cnumber[] = "           ";

	static char digits[] = "           ";
	static char number[] = "           ";

	strcpy_s(digits, cdigits);  //init source buffer
	strcpy_s(number, cnumber);  //init destination buffer

	target--;

	unsigned n = 10;
	unsigned ndigits = 0;

	do
	{
		unsigned fn = Faculty(n - 1);
		unsigned i = target / fn;       //calculate index from source buffer
		target -= i*fn;               //adjust target for next loop

									  //put calculated digit in destination buffer
		number[ndigits++] = digits[i];

		//remove digit from source buffer
		for (unsigned r = i; r < n; r++)
		{
			digits[r] = digits[r + 1];
		}
	} while (--n);
	return number;
}

int main()
{
	const unsigned target = 1000000;
	printf("\nperm(%7d) = %s", target, PermN(target));

	system("pause");
	return 0;
}