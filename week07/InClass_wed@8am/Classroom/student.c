#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <string.h>
#include <stdbool.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

STUDENT CreateStudent(int StudentNum, char* Name) {
	STUDENT s;

	s.studentnum = StudentNum;
	strncpy(s.name, Name, MAXNAME);
	return s;
}

int GetStudentNumber(STUDENT s) {
	return s.studentnum;
}

bool GetStudentName(STUDENT s, char* Name) {
	if (Name == NULL || strlen(s.name) == 0)  // '\0'
		return false;

	strncpy(Name, s.name, MAXNAME);
	return true;
}

void SetStudentNumber(STUDENT s, int StudentNum) {
	s.studentnum = StudentNum;
}

void SetStudentName(STUDENT s, char* Name) {

}

void DestroyStudent(STUDENT s) {
	//nothing to do.
}