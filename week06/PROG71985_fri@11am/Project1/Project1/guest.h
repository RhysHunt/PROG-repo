#pragma once
#include <stdbool.h>

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

#define NAMESIZE	80

typedef struct guest {
	char name[NAMESIZE];
} GUEST;  //alias  or also known as

//C
GUEST CreateGuest(char* Name);

bool SaveGuestToDisk(GUEST g, char* filename);


void DestroyGuest(GUEST g);
