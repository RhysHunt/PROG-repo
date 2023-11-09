#pragma once
#include <stdbool.h>
#include <stdio.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

#define MAXSIZE		80

typedef struct guest {
	char name[MAXSIZE];
} GUEST;

GUEST CreateGuest(char* Name);

void PrintGuest(GUEST g);

bool CopyGuest(GUEST* dest, const GUEST src);

void SetGuestName(GUEST g, char* Name);

bool GetGuestName(GUEST g, char* Name);

bool SaveGuestToDisk(GUEST, FILE* fp);

GUEST LoadGuestFromDisk(FILE* fp);

void DestroyGuest(GUEST g);
