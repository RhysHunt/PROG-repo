// we can mask off parts of data also.
//
// prog71985 - fall 2022 - professor steveh

#include <stdio.h>
#include <stdint.h>
#include "binary.h"

int main()
{
	uint32_t highest3ByteMask = 0x000000ff;

	int someVeryLargeNumber = 2343231;		// random keyboarding

	int lowestByteValue = someVeryLargeNumber & highest3ByteMask;

	to_binary(someVeryLargeNumber);
	printf("\nXXXXXXXXXXXXXX  ");  // the masked off parts represented by X's
	to_binary(lowestByteValue);
	printf("\n\n");

}
