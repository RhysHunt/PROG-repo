// write a program that has an algorithm to determine the max of 3 numbers

// steveh - prog71985 - fall23 - week04

#include <stdio.h>



int main(void) {

	int a = 1, b = 2, c = 3;

	printf("the max is %d\n", maxof(a,b,c));
	return 0;
}

int maxof(int a, int b, int c) {
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}