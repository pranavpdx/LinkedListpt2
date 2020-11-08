#pragma once
class Student
{
public:
	// variables in students, just name
	char* first;
	char* last;
	int id;
	float gpa;
	// gets the name of students
	char* getFirst();
	char* getLast();
	int getID();
	float getGPA();
	// sets the name of student
	void setFirst(char* name);
	void setLast(char* name);
	void setID(int id1);
	void setGPA(float gpa1);
	// constructer and destructor, initializes and deletes pointers
	Student();
	~Student();
};

