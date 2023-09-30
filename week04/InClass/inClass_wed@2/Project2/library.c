#include "library.h"

// some more comments

int maxof(int a, int b, int c) {   //impl
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}