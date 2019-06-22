#include<iostream>
#include<ctime>
using namespace std;

#define MAX  10001
long long int arr[MAX];

int bs(int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return bs(l, mid - 1, x);

		// Else the element can only be present in right subarray
		return bs(mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}


int main()
{
	clock_t t = clock();
	for (long long int i = 1; i<MAX; i++)
		arr[i] = i*(3 * i - 1) / 2;
	for (int d = 1; d<MAX - 1; d++)
		for (int i = 1 + d; i<MAX; i++)
			if (bs(1, i, arr[i] - arr[i - d]) != -1)
				if (bs(i - 2, MAX - 1, arr[i] + arr[i - d]) != -1)
					cout << arr[i] - arr[i - d] << endl;
	t = clock() - t;
	cout << " done in " << (double)t / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}