#include "library.h"

// make sure to add your comments.  or else!

int maxof(int a, int b, int c) {
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}