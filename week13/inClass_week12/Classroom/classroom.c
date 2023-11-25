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

CLASSROOM CreateClassroom(char* Name, int Capacity) {
	CLASSROOM c = { 0 };
	c.capacity = Capacity;
	c.classlist = NULL;   //redundant, but here for clarity
	RemoveNewLine(Name);
	strncpy(c.name, Name, MAXSIZE);
	return c;
}

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o) {
	if (c == NULL)     // thisd protects from non-existent clasroom
		return false;

	if (GetCurrentCountFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return false;

	return Add(&(c->classlist), o);
}

//int GetNextOpenSeatFromClassroom(CLASSROOM* c, bool ReserveSeat) {
//	int seat = -1;
//	if (GetCurrentCountFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
//		return seat;
//
//	for (int i = 0; i < CLASROOMCAPACITY; i++)
//		if (c->seats[i] == EMPTY) {
//			if (ReserveSeat)
//				c->seats[i] = FILLED;
//			return i;
//		}
//	return seat;
//}

int GetCurrentCountFromClassroom(CLASSROOM c) {
	return GetCountInList(c.classlist);
}

int GetMaxCapacityFromClassroom(CLASSROOM c) {
	return c.capacity;
}

OCCUPANT GetOccupantFromClasroomByOrdinal(CLASSROOM c, int Ordinal) {
	if (Ordinal > GetCurrentCountFromClassroom(c)) {
		OCCUPANT none = { 0 };
		return none;
	}
	else {
		return GetOccupantFromListAt(c.classlist, Ordinal);
	}
}


bool SaveClassroomToDisk(CLASSROOM c, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
		return false;

	fprintf(fp, "%s\n", c.name);
	fprintf(fp, "%d\n", GetMaxCapacityFromClassroom(c));
	fprintf(fp, "%d\n", GetCurrentCountFromClassroom(c));
	SaveListToDisk(c.classlist, fp);
	fclose(fp);
	return true;
}
CLASSROOM LoadClassroomFromDisk(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		exit(1);

	char tmpBuffer[MAXSIZE];
	fgets(tmpBuffer, MAXSIZE, fp);
	int maxCapacity;
	int chars = fscanf(fp, "%d\n", &maxCapacity);
	CLASSROOM c = CreateClassroom(tmpBuffer, maxCapacity);

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
	Display(c.classlist);
}

//bool GetOccupantFromClassroomByName(CLASSROOM c, OCCUPANT* o, char* Name)  {
//	for (int i = 0; i < GetMaxCapacityFromClassroom(c); i++) {
//		if (c.seats[i] == FILLED) {
//			OCCUPANT found = GetOccupantByName(GetOccupantFromClasroomByOrdinal(c, i), Name);
//			if (GetOccupantType(found) != NONE) {
//				CopyOccupant(o, found);
//				return true;
//			}
//		}
//	}
//	return false;
//}

bool RemoveOccupantFromClassroom(CLASSROOM* c, OCCUPANT o) {
	return Remove(&(c->classlist), o);
}

bool RemoveOccupantByNameFromClassroom(CLASSROOM* c, char* Name) {
	//OCCUPANT o;
	//if (GetOccupantFromClassroomByName(*c, &o, Name))
	//	return RemoveOccupantFromClassroom(c, o);
	//else
		return false;
}

void DestroyClassroom(CLASSROOM c) {
	DestroyList(&(c.classlist));
}