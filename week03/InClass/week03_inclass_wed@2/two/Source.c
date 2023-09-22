// find max of 3 ints

//prog71985 - fall23 - prog71985 - week03

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