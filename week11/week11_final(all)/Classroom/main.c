#include "student.h"
#include "guest.h"
#include "professor.h"
#include "occupant.h"
#include "classroom.h"

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh


int main(void) {

	STUDENT s = CreateStudent(12345678, "bob");
	OCCUPANT o1 = CreateOccupantFromStudent(s);

	CLASSROOM c = CreateClassroom("prog71985");
	AddOccupantToClassroom(&c, o1);

	PROFESSOR p = CreateProfessor("steve", "ACSIT");
	AddOccupantToClassroom(&c, CreateOccupantFromProfessor(p));

	GUEST g = CreateGuest("my special friend");
	AddOccupantToClassroom(&c, CreateOccupantFromGuest(g));
	printf("adds done.  Now save, then print--------------------------------------------\n");
	SaveClassroomToDisk(c, "classroom.txt");
	PrintClassroom(c);

	printf("Search and print found then remove--------------------------------------------\n");
	OCCUPANT search = { 0 };
	GetOccupantFromClassroomByName(c, &search, "steve");
	PrintOccupant(search);
	RemoveOccupantFromClassroom(&c, search);
	printf("print after removed by occupant--------------------------------------------\n");
	PrintClassroom(c);
	printf("now remove by name--------------------------------------------\n");
	RemoveOccupantByNameFromClassroom(&c, "bob");
	printf("printf after  remove by name--------------------------------------------\n");
	PrintClassroom(c);
	printf("load original class from file--------------------------------------------\n");
	CLASSROOM d = LoadClassroomFromDisk("classroom.txt");
	PrintClassroom(d);

	//int studentnum;
	//GetStudentNumber(s, &studentnum);
	//char name[MAXNAME];
	//GetStudentName(s, &name);
	//printf("STUDENT: %s, %d\n", name, studentnum);
	//
	//DestroyStudent(s);

	//CLASSROOM classroom;
	//while (people at the door) {
	//	if pers
	//}
	//AddOccupantToClassroom(classroom, 
	//OCCUPANT o2 = CreateOccupantFromGuest(CreateGuest("my other special friend"));

	//GetGuestName(g, &name);
	//printf("GUEST: %s\n", name);
	//DebugPrintGuest(g);
	//DestroyGuest(g);

	//
	//GetProfessorName(p, &name);
	//SetProfessorName(&p, "steve2");

	//DestroyProfessor(p);

	return 0;
}
//$ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out 
//==890058== Memcheck, a memory error detector
//==890058== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==890058== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
//==890058== Command: ./a.out
//==890058== 
//Classroom: prog71985
//Occupancy: 3 of 35 max
//STUDENT: bob, 12345678
//PROFESSOR: steve, ACSIT
//GUEST: my special friend
//--------------------------------------------
//Classroom: prog71985
//Occupancy: 3 of 35 max
//STUDENT: bob, 12345678
//PROFESSOR: steve, ACSIT
//GUEST: my special friend
//==890058== 
//==890058== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==890058== 
//==890058== HEAP SUMMARY:
//==890058==     in use at exit: 0 bytes in 0 blocks
//==890058==   total heap usage: 5 allocs, 5 frees, 10,160 bytes allocated
//==890058== 
//==890058== All heap blocks were freed -- no leaks are possible
//==890058== 
//==890058== For lists of detected and suppressed errors, rerun with: -s
//==890058== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

