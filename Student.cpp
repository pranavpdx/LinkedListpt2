#pragma warning(disable : 4996)
#include "Student.h"
#include <cstring>
Student::Student(){
	first = new char();
	last = new char();
	id = 0;
	gpa = 0.0;
}
Student::~Student() {
	delete first;
	delete last;
}
char* Student::getFirst() {
	return first;
}
char* Student::getLast() {
	return last;
}
int Student::getID() {
	return id;
}
float Student::getGPA() {
	return gpa;
}
void Student::setFirst(char* name1) {
	first = new char[strlen(name1) + 1];
	strcpy(first, name1);
}
void Student::setLast(char* name1) {
	last = new char[strlen(name1) + 1];
	strcpy(last, name1);
}
void Student::setID(int id1) {
	id = id1;
}
void Student::setGPA(float gpa1) {
	gpa = gpa1;
}