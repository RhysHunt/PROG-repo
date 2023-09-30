// take 3 numbers, find the max of them and print it out

// steveh - prog719895 - fall23 - week04

#include <stdio.h>
#include <stdlib.h>

int maxof(int, int, int);   //formal prototype, signature, 

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