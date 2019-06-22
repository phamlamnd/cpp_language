#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream FileIn;
	FileIn.open("abc.txt", ios_base::in);
	if (!FileIn)
	{
		cout << "Can not open";
		system("pause");
		return 0;
	}
	int x;
	FileIn >> x;
	cout << x;
	FileIn.close();
	system("pause");
	return 0;
}