// find the max of 3 numbers.  store in 'max'

#include <stdio.h>

int main(void) {

	// either prompt and accept user input or just hard-code them for now.
	int a = 1, b = 2, c = 3;
	int max;

	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;

	printf("the max is: %d\n", max);

	return 0;
}