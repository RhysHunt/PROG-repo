

// mvp of classroom
// ADTs - the classroom!  
// week6 - fall23 - prog71985 - steveh

int main(void) {

	classroom c = CreateClassroom("prog71985");
	AddProfessorToClassroom(c, CreateProfessor("steve", "acsit"));

	while (!ClassIsAtCapacity(c)) {
		int StudentNum = GetIntFromUser();
		char* Name = GetStringFromUser();
		student s = CreateStudent(StudentNum, Name);
		AddStudentToClassroom(c, s);
	}

	PrintClassList(c);

	DestroyClassroom(c);





	return 0;
}