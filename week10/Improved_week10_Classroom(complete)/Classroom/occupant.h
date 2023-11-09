#pragma once
#include "guest.h"
#include "student.h"
#include "professor.h"
#include <stdio.h>
// ensure that 1 "person" per "seat"
// 

#define STUDENT_LABEL			"__STUDENT__\n"
#define GUEST_LABEL				"__GUEST__\n"
#define PROFESSOR_LABEL		"__PROFESSOR__\n"

typedef union person {  //allows 1 only to use the space
	GUEST guest;		//sizeof(GUEST) == 80
	STUDENT student;    // sizeof(STUDENT) == 44
	PROFESSOR professor;
} PERSON;               //sizeof(PERSON) == 80

typedef enum type { NONE=0, STUDENT_TYPE, GUEST_TYPE, PROFESSOR_TYPE } TYPE;

typedef struct occupant {
	TYPE personType;
	PERSON person;
} OCCUPANT;

//C
OCCUPANT CreateOccupantFromStudent(STUDENT s);
OCCUPANT CreateOccupantFromGuest(GUEST g);
OCCUPANT CreateOccupantFromProfessor(PROFESSOR p);

//Read (Get)
//PERSON GetPersonFromOccupant(OCCUPANT o);   //not a good idea
// WEEK10:  START HERE:  return a copy or reference to existing?

bool CopyOccupant(OCCUPANT* dest, OCCUPANT src);

//Update (Set)
TYPE GetOccupantType(OCCUPANT o);							//NEW
OCCUPANT GetOccupantByName(OCCUPANT o, char* Name);			//NEW
bool CompareOccupant(OCCUPANT lhs, OCCUPANT rhs);                    // NEW

bool SaveOccupantToDisk(OCCUPANT o, FILE* fp);
OCCUPANT LoadOccupantFromDisk(FILE* fp);

void PrintOccupant(OCCUPANT o);

//D
void DestroyOccupant(OCCUPANT o);
