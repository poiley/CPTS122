#pragma once

#include "Resources.h"
#include "TestPerson.h"

int main(void) {
	string name = "Donald Glover";
	int age = 30;
	char gender = 'm';
	double height = 5.9;

	TestPerson test = TestPerson(name, age, gender, height);

	out("getName", test.test_getName(name));
	out("getAge", test.test_getAge(age));
	out("getGender", test.test_getGender(gender));
	out("getHeight", test.test_getHeight(height));

	cout << endl;

	out("setName", test.test_setName("Childish Gambino"));
	out("setAge", test.test_setAge(100));
	out("setGender", test.test_setGender('m'));
	out("setHeight", test.test_setHeight(6.0));

	cout << endl;

	out("assignmentOperator", test.test_assignmentOperator(Person("Donald Glover", 30, 'm', 5.9)));
	
	cout << endl;

	out("extractionOperator", test.test_extractionOperator());
}

void out(string functionName, bool test) {
	cout << "[TEST] " << functionName << " - " << resultStr(test) << endl;
}

string resultStr(bool toString) {
	if (toString)
		return "PASS";
	return "FAIL";
}