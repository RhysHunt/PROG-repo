#include "student.h"

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


//C
STUDENT CreateStudent(int StudentNum, char* Name) {
	STUDENT s;
	s.studentnum = StudentNum;
	strcpy(s.name, Name);
	return s;
}

//R
int GetStudentNumberFromStudent(STUDENT s) {

}
char* GetStudentNameFromStudent(STUDENT s) {

}

//U
bool SetStudentNumberInStudent(STUDENT s, int StudentNum) {

}
bool SetStudentNameInStudent(STUDENT s, char* Name) {

}

//D
void DestroyStudent(STUDENT s) {

}