// write a program to take inches input from user and transform
// to cm and display to user.

// prog71985 fall 23 steveh - week01, week02

#include <stdio.h>

int main(void) {

	//input (a number)
	int inches;
	printf("please enter your height in inches: ");
	scanf_s("%d", &inches);
	if (inches <= 0) {
		printf("not valid input. goodbye\n");
		exit(1);
	}


	//transform (convert)
	float cm = inches * 2.54;

	//output
	printf("your height in cm is %f\n", cm);

	return 0;
}