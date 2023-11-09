#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <string.h>

// professor implementation
// steveh - prog71985 - fal23 - week09

static void RemoveNewLine(char* buffer) {		//this is a new thing - static functions are only visible in the scope of the file they 'live in'
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}

PROFESSOR CreateProfessor(char* Name, char* Dept) {
	PROFESSOR p = { 0 };
	RemoveNewLine(Name);
	strncpy(p.name, Name, MAXSIZE);
	RemoveNewLine(Dept);
	strncpy(p.dept, Dept, MAXSIZE);
	return p;
}

bool CopyProfessor(PROFESSOR* dest, const PROFESSOR src) {
	if (dest == NULL || strlen(src.name) == 0)
		return false;
	strncpy(dest->name, src.name, MAXSIZE);
	strncpy(dest->dept, src.dept, MAXSIZE);
	return true;
}

bool CompareProfessor(PROFESSOR lhs, PROFESSOR rhs) {
	if (strcmp(lhs.name, rhs.name) == 0)
		return true;
	else
		return false;
}

bool SetProfessorName(PROFESSOR* p, const char* Name) {
	if (Name == NULL)
		return false;
	strncpy(p->name, Name, MAXSIZE);
	return true;
}

bool SetProfessorDept(PROFESSOR* p, const char* Dept) {
	if (Dept == NULL)
		return false;
	strncpy(p->dept, Dept, MAXSIZE);
	return true;
}

bool GetProfessorDept(const PROFESSOR p, char* Dept) {
	if (Dept == NULL || strlen(p.dept) == 0)
		return false;
	strncpy(Dept, p.dept, MAXSIZE);
	return true;
}
bool GetProfessorName(const PROFESSOR p, char* Name) {
	if (Name == NULL || strlen(p.name) == 0)
		return false;
	strncpy(Name, p.name, MAXSIZE);
	return true;
}

bool SaveProfessorToDisk(PROFESSOR p, FILE* fp) {
	fprintf(fp, "%s\n", p.name);
	fprintf(fp, "%s\n", p.dept);
	return true;
}

PROFESSOR LoadProfessorFromDisk(FILE* fp) {
	char name[MAXSIZE];
	fgets(name, MAXSIZE, fp);
	char dept[MAXSIZE];
	fgets(dept, MAXSIZE, fp);
	return CreateProfessor(name, dept);
}

void PrintProfessor(PROFESSOR p) {
	printf("PROFESSOR: %s, %s\n", p.name, p.dept);
}

void DestroyProfessor(PROFESSOR p) {
	// nothing to do here
}