// pointers to functions
//
// prog71985 - fall 2022 - professor steveh
//
#include <stdio.h>

int add2Ints(int a, int b)
{
	return a + b;
}

int main(void)
{
	int a = 2;
	int b = 2;

	// traditional call:
	printf("the sum is: %d\n", add2Ints(a, b));

//   V--- the return value
//       V--- denotes a pointer
//             V--- the name we will refer to
//                                 V--- the parameters, in this case 2 ints
//                                              V--- the address of the function to point to
	int (*functionPtr)(int, int) = &add2Ints;
	printf("the sum is: %d\n", (*functionPtr)(a, b));

	// or

	int (*anotherFunctionPtr)(int, int);
	anotherFunctionPtr = add2Ints;
	printf("the sum is: %d\n", anotherFunctionPtr(a, b));
}
