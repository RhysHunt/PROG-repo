#pragma once

// student adt.
// week06 - prog71985 - fall23 - steveh

#include <stdio.h>
#include <stdbool.h>

#define MAXNAME		40

typedef struct student {
	int studentnum;
	char name[MAXNAME];
} STUDENT;

STUDENT CreateStudent(int StudentNum, char* Name);

bool SetStudentNumber(STUDENT s, int StudentNum);

bool CopyStudent(STUDENT* dest, const STUDENT src);

void SetStudentName(STUDENT s, char* Name);

bool GetStudentNumber(STUDENT s, int* StudentNum);

bool GetStudentName(STUDENT s, char* Name);

void DestroyStudent(STUDENT s);

