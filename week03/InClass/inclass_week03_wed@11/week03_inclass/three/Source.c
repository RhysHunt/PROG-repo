//  search an array of ints.

// steveh - prog71985 - fall23 - week03

#include <stdio.h>

#define MAXSIZE	5

#define TARGET 6

int main(void) {



	int arr[MAXSIZE] = { 1, 2, 3, 4, 5 };

	//  i = i + 1;
	//  i += 1;
	//  i++;


	for (int i = 0; i < MAXSIZE; i++)
	{
		if (arr[i] == TARGET)
			printf("found\n");

	}
}