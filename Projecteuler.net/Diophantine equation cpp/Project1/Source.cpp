#include<iostream>
#include<vector>
using namespace std;
class ABC
{
private:
	int m_member;
public:
	ABC(const int &x) : m_member(x)
	{
	}
	ABC(int &&x) : m_member(x)
	{
	}
	ABC() { }
};

class A
{
//private:
	int x;
public:
	A(){}
	A(int y) : x(y)
	{

	}
	void Xuat()
	{
		std::cout << x;
	}
};
struct MyStruct
{
	int x;
	int y;
	MyStruct() : x(0), y(0){}
	~MyStruct()
	{
		cout << "Check struct";
	}
};
int x = 5;
void CheckStruct()
{
	MyStruct a;
}
int& foo() { return x; }
int main()
{
	string sss = "Pham Van Lam";
	for (auto c : sss) { cout << c << endl; }
	vector<int> ss{ 2, 3, 4, 5 };
	for (auto &&i : ss) { cout << i << endl; }
	ABC ad;
	foo() = 2;
	A clas = A(2);
	int b = 5;
	int&& a = 5;
	//cout << &a;
	//int y = 6;
	//A b{ y };
	//b.Xuat();
	/*int arr[6] = { 1, 2, 3, 4, 5, 6};
	for (int x : arr)
	{
		std::cout << x << std::endl;
	}*/
	//CheckStruct();
	//MyStruct a;
	system("pause");
	return 0;
}