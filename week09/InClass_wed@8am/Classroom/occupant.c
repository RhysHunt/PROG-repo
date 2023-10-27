#include "occupant.h"
#include <stdio.h>

// impl for occupant
// week07 - prog71985 - fall23 - steveh

//C
OCCUPANT CreateOccupantFromStudent(STUDENT s) {
	OCCUPANT o;

	o.personType = STUDENT_TYPE;
	
	o.person.student = s;  //strcpy

	return o;
}

OCCUPANT CreateOccupantFromGuest(GUEST g) {

}

//R

//U

//D
void DestroyOccupant(OCCUPANT o) {
	if (o.personType == STUDENT_TYPE)
		DestroyStudent(o.person.student);
	else if (o.personType == GUEST_TYPE)
		DestroyGuest(o.person.guest);
	else
		fprintf(stderr, "unrecognized/unsupported occupant type\n");

	// nothing here yet
}