#include<iostream>
#include<set>
#include<vector>
using namespace std;

bool isPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
	if (x > 3)
	{
		if (x % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i <= sqrt(x); i+= 2)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}


void distinctPrimesFactors(int x) //phan tich thanh cac thua so nguyen to
{
	vector<int> v;
	while(x % 2 == 0)
	{
		v.push_back(2);
		x /= 2;
		cout << "x=" << x << endl;
	}
	for (int n = 3; n <= x; n += 2) //xet cac so le n < x
	{
		if(isPrime(n) == true && x % n == 0)
		{
			v.push_back(n);
			x /= n;
			n = 3;
			cout << "x = " << x << endl;
		}
	}
	cout << "size = " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "*";
	}
}

vector<int> countDistinctPrimesFactors(int x) //dem 
{
	vector<int> v;
	if (x % 2 == 0)
	{
		v.push_back(2);
		x /= 2;
	}
	for (int n = 3; n <= x; n += 2) //xet cac so le n < x
	{
		if (isPrime(n) == true && x % n == 0)
		{
			v.push_back(n);
			x /= n;
		}
	}
	return v;
}

int EulersTotientFunction(int n)
{
	vector<int> v = countDistinctPrimesFactors(n);
	int mul = n;
	for (int i = 0; i < v.size(); i++)
	{
		mul *= v[i] - 1;
		mul /= v[i];
	}
	return mul;
}

int main()
{
	int max = 0;
	int val;
	for (int n = 2; n <= 100000; n++)
	{
		double tem = (double)n / EulersTotientFunction(n);
		if(tem > max)
		{
			max = tem;
			val = n;
		}
	}
	cout << val;
	system("pause");
	return 0;
}