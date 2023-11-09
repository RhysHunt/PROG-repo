#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <stdio.h>
#include <string.h>

// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

static void RemoveNewLine(char* buffer) {		//this is a new thing - static functions are only visible in the scope of the file they 'live in'
 	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == '\n')
			buffer[i] = '\0';
}

STUDENT CreateStudent(int StudentNum, char* Name)
{
	STUDENT s = { 0 };		
	s.studentnum = StudentNum;
	RemoveNewLine(Name);
	strncpy(s.name, Name, MAXNAME);
	return s;
}

bool CopyStudent(STUDENT* dest, const STUDENT src) {
	if(dest == NULL || strlen(src.name) == 0)
		return false;
	dest->studentnum = src.studentnum;
	strncpy(dest->name, src.name, MAXNAME);
	return true;
}

bool CompareStudent(STUDENT lhs, STUDENT rhs) {				//yes, this could be improved, but its a good version 1.0
	if (strcmp(lhs.name, rhs.name) == 0)
		return true;
	else
		return false;
}

bool SetStudentNumber(STUDENT s, int StudentNum)
{
	if (StudentNum <= 0) {
		fprintf(stderr, "invalid student number\n");
		s.studentnum = -1;
		return false;
	}
	s.studentnum = StudentNum;
	return true;
}

void SetStudentName(STUDENT s, char* Name)
{
	strncpy(s.name, Name, MAXNAME);
}

bool GetStudentNumber(STUDENT s, int* StudentNum)
{
	if(StudentNum == NULL || s.studentnum <= 0)
		return false;
	*StudentNum = s.studentnum;
	return true;
}

bool GetStudentName(STUDENT s, char* Name)
{
	if (Name == NULL || strlen(s.name) == 0)
		return false;
	strncpy(Name, s.name, MAXNAME);
	return true;
}

bool SaveStudentToDisk(STUDENT s, FILE* fp) {
	fprintf(fp, "%s\n", s.name);
	fprintf(fp, "%d\n", s.studentnum);
	return true;
}

STUDENT LoadStudentFromDisk(FILE* fp) {
	char name[MAXNAME];
	int studentnum;
	fgets(name, MAXNAME, fp);
	int chars = fscanf(fp, "%d\n", &studentnum);
	return CreateStudent(studentnum, name);
}

void PrintStudent(STUDENT s) {
	printf("STUDENT: %s, %d\n", s.name, s.studentnum);
}

void DestroyStudent(STUDENT s)
{
	// nothing to do here
}
