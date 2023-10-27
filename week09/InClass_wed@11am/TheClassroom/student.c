#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <string.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


//C
STUDENT CreateStudent(int StudentNum, char* Name) {
	STUDENT s;
	s.studentnum = StudentNum;
	strncpy(s.name, Name, MAXNAME);
	return s;
}

//R
int GetStudentNumberFromStudent(STUDENT s) {

}
bool GetStudentNameFromStudent(STUDENT s, char* Name) {

	if(Name == NULL || strlen(s.name) == 0)  // == NULL == '\0'
		return false;

	strncpy(Name, s.name, MAXNAME);
	return true;
}

//U
bool SetStudentNumberInStudent(STUDENT s, int StudentNum) {

}
bool SetStudentNameInStudent(STUDENT s, char* Name) {

}

//D
void DestroyStudent(STUDENT s) {

}