#pragma once

// our MVP student ADT - interface
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

#define MAXNAME		40

typedef struct student{
	int studentnum;
	char name[MAXNAME];
}STUDENT;

STUDENT CreateStudent(int StudentNum, char* Name);

int GetStudentNumber(STUDENT s);
char* GetStudentName(STUDENT s);

void SetStudentNumber(STUDENT s, int StudentNum);
void SetStudentName(STUDENT s, char* Name);

void DestroyStudent(STUDENT s);