#pragma once

// student adt.
// week06 - prog71985 - fall23 - steveh

#include <stdio.h>
#include <stdbool.h>

#define MAXNAME		80

typedef struct student {
	int studentnum;
	char name[MAXNAME];
} STUDENT;

STUDENT CreateStudent(int StudentNum, char* Name);

bool CopyStudent(STUDENT* dest, const STUDENT src);
bool CompareStudent(STUDENT lhs, STUDENT rhs);					//NEW

bool SetStudentName(STUDENT* s, char* Name);
bool SetStudentNumber(STUDENT* s, int StudentNum);

bool GetStudentNumber(STUDENT s, int* StudentNum);
bool GetStudentName(STUDENT s, char* Name);

bool SaveStudentToDisk(STUDENT, FILE* fp);
STUDENT LoadStudentFromDisk(FILE* fp);

void PrintStudent(STUDENT s);

void DestroyStudent(STUDENT s);

