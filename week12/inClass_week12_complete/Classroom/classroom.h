#pragma once
#include "occupant.h"
#include "list.h"
#include <stdbool.h>

// classroom interface
// prog71985 - steveh - fall23 - week10

#define MAXSIZE						80

typedef struct classroom {
	PLISTNODE classlist;
	int capacity;
	char name[MAXSIZE];
}CLASSROOM;

CLASSROOM CreateClassroom(char* Name, int Capacity);

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o);
bool RemoveOccupantFromClassroom(CLASSROOM* c, OCCUPANT o);				
//bool RemoveOccupantByNameFromClassroom(CLASSROOM* c, char* Name);	 //next week

int GetCurrentCountFromClassroom(CLASSROOM c);
int GetMaxCapacityFromClassroom(CLASSROOM c);
//int GetNextOpenSeatFromClassroom(CLASSROOM* c, bool ReserveSeat);			

OCCUPANT GetOccupantFromClasroomByOrdinal(CLASSROOM c, int Ordinal);
//bool GetOccupantFromClassroomByName(CLASSROOM c, OCCUPANT* o, char* Name);	//next week

bool SaveClassroomToDisk(CLASSROOM c, char* filename);
CLASSROOM LoadClassroomFromDisk(char* filename);

void PrintClassroom(CLASSROOM c);

void DestroyClassroom(CLASSROOM c);
