// take 3 numbers, find the max of them and print it out

// steveh - prog719895 - fall23 - week03

#include <stdio.h>

int main(void) {

	int a = 1, b = 2, c = 3;
	int max;

	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;

	printf("the max is %d\n", max);

	return 0;
}