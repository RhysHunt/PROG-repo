#include "../Project2/library.h"

#include <stdio.h>

void run_test(int expected, int a, int b, int c) {

	printf("test maxof(%d, %d, %d) => %d: ", a, b, c, expected);
	int actual = maxof(a, b, c);
	if (expected == actual)
		printf("pass\n");
	else
		printf("fail\n");
}

int main(void) {
	
	run_test(3,    1, 2, 3);
	run_test(1,   -1, 0, 1);

	return 0;

}
