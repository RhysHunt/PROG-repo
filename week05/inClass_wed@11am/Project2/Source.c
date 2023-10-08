// playing with scanf 
// steveh - prog71985 - fall23 - week05
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	printf("please enter a number: ");
	int a;
	while (scanf("%d", &a) != 1) {

		// try replacing scanf with fgets

		fprintf(stderr, "bad value. try again\n");
	}

	printf("you entered %d\n", a);
	return 0;
}
