#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string base = "0123456789";

	for (int i = 1; i < 1000000; i++)
	{
		next_permutation(base.begin(), base.end());
	}	
	cout << base << endl;
	system("pause");
	return 0;
}