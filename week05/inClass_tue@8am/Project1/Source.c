#include <stdio.h>
#include <stdbool.h>

// playing with pass by value, pass by ref
// prog71985 - week05 - fall23 - steveh

bool swap(int* a, int* b) {  //  i always recommend using return as indicator 
	if (a == NULL || b == NULL)  // of success
		return false;
	int temp = *a;
	*a = *b;
	*b = temp;
	return true;
}

int main(void) {

	int a = 3;
	int b = 5;

	if (swap(&a, &b)) { //send the address of variable, because 
						// those can be discarded with no consequence
		printf("a == %d == 5\n", a);
		printf("b == %d == 3\n", b);
	}
	else {
		fprintf(stderr, "oops - something went wrong\n");
	}
}