#include "list.h"
#include "occupant.h"
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
		PrintOccupant(current->data);  
		current = current->next;	// advance the bouncy ball
	} while (current != NULL); // end when the list is done
}

int GetCountInList(PLISTNODE list) {
	int count = 0;
	PLISTNODE current = list;
	while (current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

OCCUPANT GetOccupantFromListAt(PLISTNODE list, int Ordinal) {
	int count = 0;
	OCCUPANT o = { 0 };
	PLISTNODE current = list;
	while (current != NULL) {
		if (count == Ordinal) {
			CopyOccupant(&o, current->data);
			return o;
		}
		count++;
		current = current->next;
	}
	return o;
}


bool SaveListToDisk(PLISTNODE list, FILE* fp) {
	PLISTNODE current = list;
	while (current != NULL) {
		SaveOccupantToDisk(current->data, fp);
		current = current->next;
	}
	return true;
}

bool Add(PLISTNODE* list, OCCUPANT o) {
	PLISTNODE newNode = (PLISTNODE)malloc(sizeof(LISTNODE));
	if (newNode == NULL)
		return false;

	if (!CopyOccupant(&(newNode->data), o)) {
		free(newNode);
		return false;
	}
	newNode->next = *list;

	*list = newNode;
	return true;
}

bool Remove(PLISTNODE* list, OCCUPANT o) {
	PLISTNODE current = *list;
	if(current != NULL && CompareOccupant(current->data, o)) { //not empty, matched on first
		*list = current->next;  //simplified - in both conditions we can assign to current->next

		free(current);
		return true;
	}

	PLISTNODE prev = NULL;
	while (current != NULL && !CompareOccupant(current->data, o)) {
		prev = current;
		current = current->next;
	}

	// either we are at the end of the list, nothing found or found
	if (current == NULL)
		return false;

	// if we got here, not null and found.
	prev->next = current->next;
	free(current);
	return true;
}

void DestroyList(PLISTNODE* list) {
	PLISTNODE current = *list;
	while (current != NULL) {
		PLISTNODE tmp = current;
		current = current->next;
		DestroyOccupant(tmp->data);
		free(tmp);
	}
	*list = NULL;
}