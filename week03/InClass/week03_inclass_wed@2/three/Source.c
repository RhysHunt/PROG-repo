// array search

// steveh - prog71985 - week03 - fall23
#include <stdio.h>
#include <stdbool.h>

#define TARGET		6
#define MAXSIZE		5

int main(void) {

	int arr[MAXSIZE] = { 1, 2, 3, 4, 5 };
	int found = false;

	// while - early exist, 0 or more elements
	//int i = 0;
	//while (!found && i < MAXSIZE) {     
	//	if (arr[i++] == TARGET) {
	//		found = true;
	//	}
	//}
	
	// do...while - early exit  and 1 or more times  (absolute once)
	int i = 0;
	do {
		if (arr[i++] == TARGET) {
			found = true;
		}
	} while (!found && i <= MAXSIZE);
	// do...while


	// default, really good for 'visit'ing every element, esp. when size is known
	//for (int i = 0; i < MAXSIZE; i++) {
	//	if (arr[i] == TARGET) {
	//		found = true;
	//	}
	//}
	if(found)
		printf("found");
	else
		printf("not found");
	
	return 0;
}