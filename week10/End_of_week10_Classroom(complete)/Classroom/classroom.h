#pragma once
#include "occupant.h"

// classroom interface
// prog71985 - steveh - fall23 - week10

#define CLASROOMCAPACITY	35
#define MAXSIZE						80

typedef struct classroom {
	OCCUPANT occupants[CLASROOMCAPACITY];
	int currentCount;
	char name[MAXSIZE];
}CLASSROOM;

CLASSROOM CreateClassroom(char* Name);

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o);

int GetCurrentCountFromClassroom(CLASSROOM c);
int GetMaxCapacityFromClassroom(CLASSROOM c);

OCCUPANT GetOccupantFromClasroomByOrdinal(CLASSROOM c, int Ordinal);

bool SaveClassroomToDisk(CLASSROOM c, char* filename);
CLASSROOM LoadClassroomFromDisk(char* filename);

void PrintClassroom(CLASSROOM c);

void DestroyClassroom(CLASSROOM c);
