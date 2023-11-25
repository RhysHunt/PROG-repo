#include "item.h"
#include "list.h"
#include <stdio.h>

int main(void) {

	PLISTNODE list = NULL;

	Add(&list, CreateItem(5));
	Add(&list, CreateItem(8));
	DestroyList(&list);

	Display(list);
	printf("---------\n");
	Remove(&list, CreateItem(8));
	Display(list);
	printf("---------\n");
	Remove(&list, CreateItem(5));
	Display(list);
	printf("---------\n");
	Remove(&list, CreateItem(5));	//remove with epty list and not matching
	
	DestroyList(&list);
	return 0;
}