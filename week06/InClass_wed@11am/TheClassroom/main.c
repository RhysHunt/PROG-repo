#include <stdio.h>
#include "student.h"

// mvp of a classroom
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int main(void) {

	classroom c = CreateClassroom("prog71985");
	AddProfessorToClassroom(c, CreateProfessor("steve", "acsit"));

	while (!IsClassroomFull(c))
	{
		StudentNum = GetIntInputFromUser();

		STUDENT s = CreateStudent(StudentNum, StudentName);
		AddStudentToClassroom(c, s);
	}

	PrintStudentsInClassroom(c);


	return 0;
}