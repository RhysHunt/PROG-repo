#pragma once
#include <stdbool.h>
#include <stdio.h>

// proferssor adt
// steveh - prog71985 - week09 - fall23

#define MAXSIZE		80

typedef struct professor {
	char name[MAXSIZE];
	char dept[MAXSIZE];
} PROFESSOR;

PROFESSOR CreateProfessor(char* Name, char* Dept);

bool CopyProfessor(PROFESSOR* dest, const PROFESSOR src);

bool SetProfessorName(PROFESSOR* p, const char* Name);
bool SetProfessorDept(PROFESSOR* p, const char* Dept);

bool GetProfessorDept(const PROFESSOR p, char* Dept);
bool GetProfessorName(const PROFESSOR p, char* Name);

bool SaveProfessorToDisk(PROFESSOR, FILE* fp);
PROFESSOR LoadProfessorFromDisk(FILE* fp);

void PrintProfessor(PROFESSOR p);

void DestroyProfessor(PROFESSOR p);