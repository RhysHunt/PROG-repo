#include "item.h"

//item impl
// steveh - prog71985

ITEM CreateItem(int Value) {
	ITEM i;
	i.value = Value;
	return i;
}

bool CompareItem(ITEM lhs, ITEM rhs) {
	return (lhs.value == rhs.value);
}

ITEM CopyItem(ITEM i) {
	return CreateItem(i.value);
}

void PrintItem(ITEM i) {
	printf("ITEM: %d\n", i.value);
}

void DestroyItem(ITEM i) {
	//does nothing
}