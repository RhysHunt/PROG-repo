#pragma once
#include "occupant.h"
#include <stdbool.h>

// list interface
// steveh  prog71985

typedef struct listnode {
	OCCUPANT data;
	struct listnode* next;
}LISTNODE, *PLISTNODE;

void Display(PLISTNODE list);
int GetCountInList(PLISTNODE list);
OCCUPANT GetOccupantFromListAt(PLISTNODE list, int Ordinal);

bool SaveListToDisk(PLISTNODE list, FILE* fp);

bool Add(PLISTNODE* list, OCCUPANT o);

bool Remove(PLISTNODE* list, OCCUPANT o);

void DestroyList(PLISTNODE* list);
