#include "occupant.h"

// impl for occupant
// steveh - prog71985 - fall23 - week07
// 
// c
OCCUPANT CreateOccupantFromStudent(STUDENT s) {

}

OCCUPANT CreateOccupantFromGuest(GUEST g) {

}


// r
// u

// d
void DestroyOccupant(OCCUPANT o)
{
	//first delete the inner piece (guest student)
	if (o.personType == STUDENT_TYPE)
		DestroyStudent(o.person.student);
	else if

	else

	// second delete the occupant pieces
	//nothing to do
}