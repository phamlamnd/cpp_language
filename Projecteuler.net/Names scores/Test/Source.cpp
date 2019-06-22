#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream FileIn;
	FileIn.open("OUTPUT.txt", ios_base::in);
	if (!FileIn)
	{
		cout << "Can not open";
		system("pause");
		return 0;
	}
	int count = 0;
	int score = 0;
	while (!FileIn.eof())
	{
		string s;
		int sum = 0;
		count++;
		getline(FileIn, s, ',');
		for (int i = 0; i < s.length(); i++)
		{
			sum += s[i] - 64;
		}
		score += sum * count;
	}
	cout << score;
	system("pause");
	return 0;
}