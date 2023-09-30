//  search an array of ints.

// steveh - prog71985 - fall23 - week03

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE	5

#define TARGET 6

int main(void) {

	int arr[MAXSIZE] = { 1, 2, 3, 4, 5 };

	bool found = false;

	//while - early exit,  0 or more elements
	//int i = 0;
	//while (!found  && i < MAXSIZE) {
	//	// execute when (found == false) == !found   
	//	if (arr[i++] == TARGET) {
	//		found = true;
	//	}
	//}
	//do...while - early exit, 1 or more elements (but always at least 1)
	int i = 0;
	do {
		if (arr[i++] == TARGET) {
			found = true;
		}
	} while (!found && i < MAXSIZE);

	//no early exit, but perfect for 'visiting' all elements in a fixed size collection
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (arr[i] == TARGET) {
			found = true;
		}
	}

	if (found)
		printf("found\n");
	else
		printf("not found\n");


}