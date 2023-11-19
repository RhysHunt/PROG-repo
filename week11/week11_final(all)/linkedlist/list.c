#include "list.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// list impl
// prog71985 - steveh - etc

void Display(PLISTNODE list) {
	PLISTNODE current = list;  
	if (current == NULL)				// list is empty
		return; 

	do {								// list is not empty
		PrintItem(current->data);  
		current = current->next;	// advance the bouncy ball
	} while (current != NULL); // end when the list is done
}

void Add(PLISTNODE* list, ITEM i) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	assert(newNode != NULL);

	newNode->data = CopyItem(i);
	newNode->next = *list;

	*list = newNode;
}

void Remove(PLISTNODE* list, ITEM i) {
	PLISTNODE current = *list;
	if(current != NULL && CompareItem(current->data, i)) { //not empty, matched on first
			*list = current->next;  //simplified - in both conditions we can assign to current->next

		free(current);
		return;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareItem(current->data, i)) {
		prev = current;
		current = current->next;
	}

	// either we are at the end of the list, nothing found or found
	if (current == NULL)
		return;

	// if we got here, not null and found.
	prev->next = current->next;
	free(current);
}