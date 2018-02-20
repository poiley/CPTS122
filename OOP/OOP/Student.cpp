#include "Main.h"
#include "Student.h"

Student::Student() {
	age  = 0;
	GPA  = 0.0;
	name = "";
}

Student::Student(int newAge, double newGPA, char *newName) {
	age  = newAge;
	GPA  = newGPA;

	name = (char *) malloc(sizeof(char *) * strlen(newName));
	strcpy(name, newName);
}

Student::Student(Student &copy) {
	age  = copy.getAge();
	GPA  = copy.getGPA();
	name = copy.getName();
}

Student::~Student() {}

int Student::getAge() {
	return age;
}

double Student::getGPA() {
	return GPA;
}

char *Student::getName() {
	return name;
}

void Student::setAge(int newAge) {
	age  = newAge;
}

void Student::setGPA(double newGPA) {
	GPA  = newGPA;
}

void Student::setName(char *newName) {
	name = (char *) malloc(sizeof(char *) * strlen(newName));
	strcpy(name, newName);
}

