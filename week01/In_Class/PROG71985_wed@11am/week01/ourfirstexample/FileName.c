// write a program to input a number (inches) and convert it to 
// centimeters

// program71985 - fall23 - week01 - steveh


#include <stdio.h>
#include <stdlib.h>

#define CM_IN_INCHES		2.54

int main(void) {

	// input a number
	int inches;
	printf("please enter you height in inches: ");

#ifdef _WIN32
	int numParsed = scanf_s("%d", &inches);
#else
	int numParsed = scanf("%d", &inches);
#endif

	if (numParsed != 1 || inches <= 0) {
		printf("invalid input. goodbye\n");
		exit(EXIT_FAILURE);
	}


	// transform to cm
	float cm = inches * CM_IN_INCHES;

	// output
	printf("the height in cm is %f\n", cm);

	return EXIT_SUCCESS;
}