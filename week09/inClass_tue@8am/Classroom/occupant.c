#include "occupant.h"
#include <string.h>

// the impl. of occupant interface
// week07

OCCUPANT CreateOccupantFromStudent(STUDENT s) {
	OCCUPANT o;
	o.personType = STUDENT_TYPE;
	CopyStudent(&(o.person.student), s);  //OPTION 1 - the correct option
	memcpy(&o.person.student, &s, sizeof(STUDENT));
	return o;
}

OCCUPANT CreateOccupantFromGuest(GUEST g) {

}

//RU

//D
void DestroyOccupant(OCCUPANT o) {

	if (o.personType == STUDENT_TYPE)
		DestroyStudent(o.person.student);
	else if (o.personType == GUEST_TYPE)
		DestroyGuest(o.person.guest);
	else
		fprintf(stderr, "unknown occupant type");

	//nothing to do
}