// array search

//steveh - prog71985 - fall23 - week03
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE		8

int main(void) {

	int arr[MAXSIZE] = {1, 2, 3, 4, 5, 7, 8, 9};

	bool exists = false;

	int target = 6;

	// while  - 0 or more times, early exit
	int i=0;
	while (!exists && i < MAXSIZE) {
		if (arr[i++] == target)
			exists = true;
	}

	// do... while -- 1 or more times, early exit
	do {
		if (arr[i++] == target)
			exists = true;
	} while (!exists && i < MAXSIZE);

	// for construct - excels at full collection visit
	for (int i = 0; i < MAXSIZE; i++) {
		if (arr[i] == target)
			exists = true;
	}

	if (exists)
		printf("we found it\n");
	else
		printf("we did not find it\n");

	return 0;
}