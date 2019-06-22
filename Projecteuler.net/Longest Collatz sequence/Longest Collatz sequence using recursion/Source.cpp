#include<stdio.h>
#include<conio.h>
#define LIMIT 1000000

inline unsigned int next(unsigned int n) { return n % 2 == 0 ? n / 2 : 3 * n + 1; }

int len(unsigned int n) {
	static int table[LIMIT] = { 0, 1 };
	if (n < LIMIT) {
		if (table[n] == 0) {
			table[n] = len(next(n)) + 1;
		}
		return table[n];
	}
	else {
		return len(next(n)) + 1;
	}
}

int main(void) {
	unsigned int max = 1;
	for (unsigned int n = 2; n < LIMIT; n++) {
		if (len(max) < len(n)) {
			max = n;
		}
	}
	printf("Max:%u, Length:%d\n", max, len(max));
	_getch();
	return 0;
}