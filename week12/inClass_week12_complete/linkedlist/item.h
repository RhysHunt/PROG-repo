#pragma once
#include <stdbool.h>

// item interface
// prog71985 - steveh - fall23 - week11

typedef struct item {
	int value;
}ITEM;

ITEM CreateItem(int Value);

bool CompareItem(ITEM lhs, ITEM rhs);

ITEM CopyItem(ITEM i);

void PrintItem(ITEM i);

void DestroyItem(ITEM i);