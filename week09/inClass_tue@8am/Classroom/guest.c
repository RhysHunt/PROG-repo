#define _CRT_SECURE_NO_WARNINGS

#include "guest.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

GUEST CreateGuest(char* Name) {
	GUEST g;
	strncpy(g.name, Name, MAXSIZE);
	return g;
}

void DebugPrintGuest(GUEST g) {
	printf("GUEST: %s\n", g.name);
}

bool SaveGuestToDisk(GUEST g, char* Filename) {
	FILE* fp;
	fp = fopen(Filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "error opening file for write\n");
		return false;
	}
	fprintf(fp, "%s\n", g.name);
	fclose(fp);
	return true;

}

GUEST LoadGuestFromDisk(char* Filename) {
	FILE* fp;
	GUEST n;  //we don't know if this has been initialized
	fp = fopen(Filename, "r");
	if (fp == NULL) {
		fprintf(stderr, "error opening file for read\n");
		exit(1); //TODO: make this better
	}
	char buff[MAXSIZE];
	fgets(buff, MAXSIZE, fp);
	fclose(fp);
	return CreateGuest(buff);
}

void DestroyGuest(GUEST g) {
	//does nothing right now
}