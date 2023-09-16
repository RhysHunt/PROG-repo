// write a program to input a number (inches) and convert it to 
// centimeters

// program71985 - fall23 - week01 - steveh

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// input a number
	int inches;
	printf("please enter you height in inches: ");
	int numParsed = scanf_s("%d", &inches);
	if (inches <= 0) {
		printf("invalid input. goodbye\n");
		exit(1);
	}
	if (numParsed != 1) {
		printf("invalid input. goodbye\n");
		exit(1);
	}

	// transform to cm
	float cm = inches * 2.54;

	// output
	printf("the height in cm is %f\n", cm);

	return 0;
}