#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <string.h>


//C
STUDENT CreateStudent(int StudentNum, char* Name) {
	STUDENT s;
	s.studentnum = StudentNum;
	strncpy(s.name, Name, MAXNAME);
	return s;
}

bool GetStudentNameFromStudent(STUDENT s, char* Name) {
	if(strlen(s.name) == 0 || Name == NULL )     // s.name = '\0'  == NULL ;  
		return false;

	strncpy(Name, s.name, MAXNAME);
	
	return true;
}


//D
void DestroyStudent(STUDENT s) {
	//do nothing right now
}