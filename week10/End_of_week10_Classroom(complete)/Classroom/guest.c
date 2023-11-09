#define _CRT_SECURE_NO_WARNINGS

#include "guest.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

static void RemoveNewLine(char* buffer) {		//this is a new thing - static functions are only visible in the scope of the file they 'live in'
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}
GUEST CreateGuest(char* Name) {
	GUEST g = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	RemoveNewLine(Name);
	strncpy(g.name, Name, MAXSIZE);
	return g;
}

void PrintGuest(GUEST g) {
	printf("GUEST: %s\n", g.name);
}

bool SaveGuestToDisk(GUEST g, FILE* fp) {
	fprintf(fp, "%s\n", g.name);
	return true;
}

bool CopyGuest(GUEST* dest, const GUEST src) {
	if (dest == NULL || strlen(src.name) == 0)
		return false;
	strncpy(dest->name, src.name, MAXSIZE);
	return true;
}

void SetGuestName(GUEST g, char* Name) {
	strncpy(g.name, Name, MAXSIZE);
}

bool GetGuestName(GUEST g, char* Name) {
	if (Name == NULL)
		return false;
	strncpy(Name, g.name, MAXSIZE);
	return true;
}

GUEST LoadGuestFromDisk(FILE* fp) {
	char buff[MAXSIZE];
	fgets(buff, MAXSIZE, fp);

	return CreateGuest(buff);
}

void DestroyGuest(GUEST g) {
	//does nothing right now
}