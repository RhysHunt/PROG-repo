#include "student.h"

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


int main(void) {

	STUDENT s = CreateStudent(12345678, "bob");

	int studentnum;
	GetStudentNumber(s, &studentnum);
	char name[MAXNAME];
	GetStudentName(s, &name);
	printf("STUDENT: %s, %d\n", name, studentnum);
	
	DestroyStudent(s);
	return 0;
}