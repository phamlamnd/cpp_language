#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	clock_t start = clock();
	int max = 0;
	for (int num = 1; num <= 9999; num++)
	{
		string sprod = "";
		int n = 1;
		int check[10] = {0};
		while (true)
		{
			int prod = num * n;
			sprod += std::to_string(prod);
			bool checkdigit = false;
			while (prod != 0)
			{
				check[prod % 10]++;
				prod /= 10;
				if (check[0] > 0 || check[1] > 1 || check[2] > 1 || check[3] > 1 || check[4] > 1 || check[5] > 1 || check[6] > 1 || check[7] > 1 || check[8] > 1 || check[9] > 1)
				{
					checkdigit = true;
					break;
				}
			}
			if (checkdigit == true)
			{
				break;
			}
			if (check[0] == 0 && check[1] == 1 && check[2] == 1 && check[3] == 1 && check[4] == 1 && check[5] == 1 && check[6] == 1 && check[7] == 1 && check[8] == 1 && check[9] == 1)
			{
				
				int temp = stoi(sprod);
				if (temp > max)
				{
					max = temp;
				}
				break;
			}
			n++;
		}
	}
	cout << max;
	clock_t end = clock();
	cout << " done in " << double(end - start) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
	system("pause");
	return 0;
}