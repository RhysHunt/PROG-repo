#include <stdio.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int mina(void) {

	CLASS a = CreateAClass("prog71985");
	AddProfessorToClass(a, "professorsteve");


	While(!IsClassFull(a))
	{
		PromptToGetString("eneter student name: ", &name);
		int studentNum = 
		struct student s = CreateStudent(studentnum, name);
		EnrollStudentIntoClass(a, s);
	}



	PrintClassList(a)



	return 0;
}