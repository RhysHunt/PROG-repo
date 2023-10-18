#pragma once
#include <stdbool.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

#define MAXSIZE		80

typedef struct guest {
	char name[MAXSIZE];
} GUEST;

GUEST CreateGuest(char* Name);

void DebugPrintGuest(GUEST g);

bool SaveGuestToDisk(GUEST, char* Filename);

GUEST LoadGuestFromDisk(char* Filename);

void DestroyGuest(GUEST g);
