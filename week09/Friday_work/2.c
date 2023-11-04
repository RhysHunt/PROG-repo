#include <stdio.h>
#include <stdlib.h>

#define MAXNAME     80

// our first foray into heap allocations
// steveh - fall23 - prog71985 - week09

int main(void) {
//    char name[MAXNAME];


    char* name = (char*)malloc(MAXNAME*sizeof(char));
    if (name == NULL)
        exit(1);

    printf("enter your name: ");
    scanf("%s", name);


    printf("%s\n", name);

    free(name);
    return 0;
}
//$ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out 
//==1219500== Memcheck, a memory error detector
//==1219500== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==1219500== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
//==1219500== Command: ./a.out
//==1219500== 
//enter your name: steve
//steve
//==1219500== 
//==1219500== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1219500== 
//==1219500== HEAP SUMMARY:
//==1219500==     in use at exit: 0 bytes in 0 blocks
//==1219500==   total heap usage: 3 allocs, 3 frees, 2,128 bytes allocated
//==1219500== 
//==1219500== All heap blocks were freed -- no leaks are possible
//==1219500== 
//==1219500== For lists of detected and suppressed errors, rerun with: -s
//==1219500== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
