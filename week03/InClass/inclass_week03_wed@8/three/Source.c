// array search

// prog71985 - steveh - fall23 - week03, week04

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE		5
#define TARGET		2			//this is what we are searching for


int main(void) {

	int arr[MAXSIZE] = { 1, 2, 3, 4, 5 };

	bool found = false;

	// while  - early exit,  0 or more times
	//int i = 0;
	//while (!found  && i<MAXSIZE) {
	//	//this will run if found == false     
	//	if (TARGET == arr[i++]) {
	//		found = true;
	//	}
	//} 
	// do while - early exit,  1 or more times
	int i = 0;
	do {
		if (TARGET == arr[i++]) {
			found = true;
		}
	} while (!found && i<=MAXSIZE);

	// for defined collections,  visit every element in fixed collection
	//for (int i = 0; i < MAXSIZE; i++) {
	//	if (TARGET == arr[i]) {
	//		found = true;
	//	}
	//}

	if (found)
		printf("we found it\n");
	else
		printf("not there\n");

	return 0;
}