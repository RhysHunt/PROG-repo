#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	printf("enter a number: ");

	int a;
	while (scanf("%d", &a) != 1) {


		//  replace scanf with fgets


		fprintf(stderr, "bad entry. try again\n");
	}


	printf("you typed %d\n", a);

	return 0;
}