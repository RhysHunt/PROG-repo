#include "occupant.h"
#include <string.h>

// the impl. of occupant interface
// week07

OCCUPANT CreateOccupantFromStudent(STUDENT s) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = STUDENT_TYPE;
	CopyStudent(&(o.person.student), s);  //OPTION 1 - the correct option
	//memcpy(&o.person.student, &s, sizeof(STUDENT));
	return o;
}

OCCUPANT CreateOccupantFromGuest(GUEST g) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = GUEST_TYPE;
	CopyGuest(&(o.person.guest), g);  //OPTION 1 - the correct option
	return o;
}

OCCUPANT CreateOccupantFromProfessor(PROFESSOR p) {
	OCCUPANT o = { 0 };		//if you wish to get rid of the reminder that struct is not initialized (set to known/default values)
	o.personType = PROFESSOR_TYPE;
	CopyProfessor(&(o.person.professor), p);  //OPTION 1 - the correct option
	return o;
}

bool CopyOccupant(OCCUPANT* dest, OCCUPANT src) {
	if (dest == NULL)
		return false;

	dest->personType = src.personType;
	if (src.personType == STUDENT_TYPE)
		return CopyStudent(&(dest->person.student), src.person.student);
	else if (src.personType == GUEST_TYPE)
		return CopyGuest(&(dest->person.guest), src.person.guest);
	else if (src.personType == PROFESSOR_TYPE)
		return CopyProfessor(&(dest->person.professor), src.person.professor);
	else
		return false;
}

//make this private and only accessible within this TU
static OCCUPANT createNoneOccupant() {
	OCCUPANT o = { 0 };
	o.personType = NONE;
	return o;
}

OCCUPANT GetOccupantByName(OCCUPANT o, char* Name) {
	char buffer[MAXSIZE];
	switch (o.personType) {
		case STUDENT_TYPE: 
			if (GetStudentName(o.person.student, buffer)) {
				if (strncmp(Name, buffer, MAXSIZE) == 0)
					return o;
			}
			break;
		case GUEST_TYPE: 
			if (GetGuestName(o.person.guest, buffer)) {
				if (strncmp(Name, buffer, MAXSIZE) == 0)
					return o;
			}
			break;
		case PROFESSOR_TYPE: 
			if (GetProfessorName(o.person.professor, buffer)) {
				if (strncmp(Name, buffer, MAXSIZE) == 0)
					return o;
			}
			break;
		default:
			fprintf(stderr, "invalid Occupant type\n");
			break;
	}
	return createNoneOccupant();
}

bool CompareOccupant(OCCUPANT lhs, OCCUPANT rhs) {
	if (lhs.personType != rhs.personType)
		return false;

	switch (lhs.personType) {
	case STUDENT_TYPE:
		return CompareStudent(lhs.person.student, rhs.person.student);
		break;
	case GUEST_TYPE:
		return CompareGuest(lhs.person.guest, rhs.person.guest);
		break;
	case PROFESSOR_TYPE:
		return CompareProfessor(lhs.person.professor, rhs.person.professor);
		break;
	default:
		return false;
	}
}

//RU
bool SaveOccupantToDisk(OCCUPANT o, FILE* fp) {
	if (o.personType == GUEST_TYPE) {
		fprintf(fp, GUEST_LABEL);
		return SaveGuestToDisk(o.person.guest, fp);
	} else if (o.personType == STUDENT_TYPE) {
		fprintf(fp, STUDENT_LABEL);
		return SaveStudentToDisk(o.person.student, fp);
	} else if (o.personType == PROFESSOR_TYPE) {
		fprintf(fp, PROFESSOR_LABEL);
		return SaveProfessorToDisk(o.person.professor, fp);
	}
	else
		return false;
}

OCCUPANT LoadOccupantFromDisk(FILE* fp) {
	char tmpBuffer[MAXSIZE];

	fgets(tmpBuffer, MAXSIZE, fp);
	if (strncmp(tmpBuffer, GUEST_LABEL, strlen(GUEST_LABEL)) == 0) {
		GUEST g = LoadGuestFromDisk(fp);
		return CreateOccupantFromGuest(g);
	}
	else if (strncmp(tmpBuffer, STUDENT_LABEL, strlen(STUDENT_LABEL)) == 0) {
		STUDENT s = LoadStudentFromDisk(fp);
		return CreateOccupantFromStudent(s);
	}
	else if (strncmp(tmpBuffer, PROFESSOR_LABEL, strlen(PROFESSOR_LABEL)) == 0) {
		PROFESSOR p = LoadProfessorFromDisk(fp);
		return CreateOccupantFromProfessor(p);
	}
	else {
		fprintf(stderr, "unknown occupant type in datafile\n");
		OCCUPANT o = { 0 };		//kind of a hack, but we will fix this in the next version
		o.personType = NONE;
		return o;
	}
}

TYPE GetOccupantType(OCCUPANT o) {
	return o.personType;
}

void PrintOccupant(OCCUPANT o) {
	if (o.personType == STUDENT_TYPE)
		PrintStudent(o.person.student);
	else if (o.personType == GUEST_TYPE)
		PrintGuest(o.person.guest);
	else if (o.personType == PROFESSOR_TYPE)
		PrintProfessor(o.person.professor);
	else
		fprintf(stderr, "unknown occupant type");
}

//D
void DestroyOccupant(OCCUPANT o) {

	if (o.personType == STUDENT_TYPE)
		DestroyStudent(o.person.student);
	else if (o.personType == GUEST_TYPE)
		DestroyGuest(o.person.guest);
	else if (o.personType == PROFESSOR_TYPE)
		DestroyProfessor(o.person.professor);
	else
		fprintf(stderr, "unknown occupant type");

	//nothing to do
}