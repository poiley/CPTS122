#pragma once

#include "Person.h";

Person::Person() {
	this->name	 = "";
	this->age	 = 0;
	this->gender = '\0';
	this->height = 0.00;
}

Person::Person(string newName, int newAge, char newGender, double newHeight) {
	this->name	 = newName;
	this->age	 = newAge;
	this->gender = newGender;
	this->height = newHeight;
}

Person::Person(Person &copy) {
	this->name	 = copy.name;
	this->age	 = copy.age;
	this->gender = copy.gender;
	this->height = copy.height;
}

void Person::operator=(const Person &p) {
	this->name	 = p.name;
	this->age	 = p.age;
	this->gender = p.gender;
	this->height = p.height;
}

string Person::getName() const { return name; }
int	Person::getAge() const { return age; }
char Person::getGender() const { return gender; }
double Person::getHeight() const { return height; }

void Person::setName(string newName) { this->name = newName; }
void Person::setAge(int newAge) { this->age = newAge; }
void Person::setGender(char newGender) { this->gender = newGender; }
void Person::setHeight(double newHeight) { this->height = newHeight; }

ostream & operator << (ostream &out, const Person &p) {
	out <<
		p.getName() << ", " <<
		p.getAge() << ", " <<
		p.getGender() << ", " <<
		p.getHeight();
	return out;
}

istream & operator >> (istream &in, Person &p) {
	string input_str; int input_int; double input_double; char input_char;
	
	cout << "Enter Name";
	in >> input_str;
	p.setName(input_str);

	cout << "Enter Age";
	in >> input_str;
	p.setAge(stoi(input_str));

	cout << "Enter gender ('m' or 'f')";
	in >> input_str;
	p.setGender(input_str[0]);
	
	cout << "Enter height (as decimal)";
	in >> input_str;
	p.setHeight(stod(input_str));
	
	return in;
}