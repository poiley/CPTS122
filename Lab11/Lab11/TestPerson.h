#pragma once

#include "Resources.h";
#include "Person.h";

class TestPerson : public Person {
	public:
		TestPerson() {};
		TestPerson(string newName, int newAge, char newGender, double newHeight);
		
		bool test_getName(string name);
		bool test_getAge(int age);
		bool test_getGender(char gender);
		bool test_getHeight(double height);
		
		bool test_setName(string name);
		bool test_setAge(int age);
		bool test_setGender(char gender);
		bool test_setHeight(double height);

		bool test_assignmentOperator(Person newPerson);

		bool TestPerson::test_extractionOperator();
	private:
};
