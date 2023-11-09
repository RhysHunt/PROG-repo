#pragma once
#include "occupant.h"
#include <stdbool.h>

// classroom interface
// prog71985 - steveh - fall23 - week10

#define CLASROOMCAPACITY	35
#define MAXSIZE						80

typedef enum state {EMPTY, FILLED } STATE;

typedef struct classroom {
	OCCUPANT occupants[CLASROOMCAPACITY];
	STATE seats[CLASROOMCAPACITY];
	char name[MAXSIZE];
}CLASSROOM;

CLASSROOM CreateClassroom(char* Name);

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o);
bool RemoveOccupantFromClassroom(CLASSROOM* c, OCCUPANT o);					//NEW
bool RemoveOccupantByNameFromClassroom(CLASSROOM* c, char* Name);			//NEW

int GetCurrentCountFromClassroom(CLASSROOM c);
int GetMaxCapacityFromClassroom(CLASSROOM c);
int GetNextOpenSeatFromClassroom(CLASSROOM* c, bool ReserveSeat);				//NEW

OCCUPANT GetOccupantFromClasroomByOrdinal(CLASSROOM c, int Ordinal);
bool GetOccupantFromClassroomByName(CLASSROOM c, OCCUPANT* o, char* Name);		//NEW

bool SaveClassroomToDisk(CLASSROOM c, char* filename);
CLASSROOM LoadClassroomFromDisk(char* filename);

void PrintClassroom(CLASSROOM c);

void DestroyClassroom(CLASSROOM c);
