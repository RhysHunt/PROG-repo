#include "student.h"
#include "guest.h"
#include "occupant.h"
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


int main(void) {

	STUDENT s = CreateStudent(12345678, "bob");
	OCCUPANT o1 = CreateOccupantFromStudent(s);


	int studentnum;
	GetStudentNumber(s, &studentnum);
	char name[MAXNAME];
	GetStudentName(s, &name);
	printf("STUDENT: %s, %d\n", name, studentnum);
	
	DestroyStudent(s);


	GUEST g = CreateGuest("my special friend");

	CLASSROOM classroom;
	while (people at the door) {
		if pers
	}
	AddOccupantToClassroom(classroom, 
		CreateOccupantFromGuest(
			CreateGuest("my other special friend"));


	DebugPrintGuest(g);
	DestroyGuest(g);

	return 0;
}