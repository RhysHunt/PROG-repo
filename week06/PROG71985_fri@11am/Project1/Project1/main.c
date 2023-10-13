#include <stdio.h>
#include "guest.h"

// some more ADTs, but this time with file I/O
// week6 - fall23 - prog71985 - steveh

int main(void) {

	GUEST g = CreateGuest("my special friend");

	DebugPrint(g);

	SaveGuestToDisk(g, "guest.dat");

	GUEST h = LoadGuestFromDisk("guest.dat");

	DestroyGuest(g);
	DestroyGuest(h);

	return 0;
}