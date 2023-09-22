// write a program to take inches input from user and transform
// to cm and display to user.

// prog71985 fall 23 steveh - week01, week02, week03
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define CM_IN_INCHES	2.54

int main(void) {

	//input (a number)
	int inches;
	printf("please enter your height in inches: ");

#ifdef _WIN32
	int numParsed = scanf_s("%d", &inches);
#else
	int numParsed = scanf("%d", &inches);
#endif

	if (numParsed != 1 || inches <= 0) {  //  || ==> logical or  
		printf("not valid input. goodbye\n");
		exit(EXIT_FAILURE);
	}

	//test cases
	// 74 -> 188
	// -1 -> not valid
	//  0 -> not valid
	// steve -> not valid 

	//transform (convert)
	float cm = inches * CM_IN_INCHES;

	//output
	printf("your height in cm is %f\n", cm);

	return EXIT_SUCCESS;
}