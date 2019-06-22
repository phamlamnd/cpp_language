#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<double> myset;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= 100; j++)
		{
			myset.insert(pow(i, j));
		}
	}
	cout << myset.size();
	system("pause");
	return 0;
}