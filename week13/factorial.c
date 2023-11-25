#include <stdio.h>
//  n! = n * (n-1)!, until n == 0 
//                    2! = 2 * 1!
//           3! = 3 * 2!
//  4! = 4 * 3!
//  4! = 4 * 3 * 2 * 1
//  0! = 1
// in recursion we always have 2 cases:
// 1st case: the base case (i am home,  0 ! = 1)
// 2nd case:  the rest (greater than 0 in factorial)


int factorialR(int in) {
    if(in == 0)          // are we at the base case
        return 1;   // 0! yes
    else
        return in * factorialR(in-1);    //no
}

int factorial(int in) {
    int answer = 1;

    for(int i = in; i>0; i--) 
        answer = answer * i;

    return answer;
}

int main(void) {

    printf("4! = %d\n", factorialR(16));
    return 0;
}