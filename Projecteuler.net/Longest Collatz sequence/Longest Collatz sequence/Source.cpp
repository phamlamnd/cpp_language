/*Longest Collatz sequence
Problem 14
The following iterative sequence is defined for the set of positive integers:
n → n/2 (n is even)
n → 3n + 1 (n is odd)
Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.*/

#include<iostream>
#include<Windows.h>
using namespace std;
struct Node
{
	int data;
	struct Node *pLeft;
	struct Node *pRight;
};

void Init(Node *&T)
{
	T = NULL;
}

void Insert(Node *&T, int x)
{
	if (T == NULL)
	{
		Node *p = new Node;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		T = p;
	}
	else
	{
		if (x < T->data)
		{
			Insert(T->pLeft, x);
		}
		else if (x > T->data)
		{
			Insert(T->pRight, x);
		}
	}
}

bool Search(Node *&T, int x)
{
	if (T == NULL)
	{
		return false;
	}
	if (T != NULL)
	{
		if (T->data == x)
		{
			return true;
		}
		else if (x < T->data)
		{
			Search(T->pLeft, x);
		}
		else
		{
			Search(T->pRight, x);
		}
	}
}

int main()
{
	int LongestCollatz = 0;
	int max = 0;
	for (int i = 1; i < 1000000; i++)
	{
		int count = 1;
		long long val = i;
		while (val != 1) val = val % 2 ? val * 3 + 1 : val / 2, count++;
		if (count > max) max = count, LongestCollatz = i;
	}
	cout << max << endl;
	cout << LongestCollatz;
	system("pause");
	return 0;
}