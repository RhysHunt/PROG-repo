#define _CRT_SECURE_NO_WARNINGS

#include "classroom.h"
#include <string.h>
#include <stdlib.h>

// classroom implementation
// steveh - prog71985 - week10 - fall23

static void RemoveNewLine(char* buffer) {		//this is a new thing - static functions are only visible in the scope of the file they 'live in'
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}

CLASSROOM CreateClassroom(char* Name) {
	CLASSROOM c = { 0 };
	for (int i = 0; i < CLASROOMCAPACITY; i++)
		c.seats[i] = EMPTY;
	RemoveNewLine(Name);
	strncpy(c.name, Name, MAXSIZE);
	return c;
}

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o) {
	if (c == NULL)     // thisd protects from non-existent clasroom
		return false;

	if (GetCurrentCountFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return false;

	return CopyOccupant(&(c->occupants[GetNextOpenSeatFromClassroom(c, true)]), o);
}

int GetNextOpenSeatFromClassroom(CLASSROOM* c, bool ReserveSeat) {
	int seat = -1;
	if (GetCurrentCountFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return seat;

	for (int i = 0; i < CLASROOMCAPACITY; i++)
		if (c->seats[i] == EMPTY) {
			if (ReserveSeat)
				c->seats[i] = FILLED;
			return i;
		}
	return seat;
}

int GetCurrentCountFromClassroom(CLASSROOM c) {
	int count = 0;
	for (int i = 0; i < CLASROOMCAPACITY; i++)
		if (c.seats[i] == FILLED)
			count++;
	return count;
}

int GetMaxCapacityFromClassroom(CLASSROOM c) {
	return CLASROOMCAPACITY;
}

OCCUPANT GetOccupantFromClasroomByOrdinal(CLASSROOM c, int Ordinal) {
	return c.occupants[Ordinal];
}


bool SaveClassroomToDisk(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
		return false;

	fprintf(fp, "%s\n", c.name);
	fprintf(fp, "%d\n", GetMaxCapacityFromClassroom(c));
	fprintf(fp, "%d\n", GetCurrentCountFromClassroom(c));
	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++) {
		if (c.seats[i] == FILLED) {
			OCCUPANT o = GetOccupantFromClasroomByOrdinal(c, i);
			SaveOccupantToDisk(o, fp);
		}
	}
	fclose(fp);
	return true;
}
CLASSROOM LoadClassroomFromDisk(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		exit(1);

	char tmpBuffer[MAXSIZE];
	fgets(tmpBuffer, MAXSIZE, fp);
	CLASSROOM c = CreateClassroom(tmpBuffer);
	int maxCapacity;
	int chars = fscanf(fp, "%d\n", &maxCapacity);
	int count;
	chars = fscanf(fp, "%d\n", &count);
	for (int i = 0; i < count; i++) {
		OCCUPANT o = LoadOccupantFromDisk(fp);
		AddOccupantToClassroom(&c, o);
	}
	fclose(fp);
	return c;
}

void PrintClassroom(CLASSROOM c) {
	printf("Classroom: %s\n", c.name);
	printf("Occupancy: %d of %d max\n", GetCurrentCountFromClassroom(c), GetMaxCapacityFromClassroom(c));
	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++)
		if(c.seats[i] == FILLED)
			PrintOccupant(GetOccupantFromClasroomByOrdinal(c, i));
}

bool GetOccupantFromClassroomByName(CLASSROOM c, OCCUPANT* o, char* Name)  {
	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++) {
		if (c.seats[i] == FILLED) {
			OCCUPANT found = GetOccupantByName(GetOccupantFromClasroomByOrdinal(c, i), Name);
			if (GetOccupantType(found) != NONE) {
				CopyOccupant(o, found);
				return true;
			}
		}
	}
	return false;
}

bool RemoveOccupantFromClassroom(CLASSROOM* c, OCCUPANT o) {
	for (int i = 0; i < GetMaxCapacityFromClassroom(*c); i++) {
		if (c->seats[i] == FILLED) {
			OCCUPANT current = GetOccupantFromClasroomByOrdinal(*c, i);
			if (CompareOccupant(current, o)) {
				c->seats[i] = EMPTY;
				return true;
			}
		}
	}
	return false;
}

bool RemoveOccupantByNameFromClassroom(CLASSROOM* c, char* Name) {
	OCCUPANT o;
	if (GetOccupantFromClassroomByName(*c, &o, Name))
		return RemoveOccupantFromClassroom(c, o);
	else
		return false;
}

void DestroyClassroom(CLASSROOM c) {
	//nothing to do here
}