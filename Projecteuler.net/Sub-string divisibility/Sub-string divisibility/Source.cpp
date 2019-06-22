/*Sub-string divisibility
Problem 43
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property.*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	unsigned long long sum = 0;
	for(std::string num = "1406357289"; num <= "9876543210"; std::next_permutation(num.begin(), num.end()))
	{
		if (stoi(num.substr(1, 3)) % 2 == 0 && stoi(num.substr(2, 3)) % 3 == 0 && stoi(num.substr(3, 3)) % 5 == 0 && stoi(num.substr(4, 3)) % 7 == 0 && stoi(num.substr(5, 3)) % 11 == 0 && stoi(num.substr(6, 3)) % 13 == 0 && stoi(num.substr(7, 3)) % 17 == 0)
		{
			cout << num << endl;
			sum += stoi(num);
		}
	}
	cout << sum;
	std::system("pause");
	return 0;
}