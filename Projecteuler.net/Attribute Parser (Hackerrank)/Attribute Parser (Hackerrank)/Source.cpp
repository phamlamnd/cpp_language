#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<sstream>
using namespace std;
int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT

	Sample Input
	4 3
	<tag1 value = "HelloWorld">
	<tag2 name = "Name1">
	</tag2>
	</tag1>
	tag1.tag2~name
	tag1~name
	tag1~value

	Sample Output
	Name1
	Not Found!
	HelloWorld
	*/
	int N, Q;
	cin >> N >> Q;
	vector<string> vn, vq;

	string *tag_name = new string[N / 2];
	string *attribute_name = new string[N / 2];
	string *value = new string[N / 2];

	for (int i = 1; i <= N; i++)
	{
		string s = "<tag1 value = HelloWorld>>";
		//cin >> s;
		vn.push_back(s);
		s.erase(s.begin());
		s.erase(s.end());
		stringstream ss(s);
		getline(ss, tag_name[i], ' ');
		getline(ss, attribute_name[i], ' ');
		ss.seekg(SEEK_CUR, 2);
		getline(ss, value[i], '>');
		cout << tag_name[0] << endl;
		cout << attribute_name[0] << endl;
		cout << value[0] << endl;
	}

	for (int i = 1; i <= Q; i++)
	{
		string s;
		cin >> s;
		vq.push_back(s);
	}

	for (int i = 0; i < Q; i++)
	{
		stringstream ss(vn[i]);
		string s;
		while (!ss.eof())
		{
			getline(ss, s, '.');
		}
	}

	delete tag_name;
	delete attribute_name;
	delete value;
	system("pause");
	return 0;
}
