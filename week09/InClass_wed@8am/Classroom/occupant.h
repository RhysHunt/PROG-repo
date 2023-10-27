#pragma once
#include "guest.h"
#include "student.h"


// ensure that 1 seat == 1 'person'
// week 7 - prog71985 - steveh - fall23

typedef union person {		//sizeof(person) == 80
	STUDENT student;			// sizeof(student) == 44 
	GUEST guest;				//sizeof(guest)  == 80
	//PROFESSOR professor; 
} PERSON;

typedef enum persontype {STUDENT_TYPE, GUEST_TYPE } PERSON_TYPE;

typedef struct occupant {			// sizeof(o) == 84
	PERSON_TYPE personType;
	PERSON person;
} OCCUPANT;

//C
OCCUPANT CreateOccupantFromStudent(STUDENT s);
OCCUPANT CreateOccupantFromGuest(GUEST g);

//R

//U

//D
void DestroyOccupant(OCCUPANT o);