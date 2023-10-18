#include <stdio.h>
#include "student.h"
#include "guest.h"

// mvp of a classroom
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int main(void) {

	GUEST classroom[40];


	//classroom c = CreateClassroom("prog71985");
	//AddProfessorToClassroom(c, CreateProfessor("steve", "acsit"));

	//while (!IsClassroomFull(c))
	//{
	//	StudentNum = GetIntInputFromUser();

	STUDENT s = CreateStudent(12345678, "Student Name");

	char buf[MAXNAME];
	GetStudentNameFromStudent(s, buf);
	printf("NAME: %s\n", buf);

	//	AddStudentToClassroom(c, s);
	//}

	//PrintStudentsInClassroom(c);


	GUEST g = CreateGuest("my special friend");
	DebugPrintGuest(g);

	return 0;
}