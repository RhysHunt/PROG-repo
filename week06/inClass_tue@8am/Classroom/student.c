#include "student.h"
#include <stdio.h>
#include <string.h>


// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

// ugh - most languages disallow 'constructors' from
// failing.  we need a few more tools before we can do
// this properly.  until then, let's leave this 
// as it is (but we will come back to this!)
STUDENT CreateStudent(int StudentNum, char* Name)
{
	STUDENT s;
	s.studentnum = StudentNum;
	SetStudentName(s, Name);	// let's revert this too!
	return s;
}

bool SetStudentNumber(STUDENT s, int StudentNum)
{
	if (StudentNum <= 0) {
		fprintf(stderr, "invalid student number\n");
		s.studentnum = -1;
		return false;
	}
	s.studentnum = StudentNum;
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

}

void DestroyStudent(STUDENT s)
{

}
