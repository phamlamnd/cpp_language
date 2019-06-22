#include "LinkedList.h"
#include "Employee.h"

int main()
{
	LinkedList<double> numberList;
	numberList.push_back(2);
	numberList.push_back(1);
	numberList.push_back(4);
	numberList.push_back(3);
	numberList.push_back(5);
	numberList.push_back(6);

	LinkedList<double>::Iterator it = numberList.begin();
	for (; it != numberList.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}