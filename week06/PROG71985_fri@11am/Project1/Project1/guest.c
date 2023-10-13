#include "guest.h"
#include <string.h>
#include <stdio.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

GUEST CreateGuest(char* Name) {
	GUEST g;
	strncpy(g.name, Name, NAMESIZE);
	return g;
}

bool SaveGuestToDisk(GUEST g, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "could not open file\n");
		return false;
	}
	fprintf(fp, "%s\n", g.name);
	fclose(fp);
	return true;
}

void DestroyGuest(GUEST g) {
	//nothing to do here.
}