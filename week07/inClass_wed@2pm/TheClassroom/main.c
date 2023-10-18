#include "student.h"
#include "guest.h"
#include <stdio.h>

// mvp of classroom
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int main(void) {

	//PERSON classroom[40]; //=> PERSON == GUEST or STUDENT

	//classroom c = CreateClassroom("prog71985");
	//AddProfessorToClassroom(c, CreateProfessor("steve", "acsit"));

	//while (!ClassIsAtCapacity(c)) {
	//	int StudentNum = GetIntFromUser();
	//	char* Name = GetStringFromUser();
	STUDENT s = CreateStudent(12345678, "Student Name");

	char buf[MAXNAME];
	GetStudentNameFromStudent(s, buf);
	printf("%s\n", buf);

	//	AddStudentToClassroom(c, s);
	//}

	//PrintClassList(c);

	//DestroyClassroom(c);

	GUEST g = CreateGuest("my special friend");
	DebugPrintGuest(g);


	return 0;
}