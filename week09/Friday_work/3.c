#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// our first attempt at having a heap allocation in a struct
// steveh - prog71985 - week09 - fall23

#define MAXSIZE 80

typedef struct student {
    int num;
    char* name;
} STUDENT;

void failAndExit(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

STUDENT CreateStudent(char* Name, int Num) {
    STUDENT s;
    int len = strlen(Name);
    s.name = (char*)malloc(len*sizeof(char));
    if (s.name == NULL)
        failAndExit("memory allocation issue");

    strncpy(s.name, Name, MAXSIZE);
    s.num = Num;
    return s;
}

void DestroyStudent(STUDENT s) {
    free(s.name);
}

int main(void) {
    STUDENT s;
    printf("sizeof(s): %zu\n", sizeof(s));

    return 0;
}
//$ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out 
//==1219277== Memcheck, a memory error detector
//==1219277== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==1219277== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
//==1219277== Command: ./a.out
//==1219277== 
//sizeof(s): 16
//==1219277== 
//==1219277== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1219277== 
//==1219277== HEAP SUMMARY:
//==1219277==     in use at exit: 0 bytes in 0 blocks
//==1219277==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
//==1219277== 
//==1219277== All heap blocks were freed -- no leaks are possible
//==1219277== 
//==1219277== For lists of detected and suppressed errors, rerun with: -s
//==1219277== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
