#pragma once
#include "item.h"

// list interface
// steveh  prog71985

typedef struct listnode {
	ITEM data;
	struct listnode* next;
}LISTNODE, *PLISTNODE;

void Display(PLISTNODE list);

void Add(PLISTNODE* list, ITEM i);

void Remove(PLISTNODE* list, ITEM i);

void DestroyList(PLISTNODE* list);

PLISTNODE Search(PLISTNODE list, ITEM i);
PLISTNODE SearchR(PLISTNODE list, ITEM i);
