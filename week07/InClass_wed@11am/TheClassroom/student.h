#pragma once
#include <stdbool.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

#define MAXNAME		40

typedef struct student {
	int studentnum;
	char name[MAXNAME];
} STUDENT;

//C
STUDENT CreateStudent(int StudentNum, char* Name);

//R
int GetStudentNumberFromStudent(STUDENT s);
bool GetStudentNameFromStudent(STUDENT s, char* Name);

//U
bool SetStudentNumberInStudent(STUDENT s, int StudentNum);
bool SetStudentNameInStudent(STUDENT s, char* Name);

//D
void DestroyStudent(STUDENT s);