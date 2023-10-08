#include <stdio.h>
#include <stdbool.h>

// playing around with pass by value, pass by reference
// week05 - steveh - fall23 - prog71985

bool swap(int* a, int* b) { // * = the value at
	if (a == NULL || b == NULL)
		return false;
	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}

int main(void) {
	int a = 3;
	int b = 5;

	printf("before: a== %d (should be 3), b==%d (should be 5)\n", a, b);

	if (swap((void*)0, &b)) { // & = the address of
		printf("after: a== %d (should be 5), b==%d (should be 3)\n", a, b);
	}
	else {
		fprintf(stderr, "oops - we have a problem\n");
	}
	return 0;
}