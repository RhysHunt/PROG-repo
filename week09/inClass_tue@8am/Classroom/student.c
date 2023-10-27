#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <stdio.h>
#include <string.h>


// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


STUDENT CreateStudent(int StudentNum, char* Name)
{
	STUDENT s;
	s.studentnum = StudentNum;
	strncpy(s.name, Name, MAXNAME);
	return s;
}

bool SetStudentNumber(STUDENT s, int StudentNum)
{
	if (StudentNum <= 0) {
		fprintf(stderr, "invalid student number\n");
		s.studentnum = -1;
		return false;
	}
	s.studentnum = StudentNum;
}

void SetStudentName(STUDENT s, char* Name)
{
	strncpy(s.name, Name, MAXNAME);
}

bool GetStudentNumber(STUDENT s, int* StudentNum)
{
	if(StudentNum == NULL || s.studentnum <= 0)
		return false;
	*StudentNum = s.studentnum;
	return true;
}

bool GetStudentName(STUDENT s, char* Name)
{
	if (Name == NULL || strlen(s.name) == 0)
		return false;
	strncpy(Name, s.name, MAXNAME);
	return true;
}

void DestroyStudent(STUDENT s)
{
	// nothing to do here
}
