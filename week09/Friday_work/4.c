#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// pushing our STUDENT into the heap
//  week09 - steveh - prog71985 - fall23

#define MAXNAME     80

typedef struct student {
    int num;
    char name[MAXNAME];
} STUDENT;

void ErrorAndExit(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

STUDENT* CreateStudent(char* name, int num) {
    STUDENT* newS = (STUDENT*)malloc(sizeof(STUDENT));
    if (newS == NULL)
        ErrorAndExit("ERROR: no memory for new Student");

    memset(newS, 0, sizeof(STUDENT));
    strncpy(newS->name, name, MAXNAME);
    newS->num = num;

    return newS;
}

bool GetNameFromStudent(STUDENT* s, char* name) {
    if (s == NULL || name == NULL)
        return false;

    strncpy(name, s->name, MAXNAME);
    return true;
}

void DestroyStudent(STUDENT* s) {
    free(s);
}

int main(void) {
    STUDENT* ptrS = CreateStudent("steve", 123);
    if (ptrS == NULL)
        ErrorAndExit("ERROR: somethiung bad happened");

    char tmpName[MAXNAME];
    if (GetNameFromStudent(ptrS, tmpName))
        printf("student name: %s\n", tmpName);

    printf("here\n");
    STUDENT* s;
    printf("s=%p\n", s);
    if (GetNameFromStudent(s, tmpName))
        printf("student: %s\n", tmpName);

    DestroyStudent(ptrS);
    return 0;

}
// the 'issues' noted below are ok, they were coded as a test to make sure it was 'safe' even when not-initialized
//valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out 
//==1218337== Memcheck, a memory error detector
//==1218337== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==1218337== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
//==1218337== Command: ./a.out
//==1218337== 
//student name: steve
//here
//==1218337== Conditional jump or move depends on uninitialised value(s)
//==1218337==    at 0x48E6E85: __vfprintf_internal (vfprintf-internal.c:1516)
//==1218337==    by 0x48D179E: printf (printf.c:33)
//==1218337==    by 0x10940C: main (4.c:53)
//==1218337== 
//s=(nil)
//==1218337== Conditional jump or move depends on uninitialised value(s)
//==1218337==    at 0x109316: GetNameFromStudent (4.c:31)
//==1218337==    by 0x10941F: main (4.c:54)
//==1218337== 
//==1218337== 
//==1218337== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1218337== 
//==1218337== HEAP SUMMARY:
//==1218337==     in use at exit: 0 bytes in 0 blocks
//==1218337==   total heap usage: 2 allocs, 2 frees, 1,108 bytes allocated
//==1218337== 
//==1218337== All heap blocks were freed -- no leaks are possible
//==1218337== 
//==1218337== Use --track-origins=yes to see where uninitialised values come from
//==1218337== For lists of detected and suppressed errors, rerun with: -s
//==1218337== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
