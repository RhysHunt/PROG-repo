#pragma once
#include "guest.h"
#include "student.h"

// the idea of 1 'person' per seat 
// steveh - prog71985 - fall23 - week07



typedef union person{			// or
	GUEST guest;
	STUDENT student;
	//PROFESSOR professor;
} PERSON;

typedef enum persontype { GUEST_TYPE, STUDENT_TYPE } PERSON_TYPE;

typedef struct occupant {
	PERSON_TYPE personType;
	PERSON person;
} OCCUPANT;

//c
OCCUPANT CreateOccupantFromStudent(STUDENT s);
OCCUPANT CreateOccupantFromGuest(GUEST g);

//r

//u


//d
void DestroyOccupant(OCCUPANT o);
