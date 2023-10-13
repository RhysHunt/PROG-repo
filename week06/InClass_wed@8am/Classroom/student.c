#include "student.h"
#include <string.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

STUDENT CreateStudent(int StudentNum, char* Name) {
	STUDENT s;

	s.studentnum = StudentNum;
	strncpy(s.name, Name, MAXNAME);
	return s;
}

int GetStudentNumber(STUDENT s) {

}

char* GetStudentName(STUDENT s) {

}

void SetStudentNumber(STUDENT s, int StudentNum) {


}

void SetStudentName(STUDENT s, char* Name) {

}

void DestroyStudent(STUDENT s) {

}