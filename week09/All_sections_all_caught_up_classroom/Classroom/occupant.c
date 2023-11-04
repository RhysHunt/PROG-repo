#include "occupant.h"
#include <string.h>

// the impl. of occupant interface
// week07

OCCUPANT CreateOccupantFromStudent(STUDENT s) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = STUDENT_TYPE;
	CopyStudent(&(o.person.student), s);  //OPTION 1 - the correct option
	//memcpy(&o.person.student, &s, sizeof(STUDENT));
	return o;
}

OCCUPANT CreateOccupantFromGuest(GUEST g) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = GUEST_TYPE;
	CopyGuest(&(o.person.guest), g);  //OPTION 1 - the correct option
	return o;
}

OCCUPANT CreateOccupantFromProfessor(PROFESSOR p) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = PROFESSOR_TYPE;
	CopyProfessor(&(o.person.professor), p);  //OPTION 1 - the correct option
	return o;
}

//RU

//D
void DestroyOccupant(OCCUPANT o) {

	if (o.personType == STUDENT_TYPE)
		DestroyStudent(o.person.student);
	else if (o.personType == GUEST_TYPE)
		DestroyGuest(o.person.guest);
	else if (o.personType == PROFESSOR_TYPE)
		DestroyProfessor(o.person.professor);
	else
		fprintf(stderr, "unknown occupant type");

	//nothing to do
}