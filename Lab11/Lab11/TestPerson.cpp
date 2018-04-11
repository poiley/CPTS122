#pragma once

#include "TestPerson.h"

TestPerson::TestPerson(string newName, int newAge, char newGender, double newHeight) 
	: Person(newName, newAge, newGender, newHeight) {
	// uses custom constructor from Person to construct TestPerson
}

bool TestPerson::test_getName(string name) {
	if (this->getName() == name)
		return true;
	return false;
}

bool TestPerson::test_getAge(int age) {
	if (this->getAge() == age)
		return true;
	return false;
}

bool TestPerson::test_getGender(char gender) {
	if (this->getGender() == gender)
		return true;
	return false;
}

bool TestPerson::test_getHeight(double height) {
	if (this->getHeight() == height)
		return true;
	return false;
}

bool TestPerson::test_setName(string name) {
	this->setName(name);

	if (this->getName() == name)
		return true;
	return false;
}

bool TestPerson::test_setAge(int age) {
	this->setAge(age);

	if (this->getAge() == age)
		return true;
	return false;
}

bool TestPerson::test_setGender(char gender) {
	this->setGender(gender);

	if (this->getGender() == gender)
		return true;
	return false;
}

bool TestPerson::test_setHeight(double height) {
	this->setHeight(height);

	if (this->getHeight() == height)
		return true;
	return false;
}

bool TestPerson::test_assignmentOperator(Person newPerson) {
	*(dynamic_cast<Person *>(this)) = newPerson;
	
	if (this->getName() == newPerson.getName() &&
		this->getAge() == newPerson.getAge() &&
		this->getGender() == newPerson.getGender() &&
		this->getHeight() == newPerson.getHeight())
		return true;
	return false;
}

bool TestPerson::test_extractionOperator() {
	*(dynamic_cast<Person *>(this));

}