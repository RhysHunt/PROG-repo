#include <stdio.h>
#include <stdbool.h>

// fun with pass by value, pass by reference
// steveh - prog71985 - fall23 - week05

bool swap(int* a, int* b) {
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

	printf("PRE:  a == %d (should be 3), b == %d (should be 5)\n", a, b);

	if (swap(&a, &b)) {
		printf("POST: a == %d (should be 5), b == %d (should be 3)\n", a, b);
	}
	else {
		fprintf(stderr, "oops - something went wrong\n");
	}

	return 0;
}
