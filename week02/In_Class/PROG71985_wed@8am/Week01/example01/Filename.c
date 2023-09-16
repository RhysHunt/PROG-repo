// write a program to take inches input from user and transform
// to cm and display to user.

// prog71985 fall 23 steveh 

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// take input from user
	int inches;
	printf("please enter your height in inches: ");
	scanf_s("%d", &inches);
	if (inches <= 0) {
		printf("this is not a valid input\n");
		exit(1);
	}

	// transform
	float cm = inches * 2.54;

	//display output
	printf("the height in cm is %f\n", cm);

	return 0;
}