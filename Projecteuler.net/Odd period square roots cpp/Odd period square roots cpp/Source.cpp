#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

bool check_square_number(int X)
{
	return sqrt(X) == (int)sqrt(X);
}

int period_square_roots(int X)
{
	if (check_square_number(X) == true) return 0;
	vector<int> arr_a;
	vector<int> arr_b;
	int count = 0;
	int a = 1; //1 / (sqrt(13) - 3), a / (sqrt(X) - b)
	int b = (int)sqrt(X);
	while (true)
	{
		int check = 0; //bien check kiem tra xem lap lai chua
		for (int i = 0; i < arr_a.size(); i++)
		{
			if (arr_a[i] == a && arr_b[i] == b)
			{
				check = 1; //check = 1 neu lap lai
				break;
			}
		}
		if (check == 0) //neu chua lap lai thi them vao vector
		{
			count++;
			arr_a.push_back(a);
			arr_b.push_back(b);
		}
		else //neu lap lai thi thoat khoi vong lap while()
		{
			break;
		}

		int c = (X - (int)pow(b, 2)) / a; //a *(sqrt(X) + b) / (X - (int)pow(b, 2))
		if (c == 0) //neu day la so chinh phuong
		{
			count = 0;
			break;
		}
		int d;
		for (int i = (int)sqrt(X); i >= 1; i--)
		{
			if ((i + b) % c == 0)
			{
				d = i + b;
				b = i;
				break;
			}
		}
		a = c;
	}
	return count;
}

int main()
{
	clock_t t = clock();
	int dem = 0;
	for (int X = 1; X <= 10000; X++)
	{
		if (period_square_roots(X) % 2 != 0)
		{ 
			dem++;
		}
	}
	cout << dem;
	cout << " done in " << (double)(clock() - t) / CLOCKS_PER_SEC << "s";
	system("pause");
	return 0;
}