#include "student.h"
#include "guest.h"
#include "professor.h"
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

	//CLASSROOM classroom;
	//while (people at the door) {
	//	if pers
	//}
	//AddOccupantToClassroom(classroom, 
	OCCUPANT o2 = CreateOccupantFromGuest(CreateGuest("my other special friend"));

	GetGuestName(g, &name);
	printf("GUEST: %s\n", name);
	DebugPrintGuest(g);
	DestroyGuest(g);

	PROFESSOR p = CreateProfessor("steve", "ACSIT");
	GetProfessorName(p, &name);
	SetProfessorName(&p, "steve2");

	DestroyProfessor(p);

	return 0;
}