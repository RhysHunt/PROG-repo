#include <stdio.h>
#include "student.h"

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int main(void) {

	//CLASS a = CreateAClass("prog71985");
	//AddProfessorToClass(a, "professorsteve");


	//While(!IsClassFull(a))
	//{
	//	PromptToGetString("enter student name: ", &name);
	//	int studentNum = 
	
	STUDENT s = CreateStudent(12345678, "student name");
	char n[MAXNAME];
	GetStudentName(s, n);
	printf("NAME: %s\n", n);

	//	EnrollStudentIntoClass(a, s);
	//}



	//PrintClassList(a)

	DestroyStudent(s);

	return 0;
}