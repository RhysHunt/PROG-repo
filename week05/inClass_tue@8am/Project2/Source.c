#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXLEN	80

bool GetIntFromUser(int *input) {
	char buffer[MAXLEN];

	fgets(buffer, MAXLEN, stdin);

	input = atoi(buffer);
	// what does atoi do when it fails...  returns 0
	return;
}

int main(void) {

	int userInput;
	printf("enter a number: ");

	while(!GetIntFromUser(&userInput)) { 
		fprintf(stderr, "bad input, retrying...\n");
	}

	printf("the userInput is %d\n", userInput);

	return 0;
}