#pragma once

#include "Resources.h";

class Person {
	public:
		Person();
		Person(string name, int age, char gender, double height);
		Person(Person &copy);
		~Person() {};

		void operator=(const Person &p);

		string	getName() const;
		int		getAge() const;
		char	getGender() const;
		double	getHeight() const;

		void	setName(string newName);
		void	setAge(int newAge);
		void	setGender(char newGender);
		void	setHeight(double setHeight);
	private:
		string name;
		int age;
		char gender;
		double height;
};

ostream & operator << (ostream &out, const Person &p);
istream & operator >> (istream &in, Person &p);