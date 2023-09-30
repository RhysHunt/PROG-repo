#include "library.h"
//         ^^^^^^
//         either fix with ../Project2/library.h"
//         or add that directory to Project properties
#include <stdio.h>

int main(void) {
	
	int actual;
	int expected;

	//test 01
	printf("test01: ");
	expected = 3;
	actual = maxof(3, 2, 1);
	if (expected == actual)
		printf("pass\n");
	else
		printf("fail\n");

	return 0;

}
