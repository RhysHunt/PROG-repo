// pointers to functions
//
// prog71985 - fall 2022 - professor steveh
//
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int compareByStudentNumberFunction(const STUDENT* a, const STUDENT* b)
{
	return (a->studentnum - b->studentnum);
}


int compareByStudentNameFunction(const STUDENT* a, const STUDENT* b)
{
	return (a->name[0] - b->name[0]);
}

int main(void)
{
	STUDENT classList[] = {
		createStudent("Harry", 3234),
		createStudent("Zoey", 1234),
		createStudent("Abigail", 9234),
		createStudent("Rhonda", 7234),
		createStudent("Charlie", 2234)
	};

	printf("Sorted by Student Number:\n");
	qsort(classList, sizeof(classList) / sizeof(STUDENT), sizeof(STUDENT), compareByStudentNumberFunction);

	for (int i = 0; i < sizeof(classList) / sizeof(STUDENT); i++)
		printStudent(classList[i]);

	printf("\n\nSorted by Student Name:\n");
	qsort(classList, sizeof(classList) / sizeof(STUDENT), sizeof(STUDENT), compareByStudentNameFunction);

	for (int i = 0; i < sizeof(classList) / sizeof(STUDENT); i++)
		printStudent(classList[i]);
}
