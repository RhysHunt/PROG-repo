// write a program to take inches input from user and transform
// to cm and display to user.

// prog7198
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define CM_IN_INCHES   2.54

int main(void) {

	// take input from user
	int inches;
	printf("please enter your height in inches: ");

	// if you enter "steve" 
#ifdef _WIN32
	int numParsed = scanf_s("%d", &inches);
#else
	int numParsed = scanf("%d", &inches);
#endif

	if (numParsed != 1 || inches <= 0) {  //       || = logical or,  && = logical and
		printf("this is not a valid input\n");
		exit(EXIT_FAILURE);
	}


	// transform
	float cm = inches * CM_IN_INCHES;

	//display output
	printf("the height in cm is %f\n", cm);

	return EXIT_SUCCESS;
}