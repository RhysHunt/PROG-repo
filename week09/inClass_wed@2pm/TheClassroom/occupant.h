#pragma once
#include "guest.h"
#include "student.h"


// interface for the idea of 1 person, 1 chair (location)
// person occupies storage location (chair)

typedef union person {		// OR
	GUEST guest;
	STUDENT student;
	//PROFESSOR professor;
} PERSON;

typedef enum persontype {GUEST_TYPE = 100, STUDENT_TYPE} PERSON_TYPE;

typedef struct occupant {
	PERSON_TYPE	personType;
	PERSON person;
} OCCUPANT;

// c
OCCUPANT CreateOccupantFromStudent(STUDENT s);
OCCUPANT CreateOccupantFromGuest(GUEST g);


// r
// u

// d
void DestroyOccupant(OCCUPANT o);
