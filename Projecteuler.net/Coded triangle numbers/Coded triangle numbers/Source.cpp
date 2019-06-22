/*Coded triangle numbers
Problem 42 
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
	clock_t start = clock();
	vector<int> v;
	for (int i = 0; i < 1000; i++)
	{
		v.push_back((i + 1)*(i + 2) / 2);
	}

	ifstream FileIn("p042_words.txt");
	if (!FileIn)
	{
		cout << "Can not open";
		system("pause");
		return 0;
	}
	int count = 0;
	while (!FileIn.eof())
	{
		int sum = 0;
		string s;
		getline(FileIn, s, ',');
		s.erase(s.begin());
		s.erase(s.end() - 1);
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			sum += s[i] - 64;
		}
		if (binary_search(v.begin(), v.end(), sum))
		{
			count++;
		}
	}
	cout << count;
	clock_t end = clock();
	cout << " done in " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}