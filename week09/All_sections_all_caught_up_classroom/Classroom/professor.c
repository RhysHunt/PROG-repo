#define _CRT_SECURE_NO_WARNINGS
#include "professor.h"
#include <stdio.h>
#include <string.h>

// professor implementation
// steveh - prog71985 - fal23 - week09

PROFESSOR CreateProfessor(char* Name, char* Dept) {
	PROFESSOR p = { 0 };
	strncpy(p.name, Name, MAXSIZE);
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

void DestroyProfessor(PROFESSOR p) {
	// nothing to do here
}