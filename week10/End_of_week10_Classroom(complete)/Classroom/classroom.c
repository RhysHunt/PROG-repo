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
	c.currentCount = 0;
	RemoveNewLine(Name);
	strncpy(c.name, Name, MAXSIZE);
	return c;
}

bool AddOccupantToClassroom(CLASSROOM* c, OCCUPANT o) {
	if (c == NULL)     // thisd protects from non-existent clasroom
		return false;

	if (GetCurrentCountFromClassroom(*c) >= GetMaxCapacityFromClassroom(*c))
		return false;

	return CopyOccupant(&(c->occupants[c->currentCount++]), o);
}


int GetCurrentCountFromClassroom(CLASSROOM c) {
	return c.currentCount;
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
	for (int i = 0; i < GetCurrentCountFromClassroom(c); i++) {
		OCCUPANT o = GetOccupantFromClasroomByOrdinal(c, i);
		SaveOccupantToDisk(o, fp);
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
	int chars = fscanf(fp, "%d\n", &count);
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
	for (int i = 0; i < GetCurrentCountFromClassroom(c); i++)
		PrintOccupant(GetOccupantFromClasroomByOrdinal(c, i));
}
void DestroyClassroom(CLASSROOM c) {
	//nothing to do here
}