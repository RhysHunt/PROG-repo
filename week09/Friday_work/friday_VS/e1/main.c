#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// progression - week9 - what not to do
// steveh - prog71985 - fall22 - week09

#define MAXNAME 40

typedef struct student {
    int number;
    char name[MAXNAME];
} STUDENT;

STUDENT CreateStudent(char* Name, int Num) {
    STUDENT s;
    strncpy(s.name, Name, MAXNAME);
    s.number = Num;
    return s;
}

char* GetNameBad(STUDENT s) {
    return s.name;
}

char* InputValidation() {
    char input[MAXNAME];
    printf("enter name: ");
    scanf("%s", input);
    return input;
}

int main(void) {

    printf("sizeof student: %zu\n", sizeof(STUDENT));

    STUDENT s = CreateStudent(InputValidation(), 55);
    printf("name is %s\n", GetNameBad(s));

    return 0;
}
//$ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out 
//==1219755== Memcheck, a memory error detector
//==1219755== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
//==1219755== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
//==1219755== Command: ./a.out
//==1219755== 
//sizeof student: 44
//enter name: steve
//==1219755== Invalid read of size 1
//==1219755==    at 0x484EFFF: strncpy (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
//==1219755==    by 0x1091EB: CreateStudent (1.c:16)
//==1219755==    by 0x10930A: main (1.c:36)
//==1219755==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
//==1219755== 
//==1219755== 
//==1219755== Process terminating with default action of signal 11 (SIGSEGV)
//==1219755==  Access not within mapped region at address 0x0
//==1219755==    at 0x484EFFF: strncpy (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
//==1219755==    by 0x1091EB: CreateStudent (1.c:16)
//==1219755==    by 0x10930A: main (1.c:36)
//==1219755==  If you believe this happened as a result of a stack
//==1219755==  overflow in your program's main thread (unlikely but
//==1219755==  possible), you can try to increase the size of the
//==1219755==  main thread stack using the --main-stacksize= flag.
//==1219755==  The main thread stack size used in this run was 8388608.
//==1219755== 
//==1219755== FILE DESCRIPTORS: 3 open (3 std) at exit.
//==1219755== 
//==1219755== HEAP SUMMARY:
//==1219755==     in use at exit: 2,048 bytes in 2 blocks
//==1219755==   total heap usage: 2 allocs, 0 frees, 2,048 bytes allocated
//==1219755== 
//==1219755== 1,024 bytes in 1 blocks are still reachable in loss record 1 of 2
//==1219755==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
//==1219755==    by 0x48EFBA3: _IO_file_doallocate (filedoalloc.c:101)
//==1219755==    by 0x48FECDF: _IO_doallocbuf (genops.c:347)
//==1219755==    by 0x48FDF5F: _IO_file_overflow@@GLIBC_2.2.5 (fileops.c:744)
//==1219755==    by 0x48FC6D4: _IO_new_file_xsputn (fileops.c:1243)
//==1219755==    by 0x48FC6D4: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
//==1219755==    by 0x48E614C: outstring_func (vfprintf-internal.c:239)
//==1219755==    by 0x48E614C: __vfprintf_internal (vfprintf-internal.c:1263)
//==1219755==    by 0x48D179E: printf (printf.c:33)
//==1219755==    by 0x1092E9: main (1.c:34)
//==1219755== 
//==1219755== 1,024 bytes in 1 blocks are still reachable in loss record 2 of 2
//==1219755==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
//==1219755==    by 0x48EFBA3: _IO_file_doallocate (filedoalloc.c:101)
//==1219755==    by 0x48FECDF: _IO_doallocbuf (genops.c:347)
//==1219755==    by 0x48FDCDB: _IO_file_underflow@@GLIBC_2.2.5 (fileops.c:485)
//==1219755==    by 0x48FED95: _IO_default_uflow (genops.c:362)
//==1219755==    by 0x48D40CF: __vfscanf_internal (vfscanf-internal.c:628)
//==1219755==    by 0x48D3141: __isoc99_scanf (isoc99_scanf.c:30)
//==1219755==    by 0x109299: InputValidation (1.c:28)
//==1219755==    by 0x1092F3: main (1.c:36)
//==1219755== 
//==1219755== LEAK SUMMARY:
//==1219755==    definitely lost: 0 bytes in 0 blocks
//==1219755==    indirectly lost: 0 bytes in 0 blocks
//==1219755==      possibly lost: 0 bytes in 0 blocks
//==1219755==    still reachable: 2,048 bytes in 2 blocks
//==1219755==         suppressed: 0 bytes in 0 blocks
//==1219755== 
//==1219755== For lists of detected and suppressed errors, rerun with: -s
//==1219755== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
//Segmentation fault (core dumped)
