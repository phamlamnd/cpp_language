/*Names scores
Problem 22 
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
What is the total of all the name scores in the file?*/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream FileIn;
	FileIn.open("p022_names.txt", ios_base::in);
	ofstream FileOut;
	FileOut.open("OUTPUT.txt", ios_base::out);
	if (!FileIn)
	{
		cout << "Can not open";
		system("pause");
		return 0;
	}
	int count = 0;
	while (!FileIn.eof())
	{
		string s;
		getline(FileIn, s, ',');
		count++;
	}
	FileIn.seekg(0, SEEK_SET);
	string *arrname = new string[count];
	for (int i = 0; i < count; i++)
	{
		getline(FileIn, arrname[i], ',');
		arrname[i].erase(0, 1);
		arrname[i].erase(arrname[i].length() - 1, 1);
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arrname[i].compare(arrname[j]) > 0)
			{
				string temp = arrname[i];
				arrname[i] = arrname[j];
				arrname[j] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << arrname[i] << endl;
		FileOut << arrname[i] << ",";
	}

	long long score = 0;
	for (int i = 0; i < count; i++)
	{
		int sum = 0;
		for (int j = 0; j < arrname[i].length(); j++)
		{
			sum += arrname[i][j] - 64;
		}
		score += sum * (i + 1);
	}

	cout << score << endl;

	FileIn.close();
	FileOut.close();
	system("pause");
	return 0;
}